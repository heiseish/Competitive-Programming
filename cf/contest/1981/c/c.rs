#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
#![allow(unused_macros)]
#![allow(unused_imports)]
use core::f32::*;
use std::cmp::*;
use std::collections::*;
use std::f32::consts::*;
use std::fs::File;
use std::io::*;
use std::iter::FromIterator;
use std::ops::*;

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    let mut a = vec![0i64; 200_005];
    let mut b = vec![0i64; 200_005];
    'outer: for _ in 0..(input.next::<usize>()) {
        let n: usize = input.next();
        a[1..=n].iter_mut().for_each(|x| *x = input.next());
        if *a[1..=n].iter().max().unwrap() == -1 {
            let ans = [1, 2];
            let mut flag = 0;
            for _ in 1..=n {
                write!(output, "{} ", ans[flag]);
                flag ^= 1;
            }
            write!(output, "\n");
            continue;
        }
        let mut st = 0;

        fn count_bits(mut n: i64) -> i64 {
            let mut res = 0;
            while n > 0 {
                n >>= 1;
                res += 1;
            }
            res
        }
        fn bit_array(mut n: i64) -> VecDeque<bool> {
            let mut res = VecDeque::new();

            while n > 0 {
                if n & 1 > 0 {
                    res.push_front(true);
                } else {
                    res.push_front(false);
                }
                n >>= 1;
            }
            res
        }
        for i in 1..=n {
            if a[i] == -1 {
                continue;
            }
            b[i] = a[i];
            if st == 0 {
                // open beginning
                let mut idx = i - 1;
                let mut flag = 0;
                while idx >= 1 {
                    if flag == 0 {
                        b[idx] = b[idx + 1] << 1;
                    } else {
                        b[idx] = b[idx + 1] >> 1;
                    }
                    flag ^= 1;
                    idx -= 1;
                }
                st = i;
                continue;
            }
            let mut diff = i - st;
            let mi = a[i].min(a[st]);
            let ma = a[i].max(a[st]);
            let start = count_bits(mi);
            let end = count_bits(ma);
            // dbg!(st, i, start, end, diff);
            if (end - start) % 2 != diff as i64 % 2 {
                write!(output, "-1\n");
                continue 'outer;
            }
            let sst = st;
            let rev = a[st] > a[i];

            let bit_array_l = bit_array(mi);
            let bit_array_r = bit_array(ma);
            b[st] = mi;
            b[i] = ma;
            let mut pop = 0;
            let mut popidx = bit_array_l.len();
            for i in 0..bit_array_l.len() {
                if bit_array_l[i] != bit_array_r[i] {
                    pop = bit_array_l.len() - i;
                    popidx = i;
                    break;
                }
            }
            // dbg!(&b[sst..=i]);
            for _ in 0..pop {
                if st + 1 >= i {
                    write!(output, "-1\n");
                    continue 'outer;
                }
                // dbg!(&b[sst..=i]);
                b[st + 1] = b[st] >> 1;
                st += 1;
            }
            // dbg!(&b[sst..=i]);
            // dbg!(popidx, bit_array_r.len() - 1);
            for ii in popidx..(bit_array_r.len() - 1) {
                if st + 1 >= i {
                    write!(output, "-1\n");
                    continue 'outer;
                }
                if bit_array_r[ii] {
                    b[st + 1] = b[st] << 1 | 1;
                } else {
                    b[st + 1] = b[st] << 1;
                }
                // dbg!(&b[sst..=i]);
                st += 1;
            }
            // assert_eq!(b[st], b[i]);
            let mut flag = 0;
            while st + 1 != i {
                if flag == 0 {
                    b[st + 1] = b[st] << 1;
                } else {
                    b[st + 1] = b[st] >> 1;
                }
                // dbg!(&b[sst..=i]);
                flag ^= 1;
                st += 1;
            }
            // dbg!(&b[sst..=i]);

            if rev {
                b[sst..=i].reverse();
            }
            // dbg!(&b[sst..=i]);
            st = i;
        }

        if st != n {
            // open last
            let mut flag = 0;
            for i in (st + 1)..=n {
                if flag == 0 {
                    b[i] = b[i - 1] << 1;
                } else {
                    b[i] = b[i - 1] >> 1;
                }
                flag ^= 1;
            }
        }
        for i in 1..=n {
            write!(output, "{} ", b[i]);
        }
        write!(output, "\n");
    }
}

fn main() {
    let input = InputReader::new();
    let writer = BufWriter::new(stdout().lock());
    solve(input, writer);
}

pub struct InputReader<R: BufRead> {
    reader: R,
    buf: [u8; 1 << 16],
    bytes_read: usize,
    strent_index: usize,
}

impl InputReader<StdinLock<'_>> {
    pub fn new() -> Self {
        Self::from_reader(stdin().lock())
    }
}

impl InputReader<BufReader<File>> {
    pub fn from_file(path: &str) -> Self {
        Self::from_reader(BufReader::new(File::open(path).unwrap()))
    }
}

