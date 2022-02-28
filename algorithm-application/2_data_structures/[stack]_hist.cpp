//
// Created by DINH CHI CONG on 10/4/2021.
//
#include<bits/stdc++.h>
using namespace std;

long long max_retangular(long long number_retangular){

    // input
    long long retangular[number_retangular];
    for (int i=0; i< number_retangular;i++){
        cin>>retangular[i];
        getchar();
    }

    // tim max
    long long tmp=0,s_hcn =0;
    long long maxs=0;
    stack<long long> max_left;
    max_left.push(0);
    for (int i=1; i< number_retangular;i++){

        // them phan tu be hon vao
        while (retangular[i] < retangular[max_left.top()]) {
            tmp = max_left.top();
            max_left.pop();
            if (!max_left.empty()){
                s_hcn = (i-1 - max_left.top()) * retangular[tmp];
                if (s_hcn > maxs) maxs = s_hcn;
            }
            else{
                s_hcn = i*retangular[tmp];
                if (s_hcn > maxs) maxs = s_hcn;
                break;
            }
        }
        // them phan tu lon hon bang
        if (!max_left.empty()){
            if (retangular[i] == retangular[max_left.top()]){
                max_left.pop();
            }
        }
        max_left.push(i);

    }

    // Lay gia tri con thua
    while (!max_left.empty()){
        tmp = max_left.top();
        max_left.pop();
        if(max_left.empty()){
            s_hcn =number_retangular*retangular[tmp];
        }
        else{
            s_hcn =(number_retangular-1 -max_left.top())*retangular[tmp];
        }
        if (s_hcn > maxs) maxs = s_hcn;
    }

    return maxs;
}


int main(){
    // Nhap gia tri n ban dau
    long long number_retangular;
    cin>>number_retangular;
    getchar();

    long long x=0;
    while(number_retangular!=0) {
        cout<<max_retangular(number_retangular)<<endl;
        cin >> number_retangular;
        getchar();
    }

    return 0;
}


