## 分析

### 题意

给定 $n$ 个整数的序列和 $m$ 次操作机会，每次操作可对一个数做 “$+2$、$-2$、$\times 2$、$\lfloor \frac{x}{2} \rfloor$” 中的一种。目标是用完 $m$ 次操作后，让序列的 “极差（最大值 - 最小值）” 最大。

### 思路

$m$ 最大仅为 $10$ 次，且在四种操作中，$\times 2$ 是使数值增大最快的运算，对初始最小值操作的收益极低 —— 要么使最小值增大（缩小极差），要么即使减小（如 $-2$），收益也远不如将操作次数用于放大初始最大值。

首先遍历序列，找到初始最大值 $\text{Max}$ 和最小值 $\text{Min}$，且 $\text{Min}$ 全程保持不变。

再将 $m$ 次操作全部用于放大 $\text{Max}$：

1. 若初始 $\text{Max} < 2$，先消耗 $1$ 次操作执行 $\text{Max+2}$（此时 $\text{Max} \geq 2$，后续乘 $2$ 收益更高），剩余 $m-1$ 次操作全部执行 $\text{Max} \times 2$。

2. 若初始 $\text{Max} \geq 2$，直接将 $m$ 次操作全部执行 $\text{Max} \times 2$（最终 $\text{Max}$ 变为 $\text{Max} \times 2^m$）。

## 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 1e9;
int a[MAXN];
int main(){
    int n, m;
	cin >> n >> m;
    int Max = 0, Min = INF;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		Max = max(a[i], Max);
        Min = min(a[i], Min);
	}
	if(Max < 2){
        Max += 2;
        m--;
    }
    cout << ((1ll * Max) << m) - Min;//转为 long long 防止溢出
	return 0;
}
```