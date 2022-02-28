#include <bits/stdc++.h>
using namespace std;

int n;
long long cost[12][12];
void inputData(){
    cin>>n;
    for (int i=0;i<2*n+1;i++){
        for (int j=0;j<2*n+1;j++){
            cin>>cost[i][j];
        }
    }
}

bool visited[12];
long long sum_cost[12];
int vitri[12];
long long min_cost = INT_MAX;
void Try(int x){
    for (int i=1;i<=n;i++){
        if(!visited[i]){
            sum_cost[x] = sum_cost[x-1] + cost[vitri[x-1]][i] +cost[i][i+n];
            vitri[x] = i+n;
            visited[i] = true;

            if (x==n){
                sum_cost[x] = sum_cost[x] + cost[i+n][0];
                min_cost = min(min_cost,sum_cost[x]);
            }
            else{
                Try(x+1);
            }

            visited[i] = false;
        }
    }
}

int main(){
    inputData();
    Try(1);
    cout<<min_cost;
}