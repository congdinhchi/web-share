//
// Created by DINH CHI CONG on 10/18/2021.
//

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    long long T,tmp;
    long long L, C;
    cin>>T;
    while (T>0){

        cin>>L>>C;

        // input_1
        vector<pair<long long, long long>> img_1;
        for (long long i = 0; i<L ; i++){
            for (long long j=0; j<C;j++){
                cin>>tmp;
                if(tmp) img_1.push_back({i,j});
            }
        }

        // input_2
        vector<pair<long long, long long>> img_2;
        for (long long i = 0; i<L ; i++){
            for (long long j=0; j<C;j++){
                cin>>tmp;
                if(tmp) img_2.push_back({i,j});
            }
        }

        // find
        long long x,y;
        long long big_dot = 0;
        map<pair<long long, long long>, long long> same_dot;
        for (long long i=0; i<img_1.size(); i++){
            for(long long j=0; j<img_2.size(); j++){
                x = img_2[i].first - img_1[j].first + 1005;
                y = img_2[i].second - img_1[j].second + 1005;
                same_dot[{x, y}]++;
                big_dot = max(same_dot[{x,y}], big_dot);

            }
        }
        cout<<big_dot;
        T--;
    }
}