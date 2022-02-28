#include<bits/stdc++.h>
using namespace std;
const long long MAX = 100005;
vector<long long> v[MAX];
long long n, m;
bool bitmask[MAX];

void setup(long long v_start, long  long v_end){
    v[v_start].push_back(v_end);
    v[v_end].push_back(v_start);
}

void input(){
    cin>>n>>m;

    long long v_start, v_end;
    for(long long i = 1 ; i<=m;i++){
        cin>>v_start>>v_end;
        setup(v_start, v_end);
    }
}

void dfs(long long x){
    bitmask[x] = true;
    for (long long v_end : v[x]){
        if(!bitmask[v_end]){
            dfs(v_end);
        }
    }
}

long long solution(){
    long long cnt = 0;
    for(long long i = 1; i <= n; i++){
        if(!bitmask[i]){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}


int main(){
    input();
    cout<<solution();

}