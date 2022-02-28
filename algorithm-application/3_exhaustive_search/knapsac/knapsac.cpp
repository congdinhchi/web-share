#include<bits/stdc++.h>
using namespace std;

int n, b;
vector<pair<int,int>> store;
void inputData(){
    cin>>n>>b;
    for (int i=1;i<=n;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        store.push_back({tmp1,tmp2});
    }
}


bool comp(pair<int,int>x, pair<int,int> y){
    float tmp1, tmp2;
    tmp1 = 1.0*x.second/x.first;
    tmp2 = 1.0*y.second/y.first;
    if (tmp1 >= tmp2) return true;
    return false;
}

pair<int,int> a[31];
bool visited[31];
int c_max = INT_MIN;
void Try(int x, int k){
    for (int i=k; i<n;i++){
        if (!visited[i]) {
            a[x] = {a[x - 1].first + store[i].first, a[x - 1].second + store[i].second};
            visited[i] = true;

            if (a[x].first < b && x<= n) {
                Try(x + 1, i + 1);
            }
            else c_max = max(a[x-1].second,c_max);

            visited[i]=false;
        }
    }
}

int main(){
    inputData();
    sort(store.begin(), store.end(), comp);
    a[0]={0,0};
    Try(1, 0);
    cout<<c_max;
}