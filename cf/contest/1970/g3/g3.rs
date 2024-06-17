#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
#![allow(unused_macros)]
#![allow(unused_imports)]
use core::f32::*;
use core::iter::{self, repeat, Chain, Enumerate, FromIterator, Repeat, Skip, Take};
use core::ops::*;
use core::{cmp, fmt, hash, mem, slice};
use std::cmp::*;
use std::collections::*;
use std::f32::consts::*;
use std::fs::File;
use std::io::*;
use std::ops::*;

mod bitset2 {
    #![allow(clippy::suspicious_op_assign_impl)]

    const TRUE: &bool = &true;
    const FALSE: &bool = &false;

    #[derive(Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
    /// Fixed sized bitset
    pub struct BitSet {
        buf: Vec<u64>,
        size: usize,
    }

    impl BitSet {
        /// Construct a new, zero bitset with specified capacity.
        /// This method allocates O(size) bits
        pub fn new(size: usize) -> BitSet {
            BitSet {
                buf: vec![0; (size + 63) / 64],
                size,
            }
        }

        /// Set i-th bit to `b`
        #[inline]
        pub fn set(&mut self, i: usize, b: bool) {
            assert!(i < self.size);
            if b {
                self.buf[i >> 6] |= 1 << (i & 63);
            } else {
                self.buf[i >> 6] &= !(1 << (i & 63));
            }
        }

        /// Get the size of bits
        #[inline]
        pub fn size(&self) -> usize {
            self.size
        }

        /// Get the number of ones
        #[inline]
        pub fn count_ones(&self) -> u32 {
            self.buf.iter().map(|x| x.count_ones()).sum()
        }

        /// Get the number of zeros
        #[inline]
        pub fn count_zeros(&self) -> u32 {
            self.size as u32 - self.count_ones()
        }

        /// Faster left shift and or
        ///
        /// `bitset | (bitset << x)`
        #[inline]
        pub fn shl_or(&mut self, x: usize) {
            let q = x >> 6;
            let r = x & 63;

            if q >= self.buf.len() {
                return;
            }

            if r == 0 {
                for i in (q..self.buf.len()).rev() {
                    *unsafe { self.buf.get_unchecked_mut(i) } |=
                        *unsafe { self.buf.get_unchecked(i - q) };
                }
            } else {
                for i in (q + 1..self.buf.len()).rev() {
                    *unsafe { self.buf.get_unchecked_mut(i) } |=
                        (unsafe { self.buf.get_unchecked(i - q) } << r)
                            | (unsafe { self.buf.get_unchecked(i - q - 1) } >> (64 - r));
                }
                *unsafe { self.buf.get_unchecked_mut(q) } |=
                    unsafe { self.buf.get_unchecked(0) } << r;
            }

            self.chomp();
        }

        /// Get inner buffer
        #[inline]
        pub fn buffer(&self) -> &[u64] {
            &self.buf
        }

        /// Get inner buffer with mutable reference
        #[inline]
        pub fn buffer_mut(&mut self) -> &mut [u64] {
            &mut self.buf
        }

        /// Set tailing bits in inner buffer whose index are greater than size to `0`
        #[inline]
        pub fn chomp(&mut self) {
            let r = self.size & 63;
            if r != 0 {
                if let Some(x) = self.buf.last_mut() {
                    let d = 64 - r;
                    *x = (*x << d) >> d;
                }
            }
        }
    }

    impl std::ops::Index<usize> for BitSet {
        type Output = bool;
        #[inline]
        fn index(&self, index: usize) -> &bool {
            assert!(index < self.size);
            [FALSE, TRUE][(self.buf[index >> 6] >> (index & 63)) as usize & 1]
        }
    }

    impl std::ops::ShlAssign<usize> for BitSet {
        #[inline]
        fn shl_assign(&mut self, x: usize) {
            let q = x >> 6;
            let r = x & 63;

            if q >= self.buf.len() {
                for x in &mut self.buf {
                    *x = 0;
                }
                return;
            }

            if r == 0 {
                for i in (q..self.buf.len()).rev() {
                    *unsafe { self.buf.get_unchecked_mut(i) } =
                        *unsafe { self.buf.get_unchecked(i - q) };
                }
            } else {
                for i in (q + 1..self.buf.len()).rev() {
                    *unsafe { self.buf.get_unchecked_mut(i) } =
                        (unsafe { self.buf.get_unchecked(i - q) } << r)
                            | (unsafe { self.buf.get_unchecked(i - q - 1) } >> (64 - r));
                }
                *unsafe { self.buf.get_unchecked_mut(q) } =
                    unsafe { self.buf.get_unchecked(0) } << r;
            }

            for x in &mut self.buf[..q] {
                *x = 0;
            }

            self.chomp();
        }
    }

