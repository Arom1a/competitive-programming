#![allow(unused)]

use std::fmt::Debug;
use std::io;
use std::io::Write;
use std::str::FromStr;

fn next<T>() -> T
where
    T: FromStr,
    <T as FromStr>::Err: Debug,
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().parse().unwrap()
}

fn next_vec<T>() -> Vec<T>
where
    T: FromStr,
    <T as FromStr>::Err: Debug,
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let arr: Vec<T> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    arr
}

fn ask(s: String) {
    println!("{}", s);
    io::stdout().flush().unwrap();
}

macro_rules! next_tuple {
    ($($t:ty),*) => {{
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.trim().split_whitespace();
        (
            $(
                iter.next().unwrap().parse::<$t>().unwrap(),
            )*
        )
    }};
}

fn next_char_vec() -> Vec<char> {
    let s: String = next();
    s.chars().collect::<Vec<char>>()
}

macro_rules! multi {
    ($blk: block) => {
        let t: usize = next();
        for _ in 0..t {
            $blk
        }
    };
}

macro_rules! single {
    ($blk: block) => {{
        $blk
    }};
}

macro_rules! getu {
    ($name: ident) => {
        let mut $name: usize = next();
    };
}

macro_rules! simple_vec {
    ($size: ident, $name: ident, $t: ty) => {
        let $size: usize = next();
        let mut $name: Vec<$t> = next_vec();
    };
}

macro_rules! print_bool {
    ($v: expr) => {
        println!("{}", if ($v) { "Yes" } else { "No" });
    };
}

macro_rules! print_vec {
    ($v: expr) => {
        println!(
            "{}",
            ($v).iter()
                .map(|x| x.to_string())
                .collect::<Vec<_>>()
                .join(" ")
        );
    };
}

fn gcd(mut a: usize, mut b: usize) -> usize {
    if a == b {
        return a;
    }
    if b > a {
        let temp = a;
        a = b;
        b = temp;
    }
    while b > 0 {
        let temp = a;
        a = b;
        b = temp % b;
    }
    a
}

fn lcm(a: usize, b: usize) -> usize {
    return a * (b / gcd(a, b));
}

fn pow(mut n: usize, mut x: usize, p: usize) -> usize {
    let mut ans = 1;
    if x <= 0 {
        return 1;
    }
    loop {
        if x == 1 {
            return (ans * n) % p;
        }
        if x & 1 == 0 {
            n = (n * n) % p;
            x >>= 1;
            continue;
        } else {
            ans = (ans * n) % p;
            x -= 1;
        }
    }
}

#[derive(Debug, Clone)]
pub struct Fenwick<const MOD: usize> {
    n: usize,
    data: Vec<usize>,
}

impl<const MOD: usize> Fenwick<MOD> {
    pub fn new(n: usize) -> Self {
        Fenwick {
            n,
            data: vec![0; n + 1],
        }
    }

    pub fn update(&mut self, idx: usize, delta: usize) {
        assert!(idx < self.n, "index out of bounds");
        let mut i = idx + 1;
        while i <= self.n {
            let sum = self.data[i] + delta;
            self.data[i] = if MOD == 0 { sum } else { sum % MOD };
            i += i & i.wrapping_neg();
        }
    }

    pub fn query(&self, idx: usize) -> usize {
        assert!(idx < self.n, "index out of bounds");
        let mut res = 0;
        let mut i = idx + 1;
        while i > 0 {
            let sum = res + self.data[i];
            res = if MOD == 0 { sum } else { sum % MOD };
            i -= i & i.wrapping_neg();
        }
        res
    }

    pub fn range_sum(&self, l: usize, r: usize) -> usize {
        assert!(l <= r && r < self.n, "invalid range");
        let total = self.query(r);
        if l == 0 {
            total
        } else {
            let sub = self.query(l - 1);
            if MOD == 0 {
                total - sub
            } else {
                (total + MOD - sub % MOD) % MOD
            }
        }
    }
}

pub type FenwickPlain = Fenwick<0>;

pub trait Monoid: Copy {
    type T: Copy + std::fmt::Debug;
    fn combine(a: Self::T, b: Self::T) -> Self::T;
    fn identity() -> Self::T;
    fn apply(node: &mut Self::T, delta: Self::T, len: usize, modulo: usize);
}

/// Sum‐monoid:    combine = +,   identity = 0,  apply = +delta*len (modulo'd)
#[derive(Copy, Clone, Debug)]
pub struct SumMonoid;
impl Monoid for SumMonoid {
    type T = usize;
    fn combine(a: usize, b: usize) -> usize {
        a + b
    }
    fn identity() -> usize {
        0
    }
    fn apply(node: &mut usize, delta: usize, len: usize, modulo: usize) {
        let add = delta.saturating_mul(len);
        *node = if modulo == 0 {
            node.saturating_add(add)
        } else {
            (*node + add) % modulo
        };
    }
}

