#include<bits/stdc++.h>
using namespace std;

long long k[901][901];
long long a[901][901];

int main(){

    //input
    int n, m;
    int i_start,j_start;
    cin>>n>>m;
    getchar();
    cin>>i_start>>j_start;
    getchar();

    for (int i=0;i<n;i++){
        for (int j=0; j<m;j++){
            cin>>a[i][j];
        }
    }

    queue<pair<int, int>> pass;
    pass.push({i_start-1, j_start-1});
    k[i_start-1][j_start-1] = 1;
    int x,y;

    while (!pass.empty()){

        x = pass.front().first;
        y = pass.front().second;

        pass.pop();

        //kiem tra da den dich chua
        if (x==0|| x== (n-1) || y==0||y==(m-1)){
            cout<<k[x][y];
            break;
        }

        // di xuong
        if (a[x+1][y]==0 && k[x+1][y]==0){
            k[x+1][y] = k[x][y]+1;
            pass.push({x+1,y});
        }

        //di len
        if (a[x-1][y]==0 && k[x-1][y]==0){
            k[x-1][y] = k[x][y]+1;
            pass.push({x-1,y});
        }

        //sang trai
        if (a[x][y-1]==0 && k[x][y-1]==0){
            k[x][y-1] = k[x][y]+1;
            pass.push({x,y-1});
        }

        //sang phai
        if (a[x][y+1]==0 && k[x][y+1]==0){

            k[x][y+1] = k[x][y]+1;
            pass.push({x,y+1});
        }

    }

    if (x!=0 && x!=(n-1) && y!=0&&y!=m){
        cout<<-1;
    }
}