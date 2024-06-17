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

struct SuffixAutomaton {
    pub st: Vec<SAState>,
    pub sz: usize,
    pub last: usize,
}
#[derive(Default, Clone)]
struct SAState {
    pub len: usize,
    pub link: i32,
    pub next: BTreeMap<char, usize>,
}
impl SuffixAutomaton {
    pub fn new(n: usize) -> Self {
        let mut sa = Self {
            st: vec![],
            sz: 1,
            last: 0,
        };
        for i in 0..(2 * n) {
            sa.st.push(SAState::default());
        }
        sa.st[0].len = 0;
        sa.st[0].link = -1;
        sa
    }
    pub fn add(&mut self, c: char) {
        let cur = self.sz;
        self.sz += 1;
        self.st[cur].len = self.st[self.last].len + 1;
        let mut p = self.last as i32;
        while p != -1 && !self.st[p as usize].next.contains_key(&c) {
            self.st[p as usize].next.insert(c, cur);
            p = self.st[p as usize].link;
        }
        if p == -1 {
            self.st[cur].link = 0;
        } else {
            let pu = p as usize;
            let q = self.st[pu].next[&c];
            if self.st[pu].len + 1 == self.st[q].len {
                self.st[cur].link = q as i32;
            } else {
                let clone = self.sz;
                self.sz += 1;
                self.st[clone].len = self.st[pu].len + 1;
                self.st[clone].next = self.st[q].next.clone();
                self.st[clone].link = self.st[q].link;

                while p != -1 && *self.st[p as usize].next.get(&c).unwrap() == q {
                    self.st[p as usize].next.insert(c, clone);
                    p = self.st[p as usize].link;
                }
                self.st[cur].link = clone as i32;
                self.st[q].link = self.st[cur].link;
            }
        }
        self.last = cur;
    }

    pub fn get_diff_strings(&self) -> i64 {
        let mut tot = 0;
        for i in 1..self.sz {
            tot += (self.st[i].len - self.st[self.st[i].link as usize].len) as i64;
        }
        tot
    }
}
fn f(a: usize, b: usize) -> i64 {
    ({
        if a < b {
            (a + 4) * b - 1
        } else {
            (a + 1) * (b + 3) - 1
        }
    }) as i64
}
fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let mut ans = vec![];
    let mut idxes = vec![];
    let mut hh = HashMap::new();
    let mut initial = "XO".to_string();
    let mut i = 1;
    while ans.len() < 1000 {
        let mut can = !hh.contains_key(&f(i, i));
        if can {
            for idx in &idxes {
                if hh.contains_key(&f(*idx, i))
                    || hh.contains_key(&f(i, *idx))
                    || f(*idx, i) == f(i, *idx)
                {
                    can = false;
                    break;
                }
            }
        }
        if can {
            for (j, idx) in idxes.iter().enumerate() {
                hh.insert(f(*idx, i), (j, ans.len()));
                hh.insert(f(i, *idx), (ans.len(), j));
            }
            hh.insert(f(i, i), (ans.len(), ans.len()));
            ans.push(initial.clone());
            idxes.push(i);
        }
        initial.push_str("X");
        i += 1;
    }
    let n: usize = input.next();
    for i in 0..n {
        write!(output, "{}\n", ans[i]);
    }
    output.flush();
    let q: usize = input.next();
    for i in 0..q {
        let p: i64 = input.next();
        let m = hh.get(&p).unwrap();
        write!(output, "{} {}\n", m.0 + 1, m.1 + 1);
        output.flush();
    }
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

    pub fn read_line(&mut self, buf: &mut String) {
        self.consume_until(|c| c.is_ascii_graphic());
        while self.has_more() && self.peek().is_ascii_graphic() {
            buf.push(self.peek());
            self.consume();
        }
        self.consume_until(|c| c.is_ascii_graphic());
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
        while self.has_more() {
            if test(self.peek()) {
                return;
            }
            self.consume();
        }
    }

    #[inline(always)]
    fn consume_until_int<F: Fn(u8) -> bool>(&mut self, test: F) {
        while self.has_more() {
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
                if input.has_more() && input.peek() == '.' {
                    input.consume();
                    while input.has_more() && input.peek().is_ascii_digit() {
                        num = num * 10.0 + input.pop_digit() as $t;
                        factor *= 10.0;
                    }
                }
                let mantissa = sign * num / factor;

                if input.has_more() && (input.peek() == 'E' || input.peek() == 'e') {
                    let mut exp = 0.0 as $t;
                    input.consume();
                    exp *= input.consume_until_sign() as $t;
                    while input.has_more() && input.peek().is_ascii_digit() {
                        exp = exp * 10.0 + input.pop_digit() as $t;
                        factor *= 10.0;
                    }
                    mantissa * (10.0 as $t).powf(exp)
                } else {
                    mantissa
                }

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