    impl std::ops::Shl<usize> for BitSet {
        type Output = Self;

        #[inline]
        fn shl(mut self, x: usize) -> Self {
            self <<= x;
            self
        }
    }

    impl<'a> std::ops::Shl<usize> for &'a BitSet {
        type Output = BitSet;
        #[inline]
        fn shl(self, x: usize) -> Self::Output {
            let mut result = self.clone();
            result <<= x;
            result
        }
    }

    impl std::ops::ShrAssign<usize> for BitSet {
        #[inline]
        fn shr_assign(&mut self, x: usize) {
            let q = x >> 6;
            let r = x & 63;

            if q >= self.buf.len() {
                for x in &mut self.buf {
                    *x = 0;
                }
                return;
            }

            if r == 0 {
                for i in 0..self.buf.len() - q {
                    *unsafe { self.buf.get_unchecked_mut(i) } =
                        *unsafe { self.buf.get_unchecked(i + q) };
                }
            } else {
                for i in 0..self.buf.len() - q - 1 {
                    *unsafe { self.buf.get_unchecked_mut(i) } =
                        (unsafe { self.buf.get_unchecked(i + q) } >> r)
                            | (unsafe { self.buf.get_unchecked(i + q + 1) } << (64 - r));
                }
                let len = self.buf.len();
                *unsafe { self.buf.get_unchecked_mut(len - q - 1) } =
                    unsafe { self.buf.get_unchecked(len - 1) } >> r;
            }

            let len = self.buf.len();
            for x in &mut self.buf[len - q..] {
                *x = 0;
            }
        }
    }

    impl std::ops::Shr<usize> for BitSet {
        type Output = Self;

        #[inline]
        fn shr(mut self, x: usize) -> Self {
            self >>= x;
            self
        }
    }

    impl<'a> std::ops::Shr<usize> for &'a BitSet {
        type Output = BitSet;

        #[inline]
        fn shr(self, x: usize) -> Self::Output {
            let mut result = self.clone();
            result >>= x;
            result
        }
    }

    impl<'a> std::ops::BitAndAssign<&'a BitSet> for BitSet {
        #[inline]
        fn bitand_assign(&mut self, rhs: &'a Self) {
            for (a, b) in self.buf.iter_mut().zip(rhs.buf.iter()) {
                *a &= *b;
            }
        }
    }

    impl<'a> std::ops::BitAndAssign<BitSet> for BitSet {
        #[inline]
        fn bitand_assign(&mut self, rhs: Self) {
            for (a, b) in self.buf.iter_mut().zip(rhs.buf.iter()) {
                *a &= *b;
            }
        }
    }

    impl<'a> std::ops::BitAnd<&'a BitSet> for BitSet {
        type Output = Self;
        #[inline]
        fn bitand(mut self, rhs: &'a Self) -> Self::Output {
            self &= rhs;
            self
        }
    }

    impl<'a, 'b> std::ops::BitAnd<&'b BitSet> for &'a BitSet {
        type Output = BitSet;
        #[inline]
        fn bitand(self, rhs: &'b BitSet) -> Self::Output {
            let mut result = self.clone();
            result &= rhs;
            result
        }
    }

    impl<'a> std::ops::BitOrAssign<&'a BitSet> for BitSet {
        #[inline]
        fn bitor_assign(&mut self, rhs: &'a Self) {
            for (a, b) in self.buf.iter_mut().zip(rhs.buf.iter()) {
                *a |= *b;
            }
            self.chomp();
        }
    }

    impl std::ops::BitOrAssign<BitSet> for BitSet {
        #[inline]
        fn bitor_assign(&mut self, rhs: Self) {
            for (a, b) in self.buf.iter_mut().zip(rhs.buf.iter()) {
                *a |= *b;
            }
            self.chomp();
        }
    }

    impl<'a> std::ops::BitOr<&'a BitSet> for BitSet {
        type Output = Self;
        #[inline]
        fn bitor(mut self, rhs: &'a Self) -> Self::Output {
            self |= rhs;
            self
        }
    }

    impl std::ops::BitOr<BitSet> for BitSet {
        type Output = Self;
        #[inline]
        fn bitor(mut self, rhs: Self) -> Self::Output {
            self |= rhs;
            self
        }
    }

    impl<'a, 'b> std::ops::BitOr<&'b BitSet> for &'a BitSet {
        type Output = BitSet;
        #[inline]
        fn bitor(self, rhs: &'b BitSet) -> Self::Output {
            let mut result = self.clone();
            result |= rhs;
            result
        }
    }

    impl<'a> std::ops::BitXorAssign<&'a BitSet> for BitSet {
        #[inline]
        fn bitxor_assign(&mut self, rhs: &'a Self) {
            for (a, b) in self.buf.iter_mut().zip(rhs.buf.iter()) {
                *a ^= *b;
            }
            self.chomp();
        }
    }

    impl std::ops::BitXorAssign<BitSet> for BitSet {
        #[inline]
        fn bitxor_assign(&mut self, rhs: Self) {
            for (a, b) in self.buf.iter_mut().zip(rhs.buf.iter()) {
                *a ^= *b;
            }
            self.chomp();
        }
    }

    impl<'a> std::ops::BitXor<&'a BitSet> for BitSet {
        type Output = Self;
        #[inline]
        fn bitxor(mut self, rhs: &'a Self) -> Self {
            self ^= rhs;
            self
        }
    }

    impl<'a, 'b> std::ops::BitXor<&'b BitSet> for &'a BitSet {
        type Output = BitSet;
        #[inline]
        fn bitxor(self, rhs: &'b BitSet) -> Self::Output {
            let mut result = self.clone();
            result ^= rhs;
            result
        }
    }

    impl std::ops::Not for BitSet {
        type Output = Self;
        #[inline]
        fn not(mut self) -> Self::Output {
            for x in &mut self.buf {
                *x = !*x;
            }
            self.chomp();
            self
        }
    }

    impl<'a> std::ops::Not for &'a BitSet {
        type Output = BitSet;
        #[inline]
        fn not(self) -> Self::Output {
            !self.clone()
        }
    }
}

