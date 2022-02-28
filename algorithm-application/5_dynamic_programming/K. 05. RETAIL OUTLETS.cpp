//
// Created by DINH CHI CONG on 11/29/2021.
//

#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[101];

void input(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
}
long long result[501][101];
bool check[501][101];
long long solution(long long cua_hang, long long chi_nhanh){
    // Kiem tra diem cuoi
    if (chi_nhanh ==0){
        if (cua_hang == 0 ) return 1;
        else return 0;
    }
    if (cua_hang ==0) return 0;

    // Dung som
    long long cua_hang_tmp = cua_hang;
    for (int i = chi_nhanh; i>=1; i--){
        cua_hang_tmp -= a[i];
    }
    if (cua_hang_tmp <0) return 0;

    if (!check[cua_hang][chi_nhanh]) {
        long long tmp = cua_hang_tmp / a[chi_nhanh];
        for (int i = 1; i <= tmp+1; i++) {
            result[cua_hang][chi_nhanh] += solution(cua_hang - i * a[chi_nhanh], chi_nhanh - 1);
        }
        check[cua_hang][chi_nhanh] = true;
    }

    return result[cua_hang][chi_nhanh]%1000000007;
}

int main(){
    input();
    cout<<solution(m,n);
}