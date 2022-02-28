//O(N*(L1 - L2))
#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1000006;

long long n;
long long l1, l2;
long long a[MAX];
long long answer[MAX];
bool bitmask[MAX];

void input(){
    cin>>n;
    cin>>l1>>l2;
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
}

long long dynamics(long long x){
    // Diem dung
    if (x<0) return 0;
    if (bitmask[x]) return answer[x];

    // Bat dau tinh
    bitmask[x] = true;

    long long max_pre = 0;  // gia tri lon nhat trong cac giai phap truoc do
    for (int i =l1;i<=l2;i++){
        max_pre = max(dynamics(x-i), max_pre);
    }

    answer[x] += max_pre;
    answer[x] += a[x];

    return answer[x];
}

long long solution(){
    static long long max_solution;
    for (long long i = n-1 ; i >= n-1-l1;i--){
        if(!bitmask[i]) dynamics(i);
        max_solution = max(answer[i], max_solution);
    }
    return max_solution;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    cout<<solution();
}