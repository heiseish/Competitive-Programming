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

macro_rules! swap {
    ($a_ref:expr, $b_ref:expr) => {{
        ($a_ref, $b_ref) = ($b_ref, $a_ref);
    }};
}
fn backtrack(
    x: usize,
    y: usize,
    depth: u16,
    b: &mut [[u8; 5]; 5],
    f: &[[u8; 5]; 5],
    step: &mut u16,
) {
    if depth >= 11 {
        return;
    }
    if b == f {
        *step = min(depth, *step);
        return;
    }
    if x >= 2 && y >= 1 {
        swap!(b[x][y], b[x - 2][y - 1]);
        backtrack(x - 2, y - 1, depth + 1, b, f, step);
        swap!(b[x][y], b[x - 2][y - 1]);
    }
    if x >= 2 && y <= 3 {
        swap!(b[x][y], b[x - 2][y + 1]);
        backtrack(x - 2, y + 1, depth + 1, b, f, step);
        swap!(b[x][y], b[x - 2][y + 1]);
    }
    if x >= 1 && y >= 2 {
        swap!(b[x][y], b[x - 1][y - 2]);
        backtrack(x - 1, y - 2, depth + 1, b, f, step);
        swap!(b[x][y], b[x - 1][y - 2]);
    }
    if x >= 1 && y <= 2 {
        swap!(b[x][y], b[x - 1][y + 2]);
        backtrack(x - 1, y + 2, depth + 1, b, f, step);
        swap!(b[x][y], b[x - 1][y + 2]);
    }
    if x <= 2 && y >= 1 {
        swap!(b[x][y], b[x + 2][y - 1]);
        backtrack(x + 2, y - 1, depth + 1, b, f, step);
        swap!(b[x][y], b[x + 2][y - 1]);
    }
    if x <= 2 && y <= 3 {
        swap!(b[x][y], b[x + 2][y + 1]);
        backtrack(x + 2, y + 1, depth + 1, b, f, step);
        swap!(b[x][y], b[x + 2][y + 1]);
    }
    if x <= 3 && y >= 2 {
        swap!(b[x][y], b[x + 1][y - 2]);
        backtrack(x + 1, y - 2, depth + 1, b, f, step);
        swap!(b[x][y], b[x + 1][y - 2]);
    }
    if x <= 3 && y <= 2 {
        swap!(b[x][y], b[x + 1][y + 2]);
        backtrack(x + 1, y + 2, depth + 1, b, f, step);
        swap!(b[x][y], b[x + 1][y + 2]);
    }
}
fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut w: W) -> Option<()> {
    // read in int/float
    let tc: usize = input.next();
    let mut s: String = String::new();
    let mut f = [[0u8; 5]; 5];
    for x in 0..5 {
        for y in x..5 {
            f[x][y] = 1;
        }
    }
    f[2][2] = 2;
    f[3][3] = 0;
    f[4][4] = 0;
    for _ in 0..tc {
        let mut b = [[0u8; 5]; 5];
        let mut startx = 0;
        let mut starty = 0;
        for x in 0..5 {
            s.clear();
            input.read_line(&mut s);
            let mut y = 0usize;
            for c in s.chars() {
                if c == ' ' {
                    b[x][y] = 2;
                    startx = x;
                    starty = y;
                } else {
                    b[x][y] = (c as u32 - '0' as u32) as u8;
                }
                y += 1;
            }
        }
        let mut step = 11;
        backtrack(startx, starty, 0, &mut b, &f, &mut step);
        if step >= 11 {
            write!(w, "Unsolvable in less than 11 move(s).\n");
        } else {
            write!(w, "Solvable in {} move(s).\n", step);
        }
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
