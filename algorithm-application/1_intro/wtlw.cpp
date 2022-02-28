//
// Created by DINH CHI CONG on 10/3/2021.
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        getline(cin, a[i]);
    }
    for (int i=0;i<n;i++){
        if (a[i].size()>10){
            cout<<a[i].front()<<a[i].size()-2<<a[i].back();
        }
        else{
            cout<<a[i];
        }
        cout<<endl;
    }
}

