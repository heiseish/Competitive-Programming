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

mod mint {
    use std::fmt;
    use std::ops::*;

    #[derive(Default, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
    pub struct MInt<const MOD: i64>(i64);

    impl<const MOD: i64> fmt::Display for MInt<MOD> {
        fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
            write!(f, "{}", self.0)
        }
    }

    fn add<const MOD: i64>(mut a: i64, mut b: i64) -> i64 {
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

    fn mult<const MOD: i64>(a: i64, b: i64) -> i64 {
        ((a % MOD) * (b % MOD)) % MOD
    }

    fn bin_pow<const MOD: i64>(mut a: i64, mut b: i64) -> i64 {
        a %= MOD;
        let mut ret = 1;
        while b > 0 {
            if (b & 1) > 0 {
                ret = mult::<MOD>(ret, a);
            }
            a = mult::<MOD>(a, a);
            b >>= 1;
        }
        ret
    }

    impl<const MOD: i64> MInt<MOD> {
        pub fn z() -> Self {
            Self::default()
        }

        pub fn new(value: i64) -> Self {
            Self(value % MOD)
        }

        pub fn pow(self, mut exp: MInt<MOD>) -> Self {
            Self::new(bin_pow::<MOD>(self.0, exp.0))
        }

        pub fn inv(self) -> Self {
            self.pow(Self::new(MOD - 2))
        }
    }

    impl<const MOD: i64> Add for MInt<MOD> {
        type Output = Self;

        fn add(self, rhs: Self) -> Self::Output {
            Self::new(add::<MOD>(self.0, rhs.0))
        }
    }

    impl<const MOD: i64> Add<i64> for MInt<MOD> {
        type Output = Self;

        fn add(self, rhs: i64) -> Self::Output {
            Self::new(add::<MOD>(self.0, rhs))
        }
    }

    impl<const MOD: i64> AddAssign for MInt<MOD> {
        fn add_assign(&mut self, rhs: Self) {
            *self = *self + rhs;
        }
    }

    impl<const MOD: i64> AddAssign<i64> for MInt<MOD> {
        fn add_assign(&mut self, rhs: i64) {
            *self = *self + rhs;
        }
    }

    impl<const MOD: i64> Sub for MInt<MOD> {
        type Output = Self;

        fn sub(self, rhs: Self) -> Self::Output {
            Self::new(add::<MOD>(self.0, -rhs.0))
        }
    }

    impl<const MOD: i64> Sub<i64> for MInt<MOD> {
        type Output = Self;

        fn sub(self, rhs: i64) -> Self::Output {
            Self::new(add::<MOD>(self.0, -rhs))
        }
    }

    impl<const MOD: i64> SubAssign for MInt<MOD> {
        fn sub_assign(&mut self, rhs: Self) {
            *self = *self - rhs;
        }
    }

    impl<const MOD: i64> SubAssign<i64> for MInt<MOD> {
        fn sub_assign(&mut self, rhs: i64) {
            *self = *self - rhs;
        }
    }

    impl<const MOD: i64> Neg for MInt<MOD> {
        type Output = Self;

        // Required method
        fn neg(self) -> Self::Output {
            Self::new(add::<MOD>(-self.0, 0))
        }
    }

    impl<const MOD: i64> Mul for MInt<MOD> {
        type Output = Self;

        fn mul(self, rhs: Self) -> Self::Output {
            Self::new(mult::<MOD>(self.0, rhs.0))
        }
    }

    impl<const MOD: i64> Mul<i64> for MInt<MOD> {
        type Output = Self;

        fn mul(self, rhs: i64) -> Self::Output {
            Self::new(mult::<MOD>(self.0, rhs))
        }
    }

    impl<const MOD: i64> MulAssign<Self> for MInt<MOD> {
        fn mul_assign(&mut self, rhs: Self) {
            *self = *self * rhs;
        }
    }

    impl<const MOD: i64> MulAssign<i64> for MInt<MOD> {
        fn mul_assign(&mut self, rhs: i64) {
            *self = *self * rhs;
        }
    }

    impl<const MOD: i64> Div for MInt<MOD> {
        type Output = Self;

        fn div(self, rhs: Self) -> Self::Output {
            self * rhs.inv()
        }
    }

    impl<const MOD: i64> Div<i64> for MInt<MOD> {
        type Output = Self;

        fn div(self, rhs: i64) -> Self::Output {
            self * Self::new(rhs).inv()
        }
    }

    impl<const MOD: i64> DivAssign<Self> for MInt<MOD> {
        fn div_assign(&mut self, rhs: Self) {
            *self = *self * rhs.inv();
        }
    }

    impl<const MOD: i64> DivAssign<i64> for MInt<MOD> {
        fn div_assign(&mut self, rhs: i64) {
            *self = *self * Self::new(rhs).inv();
        }
    }

    impl<const MOD: i64> From<i32> for MInt<MOD> {
        fn from(val: i32) -> Self {
            Self::new(val as i64)
        }
    }

    impl<const MOD: i64> From<i64> for MInt<MOD> {
        fn from(val: i64) -> Self {
            Self::new(val)
        }
    }

    impl<const MOD: i64> From<u32> for MInt<MOD> {
        fn from(val: u32) -> Self {
            Self::new(val as i64)
        }
    }

    impl<const MOD: i64> From<u64> for MInt<MOD> {
        fn from(val: u64) -> Self {
            Self::new(val as i64)
        }
    }

    impl<const MOD: i64> From<usize> for MInt<MOD> {
        fn from(val: usize) -> Self {
            Self::new(val as i64)
        }
    }

    pub fn init_inv_mod<const MOD: i64, const N: usize>() -> [MInt<MOD>; N] {
        let mut inv = [0i64; N];
        inv[0] = 1;
        inv[1] = 1;
        for i in 2..N {
            inv[i] = mult::<MOD>(
                add::<MOD>(MOD, -MOD / i as i64),
                inv[(MOD % i as i64) as usize],
            );
        }
        inv.map(|x| x.into())
    }
}

use mint::*;
const MOD: i64 = 1_000_000_007;

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let inv = init_inv_mod::<MOD, 300_007>();

    'outer: for tc in 0..(input.next::<usize>()) {
        let n: usize = input.next();
        let k: usize = input.next();

        let mut br = 0;

        for i in 0..k {
            let u: usize = input.next();
            let v: usize = input.next();
            if u == v {
                br += 1;
            } else {
                br += 2;
            }
        }
        let mut f = vec![MInt::<MOD>::default(); n + 3];
        f[n - br] = 1.into();
        for i in (0..(n - br)).rev() {
            f[i] = f[i + 1] + f[i + 2] * (2 * (i as i64 + 1));
        }
        write!(output, "{}\n", f[0]);
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
