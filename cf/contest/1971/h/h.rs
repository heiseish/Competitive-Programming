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

mod twosat {
    pub struct TwoSat {
        n: usize,
        adj: Vec<Vec<usize>>,
        adj_t: Vec<Vec<usize>>,
    }

    impl TwoSat {
        pub fn new(n: usize) -> Self {
            let n = n << 2;
            Self {
                n,
                adj: vec![vec![]; n],
                adj_t: vec![vec![]; n],
            }
        }

        // na and nb signify whether a and b are to be negated
        pub fn add_disjunction(&mut self, a: usize, na: bool, b: usize, nb: bool) {
            let a = (a << 1) ^ na as usize;
            let b = (b << 1) ^ nb as usize;
            let neg_a = a ^ 1;
            let neg_b = b ^ 1;
            self.adj[neg_a].push(b);
            self.adj[neg_b].push(a);
            self.adj_t[b].push(neg_a);
            self.adj_t[a].push(neg_b);
        }

        pub fn solve(self) -> bool {
            let mut order = vec![];
            let n = self.n;
            let mut comp = vec![-1; n];
            let mut used = vec![false; n];
            let adj = self.adj;
            let adj_t = self.adj_t;

            fn dfs1(v: usize, used: &mut [bool], adj: &[Vec<usize>], order: &mut Vec<usize>) {
                used[v] = true;
                for &u in &adj[v] {
                    if !used[u] {
                        dfs1(u, used, adj, order);
                    }
                }
                order.push(v);
            }
            fn dfs2(v: usize, cl: i32, comp: &mut [i32], adj_t: &[Vec<usize>]) {
                comp[v] = cl;
                for &u in &adj_t[v] {
                    if comp[u] == -1 {
                        dfs2(u, cl, comp, adj_t);
                    }
                }
            }
            for i in 0..n {
                if !used[i] {
                    dfs1(i, &mut used, &adj, &mut order);
                }
            }
            let mut j = 0;
            for i in 0..n {
                let v = order[self.n - i - 1];
                if comp[v] == -1 {
                    dfs2(v, j, &mut comp, &adj_t);
                    j += 1;
                }
            }
            let mut assignment = vec![false; n / 2];
            for i in (0..n).step_by(2) {
                if comp[i] == comp[i + 1] {
                    return false;
                }
                assignment[i / 2] = comp[i] > comp[i + 1];
            }
            true
        }
    }
}
fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    'outer: for _ in 0..(input.next::<usize>()) {
        let n: usize = input.next();
        let mut mat = vec![vec![0i32; n + 3]; 3];
        for i in 0..3 {
            for j in 0..n {
                mat[i][j] = input.next();
            }
        }
        let mut ts = twosat::TwoSat::new(n);
        for i in 0..n {
            let a = mat[0][i].abs() as usize - 1;
            let b = mat[1][i].abs() as usize - 1;
            let c = mat[2][i].abs() as usize - 1;
            let na = mat[0][i] < 0;
            let nb = mat[1][i] < 0;
            let nc = mat[2][i] < 0;
            ts.add_disjunction(a, na, b, nb);
            ts.add_disjunction(c, nc, b, nb);
            ts.add_disjunction(a, na, c, nc);
        }
        if ts.solve() {
            write!(output, "YES\n");
        } else {
            write!(output, "NO\n");
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
