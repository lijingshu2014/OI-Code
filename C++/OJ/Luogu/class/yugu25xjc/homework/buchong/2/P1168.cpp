#include <bits/stdc++.h>
using namespace std;
int A[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int mid = 0;
    cout << (mid = A[1]) << endl;
    priority_queue<int> p, q;
    for (int i = 3; i <= n; i += 2) {
        if (A[i - 1] <= mid && A[i] <= mid) {
            p.push(A[i - 1]); 
            p.push(A[i]);
            q.push(-mid);
            mid = p.top(); 
            p.pop();
        }
        else if (A[i - 1] >= mid && A[i] >= mid) {
            p.push(mid);
            q.push(-A[i - 1]); 
            q.push(-A[i]);
            mid = -q.top(); 
            q.pop();
        }
        else {
            if (A[i - 1] > A[i]){
                swap(A[i - 1], A[i]);
            }
            p.push(A[i - 1]);
            q.push(-A[i]);
        }
        cout << mid << endl;
    }
    return 0;
}