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
use std::ops::*;

mod mcmf {
    use std::collections::VecDeque;

    type LT = i64;
    type Graph<T = usize> = Vec<Vec<T>>;

    const INF: LT = LT::MAX / 2;

    #[derive(Default, Clone, Debug)]
    pub struct FlowEdge {
        pub u: usize,
        pub v: usize,
        pub cap: LT,
        pub flow: LT,
    }

    impl FlowEdge {
        pub fn new(u: usize, v: usize, cap: LT) -> Self {
            Self {
                v,
                u,
                cap,
                ..Default::default()
            }
        }
    }

    pub struct MinCostMaxFlow {
        n: usize,
        adj: Graph,
        cost: Graph<LT>,
        pub capacity: Graph<LT>,
    }

    impl MinCostMaxFlow {
        pub fn new(n: usize) -> Self {
            Self {
                n,
                adj: vec![vec![0; n]; n],
                cost: vec![vec![0; n]; n],
                capacity: vec![vec![0; n]; n],
            }
        }
        pub fn add_edge(&mut self, u: usize, v: usize, cost: LT, cap: LT) {
            self.adj[u].push(v);
            self.adj[v].push(u);
            self.cost[u][v] = cost;
            self.cost[v][u] = -cost;
            self.capacity[u][v] = cap;
        }

        pub fn min_cost_flow(&mut self, s: usize, t: usize, k: LT) -> LT {
            let mut flow = 0;
            let mut cost = 0;
            let mut d = vec![];
            let mut p = vec![];

            while flow < k {
                self.shortest_paths(s, &mut d, &mut p);
                if d[t] == INF {
                    break;
                }
                // find max flow on that path
                let mut f = k - flow;
                let mut cur = t;
                while cur != s {
                    f = f.min(self.capacity[p[cur] as usize][cur]);
                    cur = p[cur] as usize;
                }

                // apply flow
                flow += f;

                // comment out this block is flow need to be equal to K
                if f * d[t] > 0 {
                    break;
                }
                //

                cost += f * d[t];
                cur = t;
                while cur != s {
                    self.capacity[p[cur] as usize][cur] -= f;
                    self.capacity[cur][p[cur] as usize] += f;
                    cur = p[cur] as usize;
                }
            }

            // uncomment out this block is flow need to be equal to K
            // if flow < k {
            //     return -1;
            // }
            //
            cost
        }

        fn shortest_paths(&self, v0: usize, d: &mut Vec<LT>, p: &mut Vec<i32>) {
            let n = self.n;
            *d = vec![INF; n];
            d[v0] = 0;

            let mut inq = vec![false; n];
            let mut q = VecDeque::new();
            q.push_back(v0);
            *p = vec![-1; n];

            while !q.is_empty() {
                let u = q.pop_front().unwrap();
                inq[u] = false;

                for &v in &self.adj[u] {
                    if self.capacity[u][v] > 0 && d[v] - self.cost[u][v] > d[u] {
                        d[v] = d[u] + self.cost[u][v];
                        p[v] = u as i32;
                        if !inq[v] {
                            inq[v] = true;
                            q.push_back(v);
                        }
                    }
                }
            }
        }
    }
}

fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let n: usize = input.next();
    let k: i64 = input.next();
    let mut a = [[0; 55]; 55];
    let mut ans = [['.'; 55]; 55];
    const B: i64 = 1 << 40;

    for i in 0..n {
        for j in 0..n {
            a[i][j] = input.next();
        }
    }

    let mut mf = mcmf::MinCostMaxFlow::new(2 * n + 2);

    let st = 2 * n;
    let en = 2 * n + 1;

    for i in 0..n {
        for j in 0..n {
            mf.add_edge(i, j + n, -a[i][j], 1);
        }
    }
    for i in 0..n {
        mf.add_edge(st, i, 0, k);
        mf.add_edge(i + n, en, 0, k);
    }

    mf.add_edge(st, en, n as i64 * k, B);

    let mcf = mf.min_cost_flow(st, en, n as i64 * k);
    write!(output, "{}\n", mcf.abs());
    for i in 0..n {
        for j in 0..n {
            if mf.capacity[i][j + n] == 0 {
                ans[i][j] = 'X';
            }
        }
    }

    for i in 0..n {
        for j in 0..n {
            write!(output, "{}", ans[i][j]);
        }
        write!(output, "\n");
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
