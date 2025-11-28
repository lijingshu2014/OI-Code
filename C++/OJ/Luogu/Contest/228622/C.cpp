#include <bits/stdc++.h>
using namespace std;
int n,l,r;
int main() {
    cin>>n>>l>>r;
    int a[1000005];
    int s=0;
    for(int i=0;i<n-1;i++){
        a[i]=rand()%2000001-1000000;
        s+=a[i];
    }
    int minv=l-s;
    int maxv=r-s;
    if(minv<-1000000)minv=-1000000;
    if(maxv>1000000)maxv=1000000;
    a[n-1]=rand()%(maxv-minv+1)+minv;
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    return 0;
}