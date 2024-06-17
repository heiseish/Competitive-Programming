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

mod st {
    use std::ops::{Add, AddAssign};

    // 1-indexed
    // Query on range using FC function
    // for invalid value, trigger call FN
    // range addition (Note: NOT assignment)
    pub struct SegmentTreeRARQ<D, FC, FN>
    where
        D: Default + Copy + AddAssign,
        FC: FnOnce(&D, &D) -> D + Clone + Copy,
        FN: FnOnce() -> D + Clone + Copy,
    {
        pub n: usize,
        pub lazy: Vec<D>,
        pub t: Vec<D>,
        pub fc: FC,
        pub fnull: FN,
    }

    impl<D, FC, FN> SegmentTreeRARQ<D, FC, FN>
    where
        D: Default + Copy + AddAssign,
        FC: FnOnce(&D, &D) -> D + Clone + Copy,
        FN: FnOnce() -> D + Clone + Copy,
    {
        pub fn new(n: usize, fc: FC, fnull: FN) -> Self {
            let n = n + 3;
            let lazy = vec![D::default(); n << 2];
            let t = vec![D::default(); n << 2];
            Self {
                n,
                lazy,
                t,
                fc,
                fnull,
            }
        }

        // modify a and this fn if necessary
        pub fn build(a: Vec<D>, fc: FC, fnull: FN) -> Self {
            let sz = a.len() + 3; // 0-indexed
            let lazy = vec![D::default(); sz << 2];
            let mut t = vec![D::default(); sz << 2];

            fn build_inner<D, FC>(v: usize, l: usize, r: usize, a: &[D], t: &mut [D], fc: &FC)
            where
                D: Default + Copy + AddAssign,
                FC: FnOnce(&D, &D) -> D + Clone + Copy,
            {
                if l == r {
                    t[v] = a[l];
                } else {
                    let mid = (l + r) >> 1;
                    build_inner(v << 1, l, mid, a, t, fc);
                    build_inner(v << 1 | 1, mid + 1, r, a, t, fc);
                    t[v] = fc(&t[v << 1], &t[v << 1 | 1]);
                }
            }

            build_inner(1, 0, a.len() - 1, &a[..], &mut t, &fc);
            Self {
                n: sz,
                lazy,
                t,
                fc,
                fnull,
            }
        }

        #[inline]
        fn push(&mut self, v: usize, l: usize, r: usize) {
            self.t[v] += self.lazy[v];
            if l < r {
                let cur = self.lazy[v].clone();
                self.lazy[v << 1] += cur;
                self.lazy[v << 1 | 1] += cur;
            }
            self.lazy[v] = D::default();
        }

        #[inline]
        pub fn update(&mut self, x: usize, y: usize, to_add: D) {
            fn update_inner<D, FC, FN>(
                st: &mut SegmentTreeRARQ<D, FC, FN>,
                v: usize,
                l: usize,
                r: usize,
                x: usize,
                y: usize,
                to_add: D,
                fc: &FC,
            ) where
                D: Default + Copy + AddAssign,
                FC: FnOnce(&D, &D) -> D + Clone + Copy,
                FN: FnOnce() -> D + Clone + Copy,
            {
                st.push(v, l, r);
                if l > y || r < x {
                    return;
                }
                if l >= x && r <= y {
                    st.lazy[v] += to_add;
                    st.push(v, l, r);
                    return;
                }
                let mid = (l + r) >> 1;
                update_inner(st, v << 1, l, mid, x, y, to_add, fc);
                update_inner(st, v << 1 | 1, mid + 1, r, x, y, to_add, fc);
                st.t[v] = fc(&st.t[v << 1], &st.t[v << 1 | 1]);
            }
            let fc = self.fc.clone();
            update_inner(self, 1, 1, self.n, x, y, to_add, &fc);
        }

        #[inline]
        pub fn get(&mut self, x: usize, y: usize) -> D {
            fn get_inner<D, FC, FN>(
                st: &mut SegmentTreeRARQ<D, FC, FN>,
                v: usize,
                l: usize,
                r: usize,
                x: usize,
                y: usize,
                fc: &FC,
                fnull: &FN,
            ) -> D
            where
                D: Default + Copy + AddAssign,
                FC: FnOnce(&D, &D) -> D + Clone + Copy,
                FN: FnOnce() -> D + Clone + Copy,
            {
                if l > y || r < x {
                    return fnull();
                }
                st.push(v, l, r);
                if l >= x && r <= y {
                    return st.t[v];
                }
                let mid = (l + r) >> 1;
                fc(
                    &get_inner(st, v << 1, l, mid, x, y, fc, fnull),
                    &get_inner(st, v << 1 | 1, mid + 1, r, x, y, fc, fnull),
                )
            }
            let fc = self.fc.clone();
            let fnull = self.fnull.clone();
            get_inner(self, 1, 1, self.n, x, y, &fc, &fnull)
        }
    }

    // 1-indexed
    // Query on range using FC function
    // for invalid value, trigger call FN
    // range addition (Note: NOT assignment)
    pub struct SegmentTreeRMRQ<D, FC, FN>
    where
        D: Default + Copy + AddAssign,
        FC: FnOnce(&D, &D) -> D + Clone + Copy,
        FN: FnOnce() -> D + Clone + Copy,
    {
        pub n: usize,
        pub lazy: Vec<bool>,
        pub t: Vec<D>,
        pub fc: FC,
        pub fnull: FN,
    }

