#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long k = 1000000007;
    unsigned long long n, sum_max=0;
    long long tmp, sum=0;
    cin>>n;
    fflush(stdin);
    for (int i=0;i<n;i++){
        cin>>tmp;
        sum+=tmp;
        if (sum<0) sum=0;
        if (sum>sum_max) sum_max=sum;
        sum_max%=k;
    }
    cout<<sum_max;
}
/*
2
-123456789
2345678904 */