/// Min‐monoid:    combine = min, identity = usize::MAX,  apply = +delta
#[derive(Copy, Clone, Debug)]
pub struct MinMonoid;
impl Monoid for MinMonoid {
    type T = usize;
    fn combine(a: usize, b: usize) -> usize {
        a.min(b)
    }
    fn identity() -> usize {
        usize::MAX
    }
    fn apply(node: &mut usize, delta: usize, _len: usize, _modulo: usize) {
        *node = node.saturating_add(delta);
    }
}

/// Max‐monoid:    combine = max, identity = 0,            apply = +delta
#[derive(Copy, Clone, Debug)]
pub struct MaxMonoid;
impl Monoid for MaxMonoid {
    type T = usize;
    fn combine(a: usize, b: usize) -> usize {
        a.max(b)
    }
    fn identity() -> usize {
        0
    }
    fn apply(node: &mut usize, delta: usize, _len: usize, _modulo: usize) {
        *node = node.saturating_add(delta);
    }
}

#[derive(Copy, Clone, Debug)]
pub struct XorMonoid;

impl Monoid for XorMonoid {
    type T = usize;

    /// a ^ b
    fn combine(a: usize, b: usize) -> usize {
        a ^ b
    }

    /// neutral element for XOR
    fn identity() -> usize {
        0
    }

    /// when XOR’ing every element in a segment of length `len` with `delta`,
    /// the combined‐XOR only flips by `delta` if `len` is odd.
    fn apply(node: &mut usize, delta: usize, len: usize, _modulo: usize) {
        if len % 2 == 1 {
            *node ^= delta;
        }
    }
}

#[derive(Debug, Clone)]
pub struct SegmentTree<M: Monoid, const MOD: usize> {
    n: usize,
    size: usize,     // = next_power_of_two(n)
    data: Vec<M::T>, // length = 2*size
}

impl<M: Monoid, const MOD: usize> SegmentTree<M, MOD> {
    pub fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        SegmentTree {
            n,
            size,
            data: vec![M::identity(); 2 * size],
        }
    }

    /// Rebuild from an array of length `n`
    pub fn build(&mut self, arr: &[M::T])
    where
        <M as Monoid>::T: From<usize>,
    {
        assert_eq!(arr.len(), self.n);
        // copy leaves
        for i in 0..self.n {
            let v = arr[i];
            self.data[self.size + i] = if MOD == 0 {
                v
            } else {
                let x: usize = unsafe { std::mem::transmute_copy(&v) };
                (x % MOD).into()
            };
        }
        // build internal nodes
        for idx in (1..self.size).rev() {
            let left = self.data[2 * idx];
            let right = self.data[2 * idx + 1];
            self.data[idx] = M::combine(left, right);
        }
    }

    /// point‐update: add `delta` at position `idx`
    pub fn update(&mut self, idx: usize, delta: M::T) {
        assert!(idx < self.n, "index out of bounds");
        let mut i = self.size + idx;
        // apply at the leaf
        M::apply(&mut self.data[i], delta, 1, MOD);
        // pull changes up
        i /= 2;
        while i > 0 {
            let l = self.data[2 * i];
            let r = self.data[2 * i + 1];
            self.data[i] = M::combine(l, r);
            i /= 2;
        }
    }

    /// range‐query over [l..r] inclusive
    pub fn query(&self, l: usize, r: usize) -> M::T {
        assert!(l <= r && r < self.n, "invalid query range");
        let mut res_l = M::identity();
        let mut res_r = M::identity();
        let mut a = self.size + l;
        let mut b = self.size + r;
        while a <= b {
            if a & 1 == 1 {
                res_l = M::combine(res_l, self.data[a]);
                a += 1;
            }
            if b & 1 == 0 {
                res_r = M::combine(self.data[b], res_r);
                b -= 1;
            }
            a /= 2;
            b /= 2;
        }
        M::combine(res_l, res_r)
    }

    /// point‐query (just `query(idx,idx)`)
    pub fn point_query(&self, idx: usize) -> M::T {
        self.query(idx, idx)
    }
}

#[derive(Debug, Clone)]
pub struct LazySegmentTree<M: Monoid, const MOD: usize> {
    n: usize,
    size: usize,
    data: Vec<M::T>,
    lazy: Vec<M::T>,
}

