## 分析

### 题意

这道题要求我们为一排彩色卡片分配数字，需要满足三个条件：

1. 数字从左到右是非递减的。

2. 相同颜色的卡片必须有相同数字。

3. 不同颜色的卡片必须有不同数字。

最后需要按数字从小到大的顺序输出颜色。如果无法满足条件，则输出 `IMPOSSIBLE`。

### 思路

如果一种颜色出现了多次，那么这些出现的位置必须是连续的。否则，就不可能满足条件。

比如在 $[3,8,2,2,8]$ 中，数字 $8$ 出现了两次但不连续，中间隔着 $2$，这就导致无论如何分配数字都无法满足非递减的要求。

所以，我们解决这道题的步骤是：

1. 检查每种颜色的出现是否都是连续的。

2. 如果有不连续的颜色，输出 `IMPOSSIBLE`。

3. 如果所有颜色都连续出现，那么按它们第一次出现的顺序输出即可（因为这个顺序自然满足非递减要求）。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int s[100005], vis[100005];
int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++) {//输出行号
        int n;
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));//每次都要清空
        bool flag = 1;//标记是否连续
		for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
			if (!vis[s[i]]) vis[s[i]] = 1;
			else if (s[i - 1] != s[i]) flag = 0;
		}
        printf("Case #%d: ", c);
		if (!flag) printf("IMPOSSIBLE\n");//如果标记被改为 0，表示不连续，即不符合条件
		else {
			for (int i = 1;i <= n; i++){
				if (s[i] != s[i - 1]) printf("%d ", s[i]);
            }
			cout << endl;
		}
	}
	return 0;
}
```