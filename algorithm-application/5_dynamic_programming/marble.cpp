#include<bits/stdc++.h>
using namespace std;

const long long MAX = 600;

long long weight, height;
long long n;
long long w[MAX], h[MAX];
long long answer[MAX][MAX];
bool bitmask[MAX][MAX];

void input(){
    cin>>weight>>height;
    cin>>n;
    for(long long i=0; i<n;i++){
        cin>>w[i]>>h[i];
    }
}

void setup(){
    long long x, y;
    for(long long i=0; i<n;i++){
        x = h[i];
        y = w[i];
        bitmask[x][y] =true;
        answer[x][y] = x*y;
    }
}

long long dynamics(long long col, long long row){
    // diem dung
    if (bitmask[col][row]) return answer[col][row];
    bitmask[col][row]=true;


    // tinh toan
    long long target;
    target = col/2 +1;
    for(long long i = 1; i < target; i++){
        answer[col][row] = max(dynamics(col - i, row) + dynamics(i, row), answer[col][row]);
    }
    target = row/2 +1;
    for(long long j = 1; j< row; j++){
        answer[col][row] = max(dynamics(col, row - j) + dynamics(col,j), answer[col][row]);
    }

    return answer[col][row];
}

long long solution(){
    return weight*height - dynamics(height,weight);
}

int main(){
    input();
    setup();
    cout<<solution();
}

