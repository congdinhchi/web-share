//
// Created by DINH CHI CONG on 11/28/2021.
//

#include<bits/stdc++.h>
using namespace std;

long long n, k1, k2;
void input(){
    cin>>n;
    cin>>k1>>k2;
}

bool save_solution[1001][2];
long long n_solution[1001][2];
long long solution(long long x, int work){

    //diem dung
    if (x<0) return 0;
    if (x==0) return 1;

    // tinh toan
    if (!save_solution[x][work]) {
        save_solution[x][work] = true;
        // neu day la ngay nghi
        if (work == 0) {
            n_solution[x][work] += solution(x - 1, 1);
        }
        //neu day la ngay lam viec
        else {
            for (int i = k1; i <= k2; i++) {
                n_solution[x][work] += solution(x - i, 0);
            }
        }
    }

    return n_solution[x][work];
}

int main(){
    input();
    cout<<solution(n,true) + solution(n, false) ;
}
