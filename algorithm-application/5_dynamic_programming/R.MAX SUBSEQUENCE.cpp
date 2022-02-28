//
// Created by DINH CHI CONG on 11/28/2021.
//

#include <bits/stdc++.h>
using namespace  std;

long long n;
long long a[1000002];

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

long long max_weigh;
void solution(){
    long long tmp = 0;
    for (int i=0;i<n;i++){
        tmp += a[i];
        if (tmp <0) tmp = 0;
        else max_weigh = max (tmp,max_weigh);
    }
}

int main(){
    input();
    solution();
    cout<<max_weigh;
}