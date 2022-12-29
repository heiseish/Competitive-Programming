#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
use std::io::{self, prelude::*};

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
    let t: i32 = input.token();
    for _ in 0..t {
        let tc: i32 = input.token();
        let n: i32 = input.token();
        write!(w, "{} {}\n", tc, n * (n + 1) / 2 + n);
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
    pub fn read_line(&mut self, buf: &mut String) {
        self.stdin.read_line(buf);
        if buf.ends_with('\n') {
            buf.pop();
            if buf.ends_with('\r') {
                buf.pop();
            }
        }
    }
}

impl<R: BufRead> From<R> for FastInput<R> {
    fn from(r: R) -> Self {
        FastInput { stdin: r, pos: 0 }
    }
}
impl<R: BufRead> TokenStream<u8> for FastInput<R> {
    fn token(&mut self) -> u8 {
        loop {
            if let Ok(buf) = self.stdin.fill_buf() {
                while self.pos < buf.len() {
                    self.pos += 1;
                    if buf[self.pos - 1] > 32 {
                        return buf[self.pos - 1];
                    }
                }
                if self.pos == 0 {
                    return 0;
                }
            } else {
                return 0;
            }
            self.stdin.consume(self.pos);
            self.pos = 0;
        }
    }
}
impl<R: BufRead> TokenStream<Vec<u8>> for FastInput<R> {
    fn token(&mut self) -> Vec<u8> {
        let mut ans = Vec::new();
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
                    ans.push(buf[self.pos]);
                    self.pos += 1;
                }
                if self.pos != buf.len() || self.pos == 0 {
                    return ans;
                }
            }
            self.stdin.consume(self.pos);
            self.pos = 0;
        }
    }
}
macro_rules! impl_token_stream {
	($($t:ident),+) => {$(
			impl<R: BufRead> TokenStream<$t> for FastInput<R> {
				fn token(&mut self) -> $t {
					let mut ans = 0;
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
								ans = ans * 10 + (buf[self.pos] - b'0') as $t;
								self.pos += 1;
							}
							if self.pos != buf.len() || self.pos == 0 {
								return ans;
							}
						}
						self.stdin.consume(self.pos);
						self.pos = 0;
					}
				}
			}
			)+}
}

// implement rust native type that can be casted by `as $t` here
impl_token_stream!(usize);
impl_token_stream!(i32);