    impl<D, FC, FN> SegmentTreeRMRQ<D, FC, FN>
    where
        D: Default + Copy + AddAssign,
        FC: FnOnce(&D, &D) -> D + Clone + Copy,
        FN: FnOnce() -> D + Clone + Copy,
    {
        pub fn new(n: usize, fc: FC, fnull: FN) -> Self {
            let n = n + 3;
            let lazy = vec![false; n << 2];
            let t = vec![D::default(); n << 2];
            Self {
                n,
                lazy,
                t,
                fc,
                fnull,
            }
        }

        // modify a and this fn if necessary
        pub fn build(a: Vec<D>, fc: FC, fnull: FN) -> Self {
            let sz = a.len() + 3; // 0-indexed
            let lazy = vec![false; sz << 2];
            let mut t = vec![D::default(); sz << 2];

            fn build_inner<D, FC>(v: usize, l: usize, r: usize, a: &[D], t: &mut [D], fc: &FC)
            where
                D: Default + Copy + AddAssign,
                FC: FnOnce(&D, &D) -> D + Clone + Copy,
            {
                if l == r {
                    t[v] = a[l];
                } else {
                    let mid = (l + r) >> 1;
                    build_inner(v << 1, l, mid, a, t, fc);
                    build_inner(v << 1 | 1, mid + 1, r, a, t, fc);
                    t[v] = fc(&t[v << 1], &t[v << 1 | 1]);
                }
            }

            build_inner(1, 0, a.len() - 1, &a[..], &mut t, &fc);
            Self {
                n: sz,
                lazy,
                t,
                fc,
                fnull,
            }
        }

        #[inline]
        fn push(&mut self, v: usize, l: usize, r: usize) {
            if self.lazy[v] {
                self.t[v << 1] = self.t[v];
                self.t[v << 1 | 1] = self.t[v];
                self.lazy[v << 1] = true;
                self.lazy[v << 1] = true;
                self.lazy[v] = false;
            }
        }

        #[inline]
        pub fn update(&mut self, x: usize, y: usize, new_val: D) {
            fn update_inner<D, FC, FN>(
                st: &mut SegmentTreeRMRQ<D, FC, FN>,
                v: usize,
                l: usize,
                r: usize,
                x: usize,
                y: usize,
                new_val: D,
                fc: &FC,
            ) where
                D: Default + Copy + AddAssign,
                FC: FnOnce(&D, &D) -> D + Clone + Copy,
                FN: FnOnce() -> D + Clone + Copy,
            {
                if l > y || r < x {
                    return;
                }
                if l >= x && r <= y {
                    st.t[v] = new_val;
                    st.lazy[v] = true;
                    return;
                }
                st.push(v, l, r);
                let mid = (l + r) >> 1;
                update_inner(st, v << 1, l, mid, x, y, new_val, fc);
                update_inner(st, v << 1 | 1, mid + 1, r, x, y, new_val, fc);
                st.t[v] = fc(&st.t[v << 1], &st.t[v << 1 | 1]);
            }
            let fc = self.fc.clone();
            update_inner(self, 1, 1, self.n, x, y, new_val, &fc);
        }

        #[inline]
        pub fn get(&mut self, x: usize, y: usize) -> D {
            fn get_inner<D, FC, FN>(
                st: &mut SegmentTreeRMRQ<D, FC, FN>,
                v: usize,
                l: usize,
                r: usize,
                x: usize,
                y: usize,
                fc: &FC,
                fnull: &FN,
            ) -> D
            where
                D: Default + Copy + AddAssign,
                FC: FnOnce(&D, &D) -> D + Clone + Copy,
                FN: FnOnce() -> D + Clone + Copy,
            {
                if l > y || r < x {
                    return fnull();
                }
                st.push(v, l, r);
                if l >= x && r <= y {
                    return st.t[v];
                }
                let mid = (l + r) >> 1;
                fc(
                    &get_inner(st, v << 1, l, mid, x, y, fc, fnull),
                    &get_inner(st, v << 1 | 1, mid + 1, r, x, y, fc, fnull),
                )
            }
            let fc = self.fc.clone();
            let fnull = self.fnull.clone();
            get_inner(self, 1, 1, self.n, x, y, &fc, &fnull)
        }
    }
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    type MT = u64;

    let n: usize = input.next();
    let c: MT = input.next();
    let m: usize = input.next();

    const offset: MT = 2_000_000_000_000_000_000;
    let mut pre = st::SegmentTreeRMRQ::new(n + 10, |a: &MT, b: &MT| *a.max(b), || 0);
    let mut suf = st::SegmentTreeRMRQ::new(n + 10, |a: &MT, b: &MT| *a.max(b), || 0);
    pre.update(1, 1, offset + c);
    suf.update(1, 1, offset + c);

    let mut ans = offset;

    for i in 1..=m {
        let t: usize = input.next();
        let tc = t;
        let p: MT = input.next();
        let best = (pre.get(1, t) - c * tc as MT).max(suf.get(t, n) + c * tc as MT) + p;

        ans = ans.max(best);

        pre.update(t, t, best + c * tc as MT);
        suf.update(t, t, best - c * tc as MT);
    }
    write!(output, "{}\n", ans - offset);
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
