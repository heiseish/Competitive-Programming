#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
#![allow(unused_macros)]
use std::io::{self, prelude::*};

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
    let a: i64 = input.token();
    let b: i64 = input.token();
    if a > b {
        write!(w, "{} {}\n", b, a);
    } else {
        write!(w, "{} {}\n", a, b);
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
                let mut ans = 0;
                let mut parse_token = false;
                let mut dec = false;
                let mut dec_point = 1;
                let mut negate = 1;
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
                                negate = -1;
                            } else if buf[self.pos] == b'.' {
                                dec = true;
                            } else {
                                ans = ans * 10 + (buf[self.pos] - b'0');
                                if dec {
                                    dec_point *= 10;
                                }
                            }
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            return negate as $t * ans as $t / dec_point as $t;
                        }
                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
            }
        }
        )+}
}

impl_token_stream!(usize, i8, i16, i32, i64, u8, u16, u32, u64, f32, f64);
