---
title: 簡易版部分永続 Union Find (最大辺取得用)
documentation_of: ./dsu2_max.hpp
---

## 概要
部分永続 Union Find の簡易版。<br>
辺の追加順が昇順である必要がある。<br>
頂点 $u$ と頂点 $v$ が連結になったときの辺の値を返すことができる。<br>
ここらへんの問題殴る用のライブラリ。
<ul>
    <li>AtCoder：<a href="https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_h">
CODE THANKS FESTIVAL 2017「H - Union Sets」</a></li>
    <li>AtCoder：<a href="https://atcoder.jp/contests/past202004-open/tasks/past202004_o">
第二回 アルゴリズム実技検定 過去問「O - 可変全域木」</a></li>
    <li>Library Checker：<a href="https://judge.yosupo.jp/problem/persistent_unionfind">Persistent Unionfind</a></li>
    <li>Codeforces：<a href="https://codeforces.com/contest/1706/problem/E">Codeforces Round #809 (Div. 2)「E. Qpwoeirut and Vertices」</a></li>
</ul>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`dsu(int N)`|宣言。 $N$ 頂点 $0$ 辺のグラフを作成する。<br>辺の型 `T` を渡す。 | $\text{O} (N)$ | 
|`bool merge(int a, int b, T w)`|頂点 $a$ と頂点 $b$ を辺の大きさ $w$ で結ぶ。辺の追加に成功したら`true`、既に連結である場合は`false`が返される。<br>辺は昇順に追加する必要がある。 | $\text{O} (\log N)$ | 
|`bool same(int a, int b)`|頂点 $a$ と頂点 $b$ が連結であるかを返す。 | $\text{O} (\log N)$ | 
|`int leader(int a)`|頂点 $a$ の属する連結成分の代表元を返す。| $\text{O} (\log N)$ | 
|`int size(void)`|現在の連結成分の数を返す。(int型であることに注意)| $\text{O} (1)$ | 
|`int size(int a)`|頂点 $a$ の属する連結成分のサイズを返す．| $\text{O} (\log N)$ | 
|`T max_edge(int u, int v)`|最小全域木上の頂点 $u$ から頂点 $v$ までの単純パスのうち最大辺を返す。<br>・同一頂点の場合は`0`を返す。<br>・非連結の場合は`-1`を返す。| $\text{O} (\log N)$ | 
|`std::vector<std::vector<int>> groups()`|グラフを連結成分に分けてその情報を返す． 返り値は「「一つの連結成分の頂点番号のリスト」のリスト」で， リスト内でどの順番で頂点が格納されているかは未定義である．| $\text{O} (N)$ |
