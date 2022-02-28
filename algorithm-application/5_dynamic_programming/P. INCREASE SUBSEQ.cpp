#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10004];
long long iMem[10004];

long long List(long long x){
    if (iMem[x]!=-1){
        return iMem[x];
    }
    long long max_x =1;
    for(long long i=0;i<x;i++){
        if (a[i]<a[x]){
            max_x = max(max_x,1+List(i));
        }
    }
    iMem[x]=max_x;
    return max_x;
}

int main(){
    memset(iMem, -1, sizeof(iMem));
    cin>>n;
    for (long long i =0 ;i<n;i++){
        cin>>a[i];
    }
    List(n-1);
    long long max_final=0;
    for (int i=0;i<n;i++){
        max_final = max(max_final, iMem[i]);
    }
    cout<<max_final;
}