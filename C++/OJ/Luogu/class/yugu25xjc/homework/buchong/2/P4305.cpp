#include<cstdio>
#include<map>
int T, n, x;
std::map<int, bool> s;
int main(){
	scanf("%d",&T);
	for(int i = 1;i <= T;i++){
		s.clear();
		scanf("%d", &n);
		for(int j = 1;j <= n;j++){
			scanf("%d", &x);
			if(!s[x]){
				printf("%d ",x);
				s[x] = 1;
			}
		}
		puts("");
	}
	return 0;
}