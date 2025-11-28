#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

template < typename Tp >
void read(Tp &x) {
	x = 0; int fh = 1; char ch = 1;
	while(ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if(ch == '-') fh = -1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}

const int maxn = 100000 + 7;
const int maxm = 200000 + 7;

int n, a[maxn];
int Head[maxn], to[maxm], Next[maxm], tot;

void add(int x, int y) {
	to[++tot] = y, Next[tot] = Head[x], Head[x] = tot;
}

void Init(void) {
	read(n);
	for(int i = 1; i <= n; i++) {
		read(a[i]);
	}
	for(int i = 1, x, y; i < n; i++) {
		read(x); read(y);
		add(x, y); add(y, x);
	}
}

queue <int> Q;
int col;

bool check(int x) {
	int cnt = 0; long long sum = 0;
	for(int i = Head[x]; i; i = Next[i]) {
		int t = to[i];
		if(a[t]) cnt++, sum += a[t];
	}
	if(a[x]) cnt++, sum += a[x]; 
	if(cnt == 0) return false;
	if(sum % cnt) return false;
	if(a[x] && a[x] != sum / cnt) return false;
	for(int i = Head[x]; i; i = Next[i]) {
		int t = to[i];
		if(a[t] && a[t] != sum / cnt) return false;
	}
	col = sum / cnt;
	return true;
}

bool inq[maxn];

void paint(int x) {
	a[x] = 0;
	for(int i = Head[x]; i; i = Next[i]) {
		int t = to[i];
		if(a[t] && inq[t] == false) {
			Q.push(t); inq[t] = true;
		}
		a[t] = 0;
	}
}

vector <int> ansx, ansc;

void Work(void) {
	for(int i = 1; i <= n; i++) {
		if(check(i) && inq[i] == false) {
			Q.push(i); paint(i); inq[i] = true;
			ansx.push_back(i); ansc.push_back(col);
		}
	}
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(int i = Head[x]; i; i = Next[i]) {
			int t = to[i];
			if(check(t)) {
				Q.push(t); paint(t); inq[t] = true;
				ansx.push_back(t); ansc.push_back(col);
			}
		}
	}
	printf("%d\n", (int)ansx.size());
	reverse(ansx.begin(), ansx.end());
	reverse(ansc.begin(), ansc.end());
	for(int i = 0; i < (int)ansx.size(); i++) {
		printf("%d %d\n", ansx[i], ansc[i]);
	}
}

int main() {
	Init();
	Work();
	return 0;
}

