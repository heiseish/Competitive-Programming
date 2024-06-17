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

// Region -- segment tree code
#[derive(Copy, Clone, Debug, Default)]
struct Node {
    pub x: i64,
}

impl Node {
    fn combine(&self, rhs: &Node) -> Node {
        Node {
            x: self.x.min(rhs.x),
        }
    }
}

// 1-indexed
struct SegmentTree {
    pub n: usize,
    pub lazy: Vec<i64>,
    pub t: Vec<Node>,
}

impl SegmentTree {
    pub fn new(n: usize) -> Self {
        let n = n + 3;
        let mut lazy = vec![0; n << 2];
        let mut t = vec![Node::default(); n << 2];
        Self { n, lazy, t }
    }

    pub fn build(a: Vec<i64>) -> Self {
        let sz = a.len() + 3; // 0-indexed
        let lazy = vec![0; sz << 2];
        let mut t = vec![Node::default(); sz << 2];

        fn build_inner(v: usize, l: usize, r: usize, a: &[i64], t: &mut [Node]) {
            if l == r {
                t[v] = Node { x: a[l] };
            } else {
                let mid = (l + r) >> 1;
                build_inner(v << 1, l, mid, a, t);
                build_inner(v << 1 | 1, mid + 1, r, a, t);
                t[v] = t[v << 1].combine(&t[v << 1 | 1]);
            }
        }

        build_inner(1, 0, a.len(), &a[..], &mut t);
        Self { n: sz, lazy, t }
    }

    #[inline]
    pub fn push(&mut self, v: usize, l: usize, r: usize) {
        self.t[v].x += self.lazy[v];
        if l < r {
            self.lazy[v << 1] += self.lazy[v];
            self.lazy[v << 1 | 1] += self.lazy[v];
        }
        self.lazy[v] = 0;
    }

    #[inline]
    pub fn update(&mut self, x: usize, y: usize, to_add: i64) {
        fn update_inner(
            st: &mut SegmentTree,
            v: usize,
            l: usize,
            r: usize,
            x: usize,
            y: usize,
            to_add: i64,
        ) {
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
            update_inner(st, v << 1, l, mid, x, y, to_add);
            update_inner(st, v << 1 | 1, mid + 1, r, x, y, to_add);
            st.t[v] = st.t[v << 1].combine(&st.t[v << 1 | 1]);
        }
        update_inner(self, 1, 1, self.n, x, y, to_add);
    }

    #[inline]
    pub fn get(&mut self, x: usize, y: usize) -> Node {
        fn get_inner(
            st: &mut SegmentTree,
            v: usize,
            l: usize,
            r: usize,
            x: usize,
            y: usize,
        ) -> Node {
            if l > y || r < x {
                return Node { x: i64::MAX };
            }
            st.push(v, l, r);
            if l >= x && r <= y {
                return st.t[v];
            }
            let mid = (l + r) >> 1;
            get_inner(st, v << 1, l, mid, x, y).combine(&get_inner(
                st,
                v << 1 | 1,
                mid + 1,
                r,
                x,
                y,
            ))
        }
        get_inner(self, 1, 1, self.n, x, y)
    }
}

// endregion - segment tree

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let mut a = [0usize; 300_007];
    'outer: for _ in 0..(input.next::<usize>()) {
        let n: usize = input.next();
        a[1..(n + 1)].iter_mut().for_each(|x| *x = input.next());
        let mut last = vec![0; n + 2];
        let mut slast = vec![0; n + 2];

        let mut fixed = 0;
        let mut ans = 0;
        let mut st = SegmentTree::new(n);
        for i in 1..(n + 1) {
            if slast[a[i]] <= fixed {
                slast[a[i]] = 0;
            }
            if last[a[i]] <= fixed {
                last[a[i]] = 0;
            }
            let before_last = slast[a[i]];
            slast[a[i]] = last[a[i]];
            last[a[i]] = i;

            if before_last != 0 {
                st.update(fixed + 1, before_last, 1);
            }
            if slast[a[i]] != 0 {
                // minus 1
                st.update(fixed + 1, slast[a[i]], -2);
            }
            // add one to the new entry
            st.update(fixed + 1, i, 1);

            let min_s = st.get(fixed + 1, i);
            if min_s.x == 0 {
                ans += 1;
                fixed = i;
            }
        }

        write!(output, "{}\n", ans);
    }
}

fn main() {
    let input = InputReader::new();
    let writer = BufWriter::new(stdout().lock());
    solve(input, writer);
}

// region IO
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
// endregion
