## 概要

$a, b$ が与えられたとき, $ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$ を求める.

## 使い方

* `extgcd(a, b, x, y)`: $\gcd(a, b)$ を返す. $(x, y)$ には $ax + by = \gcd(a, b)$ を満たす整数解が格納される. 整数解は複数考えられるが, $\|x\| + \|y\|$ が最小のものを求めている.

## 計算量

* $O(\log {\min(a, b)})$
