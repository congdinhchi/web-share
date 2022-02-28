//
// Created by DINH CHI CONG on 10/4/2021.
//
#include<bits/stdc++.h>
using namespace std;

void print( stack<int> x){
    cout<<x.size()<<" ";
    while(!x.empty()){
        cout<<x.top()<<" ";
        x.pop();
    }
    cout<<endl;
}

int main(){
    int n,tmp;
    cin>>n;
    getchar();
    stack<int>a,b,c;
    for (int i=0; i<n;i++){
        cin>>tmp;
        if (tmp<0) a.push(tmp);
        else if (tmp > 0) b.push(tmp);
        else c.push(tmp);
    }
    print(a);
    print(b);
    print(c);
}

