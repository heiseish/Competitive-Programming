#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
#![allow(unused_macros)]
#![allow(unused_imports)]
use std::cmp::*;
use std::collections::*;
use std::io::{self, prelude::*};

fn dfs_calc(
    idx: usize,
    nc: &mut Vec<usize>,
    nm: &mut Vec<usize>,
    visited: &mut Vec<bool>,
    mar: &Vec<usize>,
    g: &Vec<Vec<usize>>,
) {
    visited[idx] = true;
    let mut tnc = 1;
    let mut tnm = mar[idx];
    for c in &g[idx] {
        if visited[*c] {
            continue;
        }
        dfs_calc(*c, nc, nm, visited, mar, g);
        tnc += nc[*c];
        tnm += nm[*c];
    }
    nc[idx] = tnc;
    nm[idx] = tnm;
}

fn dfs(
    idx: usize,
    nc: &Vec<usize>,
    nm: &Vec<usize>,
    visited: &mut Vec<bool>,
    mar: &Vec<usize>,
    g: &Vec<Vec<usize>>,
) -> i32 {
    visited[idx] = true;
    let mut res = 0;
    for c in &g[idx] {
        if visited[*c] {
            continue;
        }
        res += nc[*c].abs_diff(nm[*c]) as i32;
        res += dfs(*c, nc, nm, visited, mar, g);
    }
    res
}

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) -> Option<()> {
    loop {
        let n: usize = input.token();
        if n == 0 {
            break;
        }
        let mut g = vec![Vec::new(); n + 3];
        let mut mar = vec![0; n + 3];
        for _ in 1..=n {
            let v: usize = input.token();
            mar[v] = input.token();
            let d: usize = input.token();
            for _ in 1..=d {
                let c: usize = input.token();
                g[v].push(c);
                g[c].push(v);
            }
        }

        let mut visited = vec![false; n + 3];
        let mut nc = vec![0; n + 3];
        let mut nm = vec![0; n + 3];
        dfs_calc(1, &mut nc, &mut nm, &mut visited, &mar, &g);
        let mut visited = vec![false; n + 3];
        write!(w, "{}\n", dfs(1, &nc, &nm, &mut visited, &mar, &g));
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
