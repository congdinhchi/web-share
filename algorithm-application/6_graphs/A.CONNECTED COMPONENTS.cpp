//
// Created by DINH CHI CONG on 12/13/2021.
//
#include<bits/stdc++.h>
using namespace std;
long long v, e;

// mang luu danh sach do thi
vector<long long> repo[1000];

void input(){
    cin>>v>>e;
    long long tmp1, tmp2;
    for (long long i = 1; i<=e;i++){
        cin>>tmp1>>tmp2;
        repo[tmp1].push_back(tmp2);
        repo[tmp2].push_back(tmp1);
    }
}

bool visted[1000];
long long cnt;

void  dfs(long long tmp){
    visted[tmp] = true;
    for (long long i: repo[tmp]){
        if(!visted[i]){
            dfs(i);
        }
    }
}

void solution(){
    for (int i = 1; i<= v;i++){
        //
        if (!visted[i]){
            cnt++;
            dfs(i);
        }
    }
}

int main(){
    input();
    solution();
    cout << cnt;
}
