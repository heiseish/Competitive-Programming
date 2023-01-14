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

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut w: W) -> Option<()> {
    // read in int/float
    let n: i32 = input.next();
    let mut d = [[-1; 105]; 105];
    let mut can = [[true; 105]; 105];
    let mut s = String::new();
    let mut q = VecDeque::new();
    for i in 0..n {
        input.read_line(&mut s);
        let mut j = 0;
        for c in s.chars() {
            if c == '#' {
                can[i as usize][j as usize] = false;
            } else if c == 'K' {
                d[i as usize][j as usize] = 0;
                q.push_back((i, j));
            }
            j += 1;
        }
        s.clear();
    }
    while !q.is_empty() {
        let nxt = q.pop_front()?;
        for (r, c) in get_neighbors(nxt.0, nxt.1) {
            if r < 0 || c < 0 || r >= n || c >= n {
                continue;
            }
            if d[r as usize][c as usize] != -1 {
                continue;
            }
            if !can[r as usize][c as usize] {
                continue;
            }
            d[r as usize][c as usize] = d[nxt.0 as usize][nxt.1 as usize] + 1;
            q.push_back((r, c));
        }
    }
    // for i in 0..(n as usize) {
    //     for j in 0..(n as usize) {
    //         write!(w, "{} ", d[i][j]);
    //     }
    //     write!(w, "\n");
    // }
    write!(w, "{}\n", d[0][0]);
    Some(())
}

fn get_neighbors(r: i32, c: i32) -> [(i32, i32); 8] {
    return [
        (r + 2, c + 1),
        (r + 2, c - 1),
        (r - 2, c + 1),
        (r - 2, c - 1),
        (r + 1, c + 2),
        (r + 1, c - 2),
        (r - 1, c + 2),
        (r - 1, c - 2),
    ];
}

fn main() {
    let input = InputReader::new();
    let writer = BufWriter::new(stdout().lock());
    solve(input, writer);
}

pub struct InputReader<R: BufRead> {
    reader: R,
    buf: Vec<u8>,
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
            buf: vec![0; 1 << 16],
            bytes_read: 0,
            current_index: 0,
        }
    }

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

    pub fn has_more(&mut self) -> bool {
        if self.current_index >= self.bytes_read {
            self.bytes_read = self.reader.read(&mut self.buf[..]).unwrap();
            self.current_index = 0
        }
        self.bytes_read > 0
    }

    pub fn set_buf_size(&mut self, buf_size: usize) {
        self.buf.resize(buf_size, 0);
    }

    fn peek(&self) -> char {
        self.buf[self.current_index] as char
    }

    fn consume(&mut self) {
        self.current_index += 1;
    }

    fn pop_digit(&mut self) -> u32 {
        let c = self.peek();
        self.consume();
        c as u32 - '0' as u32
    }

    fn consume_until<F: Fn(char) -> bool>(&mut self, test: F) {
        loop {
            assert!(self.has_more());
            if test(self.peek()) {
                return;
            }
            self.consume();
        }
    }

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
      fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self {
        <$A>::from_input(input) as $T
      }
    })+
  };
}

macro_rules! impl_unsign_from_input {
    ($($t:ty),+) => {$(
        impl InputReadable for $t {
            fn from_input<R: BufRead>(input: &mut InputReader<R>) -> Self {
                input.consume_until(|c| c.is_ascii_digit());
                let mut num = 0 as $t;
                while input.peek().is_ascii_digit() {
                    num = num * 10 + input.pop_digit()as $t;
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
