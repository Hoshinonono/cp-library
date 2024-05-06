---
title: 隣接差集合
documentation_of: ./AdjacentDiffSet.hpp
---

## 概要
追加した要素からなる集合をソートした際に隣接差の最大値、最小値を得るためのライブラリ。<br>
ここらへんの問題殴る用のライブラリ。
<ul>
    <li><a href="https://atcoder.jp/contests/abc308/tasks/abc308_g">
AtCoder Beginner Contest 308「G - Minimum Xor Pair Query」</a></li>
    <li><a href="https://codeforces.com/contest/1862/problem/G">
Codeforces Round 894 (Div. 3)「G. The Great Equalizer」</a></li>
</ul>

|関数名など|機能|計算量|
|---------|----|-----|
|`Adjacent_Diff_Set`| 空集合を作成。要素の集合には番兵が入れられる。| $\text{O}(1)$ |
|`void add(long long v)`| 要素 $v$ を追加する。| $\text{O}(\log N)$ |
|`void del()`| 要素 $v$ を削除する。| $\text{O}(\log N)$ |
|`long long max()`| 加えられた要素の最大値を取得。 | $\text{O}(\log N)$ |
|`long long min()`| 加えられた要素の最小値を取得。 | $\text{O}(\log N)$ |
|`long long max_diff()`| 加えられた要素をソートしたときの隣接差の最大値を取得。<br> 要素数が2未満の場合は `0` を返す。 | $\text{O}(\log N)$ |
|`long long min_diff()`| 加えられた要素をソートしたときの隣接差の最小値を取得。<br> 要素数が2未満の場合は `0` を返す。  | $\text{O}(\log N)$ |