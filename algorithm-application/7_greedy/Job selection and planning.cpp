//
// Created by DINH CHI CONG on 1/10/2022.
//

#include<bits/stdc++.h>
using namespace std;

long long n;
vector<pair<long long, long long>> stage;

void input(){
    cin>>n;
    n=n+1;
    long long start, end;
    for (long long i = 0; i< n; i++){
        cin>> start >> end;
        stage.emplace_back(start, end);
    }
}

long long solution(){
    long long sum = 0;
    long long p_max = 0;
    long long i = 0;
    while( i<stage.size()){
        long long j = i+1;
        p_max = stage[i].second;
        cout<<stage[i].first;
        while(stage[j].first == stage[i].first){
            p_max = max(stage[j].second,p_max);
            j++;
        }
        i = j;
        sum += p_max;

    }
    return sum;
}

int main(){
    input();
    sort(stage.begin(), stage.end(),[](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.first < rhs.first; } );

    cout<<solution();
}

