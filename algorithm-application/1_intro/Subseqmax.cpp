#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    getchar();
    long long a[n];
    long long sum_tmp = 0, sum_max=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        sum_tmp=sum_tmp+a[i];
        if (sum_tmp<0) sum_tmp=0;
        if (sum_tmp>sum_max) sum_max=sum_tmp;
    }
    cout<<sum_max;
}

