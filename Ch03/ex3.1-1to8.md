## 3.1-1
Given h(n) = max(f(n), g(n)) it is obvious that the higher order component of h(n) will be the same as the highest component of f(n)+g(n), which means O(h(n)) = O(f(n) + g(n)) => the worst case running time.
The best case running time for h(n) would be the best case running time of either f(n) or h(n), depending which is bigger => h(n) = \Omega(f(n) + g(n)).
Thus, h(n) = \Theta(f(n)+g(n))

## 3.1-2
If b > 0:
(n+a)^b = n^b + c1*n^(b-1)*a + c2*n^(b-2)*a^2 + ... + a^b
=> (n+a)^b = \Theta(n^b)

## 3.1-3
"The running time of A is at LEAST O(n^2)" - seriously?
big-O is supposed to be the UPPER bound.

## 3.1-4
2^(n+1) = 2*(2^n) = O(2^n), so yes
2^(2n) = 4^n, so O(4^n) = O(2^n) ? not sure... :(

## 3.1-5 and 3.1-6
def 1: given \Omega(g(n)) = f(n) <= c1*g(n)
def 2: given O(g(n)) = f(n) <= c2*g(n)

Combining the def 1 and def 2:
\Theta(n) = g(n): c1*g(n) <= f(n) <= c2*g(n)

which is the definition of the \Theta notation

## 3.1-7
small-o: f(n) < c*g(n)
small-\omega: c*g(n) < f(n)

The intersection of the two will therefore be an empty set

## 3.1-8
&Omega;(g(n,m)) = {f(n, m): there exist positive c, n0, m0 such that 0 <= g(n, m) <= f(n, m)}
\Theta(g(n,m)) = {f(n, m): there exist positive c, n0, m0 such that 0 <= g(n, m) <= f(n, m)}