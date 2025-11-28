## 分析

### 题意

小 C 初始能力值是 $a$，目标能力值是 $b$（已知 $a < b$），还有一个参数 $k$。每天他有两种训练选择：

- 普通训练：能力值变成当前值加 $k$。

- 加训加训：能力值变成当前值乘 $k$。

我们需要算出小 C 至少要训练几天，才能让能力值大于等于 $b$。

### 思路

每次训练都选能让能力值增长更快的方式，从而用最少天数达到目标。

当某次训练后，不管选哪种方式都能达到或超过 $b$ 时，直接算 $1$ 天就能完成。

当 $k = 1$ 时，乘 $k$ 相当于能力值不变，所以此时只能一直选普通训练（加 $k$）。不过代码里不用单独处理 $k=1$，因为当 $k=1$ 时，$cur \times k = cur$，$cur + k = cur + 1$，自动选择加 $k$ 的方式。

整体思路是循环判断当前能力值 $cur$ 是否小于 $b$：

先看乘 $k$ 或加 $k$ 能不能直接到 $b$ 及以上，能的话天数加 $1$ 就结束；

如果不能，就选乘 $k$ 和加 $k$ 里能让能力值更大的那种方式，天数加 $1$，然后继续循环。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;  // 开 long long
int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;// 训练天数
    ll cur = a;// 当前能力值
    while (cur < b) {
        // 情况1
        if (cur * k >= b) {
            ans++;
            break;
        }
        // 情况2
        else if (cur + k >= b) {
            ans++;
            break;
        }
        // 情况3
        else {
            if (cur * k > cur + k) {
                cur *= k;
            } else {
                cur += k;
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
```