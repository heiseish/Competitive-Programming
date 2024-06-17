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

mod st {
    use std::fmt::Debug;
    use std::ops::{Add, AddAssign};

    // 1-indexed
    // Query on range using FC function
    // for invalid value, trigger call FN
    // range addition (Note: NOT assignment)
    pub struct SegmentTreeRMRQ<D, FC, FN>
    where
        D: Default + Copy + AddAssign + Debug,
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
        D: Default + Copy + AddAssign + Debug,
        FC: FnOnce(&D, &D) -> D + Clone + Copy,
        FN: FnOnce() -> D + Clone + Copy,
    {
        pub fn new(n: usize, fc: FC, fnull: FN) -> Self {
            let sz = n + 3;
            let lazy = vec![false; sz << 2];
            let t = vec![D::default(); sz << 2];
            Self {
                n,
                lazy,
                t,
                fc,
                fnull,
            }
        }

        // modify a and this fn if necessary
        // a is 1-indexed too
        pub fn build(n: usize, a: &[D], fc: FC, fnull: FN) -> Self {
            let sz = n + 3;
            let lazy = vec![false; sz << 2];
            let mut t = vec![D::default(); sz << 2];

            fn build_inner<D, FC>(v: usize, l: usize, r: usize, a: &[D], t: &mut [D], fc: &FC)
            where
                D: Default + Copy + AddAssign + Debug,
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

            build_inner(1, 1, n, &a, &mut t, &fc);
            Self {
                n,
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
                self.lazy[v << 1 | 1] = true;
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
                D: Default + Copy + AddAssign + Debug,
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
                D: Default + Copy + AddAssign + Debug,
                FC: FnOnce(&D, &D) -> D + Clone + Copy,
                FN: FnOnce() -> D + Clone + Copy,
            {
                if l > y || r < x {
                    return fnull();
                }
                if l >= x && r <= y {
                    return st.t[v];
                }
                st.push(v, l, r);
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
    'outer: for _ in 0..(input.next::<usize>()) {
        let mut s = String::new();
        input.read_line(&mut s);
        let mut a = vec![0i64; s.len()];
        let mut p = vec![0i64; s.len()];

        for (i, ch) in s.chars().enumerate() {
            if ch == '(' {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
        }
        p[0] = a[0];
        let mut ans = 0i64;

        // let mut tr = vec![0i64; s.len()];
        // tr[1] = 1;
        let mut tr = st::SegmentTreeRMRQ::new(s.len() + 2, |&x, &y| x + y, || 0);
        tr.update(2, 2, 1);

        for i in 1..(s.len() - 1) {
            p[i] = a[i] + p[i - 1];

            let idx = p[i] as usize;
            let val = tr.get(idx + 1, idx + 1);
            // dbg!(val);
            ans += val;

            tr.update(idx + 1, idx + 1, val + 1);
            // dbg!(i, tr.get(idx + 1, idx + 1));

            let mut cutoff = idx / 2;
            if idx % 2 == 0 && idx >= 2 {
                cutoff -= 1;
            }
            tr.update(1, cutoff + 1, 0);
            // dbg!(idx, cutoff, tr.get(idx + 1, idx + 1));
        }
        write!(output, "{}\n", ans);
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
