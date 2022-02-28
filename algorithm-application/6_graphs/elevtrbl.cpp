#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1000006;
long long f, s, g, u ,d;

queue<long long> v[MAX];
long long answer[MAX];
bool bitmask[MAX];

void input(){
    cin>>f>>s>>g>>u>>d;
}


long long bfs(long long x){
    // diem dung;
    if (x == g) return 0;
    if(bitmask[x] ) return answer[x];

    bitmask[x] = true;
    // tinh toan
    long long num = INT_MAX;
    if (x+u<=f){
        cout<<"here";
        cout<<x;
        answer[x]  = bfs(x+u);
    }
    if (x-d>0){
        cout<<"xuong";
        cout<<x;
        answer[x]  = min(answer[x] , bfs(x- d));
    }

    answer[x] += 1;
    return answer[x];
}

long long solution(){
    return bfs(s);
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    input();
    cout<<solution();
    return 0;
}