impl<M: Monoid, const MOD: usize> LazySegmentTree<M, MOD> {
    pub fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        LazySegmentTree {
            n,
            size,
            data: vec![M::identity(); 2 * size],
            lazy: vec![M::identity(); 2 * size],
        }
    }

    /// (Re)build from array
    pub fn build(&mut self, arr: &[M::T]) {
        assert_eq!(arr.len(), self.n);
        // write leaves
        for i in 0..self.n {
            self.data[self.size + i] = arr[i];
        }
        // build
        for idx in (1..self.size).rev() {
            let l = self.data[2 * idx];
            let r = self.data[2 * idx + 1];
            self.data[idx] = M::combine(l, r);
        }
    }

    /// push a pending “add lazy[idx]” down one level
    fn push(&mut self, idx: usize, left_len: usize, right_len: usize)
    where
        <M as Monoid>::T: PartialEq,
    {
        let delta = self.lazy[idx];
        if delta != M::identity() {
            // apply to children
            M::apply(&mut self.data[2 * idx], delta, left_len, MOD);
            M::apply(&mut self.lazy[2 * idx], delta, 1, 0);
            M::apply(&mut self.data[2 * idx + 1], delta, right_len, MOD);
            M::apply(&mut self.lazy[2 * idx + 1], delta, 1, 0);
            // clear
            self.lazy[idx] = M::identity();
        }
    }

    /// recursively apply “add delta” over [ql..qr]
    fn update_rec(
        &mut self,
        idx: usize,
        seg_l: usize,
        seg_r: usize,
        ql: usize,
        qr: usize,
        delta: M::T,
    ) where
        <M as Monoid>::T: PartialEq,
    {
        if ql > seg_r || qr < seg_l {
            return; // no overlap
        }
        if ql <= seg_l && seg_r <= qr {
            // full cover
            let len = seg_r - seg_l + 1;
            M::apply(&mut self.data[idx], delta, len, MOD);
            M::apply(&mut self.lazy[idx], delta, 1, 0);
            return;
        }
        // push down to children
        let mid = (seg_l + seg_r) / 2;
        self.push(idx, mid - seg_l + 1, seg_r - mid);
        // recurse
        self.update_rec(2 * idx, seg_l, mid, ql, qr, delta);
        self.update_rec(2 * idx + 1, mid + 1, seg_r, ql, qr, delta);
        // pull up
        self.data[idx] = M::combine(self.data[2 * idx], self.data[2 * idx + 1]);
    }

    /// range‐update [l..r] by adding `delta`
    pub fn update_range(&mut self, l: usize, r: usize, delta: M::T)
    where
        <M as Monoid>::T: PartialEq,
    {
        assert!(l <= r && r < self.n);
        self.update_rec(1, 0, self.size - 1, l, r, delta);
    }

    /// recursively query over [ql..qr]
    fn query_rec(&mut self, idx: usize, seg_l: usize, seg_r: usize, ql: usize, qr: usize) -> M::T
    where
        <M as Monoid>::T: PartialEq,
    {
        if ql > seg_r || qr < seg_l {
            return M::identity();
        }
        if ql <= seg_l && seg_r <= qr {
            return self.data[idx];
        }
        let mid = (seg_l + seg_r) / 2;
        self.push(idx, mid - seg_l + 1, seg_r - mid);
        let left = self.query_rec(2 * idx, seg_l, mid, ql, qr);
        let right = self.query_rec(2 * idx + 1, mid + 1, seg_r, ql, qr);
        M::combine(left, right)
    }

    /// range‐query [l..r]
    pub fn query_range(&mut self, l: usize, r: usize) -> M::T
    where
        <M as Monoid>::T: PartialEq,
    {
        assert!(l <= r && r < self.n);
        self.query_rec(1, 0, self.size - 1, l, r)
    }

    /// point‐query at idx
    pub fn query_point(&mut self, idx: usize) -> M::T
    where
        <M as Monoid>::T: PartialEq,
    {
        self.query_range(idx, idx)
    }
}

pub type SegSum<const M: usize> = SegmentTree<SumMonoid, M>;
pub type SegMin = SegmentTree<MinMonoid, 0>;
pub type SegMax = SegmentTree<MaxMonoid, 0>;
pub type SegXor<const M: usize> = SegmentTree<XorMonoid, M>;

pub type LazySegSum<const M: usize> = LazySegmentTree<SumMonoid, M>;
pub type LazySegMin = LazySegmentTree<MinMonoid, 0>;
pub type LazySegMax = LazySegmentTree<MaxMonoid, 0>;
pub type LazySegXor<const M: usize> = LazySegmentTree<XorMonoid, M>;