impl<R: BufRead> InputReader<R> {
    pub fn from_reader(reader: R) -> Self {
        Self {
            reader,
            buf: [0; 1 << 16],
            bytes_read: 0,
            strent_index: 0,
        }
    }
    #[inline(always)]
    pub fn next<T: InputReadable>(&mut self) -> T {
        T::from_input(self)
    }

    pub fn read_line(&mut self, buf: &mut String) {
        self.consume_until(|c| c.is_ascii_graphic());
        while self.has_more() && self.peek().is_ascii_graphic() {
            buf.push(self.peek());
            self.consume();
        }
        self.consume_until(|c| c.is_ascii_graphic());
    }
    #[inline(always)]
    pub fn has_more(&mut self) -> bool {
        if self.strent_index >= self.bytes_read {
            self.bytes_read = self.reader.read(&mut self.buf[..]).unwrap();
            self.strent_index = 0
        }
        self.bytes_read > 0
    }
    #[inline(always)]
    fn peek(&self) -> char {
        self.buf[self.strent_index] as char
    }

    #[inline(always)]
    fn peek_int(&self) -> u8 {
        self.buf[self.strent_index]
    }

    #[inline(always)]
    fn consume(&mut self) {
        self.strent_index += 1;
    }

    #[inline(always)]
    fn pop_digit(&mut self) -> u32 {
        let c = self.peek_int();
        self.consume();
        c as u32 - 48
    }

    #[inline(always)]
    fn consume_until<F: Fn(char) -> bool>(&mut self, test: F) {
        while self.has_more() {
            if test(self.peek()) {
                return;
            }
            self.consume();
        }
    }

    #[inline(always)]
    fn consume_until_int<F: Fn(u8) -> bool>(&mut self, test: F) {
        while self.has_more() {
            if test(self.peek_int()) {
                return;
            }
            self.consume();
        }
    }

    #[inline(always)]
    fn consume_until_sign(&mut self) -> i64 {
        loop {
            self.consume_until(|c| c.is_ascii_digit() || c == '-');
            if self.peek() != '-' {
                return 1;
            }

            self.consume();
            assert!(self.has_more());
            if self.peek().is_ascii_digit() {
                return -1;
            }
        }
    }
}

pub trait InputReadable {
    fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self;
}

impl InputReadable for String {
    fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self {
        input.consume_until(|c| c.is_ascii_graphic());
        let mut word = String::new();
        while input.peek().is_ascii_graphic() {
            word.push(input.peek());
            input.consume();
            if !input.has_more() {
                break;
            }
        }
        word
    }
}

impl InputReadable for char {
    #[inline(always)]
    fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self {
        input.consume_until(|c| c.is_ascii_graphic());
        let c = input.peek();
        input.consume();
        c
    }
}

macro_rules! impl_readable_from {
  ($A:ty, [$($T:ty),+]) => {
    $(impl InputReadable for $T {
        #[inline(always)]
      fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self {
        <$A>::from_input(input) as $T
      }
    })+
  };
}

macro_rules! impl_unsign_from_input {
    ($($t:ty),+) => {$(
        impl InputReadable for $t {
            #[inline(always)]
            fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self {
                input.consume_until_int(|c| c.is_ascii_graphic());
                let mut num = 0 as $t;
                while input.peek_int().is_ascii_graphic() {
                    num = num * 10 + input.pop_digit() as $t;
                    if !input.has_more() {
                        break;
                    }
                }
                num
            }
        }
    )+};
}

macro_rules! impl_sign_from_input {
    ($b:ty, $t:ty) => {
        impl InputReadable for $t {
            #[inline(always)]
            fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self {
                let sign = input.consume_until_sign();
                <$b>::from_input(input) as $t * sign as $t
            }
        }
    };
}

macro_rules! impl_floating_from_input {
    ($($t:ty),+) => {$(
        impl InputReadable for $t {
            #[inline(always)]
            fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self {
                let sign = input.consume_until_sign() as $t;
                let mut num = 0.0;
                while input.peek().is_ascii_digit() {
                    num = num * 10.0 + input.pop_digit() as $t;
                    if !input.has_more() {
                        break;
                    }
                }

                let mut factor = 1.0;
                if input.has_more() && input.peek() == '.' {
                    input.consume();
                    while input.has_more() && input.peek().is_ascii_digit() {
                        num = num * 10.0 + input.pop_digit() as $t;
                        factor *= 10.0;
                    }
                }
                let mantissa = sign * num / factor;

                if input.has_more() && (input.peek() == 'E' || input.peek() == 'e') {
                    let mut exp = 0.0 as $t;
                    input.consume();
                    exp *= input.consume_until_sign() as $t;
                    while input.has_more() && input.peek().is_ascii_digit() {
                        exp = exp * 10.0 + input.pop_digit() as $t;
                        factor *= 10.0;
                    }
                    mantissa * (10.0 as $t).powf(exp)
                } else {
                    mantissa
                }

            }
        }
    )+};
}

impl_unsign_from_input! {u32, u64}
impl_sign_from_input! {u32, i32}
impl_sign_from_input! {u64, i64}
impl_floating_from_input! {f32, f64}
impl_readable_from! { u32, [u16, u8, usize] }
impl_readable_from! { i32, [i16, i8, isize] }
