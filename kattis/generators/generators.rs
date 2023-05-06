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

const MaxSize: usize = 100_007;

struct Unit {
    cost: u32,
    is_plant: bool,
    idx: usize,
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) -> Option<()> {
    // read in int/float
    let n: usize = input.next();
    let m: usize = input.next();
    let mut v = Vec::with_capacity(n + m);
    for _ in 0..m {
        let l: usize = input.next();
        let c: u32 = input.next();
        v.push(Unit {
            cost: c,
            is_plant: true,
            idx: l - 1,
        })
    }
    for i in 0..n {
        let b: u32 = input.next();
        v.push(Unit {
            cost: b,
            is_plant: false,
            idx: i,
        })
    }
    v.sort_by_key(|d| d.cost);
    let mut ans: u64 = 0;
    let mut c = [false; MaxSize];
    let mut b = [false; MaxSize];
    let next = |idx: usize| (idx + 1) % n;
    let back = |idx: usize| {
        if idx == 0 {
            return n - 1;
        }
        idx - 1
    };

    let mut e = 0;
    for unit in v {
        if unit.is_plant {
            if c[unit.idx] {
                continue;
            }

            ans += unit.cost as u64;
            c[unit.idx] = true;

            let mut cur = unit.idx;
            let mut nxt = next(cur);
            while c[cur] && !c[nxt] && b[cur] {
                c[nxt] = true;
                cur = nxt;
                nxt = next(cur);
            }

            let mut cur = unit.idx;
            let mut nxt = back(cur);
            while c[cur] && !c[nxt] && b[nxt] {
                c[nxt] = true;
                cur = nxt;
                nxt = back(cur);
            }
            continue;
        }
        let mut cur = unit.idx;
        let mut nxt = next(cur);
        if (c[cur] && c[nxt]) || e == n - 1 {
            continue;
        }

        b[cur] = true;
        e += 1;
        ans += unit.cost as u64;

        while c[cur] && !c[nxt] && b[cur] {
            c[nxt] = true;
            cur = nxt;
            nxt = next(cur);
        }

        let mut cur = next(unit.idx);
        let mut nxt = back(cur);
        while c[cur] && !c[nxt] && b[nxt] {
            c[nxt] = true;
            cur = nxt;
            nxt = back(cur);
        }
    }
    write!(output, "{}\n", ans);
    None
}

// region -- template --
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
// endregion
