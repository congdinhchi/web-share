//
// Created by DINH CHI CONG on 12/13/2021.
//

#include<bits/stdc++.h>
#define N 1000005
using namespace std;

long long f, s, g, u, d;
queue<long long> que;
bool visted[N];
long long cnt[N];

void input(){
    cin>> f>>s>>g>>u>>d;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    que.push(s);
    visted[s] = true;
    while (!que.empty()){
        long long x = que.front();
        que.pop();
        if (x==g){
            cout<<cnt[x];
            return 0;
        }
        if (x+u<=f && !visted[x+u]){
            que.push(x+u);
            visted[x+u] =true;
            cnt[x+u] = cnt[x]+1;
        }
        if (x-d>=1 && !visted[x-d]){
            que.push(x-d);
            visted[x-d] =true;
            cnt[x-d] = cnt[x]+1;
        }
    }
    cout<<"use the stairs";
}