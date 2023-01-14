#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
#![allow(unused_macros)]
#![allow(unused_imports)]
use std::cmp::*;
use std::io::{self, prelude::*};

struct Person {
    name: String,
    like: u32,
    dob: usize,
}
fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) -> Option<()> {
    let n: u16 = input.token();
    let mut checked = [false; 10000];
    let mut s = String::with_capacity(150);
    let mut ve = Vec::with_capacity(n as usize);
    for _ in 1..=n {
        while !input.read_line(&mut s) {}
        let mut v = s.split(' ');
        let name = v.next()?;
        let like = v.next()?.parse::<u32>().ok()?;
        let mut d = v.next()?.chars();
        let mut dob = 1000usize * d.next()?.to_digit(10)? as usize
            + 100usize * d.next()?.to_digit(10)? as usize;
        d.next();
        dob += 10usize * d.next()?.to_digit(10)? as usize + d.next()?.to_digit(10)? as usize;
        let p = Person {
            name: name.into(),
            like,
            dob,
        };
        ve.push(p);
        s.clear();
    }
    ve.sort_by(|a, b| b.like.cmp(&a.like));
    let mut ans = Vec::with_capacity(n as usize);
    for p in ve {
        if !checked[p.dob] {
            ans.push(p.name.to_owned());
            checked[p.dob] = true;
        }
    }
    write!(w, "{}\n", ans.len());
    ans.sort();
    for a in ans {
        write!(w, "{}\n", a);
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
