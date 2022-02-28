#include<bits/stdc++.h>
using namespace std;

struct node {
    int ui;
    int vi;
    int wi;

    node(int ui, int vi, int wi){
        this->ui = ui;
        this->vi = vi;
        this->wi = wi;
    }
};

int n, m, k;
int min_weight;
int total_weigh;
int cmin;
int x[40];
bool visited[40];
vector<node> listEdge;

long long r[40];
long long p[40];

void makeSet(long long x){
    p[x] = x;
    r[x] = 0;
}

void unionSet(long long x, long long y){

// p[a] và p[b] hai đỉnh khác nhau thì mới nối vào
    if(r[x] > r[y]){
        p[y] = x;
    }else{
        p[x] = y;
        if(r[x] == r[y]) r[y]+=1;
    }
}

long long findSet(long long x){
    while(p[x] != x){
        x = p[x];
    }
    return p[x];
}


bool check(int a, int i){
    if(visited[i]) return false;

    for(int j=1; j<=n; j++) makeSet(j);
    for(int j=1; j<a; j++){
        int pa = findSet(listEdge[x[j]].ui);
        int pb = findSet(listEdge[x[j]].vi);

        unionSet(pa, pb);
    }

    int pa = findSet(listEdge[i].ui);
    int pb = findSet(listEdge[i].vi);

    if(pa == pb) return false;
    return true;
}

void TRY(int a, int z){

    for(int i=z+1; i<m; i++){
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;
            total_weigh += listEdge[x[a]].wi;

            if(a == k) min_weight = min(min_weight, total_weigh);
            else if(total_weigh + (k-a)*cmin < min_weight) TRY(a+1, i);

            visited[i] = false;
            total_weigh -= listEdge[x[a]].wi;
        }
    }
}

int main(){
    cin >> n >> m >> k;
    min_weight = INT_MAX;
    cmin = INT_MAX;
    for(int i=0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;

        listEdge.push_back(node(x, y, z));
        cmin = min(cmin, z);
    }
    TRY(1,0);

    if(min_weight == INT_MAX) cout << "-1";
    else cout << min_weight;
}