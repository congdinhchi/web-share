#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1004;
long long n;
long long a[MAX];
long long answer[MAX];
bool bitsmask[MAX];

void input(){
    cin>>n;
    for(long long i=0; i<n; i++){
        cin>>a[i];

    }
}

long long dynamics(long long x){
    // diem dung
    if(bitsmask[x]) return answer[x];

    // tinh toan
    bitsmask[x] = true;
    for(long long i = 0; i <x ;i++){
        if(a[i]<a[x]){
           answer[x] = max(dynamics(i), answer[x]);
        }
    }
    answer[x] += 1;
    return answer[x];
}

long long solution(){
    long long best_solution = 0;
    for(long long i = 0; i< n; i++){
        best_solution = max(dynamics(i), best_solution);
    }
    return best_solution;
}

int main(){
    input();
    cout<<solution();
}