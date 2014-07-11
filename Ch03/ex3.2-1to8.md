
## 3.2-1
f(n) and g(n) are monotonically increasing functions <br>
1. Given a function 
```
h(n) = f(n) + g(n)
```

if (m &le; n) then <br>
f(m) &le; f(n) <br>
g(m) &le; g(n)

Adding both sides of the inequalities: <br>
f(m) + g(m) &le; f(n) + g(n) <br>
=> h(m) &le; h(n) <br>
2. if g(n) is a monotonically increasing function, m &le; n means g(m) &le; g(n) <br>
Assume ```k = g(m)``` and ```l = g(n)```.
if f(n) is a monotonically increasing function, k &le; l means f(k) &le; f(l) <br>
Thus, f(g(n)) is a monotonically increasing function <br>
3. same logic... too lazy to write it

## 3.2-2
```
al 		= log(c, b) 
		= log(c, a) / log(b, a)
a^al 	= a^(log(c, a) / log(b, a))
		= (a^log(c, a))^-log(b, a)
		= c^-log(b, a)
		= c^log(a, b)
```
Thus, the equation holds...

## 3.2-3
Prove lg(n!) = &Theta;(n*lg(n)):
```
lg(n!)	= lg(n*(n-1)*(n-2)*...*2*1) 
		= lg(n) + lg(n-1) + lg(n-2) + ... + lg(2) + lg(1)	// n elements
```
Thus, lg(n!) = &Theta;(n*lg(n))