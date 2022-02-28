//
// Created by DINH CHI CONG on 10/17/2021.
//
#include<bits/stdc++.h>
using namespace std;

int  sign[901][901];
int a, b, c;

int main(){

    // input
    cin>> a >> b>>c;

    queue<pair<int, int>> pass;
    pass.push({0,0});
    sign[0][0] = 1;

    while (!pass.empty()){

        int a_old = pass.front().first;
        int b_old = pass.front().second;
        pass.pop();

        //kiem tra
        if (a_old == c || b_old == c) {
            cout << sign[a_old][b_old] - 1;
            break;
        }

        //do nuoc binh a;
        if (sign[a][b_old] == 0){
            sign[a][b_old] = sign[a_old][b_old] + 1;
            pass.push({a,b_old});
        }

        //do nuoc binh b
        if (sign[a_old][b] == 0){
            sign[a_old][b] = sign[a_old][b_old] + 1;
            pass.push({a_old,b});
        }

        //do nuoc a -> b
        if (a_old<=(b-b_old)) {
            if (sign[0][b_old + a_old] == 0) {
                sign[0][b_old + a_old] = sign[a_old][b_old] + 1;
                pass.push({0, b_old + a_old});
            }
        }
        else{
            if(sign[a_old - (b - b_old)][b] == 0){
                sign[a_old - (b - b_old)][b] = sign[a_old][b_old] + 1;
                pass.push({a_old - (b - b_old), b});
            }
        }

        //do nuoc a <- b
        if(b_old <= (a - a_old)){
            if (sign[a_old + b_old][0] == 0) {
                sign[a_old + b_old][0] = sign[a_old][b_old] + 1;
                pass.push({a_old + b_old, 0});
            }
        }
        else{
            if(sign[a][b_old - (a-a_old)] == 0){
                sign[a][b_old - (a-a_old)] = sign[a_old][b_old] + 1;
                pass.push({a,b_old - (a-a_old) });
            }
        }

        // do nuoc ra ngoai a
        if(sign[0][b_old]==0){
            sign[0][b_old] = sign[a_old][b_old] + 1;
            pass.push({0, b_old});
        }

        // do nuoc ra ngoai b
        if (sign[a_old][0] == 0){
            sign[a_old][0] = sign[a_old][b_old] + 1;
            pass.push({a_old, 0});
        }
    }

    if (pass.empty()){
        cout<<-1;
    }
}
