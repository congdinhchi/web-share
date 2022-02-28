#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

struct Edge{
    long long u;
    long long v;
    long long w;
};
long long n, m;
vector<Edge> vlist_w;

void input(){
    cin>>n>>m;
    vlist_w.resize(m+1);
    for (int i=1;i <=m;i++){
        cin>>vlist_w[i].u>>vlist_w[i].v>>vlist_w[i].w;
    }
}

long long r[MAX];
long long parent[MAX];

// Kết hợp nhánh
void unionSet(long long x, long long y){
    if (r[x] == r[y]) r[y]++;
    if (r[x] > r[y]){
        parent[y] = x;
    }
    else{
        parent[x] = y;
    }
}

// Tìm nút cha
long long findSet(long long x){
    while (parent[x] != x){
        x=parent[x];
    }
    return parent[x];
}

bool filter(Edge x, Edge y){
    return x.w < y.w;
}

long long solution(){
    sort(vlist_w.begin(), vlist_w.end(), filter);
    // Tạo ra các điểm đó
    for (long long i = 1; i<= n;i++){
        parent[i] = i;
        r[i] = 0;
    }

    long long ans = 0;
    for (Edge x: vlist_w){
        // so sánh 2 điểm có cùng cha không
        long long parent_u = findSet(x.u);
        long long parent_v = findSet(x.v);
        if(parent_u != parent_v){
            ans += x.w;
            //Hợp nhất 2 nhánh
            unionSet(parent_u, parent_v);
        }
    }
    return ans;
}

int main(){
    input();
    cout<<solution();
}
