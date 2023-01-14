#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
#![allow(unused_macros)]
use std::io::{self, prelude::*};

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
    let mut tc = 1;
    // read in string
    let mut s = String::new();
    while input.read_line(&mut s) {
        let v = s
            .split(" ")
            .map(|x| x.parse::<i32>().unwrap())
            .collect::<Vec<i32>>();

        let mut res = 0;
        while (v[0] + res) % 365 != 0 || (v[1] + res) % 687 != 0 {
            res += 1;
        }

        write!(w, "Case {}: {}\n", tc, res);
        tc += 1;
        s.clear();
    }
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
        if let Ok(n) = self.stdin.read_line(buf) {
            if n == 0 {
                return false;
            }
            if buf.ends_with('\n') {
                buf.pop();
                if buf.ends_with('\r') {
                    buf.pop();
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

macro_rules! impl_token_stream {
	($($t:ident),+) => {$(
        impl<R: BufRead> TokenStream<$t> for FastInput<R> {
            fn token(&mut self) -> $t {
                let mut ans = 0 as $t;
                let mut parse_token = false;
                let mut dec = false;
                let mut dec_point = 1 as $t;
                loop {
                    if let Ok(buf) = self.stdin.fill_buf() {
                        if !parse_token {
                            while self.pos < buf.len() && buf[self.pos] <= 32 {
                                self.pos += 1;
                            }
                        }
                        while self.pos < buf.len() && buf[self.pos] > 32 {
                            parse_token = true;

                            if buf[self.pos] == b'.' {
                                dec = true;
                                self.pos += 1;
                                continue;
                            }
                            ans = ans * 10 as $t + (buf[self.pos] - b'0') as $t;
                            if dec {
                                dec_point += 1 as $t;
                            }
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            return ans / dec_point;
                        }
                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
            }
        }
        )+}
}

impl_token_stream!(usize);
impl_token_stream!(i32);
impl_token_stream!(i64);
impl_token_stream!(i16);
impl_token_stream!(i8);
impl_token_stream!(u8);
impl_token_stream!(u16);
impl_token_stream!(u32);
impl_token_stream!(u64);
impl_token_stream!(f32);
impl_token_stream!(f64);
