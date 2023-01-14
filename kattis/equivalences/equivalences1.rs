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

pub struct Graph {
    g: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Self {
            g: vec![Vec::new(); n],
        }
    }

    fn rev(g: &Graph) -> Self {
        let mut s = Self {
            g: vec![Vec::new(); g.len()],
        };
        for i in 0..g.len() {
            for neighbor in g.get_neighbors(i) {
                s.add_edge(*neighbor, i);
            }
        }
        s
    }

    #[inline(always)]
    fn add_edge(&mut self, x: usize, y: usize) {
        self.g[x].push(y);
    }

    #[inline(always)]
    fn get_neighbors(&self, x: usize) -> &Vec<usize> {
        &self.g[x]
    }

    #[inline(always)]
    fn len(&self) -> usize {
        self.g.len()
    }
}

mod tarjan {
    use crate::Graph;

    #[inline(always)]
    fn dfs1(v: usize, g: &Graph, used: &mut Vec<bool>, order: &mut Vec<usize>) {
        used[v] = true;
        for u in g.get_neighbors(v) {
            if !used[*u] {
                dfs1(*u, g, used, order);
            }
        }
        order.push(v);
    }

    #[inline(always)]
    fn dfs2(v: usize, rev_g: &Graph, used: &mut Vec<bool>, components: &mut Vec<usize>) {
        used[v] = true;
        components.push(v);

        for u in rev_g.get_neighbors(v) {
            if !used[*u] {
                dfs2(*u, rev_g, used, components);
            }
        }
    }

    pub fn run(g: &Graph, comps: &mut Vec<usize>) -> usize {
        let rev = Graph::rev(&g);
        let mut used = vec![false; g.len()];
        let mut order = Vec::with_capacity(g.len());

        for i in 0..g.len() {
            if !used[i] {
                dfs1(i, &g, &mut used, &mut order);
            }
        }
        let mut used = vec![false; g.len()];
        let order = order.into_iter().rev().collect::<Vec<usize>>();
        let mut components = Vec::with_capacity(g.len());
        let mut cnt = 0;
        for v in order {
            if !used[v] {
                dfs2(v, &rev, &mut used, &mut components);
                for c in &components {
                    comps[*c] = cnt;
                }
                cnt += 1;
                components.clear();
            }
        }
        cnt
    }
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut w: W) -> Option<()> {
    // read in int/float
    let tc: usize = input.next();
    for _ in 0..tc {
        let n: usize = input.next();
        let m: usize = input.next();
        let mut g = Graph::new(n);
        for _ in 0..m {
            let x: usize = input.next();
            let y: usize = input.next();
            g.add_edge(x - 1, y - 1);
        }
        let mut c = vec![0; n];
        let nc = tarjan::run(&g, &mut c);
        if nc == 1 {
            write!(w, "{}\n", 0);
            continue;
        }

        let mut cin = vec![0; nc];
        let mut cout = vec![0; nc];
        for i in 0..n {
            for v in g.get_neighbors(i) {
                if c[*v] == c[i] {
                    continue;
                }
                cin[c[*v]] += 1;
                cout[c[i]] += 1;
            }
        }
        let mut iin = 0;
        let mut out = 0;
        for i in 0..nc {
            if cin[i] == 0 {
                iin += 1;
            }
            if cout[i] == 0 {
                out += 1;
            }
        }
        write!(w, "{}\n", max(iin, out));
    }
    None
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

    pub fn read_line(&mut self, buf: &mut String) -> bool {
        assert!(self.has_more());
        let mut ret = false;
        // retry
        for _ in 1..=2 {
            while self.peek() != '\n' {
                buf.push(self.peek());
                self.consume();
                ret = true;
                if !self.has_more() {
                    break;
                }
            }
            if ret {
                break;
            }
            self.consume();
        }
        self.consume(); // consume '\n'
        ret
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
        loop {
            assert!(self.has_more());
            if test(self.peek()) {
                return;
            }
            self.consume();
        }
    }

    #[inline(always)]
    fn consume_until_int<F: Fn(u8) -> bool>(&mut self, test: F) {
        loop {
            assert!(self.has_more());
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
