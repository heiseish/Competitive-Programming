#![allow(unused_variables)]
#![allow(unused_must_use)]
use std::io::{self, prelude::*};

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
    let N: usize = input.token();
    let mut ls = vec![0usize; N];
    for x in ls.iter_mut() {
        *x = input.token();
    }
    let ret: usize = ls.iter().sum::<usize>() - N + 1;
    write!(w, "{}", ret);
}
fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    let input = FastInput::from(stdin.lock());
    let writer = io::BufWriter::new(stdout.lock());
    solve(input, writer);
}
trait TokenStream<T> {
    fn token(&mut self) -> T;
}
struct FastInput<R> {
    stdin: R,
    pos: usize,
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
impl_token_stream!(usize);
impl_token_stream!(i32);
