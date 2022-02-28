//
// Created by DINH CHI CONG on 12/13/2021.
//
#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long n, m;
vector<long long> edges[N];

void input(){
    cin>>n>>m;
    long long tmp1, tmp2;
    for (long long i = 1; i<=m; i++){
        cin>>tmp1>>tmp2;
        edges[tmp1].push_back(tmp2);
        edges[tmp2].push_back(tmp1);
    }
}
long long num[N], low[N];
// vị trí hiện tại trong cây
long long cnt;
bool visited[N];
long long number_bridges, num_point;
long long mask[N];

// Từ đỉnh parent sẽ thăm đỉnh point
void dfs(long long parent,long long point){
    visited[point] = true;
    cnt++;
    num[point]=low[point]=cnt;
    long long dem = 0;
    // Đi đến tất cả các điểm còn lại
    for (long long i: edges[point]){
        // Nếu i chính là parent thì bỏ qua
        if (i == parent) continue;
        if (!visited[i]) {
            dem++;
            dfs(point, i);
            //Xác định là bridges
            if (num[point] < low[i]) number_bridges++;
            if (num[point] <= low[i]){
                mask[point] = 1;
            }
            low[point] = min(low[point], low[i]);
        }else { low[point] = min(low[point], num[i]); }
    }
    if (parent == 0) mask[point] = (dem>1);
}

//Duyệt từng thành phần liên thông
void solution(){
    for (long long i = 1; i<=n ;i ++){
        if (!visited[i]) dfs(0, i);
    }
}

int main(){
    input();
    solution();
    for (long long i = 1; i<=n;i++){
        num_point += mask[i];
    }
    cout<<num_point<<" "<<number_bridges;
}