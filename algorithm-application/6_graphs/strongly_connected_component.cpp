#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1000006;
long long n, m;
vector<long long> deg[MAX];
long long bitmask[MAX];
long long num[MAX], low[MAX];
bool bConnect[MAX];
void input(){
    cin>>n>>m;
    long long v_start, v_end;
    for(long long i = 1; i<= m; i++){
        cin>>v_start>>v_end;
        deg[v_start].push_back(v_end);
    }
}



void dfs(long long x){

}

long long solution(){
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    input();
    cout<<solution();
    return 0;
}