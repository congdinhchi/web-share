#include<bits/stdc++.h>
using namespace std;
long long i, j, dem;
int main(){
    long long n, m;
    cin >> n;
    getchar();
    long long a[n];
    for ( i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>m;
    getchar();
    long long b[m];
    for ( i = 0; i<m; i++){
        cin>>b[i];
    }
    for ( i = 0; i<m;i++){
        for ( j=0; j<n; j++){
            if (b[i]==a[j]){
                dem++;
                break;
            }
        }
    }
    if ( dem<m ){
        cout<<0;
    }
    else{
        cout<<1;
    }
}