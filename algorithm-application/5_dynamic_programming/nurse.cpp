#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1001;

long long n;
long long k1, k2;
bool bitmask[MAX];
long long answer[MAX];

void input(){
    cin>>n;
    cin>>k1>> k2;
}

// trong quy hoach dong deu dan den 1 truong hop tai vi tri thu i la ngay nghi => chi can luu bien bitmask[i]


long long dynamics(long long x){

    // Diem dung
    if (x == 0 || x == -1) return 1;
    if(x < 0) return 0;
    if (bitmask[x]) return answer[x];

    // Tinh toan
    bitmask[x] = true;

    for (long long i = k1; i <= k2 ; i++){
        answer[x] += dynamics(x - i - 1);
    }

    return answer[x];
}

long long solution(){
    return dynamics(n) + dynamics(n-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    cout<<solution();

    return 0;
}