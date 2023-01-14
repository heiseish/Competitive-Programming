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

mod fenwich {
    macro_rules! lsone {
        ($S:tt) => {
            (($S as i32) & -($S as i32))
        };
    }
    pub struct FenwichTree {
        ft: Vec<u32>,
        n: usize,
    }
    impl FenwichTree {
        pub fn new(f: &[u8]) -> Self {
            let n = f.len() - 1;
            let mut ft = vec![0u32; n + 1];
            for i in 1..=n {
                ft[i] += f[i] as u32;
                let j = i + lsone!(i) as usize;
                if j <= n {
                    ft[j] += ft[i];
                }
            }
            Self { ft, n }
        }

        #[inline(always)]
        pub fn rsq_s(&self, mut j: i32) -> u32 {
            let mut sum = 0;
            while j > 0 {
                sum += self.ft[j as usize];
                j -= lsone!(j);
            }
            sum
        }

        #[inline(always)]
        pub fn rsq(&self, i: i32, j: i32) -> u32 {
            self.rsq_s(j) - self.rsq_s(i - 1)
        }

        #[inline(always)]
        pub fn update(&mut self, mut i: usize, v: u32) {
            loop {
                if i > self.n {
                    break;
                }
                self.ft[i] += v;
                i += lsone!(i) as usize;
            }
        }

        #[inline(always)]
        pub fn bit_search(&self, v: u32, bound: usize) -> usize {
            let mut sum = 0;
            let mut pos = 0;
            let logn = (self.n as f32).log2().floor() as usize + 1;
            for i in (0..=logn).rev() {
                if pos + (1 << i) < bound && sum + self.ft[pos + (1 << i)] >= v {
                    sum += self.ft[pos + (1 << i)];
                    pos += 1 << i;
                }
            }
            pos
        }
    }
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut w: W) -> Option<()> {
    // read in int/float
    let tc: u8 = input.next();
    let mut b = [0u8; 100005];
    let mut a = Vec::with_capacity(100_005);
    for _ in 0..tc {
        a.clear();
        let n: usize = input.next();
        let m: u32 = input.next();
        for i in 1..=n {
            b[i] = input.next();
            if b[i] <= m as u8 {
                a.push(i);
            }
        }
        let ft = fenwich::FenwichTree::new(&b[0..=n]);
        let l = a.len();
        let mut ans = m;
        for i in 0..l {
            let idx = a[i];
            if b[idx] < m as u8 {
                continue;
            }
            if i == 0 {
                if l == 1 {
                    ans = max(ans, ft.rsq(1, n as i32));
                } else {
                    ans = max(ans, ft.rsq(1, (a[i + 1] - 1) as i32));
                }
            } else if i == l - 1 {
                if l == 1 {
                    ans = max(ans, ft.rsq(1, n as i32));
                } else {
                    ans = max(ans, ft.rsq((a[i - 1] + 1) as i32, n as i32));
                }
            } else {
                ans = max(ans, ft.rsq((a[i - 1] + 1) as i32, (a[i + 1] - 1) as i32));
            }
        }
        write!(w, "{}\n", ans);
    }
    None
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
    current_index: usize,
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
            current_index: 0,
        }
    }
    #[inline(always)]
    pub fn next<T: InputReadable>(&mut self) -> T {
        T::from_input(self)
    }

    pub fn read_line(&mut self, buf: &mut String) -> bool {
        assert!(self.has_more());
        let mut ret = false;
        // retry
        for _ in 1..=2 {
            while self.peek() != '\n' {
                buf.push(self.peek());
                self.consume();
                ret = true;
                if !self.has_more() {
                    break;
                }
            }
            if ret {
                break;
            }
            self.consume();
        }
        self.consume(); // consume '\n'
        ret
    }
    #[inline(always)]
    pub fn has_more(&mut self) -> bool {
        if self.current_index >= self.bytes_read {
            self.bytes_read = self.reader.read(&mut self.buf[..]).unwrap();
            self.current_index = 0
        }
        self.bytes_read > 0
    }
    #[inline(always)]
    fn peek(&self) -> char {
        self.buf[self.current_index] as char
    }

    #[inline(always)]
    fn peek_int(&self) -> u8 {
        self.buf[self.current_index]
    }

    #[inline(always)]
    fn consume(&mut self) {
        self.current_index += 1;
    }

    #[inline(always)]
    fn pop_digit(&mut self) -> u32 {
        let c = self.peek_int();
        self.consume();
        c as u32 - 48
    }

    #[inline(always)]
    fn consume_until<F: Fn(char) -> bool>(&mut self, test: F) {
        loop {
            assert!(self.has_more());
            if test(self.peek()) {
                return;
            }
            self.consume();
        }
    }

    #[inline(always)]
    fn consume_until_int<F: Fn(u8) -> bool>(&mut self, test: F) {
        loop {
            assert!(self.has_more());
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
                if input.peek() == '.' {
                    input.consume();
                    while input.has_more() && input.peek().is_ascii_digit() {
                        num = num * 10.0 + input.pop_digit() as $t;
                        factor *= 10.0;
                    }
                }
                sign * num / factor
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
