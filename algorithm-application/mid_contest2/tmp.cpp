#include<bits/stdc++.h>
using namespace std;



void input(){

}



long long solution(){
    string s= "=A5";
    long long row = 0;
    long long col = 0;
    for(char c: s){
        if(c-0 == 61){
            continue;
        }
        if(c-0 >57){    //day ko phai 1 so
            col = col*26 + (c-64);
        }else{
            row = row*10 + (c-48);
        }
    }
    return row;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    input();
    cout<<solution();
    return 0;
}