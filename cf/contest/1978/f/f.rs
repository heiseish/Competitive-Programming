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

mod uf {
    #[derive(Clone, Debug)]
    pub struct UnionFind {
        d: Vec<usize>,
        sz: Vec<usize>,
        cc: usize,
    }

    impl UnionFind {
        pub fn new(n: usize) -> Self {
            Self {
                d: (0..=n).collect::<Vec<_>>(),
                sz: vec![1; n + 1],
                cc: n,
            }
        }

        pub fn find(&mut self, index: usize) -> usize {
            if self.d[index] == index {
                return index;
            }
            self.d[index] = self.find(self.d[index]);
            self.d[index]
        }

        pub fn is_root(&self, index: usize) -> bool {
            self.d[index] == index
        }

        pub fn len(&mut self, index: usize) -> usize {
            let nxt = self.find(index);
            self.sz[nxt]
        }

        pub fn num_cc(&self) -> usize {
            self.cc
        }

        pub fn join(&mut self, a: usize, b: usize) -> bool {
            let a = self.find(a);
            let b = self.find(b);
            if a == b {
                return false;
            }
            self.sz[b] += self.sz[a];
            self.cc -= 1;
            self.d[a] = b;
            true
        }

        pub fn is_same(&mut self, a: usize, b: usize) -> bool {
            self.find(a) == self.find(b)
        }
    }
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let MAXA = 1_000_000;
    let mut primes_x = vec![vec![]; MAXA + 1];
    let mut is_primes = vec![true; MAXA + 1];
    let mut primes = vec![];
    for i in 2..=MAXA {
        if is_primes[i] {
            primes.push(i as i64);
            let ii = i as i64;
            for j in ((i * i)..=MAXA).step_by(i) {
                is_primes[j] = false;
            }
        }
    }

    'outer: for _ in 0..(input.next::<usize>()) {
        let n: usize = input.next();
        let k: usize = input.next();

        let mut last_ind_p = HashMap::new();
        let mut a = vec![0; n * 2 - 1];
        for i in 1..=n {
            a[i + n - 2] = input.next();
            if i > 1 {
                a[i - 2] = a[i + n - 2];
            }
        }
        let n2 = n;
        let n = a.len();
        let mut p = vec![-1; n];
        let mut p_rs = vec![-1; n];
        let mut sz = vec![-1; n];
        for i in 0..n {
            p[i] = i as i32;
            sz[i] = 1;
        }
        for i in 0..n2 {
            p_rs[i] = i as i32 + 1;
            p_rs[2 * n2 - 2 - i] = i as i32 + 1;
        }
        let mut a2 = a.clone();
        let a2 = a2.into_iter().collect::<BTreeSet<_>>();
        let mut to_clean = BTreeSet::new();

        for mut elem in a2 {
            let cur_elem = elem;
            for &p in &primes {
                if p * p > elem {
                    break;
                }
                if elem % p == 0 {
                    primes_x[cur_elem as usize].push(p);
                    if primes_x[cur_elem as usize].len() == 1 {
                        to_clean.insert(cur_elem);
                    }
                }

                while elem % p == 0 {
                    elem /= p;
                }
            }
            if elem > 1 {
                primes_x[cur_elem as usize].push(elem);
                if primes_x[cur_elem as usize].len() == 1 {
                    to_clean.insert(cur_elem);
                }
            }
        }

        let mut dst = uf::UnionFind::new(n + 3);
        for i in 0..n {
            for &cur_p in &primes_x[(a[i] as usize)] {
                if last_ind_p.contains_key(&cur_p) && i - last_ind_p[&cur_p] <= k {
                    dst.join(last_ind_p[&cur_p], i);
                }
                last_ind_p.insert(cur_p, i);
            }
        }

        for i in to_clean {
            primes_x[i as usize].clear();
        }

        let mut ans = 0i64;
        for i in 0..n {
            if dst.is_root(i) {
                if a[i] > 1 {
                    ans += 1;
                } else {
                    ans += p_rs[i] as i64;
                }
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
