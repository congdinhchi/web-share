//
// Created by DINH CHI CONG on 1/10/2022.
//

#include<bits/stdc++.h>
using namespace std;

long long cl_pay = 1000;
long long values;
stack<long long> coin;

void input(){
    cin>> values;
    long long k = 1;
    coin.push(k);
    for(int i = 0; i <=4; i++){
        if (i%2==0){
            k *= 5;
        }
        else{
            k *= 2;
        }
        coin.push(k);
    }
}

long long solution(){
    long long ch_return = cl_pay - values;
    long long num_coin = 0;
    while (ch_return>0){
        if(ch_return>coin.top()){
            num_coin += ch_return/coin.top();
            ch_return %= coin.top();
        }
        coin.pop();
    }
    return num_coin;
}

int main(){
    input();
    cout<<solution();
}