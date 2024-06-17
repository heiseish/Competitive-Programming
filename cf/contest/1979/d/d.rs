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
use std::ops::Bound::*;
use std::ops::*;

mod str_hash {
    type HashT = u64;

    pub struct StringHasher<
        const N: usize,
        const CH: char = 'a',
        const P: usize = 31,
        const M: u64 = 1_000_000_009,
    > {
        p_pow: Vec<HashT>,
        h: Vec<Vec<HashT>>,
    }

    impl<const N: usize, const CH: char, const P: usize, const M: HashT> StringHasher<N, CH, P, M> {
        pub fn new() -> Self {
            let mut p_pow = vec![0; N + 1];
            p_pow[0] = 1;
            for i in 1..=N {
                p_pow[i] = (p_pow[i - 1] * P as HashT) % M;
            }
            Self { p_pow, h: vec![] }
        }

        pub fn hash(&mut self, s: &[char]) -> usize {
            let tag = self.h.len();
            let n = s.len();
            self.h.push(vec![0; n + 1]);
            for i in 0..n {
                self.h[tag][i + 1] =
                    (self.h[tag][i] + (s[i] as HashT - CH as HashT + 1) * self.p_pow[i]) % M;
            }
            tag
        }

        pub fn compute_with_len(&mut self, tag: usize, first: usize, len: usize) -> HashT {
            let h = &self.h[tag];
            let mut res = (h[first + len] + M - h[first]) % M;
            (res * self.p_pow[N - first]) % M
        }

        pub fn compute_with_bound(&mut self, tag: usize, first: usize, last: usize) -> HashT {
            let h = &self.h[tag];
            let mut res = (h[last + 1] + M - h[first]) % M;
            (res * self.p_pow[N - first]) % M
        }

        pub fn compute_max_len(&mut self, tag: usize) -> HashT {
            self.h[tag][self.h[tag].len() - 1]
        }
    }
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let mut hasher = str_hash::StringHasher::<200_005, '0', 2>::new();

    'outer: for _ in 0..(input.next::<usize>()) {
        let n: usize = input.next();
        let k: usize = input.next();
        let mut s = String::new();
        input.read_line(&mut s);
        let s = s.chars().collect::<Vec<char>>();

        if n == k {
            if s.into_iter().collect::<HashSet<_>>().len() != 1 {
                write!(output, "-1\n");
            } else {
                write!(output, "1\n");
            }
            continue 'outer;
        }

        let mut atts = vec![vec![]; 2];
        for i in 0..k {
            atts[0].push('0');
            atts[1].push('1');
        }
        let mut flag = 1;
        while atts[0].len() != n {
            for i in 0..k {
                atts[flag].push('0');
                atts[flag ^ 1].push('1');
            }
            flag ^= 1;
        }
        for i in 0..2 {
            let mut tmp = atts[i].clone();
            atts[i].append(&mut tmp);
        }
        // should have the 000111000111 pattern now
        let mut rs = s.clone();
        rs.reverse();

        let tags = hasher.hash(&s);
        let tagrs = hasher.hash(&rs);
        let mut taghats = [0; 2];

        for i in 0..2 {
            taghats[i] = hasher.hash(&atts[i]);
        }

        for l in 1..=n {
            for j in 0..2 {
                let mut can = true;
                let p = n - l;
                // 1st half
                can &= hasher.compute_with_len(tagrs, n - p, p)
                    == hasher.compute_with_len(taghats[j], l, p);

                // 2nd half
                can &= hasher.compute_with_len(tags, p, l)
                    == hasher.compute_with_len(taghats[j], l + p, l);

                if can {
                    write!(output, "{}\n", p);
                    continue 'outer;
                }
            }
        }

        write!(output, "-1\n");
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
