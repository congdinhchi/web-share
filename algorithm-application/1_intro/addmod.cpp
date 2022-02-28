#include<bits/stdc++.h>
using namespace std;
unsigned long long a, b, c=1000000007;
unsigned long long sum;
long long buffer;
int main(){
    cin>>a>>b;
    fflush(stdin);
    a=a%c;
    b=b%c;
    sum=a+b;
    cout<<sum%c;
    return 0;
}