impl<M: Monoid, const MOD: usize> SegmentTree<M, MOD> {
    /// Assign index `idx` to exactly `val`, in O(log n).
    pub fn assign(&mut self, idx: usize, val: M::T)
    where
        <M as Monoid>::T: From<usize>,
    {
        assert!(idx < self.n, "index out of bounds");
        let mut i = self.size + idx;
        self.data[i] = if MOD == 0 {
            val
        } else {
            let x: usize = unsafe { std::mem::transmute_copy(&val) };
            (x % MOD).into()
        };
        i /= 2;
        while i > 0 {
            let l = self.data[2 * i];
            let r = self.data[2 * i + 1];
            self.data[i] = M::combine(l, r);
            i /= 2;
        }
    }
}

impl<const MOD: usize> SegmentTree<MinMonoid, MOD> {
    /// Find the first index i ∈ [l..n) with a[i] < x, if any.
    pub fn find_first_less_than(&self, l: usize, x: usize) -> Option<usize> {
        assert!(l < self.n);
        if self.query(l, self.n - 1) >= x {
            return None;
        }
        self.find_rec(1, 0, self.size - 1, l, x)
    }

    /// Returns Some(i) if in [seg_l..seg_r] there is an index ≥ `l` with a[i] < x.
    fn find_rec(
        &self,
        idx: usize,
        seg_l: usize,
        seg_r: usize,
        l: usize,
        x: usize,
    ) -> Option<usize> {
        if seg_r < l || self.data[idx] >= x {
            return None;
        }
        if seg_l == seg_r {
            return Some(seg_l);
        }
        let mid = (seg_l + seg_r) / 2;
        if let Some(i) = self.find_rec(idx * 2, seg_l, mid, l, x) {
            return Some(i);
        }
        self.find_rec(idx * 2 + 1, mid + 1, seg_r, l, x)
    }
}

impl<const MOD: usize> SegmentTree<MaxMonoid, MOD> {
    /// Find the smallest i ≥ `l` such that a[i] > x, or return None if none exists.
    pub fn find_first_greater_than(&self, l: usize, x: usize) -> Option<usize> {
        assert!(l < self.n, "start index out of bounds");
        if self.query(l, self.n - 1) <= x {
            return None;
        }
        self.find_first_gt_rec(1, 0, self.size - 1, l, x)
    }

    fn find_first_gt_rec(
        &self,
        idx: usize,
        seg_l: usize,
        seg_r: usize,
        l: usize,
        x: usize,
    ) -> Option<usize> {
        if seg_r < l || self.data[idx] <= x {
            return None;
        }
        if seg_l == seg_r {
            return Some(seg_l);
        }
        let mid = (seg_l + seg_r) / 2;
        if let Some(i) = self.find_first_gt_rec(idx * 2, seg_l, mid, l, x) {
            return Some(i);
        }
        self.find_first_gt_rec(idx * 2 + 1, mid + 1, seg_r, l, x)
    }
}

struct XorShift64 {
    state: u64,
}

impl XorShift64 {
    fn new(seed: u64) -> Self {
        Self { state: seed }
    }

    fn next(&mut self) -> u64 {
        let mut x = self.state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        self.state = x;
        x
    }
}

fn generate_random_vector(n: usize, seed: u64) -> Vec<u64> {
    let mut rng = XorShift64::new(seed);
    (0..n).map(|_| rng.next()).collect()
}

struct XorShift128 {
    state: u128,
    max: u128,
}

impl XorShift128 {
    fn new(seed: u128, max: u128) -> Self {
        Self { state: seed, max }
    }

    fn next(&mut self) -> u128 {
        let mut x = self.state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        self.state = x;
        x % self.max
    }
}

fn generate_random_vector128(n: usize, seed: u128, max: u128) -> Vec<u128> {
    let mut rng = XorShift128::new(seed, max);
    (0..n).map(|_| rng.next()).collect()
}

const U64_HASH: u64 = 6818302623243877264;
const U128_HASH: u128 = 68183026232438772646818302623243877264;

const ALPHABETS: [char; 26] = [
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x', 'y', 'z',
];

type UVec = Vec<usize>;

// const MOD: usize = 1000000007;
const MOD: usize = 998244353;

const MLOG: usize = 23;

fn main() {
    multi!({
        let n: usize = next();
        let mut grid = vec![vec![]; n];
        let mut cnt = vec![0; n * n + 1];
        for i in 0..n {
            let row: UVec = next_vec();
            for &x in &row {
                cnt[x] += 1;
            }
            grid[i] = row;
        }
        let mut ok = true;
        for i in 1..=n * n {
            if cnt[i] > n * (n - 1) {
                ok = false;
            }
        }
        if ok {
            println!("YES");
        } else {
            println!("NO");
        }
    });
}
