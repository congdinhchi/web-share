//
// Created by DINH CHI CONG on 12/6/2021.
//

#include<bits/stdc++.h>
using namespace std;

long long n;
long long c[30][30];

void input(){
    cin>>n;
    for (int i=0; i<=2*n; i++){
        for( int j = 0;j<=2*n;j++){
            cin>>c[i][j];
        }
    }
}
long long dp[1<<12][12];
bool check[1<<12][12];
long long solution(long long mask, long long point){
    //Diem dung: Neu da don tat ca hanh khach => bitmask full 1
    if (mask == ((1 << (n + 1)) - 1) ){
        return c[point + n][0];
    }
    //Check trung
    if (check[mask][point]) return dp[mask][point];
    long long cost = 1e9;
    //Di den diem tiep theo
    for (long long j = 1;j<=n;j++){
        // Kiem tra xem da don hay chua ?
        if ((mask&(1<<j))==0){
            long long new_mask = mask|(1<<j);
            // vi tri hien tai
            long long cur  = point + n;
            if (point == 0) cur = 0;
            cost= min (cost, solution(new_mask, j)+c[cur][j] + c[j][j+n]);
        }
    }
    check[mask][point] = true;
    dp[mask][point] = cost;
    return cost;
}

int main(){
    input();
    // Diem 0 cung tinh la 1 hanh khach
    cout<<solution(1, 0);
}
