题目链接：<https://www.luogu.com.cn/problem/P13190>。

## 分析

题意：给定一个 $N \times N$ 的网格，每行和每列的士兵身高严格递增。现在丢失了一行或一列，剩下 $2 \times N-1$ 个列表。要求找出缺失的那一行或列。

首先我们可以统计所有数字的出现次数（每个数字在行列中出现的总次数应该是偶数，除非它属于缺失的那一行或一列）。

然后筛选奇数次出现的数字（缺失的行或列中的每个数字出现次数为奇数）。

最后排序输出（将这些数字排序后即为缺失的行或列）。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int cnt[2505];// 统计每个身高的出现次数
int m[55];// 存储缺失的行/列
int main() {
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {//用于输出行号
		int n;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));//清空
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				cnt[x]++;
			}
		}
		// 收集出现奇数次的身高
		memset(m, 0, sizeof(m));//清空
		int k = 0; 
		for (int i = 1; i < 2505; i++) {
			if (cnt[i] % 2) m[k++] = i;
		}
		sort(m, m + k);
		printf("Case #%d:", c);
		for (int i = 0; i < k; i++) {
			printf(" %d", m[i]);
		}
		cout << endl;
	}
	return 0;
}
```

注意事项：

1. 不要学我把 `cin`，`cout` 和 `scanf`，`printf` 混用，虽然这样你可能也会 A 了这道题，但这也是不好的习惯。

2. 因为有 $T$ 组测试用例，所以每次处理要清空。