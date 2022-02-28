//
// Created by DINH CHI CONG on 12/6/2021.
//

#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[1000001];
long long m;
stack<long long> x;
stack<long long> y;

void input(){
    cin>>n;
    for (long long i = 0; i<n;i++){
        cin>>a[i];
    }
    cin>> m;
    long long tmp_x, tmp_y;
    for (long long i=1;i<=m;i++){
        cin>>tmp_x;
        cin>>tmp_y;
        x.push(tmp_x);
        y.push(tmp_y);
    }
}
long long sum;
void solution(){
    while(!x.empty()) {
        long long min_tmp = INT_MAX;
        for (long long i = x.top(); i<= y.top();i++){
            min_tmp = min(min_tmp, a[i]);
        }
        x.pop();
        y.pop();
        sum += min_tmp;
    }
}

int main(){
    input();
    solution();
    cout<<sum;
}