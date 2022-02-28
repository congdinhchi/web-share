#include<bits/stdc++.h>
using namespace std;
const long long MAX = 100;
long long r, s;
string a[MAX][MAX];
long long values[MAX][MAX];
bool bitmask[MAX][MAX];
void input(){
    cin>>r>>s;
    string values;
    for(long long i = 1; i <=r;i++){
        for(long long j = 1; j<= s;j++){
            cin >> a[i][j];
        }
    }
}


long long caculate(long long x, long long y, string s){
    if(bitmask[x][y]) return values[x][y];
    bitmask[x][y] = true;
    if (s[0] == 61){
        long long row = 0;
        long long col = 0;
        for(char c: s){
            if(c-0 == 61){
                continue;
            }
            if (c - 43 == 0){
                values[x][y] += caculate(row, col, a[row][col]);
                row = 0;
                col = 0;
                continue;
            }
            if(c-0 >57){    //day ko phai 1 so
                col = col*26 + (c-64);
            }else{
                row = row*10 + (c-48);
            }
        }
        values[x][y] += caculate(row, col, a[row][col]);
        return values[x][y] ;
    }
    else{
        for(char c: s){
            values[x][y] = values[x][y]*10 + (c-48) %   2147483648;
        }
        return values[x][y];
    }
}

void solution(){

    for(long long i = 1; i <=r;i++){
        for(long long j = 1; j<= s;j++){
            cout<<caculate(i, j, a[i][j]) <<" ";
        }
        cout<<endl;
    }
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    input();
    solution();
    return 0;
}


