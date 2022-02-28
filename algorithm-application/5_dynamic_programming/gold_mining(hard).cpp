// O(N)
#include<bits/stdc++.h>
using namespace std;

const long long MAX = 1000006;

long long n;
long long l1, l2;
long long a[MAX];
deque<long long> dq;
long long answer[MAX];

void input(){
    cin>>n;
    cin>>l1>>l2;
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
}


long long solution(){
    static long long result;
    for (long long i = 0; i < l1; i++){
        answer[i] = a[i];
    }
    for (long long i = l1; i < n; i++) {
        while (!dq.empty() && dq.front()<i-l2) {
            dq.pop_front();
        }
        while (!dq.empty() && answer[dq.back()]<answer[i-l1]){
            dq.pop_back();
        }
        dq.push_back(i-l1);
        answer[i] = a[i] + answer[dq.front()];
        result = max(result, answer[i]);
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    cout<<solution();
}