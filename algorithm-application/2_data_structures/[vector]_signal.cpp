#include<bits/stdc++.h>
using namespace std;


int main(){

    // input
    long long n;
    cin>>n;
    int b;
    cin>>b;
    long long tmp, answer = -1;
    vector<long long> a;
    for (int i=0;i<n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }

    //tim max_full
    long long max_full = 0;
    for(int i=1; i<n ; i++){
        if (a[max_full]<a[i]) max_full = i;
    }

    // xet tu 0 -> max_full
    long long max_left = 0;
    for (int i=1;i<max_full;i++){
        if (a[max_left]<=a[i]) max_left=i;
        if (a[max_left]-a[i] >= b && a[max_full]- a[i]>=b){
            tmp = a[max_left] + a[max_full] - 2*a[i];
            answer = max(tmp, answer);
        }
    }

    //xet tu max_full <- n-1
    long long max_right = n-1;
    for (int i= n-2; i>max_full;i--){
        if (a[max_right] <= a[i]) max_right = i;
        if (a[max_full]- a[i] >= b && a[max_right]- a[i]>=b){
            tmp = a[max_right] + a[max_full] - 2*a[i];
            answer = max(tmp, answer);
        }
    }
    cout<<answer;
}