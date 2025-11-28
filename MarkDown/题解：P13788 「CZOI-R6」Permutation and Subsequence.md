## 分析

### 题意

给定两个长度均为 $n$ 的由 $1$ 到 $n$ 构成的排列 $a$ 和 $b$。要求求出 $a$ 的非空连续子段中，有多少个是 $b$ 的子序列。

其中，$a$ 的连续子段是指从 $a$ 的开头和结尾各删除若干个元素（可能为 $0$ 个）后得到的序列；$b$ 的子序列是指在 $b$ 中任意位置删除若干个元素（可能为 $0$ 个）后得到的序列。

### 思路

一个序列 $c$ 是 $b$ 的子序列，意味着 $c$ 中元素在 $b$ 中出现的顺序与 $c$ 中元素的顺序一致。对于 $a$ 的连续子段，若要成为 $b$ 的子序列，其对应元素在 $b$ 中的位置应是递增的。

首先，我们可以通过一个 $pos$ 数组记录 $b$ 中每个元素的位置，即 $pos _x$ 表示元素 $x$ 在 $b$ 中的位置。

然后定义 $dp_i$ 表示以 $a_i$ 为结尾的 $a$ 的连续子段中是 $b$ 的子序列的数量。

当考虑 $a_i$时，初始情况下 $dp_i$ 至少为 $1$（即 $a_i$ 自身构成的子段）。

若 $i>1$ 且 $a_{i-1}$ 在 $b$ 中的位置 $pos_{a_{i-1}}$ 小于 $a_i$ 在 $b$ 中的位置 $pos_{a_i}$，说明以 $a_{i - 1}$ 为结尾的符合要求的子段可以和 $a_i$ 组成新的符合要求的子段，所以 $dp_i = dp_{i-1} + 1$。

最后将所有的 $dp_i$ 相加，得到的结果就是答案。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], b[MAXN];
int pos[MAXN];
int dp[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = pos[a[i]];
        dp[i] = 1;
        if (i > 1 && pos[a[i - 1]] < cur) {
            dp[i] = dp[i - 1] + 1;
        }
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}
```