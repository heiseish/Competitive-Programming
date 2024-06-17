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

mod trie {
    type IntType = u32;

    #[derive(Default, Clone)]
    pub struct IntTrie {
        l: usize,
        c: usize,
        node: Vec<[usize; 2]>,
        cnt: Vec<usize>,
    }

    impl IntTrie {
        pub fn new(n: usize) -> Self {
            let num_bits = std::mem::size_of::<IntType>() * 8;
            Self {
                l: num_bits,
                c: 1,
                node: vec![[0, 0]; (num_bits + 2) * n + 3],
                cnt: vec![0; (num_bits + 2) * n + 3],
            }
        }

        pub fn add(&mut self, x: IntType) {
            let mut cur = 0;
            // rev to find max value
            for i in (0..self.l).rev() {
                let has_bit = ((x >> i) & 1) as usize;
                if self.node[cur][has_bit] == 0 {
                    self.node[cur][has_bit] = self.c;
                    self.c += 1;
                }
                cur = self.node[cur][has_bit];
                self.cnt[cur] += 1;
            }
        }

        pub fn remove(&mut self, x: IntType) {
            let mut cur = 0;
            for i in (0..self.l).rev() {
                let has_bit = ((x >> i) & 1) as usize;
                if self.node[cur][has_bit] == 0 {
                    self.node[cur][has_bit] = self.c;
                    self.c += 1;
                }
                cur = self.node[cur][has_bit];
                self.cnt[cur] -= 1;
            }
        }
        pub fn find_max(&self, x: IntType) -> IntType {
            let mut cur = 0;
            let mut ans = 0;
            for i in (0..self.l).rev() {
                let has_bit = ((x >> i) & 1) as usize;
                if self.node[cur][has_bit ^ 1] > 0 && self.cnt[self.node[cur][has_bit ^ 1]] > 0 {
                    ans += 1 << i;
                    cur = self.node[cur][has_bit ^ 1];
                } else {
                    cur = self.node[cur][has_bit];
                }
            }
            return ans;
        }
    }
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    'outer: for _ in 0..(input.next::<usize>()) {
        let n: usize = input.next();
        let m: usize = input.next();
        let mut gx: u32 = 0;
        let mut g = vec![vec![]; n + 1];
        for i in 1..n {
            let u: usize = input.next();
            let v: usize = input.next();
            let w: u32 = input.next();
            g[u].push((v, w));
            g[v].push((u, w));
        }

        let mut gr = vec![0; n + 1];
        let mut x = vec![0; n + 1];
        fn dfs(u: usize, p: usize, g: &[Vec<(usize, u32)>], gr: &mut [usize], x: &mut [u32]) {
            for &(v, w) in &g[u] {
                if v == p {
                    continue;
                }
                gr[v] = gr[u] ^ 1;
                x[v] = x[u] ^ w;
                dfs(v, u, g, gr, x);
            }
        }
        dfs(1, 0, &g, &mut gr, &mut x);
        let mut t = vec![trie::IntTrie::new(n + 2); 2];
        for i in 1..=n {
            t[gr[i]].add(x[i]);
        }
        for _ in 0..m {
            let c: char = input.next();
            if c == '^' {
                let y: u32 = input.next();
                gx ^= y;
            } else {
                let a: usize = input.next();
                let b: u32 = input.next();
                t[gr[a]].remove(x[a]);
                let same_group = t[gr[a]].find_max(x[a] ^ b);
                let diff_group = t[gr[a] ^ 1].find_max(x[a] ^ b ^ gx);
                t[gr[a]].add(x[a]);
                write!(output, "{} ", same_group.max(diff_group));
            }
        }
        write!(output, "\n");
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