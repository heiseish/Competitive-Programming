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

mod st {
    use std::ops::{Add, AddAssign};

    type modint = crate::mint::MInt<998244353>;
    #[derive(Default, Clone, Copy)]
    pub struct Node {
        pub val: modint,
        pub siz: i64,
    }

    pub fn f_combine_node(x: &Node, y: &Node) -> Node {
        Node {
            val: x.val + y.val,
            siz: x.siz + y.siz,
        }
    }

    pub fn f_invalid_node() -> Node {
        Node::default()
    }

    #[derive(Clone, Copy)]
    pub struct Act {
        pub b: modint,
        pub c: modint,
    }

    impl Default for Act {
        fn default() -> Self {
            Self {
                b: 1.into(),
                c: 0.into(),
            }
        }
    }

    pub fn f_map_act(f: &Act, x: &Node) -> Node {
        Node {
            val: f.b * x.val + f.c * x.siz,
            siz: x.siz,
        }
    }

    // Act composition function: gb((fb)x + fc) + gc = (gb fb)x + gb fc + gc
    // g is applied on f
    pub fn f_compose_act(f: &Act, g: &Act) -> Act {
        Act {
            b: g.b * f.b,
            c: g.b * f.c + g.c,
        }
    }

    // 1-indexed
    // Query on range using FC function
    // for invalid value, trigger call FN
    // range addition (Note: NOT assignment)
    pub struct LazySegmentTree<D, FC, FN, A, FM, FCA>
    where
        D: Default + Clone + Copy,
        FC: FnOnce(&D, &D) -> D + Copy,
        FN: FnOnce() -> D + Copy,
        A: Default + Clone + Copy,
        FM: FnOnce(&A, &D) -> D + Copy,
        FCA: FnOnce(&A, &A) -> A + Copy,
    {
        pub n: usize,
        pub lazy: Vec<A>,
        pub t: Vec<D>,
        pub fcombine: FC,
        pub fnull: FN,
        pub fmap: FM,
        pub fcompose: FCA,
    }

