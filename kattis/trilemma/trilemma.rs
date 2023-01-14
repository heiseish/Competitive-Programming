#![allow(unused_variables)]
#![allow(unused_must_use)]
#![allow(dead_code)]
#![allow(unused_macros)]
#![allow(unused_imports)]
use core::f32::*;
use std::cmp::*;
use std::collections::*;
use std::f32::consts::*;
use std::io::{self, prelude::*};

#[derive(PartialEq)]
struct Point {
    x: f32,
    y: f32,
}

impl Point {
    fn new(x: f32, y: f32) -> Self {
        Self { x, y }
    }
}

#[derive(PartialEq)]
struct MathVec {
    x: f32,
    y: f32,
}

impl MathVec {
    fn new(a: &Point, b: &Point) -> Self {
        Self {huff
            x: b.x - a.x,
            y: b.y - a.y,
        }
    }
}

fn not_a_triangle(a: &Point, b: &Point, c: &Point) -> bool {
    a == b || a == c || b == c || collinear(a, b, c)
}

fn get_side(a: &Point, b: &Point) -> f32 {
    ((a.x - b.x).abs().powi(2) + (a.y - b.y).abs().powi(2)).sqrt()
}

fn get_degree(x: f32, y: f32, z: f32) -> f32 {
    ((x.powi(2) + y.powi(2) - z.powi(2)) / (2.0 * x * y)).acos()
}

fn approx_equal(x: f32, y: f32) -> bool {
    (x - y).abs() < 1e-4
}
fn cross(a: &MathVec, b: &MathVec) -> f32 {
    a.x * b.y - a.y * b.x
}

fn collinear(a: &Point, b: &Point, c: &Point) -> bool {
    cross(&MathVec::new(a, b), &MathVec::new(a, c)).abs() < EPSILON
}

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) -> Option<()> {
    // read in int/float
    let tc: usize = input.token();
    // let a: f32 = input.token();
    for tcc in 1..=tc {
        let mut ins: Vec<f32> = vec![0.0; 6];
        for i in 0..6 {
            ins[i] = input.token();
        }
        let a = Point::new(ins[0], ins[1]);
        let b = Point::new(ins[2], ins[3]);
        let c = Point::new(ins[4], ins[5]);

        if not_a_triangle(&a, &b, &c) {
            write!(w, "Case #{}: not a triangle\n", tcc);
            continue;
        }
        let x = get_side(&a, &b);
        let y = get_side(&b, &c);
        let z = get_side(&c, &a);
        let mut sides = "scalene";
        if x == y || y == z || x == z {
            sides = "isosceles";
        }

        let mut angles = "acute";
        let a = get_degree(x, y, z);
        let b = get_degree(y, z, x);
        let c = get_degree(z, x, y);
        let ra = PI / 2.;
        if approx_equal(a, ra)
            || approx_equal(b, ra)
            || approx_equal(c, ra)
            || approx_equal(x.powi(2) + y.powi(2), z.powi(2))
            || approx_equal(y.powi(2) + z.powi(2), x.powi(2))
            || approx_equal(z.powi(2) + x.powi(2), y.powi(2))
        {
            angles = "right";
        } else if a > ra || b > ra || c > ra {
            angles = "obtuse";
        }
        write!(w, "Case #{}: {} {} triangle\n", tcc, sides, angles);
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
