//
// Created by DINH CHI CONG on 10/4/2021.
//
#include<bits/stdc++.h>
using namespace std;
// Kiem tra dung sai
int check(string s){
    stack<char> data;
    for(char c:s){
        if (c=='('){
            data.push(')');
        }
        else if (c=='{'){
            data.push('}');
        }
        else if (c=='['){
            data.push(']');
        }
        else{
            if (data.empty()) return 0;
            if(data.top()==c){
                data.pop();
            }
            else {
                return 0;
            }
        }
    }
    if (data.empty()){
        return 1;
    }
    else return 0;
}

int main(){
    int n, tmp;
    cin>>n;
    getchar();
    string s;
    int a[n];
    for(int i=0;i<n;i++){
        getline(cin, s);
        a[i]=check(s);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
