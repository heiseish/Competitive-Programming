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

fn c3(a: u32) -> u32 {
    if a < 3 {
        return 0;
    }
    a * (a - 1) * (a - 2) / (2 * 3)
}
fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut w: W) -> Option<()> {
    // read in int/float
    let n: usize = input.next();
    // let mut b = [[0; 105]; 105];
    let mut v = Vec::new();
    for i in 0..n {
        let s: String = input.next();
        let mut j = 0;
        for c in s.chars() {
            if c != '.' {
                v.push((i as i32, j as i32));
            }
            j += 1;
        }
    }
    v.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
    let mut ret = 0;
    if v.len() < 3 {
        write!(w, "{}\n", ret);
        return None;
    }
    for i in 0..v.len() {
        for j in (i + 1)..v.len() {
            for z in (j + 1)..v.len() {
                if v[z].0 == v[j].0 && v[i].0 == v[j].0 {
                    ret += 1;
                } else if v[z].1 == v[j].1 && v[i].1 == v[j].1 {
                    ret += 1;
                } else if (v[j].0 - v[i].0) as f32 / (v[z].0 - v[j].0) as f32
                    == (v[j].1 - v[i].1) as f32 / (v[z].1 - v[j].1) as f32
                {
                    ret += 1;
                }
            }
        }
    }
    write!(w, "{}\n", ret);
    Some(())
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