type Graph = Vec<Vec<usize>>;

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    'outer: for _ in 0..(input.next::<usize>()) {
        let n: usize = input.next();
        let m: usize = input.next();
        let c: i64 = input.next();
        let mut g = vec![vec![]; n + 2];
        for _ in 0..m {
            let u: usize = input.next();
            let v: usize = input.next();
            g[u].push(v);
            g[v].push(u);
        }

        fn dfs(
            u: usize,
            p: i32,
            g: &Graph,
            grps: &mut [usize],
            grp: usize,
            vis: &mut [bool],
            tin: &mut [usize],
            low: &mut [usize],
            timer: &mut usize,
            bl: &mut [Vec<usize>],
            szs: &mut [usize],
        ) -> usize {
            let mut sz = 1;
            vis[u] = true;
            tin[u] = *timer;
            low[u] = *timer;
            *timer += 1;
            grps[u] = grp;

            for &v in &g[u] {
                if v as i32 == p {
                    continue;
                }
                if vis[v] {
                    low[u] = low[u].min(tin[v]);
                } else {
                    sz += dfs(v, u as i32, g, grps, grp, vis, tin, low, timer, bl, szs);
                    low[u] = low[u].min(low[v]);
                    if low[v] > tin[u] {
                        bl[grps[u]].push(v);
                    }
                }
            }
            szs[u] = sz;
            sz
        }

        let mut grps = vec![0; n + 3];
        let mut grps_size = vec![0; n + 3];
        let mut szs = vec![0; n + 3];
        let mut tin = vec![0; n + 3];
        let mut vis = vec![false; n + 3];
        let mut low = vec![0; n + 3];
        let mut ble = vec![vec![]; n + 3];
        let mut timer = 0;

        let mut grp = 1;

        for u in 1..=n {
            if !vis[u] {
                dfs(
                    u, -1, &g, &mut grps, grp, &mut vis, &mut tin, &mut low, &mut timer, &mut ble,
                    &mut szs,
                );
                grp += 1;
            }
        }
        for u in 1..=n {
            grps_size[grps[u]] += 1;
        }

        let mut ans = 0i64;
        let ct = grps_size[1..=n]
            .iter()
            .filter(|&x| *x > 0)
            .collect::<Vec<_>>()
            .len();
        ans += (ct as i64 - 1) * c;

        let mut bs1 = bitset2::BitSet::new(n + 2);
        let mut bs2 = bitset2::BitSet::new(n + 2);
        bs1.set(0, true);
        bs2.set(0, true);

        // loop through all the groups
        for i in 1..grp {
            bs2.shl_or(grps_size[i]);
            for &v in &ble[i] {
                bs2 |= bs1.clone() << szs[v];
                bs2 |= bs1.clone() << (grps_size[i] - szs[v]);
            }
            bs1.shl_or(grps_size[i]);
        }
        let mut mid = n / 2;
        while !bs2[mid] {
            mid -= 1;
        }
        if mid == 0 {
            write!(output, "-1\n");
            continue 'outer;
        }
        let mid = mid as i64;
        write!(
            output,
            "{}\n",
            ans + (mid * mid) + (n as i64 - mid) * (n as i64 - mid)
        );
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
