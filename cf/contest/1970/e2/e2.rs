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

const MOD: i64 = 1_000_000_007;

fn add(mut a: i64, mut b: i64) -> i64 {
    if a < 0 {
        a += MOD;
    }
    a %= MOD;
    if b < 0 {
        b += MOD;
    }
    b %= MOD;
    (a + b) % MOD
}

fn mult(a: i64, b: i64) -> i64 {
    (a * b) % MOD
}

#[derive(Clone, Copy)]
struct Matrix<const NR: usize, const NC: usize> {
    pub data: [[i64; NC]; NR],
}

impl<const NR: usize, const NC: usize> Default for Matrix<NR, NC> {
    fn default() -> Self {
        Self {
            data: [[0i64; NC]; NR],
        }
    }
}

impl<const R1: usize, const C1: usize, const C2: usize> Mul<Matrix<C1, C2>> for Matrix<R1, C1> {
    type Output = Matrix<R1, C2>;

    fn mul(self, rhs: Matrix<C1, C2>) -> Self::Output {
        let mut ans = [[0i64; C2]; R1];

        for i in 0..R1 {
            for j in 0..C2 {
                for k in 0..C1 {
                    ans[i][j] = add(ans[i][j], mult(self.data[i][k], rhs.data[k][j]));
                }
            }
        }
        Matrix::<R1, C2> { data: ans }
    }
}

impl<const NR: usize, const NC: usize> Matrix<NR, NC> {
    pub fn new() -> Self {
        Self {
            data: [[0i64; NC]; NR],
        }
    }
}

impl<const N: usize> Matrix<N, N> {
    pub fn pow(mut self, mut p: i64) -> Self {
        let mut ans = Self {
            data: [[0i64; N]; N],
        };
        for i in 0..N {
            for j in 0..N {
                ans.data[i][j] = (i == j) as i64;
            }
        }
        while p > 0 {
            if p & 1 > 0 {
                ans = ans * self;
            }
            self = self * self;
            p >>= 1;
        }
        ans
    }
}

fn bin_pow(mut a: i64, mut b: i64) -> i64 {
    a %= MOD;
    let mut ret = 1;
    while b > 0 {
        if (b & 1) > 0 {
            ret = mult(ret, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    ret
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let m: usize = input.next();
    let n: usize = input.next();
    let mut s = vec![0; m + 1];
    let mut l = vec![0; m + 1];
    s[1..=m].iter_mut().for_each(|x| *x = input.next());
    l[1..=m].iter_mut().for_each(|x| *x = input.next());
    let mut base = Matrix::<1, 101>::new();
    let mut mat = Matrix::<101, 101>::new();
    for i in 1..=m {
        for j in 1..=m {
            mat.data[i - 1][j - 1] = s[i] * l[j] + s[j] * l[i] + s[i] * s[j];
        }
    }
    base.data[0][0] = 1;
    let mat = base * mat.pow(n as i64);
    let mut ans = 0;
    for i in 1..=m {
        ans = add(ans, mat.data[0][i - 1]);
    }
    write!(output, "{}\n", ans);
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
