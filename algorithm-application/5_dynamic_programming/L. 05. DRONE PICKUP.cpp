//
// Created by DINH CHI CONG on 12/6/2021.
//

#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long c[3001], a[3001];

void input(){
    cin>>n>>k;
    for(long long i = 1 ; i<=n;i++){
        cin>>c[i];
    }
    for(long long i = 1 ; i<=n;i++){
        cin>>a[i];
    }
}

bool check[3001][101];
long long max_c[3001][101];
long long solution(long long point, long long k_tmp){
    // danh dau da tinh
    if (check[point][k_tmp]) return max_c[point][k_tmp];
    else check[point][k_tmp] = true;

    //Diem dung
    if (k_tmp == k+1){
        if (point != n) {
            max_c[point][k_tmp]= 0;
        }
        else{
            max_c[point][k_tmp] = c[point];
        }
        return max_c[point][k_tmp];
    }

    if (point == n) {
        max_c[point][k_tmp]= c[point];
        return max_c[point][k_tmp];
    }

    //Tinh toan
    for (int i=1;i<=a[point];i++){
        if (point+i>n) break;
        max_c[point][k_tmp] = max(max_c[point][k_tmp], solution(point + i, k_tmp+1));
    }

    if(max_c[point][k_tmp] != 0) max_c[point][k_tmp]+=c[point];

    return max_c[point][k_tmp];
}

int main(){
    input();
    cout<<solution(1,1);
}
/* test case
6 3
2 3 4 56 7 8
1 2 1 2  1 1 */