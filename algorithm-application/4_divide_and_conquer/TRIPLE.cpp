#include <bits/stdc++.h>
using namespace std;
long long N, K;
long long a[5001];
long long c[4];
long long Find[4];
long long dem;
void Try(int x, long long h){
    if (x==4){
        if(Find[x-1] ==0){
            dem++;
        }
    }
    else {
        for (int i = h; i < N; i++) {
            if (Find[x - 1] >= a[i]) {
                Find[x] = Find[x-1] - a[i];
                Try(x + 1, i+1);
            }
            else break;
        }
    }
}

int main(){
    cin>>N>>K;
    for (int i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a, a+N-1);
    Find[0] = K;
    Try(1, 0);
    cout<<dem;
}