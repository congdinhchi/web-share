#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[1000001];
long long a_max;

void Try(int x){
    if(x*(a[x-1] - a[x]) <= m){
        m -= x*(a[x-1] - a[x]);
        a_max -= (a[x-1] - a[x]);
    }
    else{
        long long tmp;
        tmp = m/x;
        m = m-tmp*x;
        a_max -= tmp;
        if (m !=0) a_max-=1;
        m=0;
    }
    if (m==0) return;
    else Try(x+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n, greater<int>());
    a_max = a[0];
    Try(1);
    cout<<a_max;
}
