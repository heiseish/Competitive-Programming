#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
#![allow(unused_macros)]
#![allow(unused_imports)]
use core::f64::*;
use std::cmp::*;
use std::collections::*;
use std::f32::consts::*;
use std::io::{self, prelude::*};
#[derive(Clone, Debug)]
struct Node {
    count: u64,
    prob: f64,
    bits: f64,
}

impl Node {
    fn merge(self, other: Self) -> Self {
        let new_prob = self.prob + other.prob;
        Self {
            bits: 1. + (self.bits * self.prob + other.bits * other.prob) / new_prob,
            prob: new_prob,
            count: 1,
        }
    }
}

impl PartialEq for Node {
    fn eq(&self, other: &Self) -> bool {
        (self.prob - other.prob).abs() < EPSILON
    }
}

impl Eq for Node {}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        other.prob.partial_cmp(&self.prob)
    }
}

impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        self.partial_cmp(other).unwrap()
    }
}

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) -> Option<()> {
    // read in int/float
    let n: usize = input.token();
    let mut ps = [0f64; 4];
    for i in 0..4 {
        ps[i] = input.token();
    }
    let mut facts = [0u64; 21];
    facts[0] = 1;
    for i in 1..=n {
        facts[i] = facts[i - 1] * i as u64;
    }

    let mut h = BinaryHeap::with_capacity(12_000);
    for fs in 0..=n {
        for fc in 0..=n {
            for fr in 0..=n {
                if fs + fc + fr > n {
                    continue;
                }
                let ff = n - fs - fc - fr;

                let mut prob = 1.;
                let ffs = vec![fs, fc, fr, ff];
                for i in 0..4 {
                    if ps[i] == 0. {
                        continue;
                    }
                    prob *= ps[i].powi(ffs[i] as i32)
                }

                let node = Node {
                    bits: 0.,
                    count: facts[n] / (facts[fs] * facts[fc] * facts[fr] * facts[ff]),
                    prob,
                };
                h.push(node);
            }
        }
    }

    loop {
        let nxt = h.pop()?;
        // write!(w, "{:?}\n", nxt);
        if h.len() == 0 && nxt.count == 1 {
            write!(w, "{:.9}\n", nxt.bits);
            break;
        }
        if nxt.count > 1 {
            if nxt.count % 2 == 0 {
                h.push(Node {
                    bits: nxt.bits + 1.,
                    prob: nxt.prob * 2.,
                    count: nxt.count / 2,
                })
            } else {
                h.push(Node {
                    bits: nxt.bits + 1.,
                    prob: nxt.prob * 2.,
                    count: nxt.count / 2,
                });

                h.push(Node {
                    bits: nxt.bits,
                    prob: nxt.prob,
                    count: 1,
                });
            }
            continue;
        }

        let mut second = h.pop()?;
        second.count -= 1;
        h.push(nxt.merge(Node {
            bits: second.bits,
            prob: second.prob,
            count: 1,
        }));

        if second.count > 0 {
            h.push(second);
        }
    }
    Some(())
}

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    let input = FastInput::from(stdin.lock());
    let writer = io::BufWriter::new(stdout.lock());
    solve(input, writer);
}

// IO helper functions
trait TokenStream<T> {
    fn token(&mut self) -> T;
}
struct FastInput<R> {
    stdin: R,
    pos: usize,
}

impl<R: std::io::BufRead> FastInput<R> {
    //! Quick wrapper function without implementing DeRef
    pub fn read_line(&mut self, buf: &mut String) -> bool {
        self.stdin.consume(self.pos);
        self.pos = 0;
        if let Ok(n) = self.stdin.read_line(buf) {
            if n == 0 {
                return false;
            }
            if buf.ends_with('\n') {
                if buf.len() == 1 {
                    buf.clear();
                    return self.read_line(buf);
                }
                buf.pop();
                if buf.ends_with('\r') {
                    buf.pop();
                }
                if buf.len() == 0 {
                    return false;
                }
            }
            return true;
        }
        false
    }
}

impl<R: BufRead> From<R> for FastInput<R> {
    fn from(r: R) -> Self {
        FastInput { stdin: r, pos: 0 }
    }
}

macro_rules! impl_positive_integer_token_stream {
    ($b:ty, [$($t:ty),+]) => {$(
        impl<R: BufRead> TokenStream<$t> for FastInput<R> {
            fn token(&mut self) -> $t {
                let mut ans = 0 as $b;
                let mut parse_token = false;
                loop {
                    if let Ok(buf) = self.stdin.fill_buf() {
                        if !parse_token {
                            while self.pos < buf.len() && buf[self.pos] <= 32 {
                                self.pos += 1;
                            }
                        }
                        while self.pos < buf.len() && buf[self.pos] > 32 {
                            parse_token = true;
                            ans = ans * 10 as $b + (buf[self.pos] - b'0') as $b;
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            return ans as $t;
                        }
                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
            }
        }
        )+}
}

macro_rules! impl_integer_token_stream {
    ($b:ty, [$($t:ty),+]) => {$(
        impl<R: BufRead> TokenStream<$t> for FastInput<R> {
            fn token(&mut self) -> $t {
                let mut ans = 0 as $b;
                let mut parse_token = false;
                let mut negate = false;
                loop {
                    if let Ok(buf) = self.stdin.fill_buf() {
                        if !parse_token {
                            while self.pos < buf.len() && buf[self.pos] <= 32 {
                                self.pos += 1;
                            }
                        }
                        while self.pos < buf.len() && buf[self.pos] > 32 {
                            parse_token = true;
                            if buf[self.pos] == b'-' {
                                negate = true;
                            } else {
                                ans = ans * 10 as $b + (buf[self.pos] - b'0') as $b;
                            }
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            if negate {
                                return -ans as $t;
                            }
                            return ans as $t;
                        }

                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
            }
        }
        )+}
}

macro_rules! impl_float_token_stream {
    ($b:ty, [$($t:ty),+]) => {$(
        impl<R: BufRead> TokenStream<$t> for FastInput<R> {
            fn token(&mut self) -> $t {
                let mut ans = 0 as $b;
                let mut parse_token = false;
                let mut dec = false;
                let mut dec_point = 1;
                let mut negate = false;
                loop {
                    if let Ok(buf) = self.stdin.fill_buf() {
                        if !parse_token {
                            while self.pos < buf.len() && buf[self.pos] <= 32 {
                                self.pos += 1;
                            }
                        }
                        while self.pos < buf.len() && buf[self.pos] > 32 {
                            parse_token = true;
                            if buf[self.pos] == b'-' {
                                negate = true;
                            } else if buf[self.pos] == b'.' {
                                dec = true;
                            } else {
                                ans = ans * 10 as $b + (buf[self.pos] - b'0') as $b;
                                if dec {
                                    dec_point *= 10;
                                }
                            }
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            if negate {
                                return -ans as $t / dec_point as $t;
                            }
                            return ans as $t / dec_point as $t;
                        }
                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
            }
        }
        )+}
}

impl_positive_integer_token_stream!(u32, [usize, u8, u16, u32]);
impl_positive_integer_token_stream!(u64, [u64]);
impl_integer_token_stream!(i32, [i8, i16, i32]);
impl_integer_token_stream!(i64, [i64]);
impl_float_token_stream!(f32, [f32]);
impl_float_token_stream!(f64, [f64]);
