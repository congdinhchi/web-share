#include<bits/stdc++.h>
using namespace std;

const long long MAX = 100005;

long long n,m;
vector<long long> deg[MAX];
bool bitmask[MAX];
long long num[MAX], low[MAX];
long long cnt;

void setup(long long v_start, long long v_end){
    deg[v_start].push_back(v_end);
    deg[v_end].push_back(v_start);
}

void input(){
    cin>>n>>m;
    long long v_start,v_end;
    for(long long i = 1; i<=m; i++){
        cin>>v_start >>v_end;
        setup(v_start,v_end);
    }
}

long long dfs(long long v_start, long long v_end){
    bitmask[v_end] = true;
    cnt ++;
    num[v_end] = low[v_end] = cnt;
    for (long long i = 1; i <= n; i++){
        if(!bitmask[v_end]){
            dfs(v_end, i);
        }
    }
}

long long solution(){
    for(long long i = 1; i<=n; i++){
        if(!bitmask[i]){
            dfs(i);
        }
    }
}

int main(){
    input();
    cout<<solution();
}

