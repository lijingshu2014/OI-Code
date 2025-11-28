## 分析

### 题意

已知小 F 需赢满 $x$ 场获胜，小 S 需赢满 $y$ 场获胜。已进行 $n$ 场比赛，求小 F 要最终获胜时，后续比赛中“最多连续胜场”的最小值。

### 思路

先统计已有胜场：遍历 $s$，求出小 F 已胜 $F$ 场，小 S 已胜 $S$ 场。

然后计算后续需求：

小 F 还需胜 $k = x - F$ 场（$k \leq 0$ 时直接输出 $0$，无需再比）。

小 S 后续最多能胜 $r = y-1 - S$ 场（再胜 $1$ 场就赢了，小 F 失败）。

### 分类讨论

| 情况                | 逻辑                                                                 | 答案                 |
|---------------------|----------------------------------------------------------------------|----------------------|
| $r \leq 0$          | 小 S 不能再胜，小 F 需连胜所有 $k$ 场                                 | $k$                  |
| $r > 0$             | 小 S 的 $r$ 场胜利将小 F 的 $k$ 场分成 $g = r+1$ 段，尽量平均分       | $\lceil \frac{k}{g} \rceil$（即 $k\%g>0$ 时 $\frac{k}{g}+1$，否则 $\frac{k}{g}$） |


## 代码
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        int F = 0, S = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'F') F++;
            else S++;
        }
        int k = x - F;
        if (k <= 0) {
            cout << 0 << endl;
            continue;
        }
        int r = y - 1 - S;
        if (r <= 0) {
            cout << k << endl;
        } else {
            int g = r + 1;
            int b = k / g;
            int rem = k % g;
            cout << (rem > 0 ? b + 1 : b) << endl;
        }
    }
    return 0;
}
```