    impl<D, FC, FN, A, FM, FCA> LazySegmentTree<D, FC, FN, A, FM, FCA>
    where
        D: Default + Clone + Copy,
        FC: FnOnce(&D, &D) -> D + Copy,
        FN: FnOnce() -> D + Copy,
        A: Default + Clone + Copy,
        FM: FnOnce(&A, &D) -> D + Copy,
        FCA: FnOnce(&A, &A) -> A + Copy,
    {
        pub fn new(n: usize, fcombine: FC, fnull: FN, fmap: FM, fcompose: FCA) -> Self {
            let n = n + 3;
            let lazy = vec![A::default(); n << 2];
            let t = vec![D::default(); n << 2];
            Self {
                n,
                lazy,
                t,
                fcombine,
                fnull,
                fmap,
                fcompose,
            }
        }

        // modify a and this fn if necessary
        // a is 1-indexed too
        pub fn build(n: usize, a: &[D], fcombine: FC, fnull: FN, fmap: FM, fcompose: FCA) -> Self {
            let sz = n + 3;
            let lazy = vec![A::default(); sz << 2];
            let mut t = vec![D::default(); sz << 2];

            fn build_inner<D, FC>(v: usize, l: usize, r: usize, a: &[D], t: &mut [D], fcombine: &FC)
            where
                D: Default + Clone + Copy,
                FC: FnOnce(&D, &D) -> D + Copy,
            {
                if l == r {
                    t[v] = a[l];
                } else {
                    let mid = (l + r) >> 1;
                    build_inner(v << 1, l, mid, a, t, fcombine);
                    build_inner(v << 1 | 1, mid + 1, r, a, t, fcombine);
                    t[v] = fcombine(&t[v << 1], &t[v << 1 | 1]);
                }
            }

            build_inner(1, 1, n, &a, &mut t, &fcombine);
            Self {
                n,
                lazy,
                t,
                fcombine,
                fnull,
                fmap,
                fcompose,
            }
        }

        #[inline]
        fn push(&mut self, v: usize, l: usize, r: usize, fmap: &FM, fcompose: &FCA) {
            self.t[v] = fmap(&self.lazy[v], &self.t[v]);
            if l < r {
                self.lazy[v << 1] = fcompose(&self.lazy[v << 1], &self.lazy[v]);
                self.lazy[v << 1 | 1] = fcompose(&self.lazy[v << 1 | 1], &self.lazy[v]);
            }
            self.lazy[v] = A::default();
        }

        #[inline]
        pub fn update(&mut self, x: usize, y: usize, upd: A) {
            fn update_inner<D, FC, FN, A, FM, FCA>(
                st: &mut LazySegmentTree<D, FC, FN, A, FM, FCA>,
                v: usize,
                l: usize,
                r: usize,
                x: usize,
                y: usize,
                upd: A,
                fc: &FC,
                fmap: &FM,
                fcompose: &FCA,
            ) where
                D: Default + Clone + Copy,
                FC: FnOnce(&D, &D) -> D + Copy,
                FN: FnOnce() -> D + Copy,
                A: Default + Clone + Copy,
                FM: FnOnce(&A, &D) -> D + Copy,
                FCA: FnOnce(&A, &A) -> A + Copy,
            {
                st.push(v, l, r, fmap, fcompose);
                if l > y || r < x {
                    return;
                }
                if l >= x && r <= y {
                    st.lazy[v] = fcompose(&st.lazy[v], &upd);
                    st.push(v, l, r, fmap, fcompose);
                    return;
                }
                let mid = (l + r) >> 1;
                update_inner(st, v << 1, l, mid, x, y, upd, fc, fmap, fcompose);
                update_inner(st, v << 1 | 1, mid + 1, r, x, y, upd, fc, fmap, fcompose);
                st.t[v] = fc(&st.t[v << 1], &st.t[v << 1 | 1]);
            }
            let fcombine = self.fcombine;
            let fmap = self.fmap;
            let fcompose = self.fcompose;
            update_inner(self, 1, 1, self.n, x, y, upd, &fcombine, &fmap, &fcompose);
        }

        #[inline]
        pub fn get(&mut self, x: usize, y: usize) -> D {
            fn get_inner<D, FC, FN, A, FM, FCA>(
                st: &mut LazySegmentTree<D, FC, FN, A, FM, FCA>,
                v: usize,
                l: usize,
                r: usize,
                x: usize,
                y: usize,
                fc: &FC,
                fnull: &FN,
                fmap: &FM,
                fcompose: &FCA,
            ) -> D
            where
                D: Default + Clone + Copy,
                FC: FnOnce(&D, &D) -> D + Copy,
                FN: FnOnce() -> D + Copy,
                A: Default + Clone + Copy,
                FM: FnOnce(&A, &D) -> D + Copy,
                FCA: FnOnce(&A, &A) -> A + Copy,
            {
                if l > y || r < x {
                    return fnull();
                }
                st.push(v, l, r, fmap, fcompose);
                if l >= x && r <= y {
                    return st.t[v];
                }
                let mid = (l + r) >> 1;
                fc(
                    &get_inner(st, v << 1, l, mid, x, y, fc, fnull, fmap, fcompose),
                    &get_inner(st, v << 1 | 1, mid + 1, r, x, y, fc, fnull, fmap, fcompose),
                )
            }
            let fcombine = self.fcombine;
            let fnull = self.fnull;
            let fmap = self.fmap;
            let fcompose = self.fcompose;
            get_inner(
                self, 1, 1, self.n, x, y, &fcombine, &fnull, &fmap, &fcompose,
            )
        }
    }
}

use st::*;

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let n: usize = input.next();
    let q: usize = input.next();
    let mut a = vec![Node::default(); n + 1];
    for i in 1..=n {
        let x: i64 = input.next();
        a[i] = Node {
            val: x.into(),
            siz: 1,
        };
    }

    let mut lazy_segtree = LazySegmentTree::build(
        n,
        &a,
        f_combine_node,
        f_invalid_node,
        f_map_act,
        f_compose_act,
    );

    for _ in 0..q {
        let t: usize = input.next();
        match t {
            0 => {
                let l: usize = input.next();
                let r: usize = input.next();
                let b: i64 = input.next();
                let c: i64 = input.next();
                lazy_segtree.update(
                    l + 1,
                    r,
                    Act {
                        b: b.into(),
                        c: c.into(),
                    },
                );
            }
            1 => {
                let l: usize = input.next();
                let r: usize = input.next();
                let res = lazy_segtree.get(l + 1, r);
                write!(output, "{}\n", res.val);
            }
            _ => todo!(),
        }
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
