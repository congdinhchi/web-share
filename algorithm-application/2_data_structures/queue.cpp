#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,i,j ;
    cin>>n;
    getchar();

    long long a[n], b[n], tmp;
    i=0;

    while (i<n){
        cin>>a[i];
        i++;
    }

    i=0;
    while (i<n) {
        tmp = 0;
        b[i] = -1;
        j = i + 1;
        while (j < n){
            if (a[j] < a[i]) {
                b[i] = b[i] + tmp + 1;
                tmp = 0;
            } else tmp++;
        j++;
        i++;
    }
i=0;
while (i<n){
cout<<b[i]<<" ";
}
}