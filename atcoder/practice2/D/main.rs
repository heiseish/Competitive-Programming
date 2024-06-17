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


struct MPM
{
    struct FlowEdge
    {
        int v, u;
        long long cap, flow;
        FlowEdge() {}
        FlowEdge(int _v, int _u, long long _cap, long long _flow)
            : v(_v), u(_u), cap(_cap), flow(_flow) {}
        FlowEdge(int _v, int _u, long long _cap)
            : v(_v), u(_u), cap(_cap), flow(0ll) {}
    };
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<char> alive;
    vector<long long> pin, pout;
    vector<list<int>> in, out;
    vector<vector<int>> adj;
    vector<long long> ex;
    int n, m = 0;
    int s, t;
    vector<int> level;
    vector<int> q;
    int qh, qt;

    bool bfs()
    {
        while (qh < qt)
        {
            int v = q[qh++];
            for (int id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q[qt++] = edges[id].u;
            }
        }
        return level[t] != -1;
    }
    long long pot(int v)
    {
        return min(pin[v], pout[v]);
    }
    void remove_node(int v)
    {
        for (int i : in[v])
        {
            int u = edges[i].v;
            auto it = find(out[u].begin(), out[u].end(), i);
            out[u].erase(it);
            pout[u] -= edges[i].cap - edges[i].flow;
        }
        for (int i : out[v])
        {
            int u = edges[i].u;
            auto it = find(in[u].begin(), in[u].end(), i);
            in[u].erase(it);
            pin[u] -= edges[i].cap - edges[i].flow;
        }
    }
    void push(int from, int to, long long f, bool forw)
    {
        qh = qt = 0;
        ex.assign(n, 0);
        ex[from] = f;
        q[qt++] = from;
        while (qh < qt)
        {
            int v = q[qh++];
            if (v == to)
                break;
            long long must = ex[v];
            auto it = forw ? out[v].begin() : in[v].begin();
            while (true)
            {
                int u = forw ? edges[*it].u : edges[*it].v;
                long long pushed = min(must, edges[*it].cap - edges[*it].flow);
                if (pushed == 0)
                    break;
                if (forw)
                {
                    pout[v] -= pushed;
                    pin[u] -= pushed;
                }
                else
                {
                    pin[v] -= pushed;
                    pout[u] -= pushed;
                }
                if (ex[u] == 0)
                    q[qt++] = u;
                ex[u] += pushed;
                edges[*it].flow += pushed;
                edges[(*it) ^ 1].flow -= pushed;
                must -= pushed;
                if (edges[*it].cap - edges[*it].flow == 0)
                {
                    auto jt = it;
                    ++jt;
                    if (forw)
                    {
                        in[u].erase(find(in[u].begin(), in[u].end(), *it));
                        out[v].erase(it);
                    }
                    else
                    {
                        out[u].erase(find(out[u].begin(), out[u].end(), *it));
                        in[v].erase(it);
                    }
                    it = jt;
                }
                else
                    break;
                if (!must)
                    break;
            }
        }
    }
    long long flow()
    {
        long long ans = 0;
        while (true)
        {
            pin.assign(n, 0);
            pout.assign(n, 0);
            level.assign(n, -1);
            alive.assign(n, true);
            level[s] = 0;
            qh = 0;
            qt = 1;
            q[0] = s;
            if (!bfs())
                break;
            for (int i = 0; i < n; i++)
            {
                out[i].clear();
                in[i].clear();
            }
            for (int i = 0; i < m; i++)
            {
                if (edges[i].cap - edges[i].flow == 0)
                    continue;
                int v = edges[i].v, u = edges[i].u;
                if (level[v] + 1 == level[u] && (level[u] < level[t] || u == t))
                {
                    in[u].push_back(i);
                    out[v].push_back(i);
                    pin[u] += edges[i].cap - edges[i].flow;
                    pout[v] += edges[i].cap - edges[i].flow;
                }
            }
            pin[s] = pout[t] = flow_inf;
            while (true)
            {
                int v = -1;
                for (int i = 0; i < n; i++)
                {
                    if (!alive[i])
                        continue;
                    if (v == -1 || pot(i) < pot(v))
                        v = i;
                }
                if (v == -1)
                    break;
                if (pot(v) == 0)
                {
                    alive[v] = false;
                    remove_node(v);
                    continue;
                }
                long long f = pot(v);
                ans += f;
                push(v, s, f, false);
                push(v, t, f, true);
                alive[v] = false;
                remove_node(v);
            }
        }
        return ans;
    }
};


fn solve<R: BufRead, W: Write>(mut input: InputReader<R>, mut output: W) {
    // read in int/float
    let n: usize = input.next();
    let m: usize = input.next();
    let mut b = vec![];
    for i in 0..n {
        let mut s = String::new();
        input.read_line(&mut s);
        b.push(s.chars().collect::<Vec<_>>());
    }
    let mut pr = dinic::Dinic::new(n * m * 2 + 4);
    let st = n * m * 2;
    let en = n * m * 2 + 1;

    let DX = [1, 0, -1, 0];
    let DY = [0, 1, 0, -1];

    let mut hh = HashMap::new();

    for i in 0..n {
        for j in 0..m {
            if b[i][j] == '#' {
                continue;
            }

            let cur = i * m + j;
            let alt_cur = cur + n * m;

            if (i + j) % 2 == 0 {
                pr.add_edge(st, cur, 1);

                for d in 0..4 {
                    let x = i as i32 + DX[d];
                    let y = j as i32 + DY[d];
                    if x < 0 || x >= n as i32 || y < 0 || y >= m as i32 {
                        continue;
                    }
                    let nxt = x as usize * m + y as usize + n * m;
                    pr.add_edge(cur, nxt, 1);
                    hh.insert(
                        (cur, nxt),
                        (
                            match (DX[d], DY[d]) {
                                (1, 0) => 'v',
                                (-1, 0) => '^',
                                (0, 1) => '>',
                                (0, -1) => '<',
                                _ => panic!(),
                            },
                            i,
                            j,
                        ),
                    );
                }
            }

            if (i + j) % 2 == 1 {
                pr.add_edge(alt_cur, en, 1);
            }
        }
    }
    let mf = pr.max_flow(st, en);
    write!(output, "{}\n", mf);

    let mut ans = vec![vec!['a'; m]; n];
    for i in 0..n {
        for j in 0..m {
            ans[i][j] = b[i][j];
        }
    }
    for ed in &pr.edges {
        if ed.u >= n * m {
            continue;
        }
        if ed.flow <= 0 {
            continue;
        }
        let (ch, i, j) = hh[&(ed.u, ed.v)];
        ans[i][j] = ch;
        match ch {
            'v' => {
                ans[i + 1][j] = '^';
            }
            '^' => {
                ans[i - 1][j] = 'v';
            }
            '<' => {
                ans[i][j - 1] = '>';
            }
            '>' => {
                ans[i][j + 1] = '<';
            }
            _ => todo!(),
        }
    }

    for i in 0..n {
        for j in 0..m {
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
