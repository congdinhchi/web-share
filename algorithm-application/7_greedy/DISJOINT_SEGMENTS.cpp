//
// Created by DINH CHI CONG on 1/10/2022.
//

#include<bits/stdc++.h>
using namespace std;

long long n;
vector<pair<long long, long long>> stage;

void input(){
    cin>>n;
    long long start, end;
    for (long long i = 0; i< n; i++){
        cin>> start >> end;
        stage.emplace_back(start, end);
    }
}

long long solution(){
    long long count = 1;
    long long save = stage[0].second;
    for (long long i = 1; i<stage.size();i++){
        if(stage[i].first > save){
            save = stage[i].second;
            count ++;
        }
    }
    return count;
}

int main(){
    input();
    sort(stage.begin(), stage.end(),[](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second < rhs.second; } );

    cout<<solution();
}