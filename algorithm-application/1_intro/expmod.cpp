#include<bits/stdc++.h>
using namespace std;
unsigned long long c=1000000007;
unsigned long long exp(unsigned long long a, unsigned long long b){
    if (b==0) return 1;
    else if (b%2==1){
        return (exp(a, --b) * a) % c;
    }
    else{
        return ((exp(a, b/2) % c) * (exp(a, b/2) % c)) %c;
    }
}
int main(){
    unsigned long long a, b;
    cin>>a>>b;
    fflush(stdin);
    // giam gia tri cua a xuong 10^9
    a%=c;
    // a^b%c tuong duong a^r%c voi r= b%(c-1)
    b%=(c-1);
    cout<<exp(a, b);
}

