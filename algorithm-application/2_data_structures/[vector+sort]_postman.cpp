#include<bits/stdc++.h>
using namespace std;

// tim thoi gian
long long endTime (vector<pair<long long, long long>> custumer, long long k){
    sort(custumer.begin(), custumer.end(), greater<pair<long long, long long>>());
    long long time=0;
    long long k_du;
    long long tmp;

    // van chuyen
    for (int i= 0; i<custumer.size();i++){

        if (custumer[i].second == 0) continue;

        if (custumer[i].second % k == 0) {
            // van chuyen di + ve
            time += ((custumer[i].second/k) * custumer[i].first *2);
        }
        else{
            tmp = i+1;
            //van chuyen di
            time += ((custumer[i].second/k)+1) * custumer[i].first *2;
            k_du = k- (custumer[i].second % k);

            // van chuyen ve
            while ((k_du > 0)&&(tmp<custumer.size())){
                if (k_du>=custumer[tmp].second){
                    k_du -= custumer[tmp].second;
                    custumer[tmp].second = 0;
                    tmp++;
                }
                else{
                    custumer[tmp].second -= k_du;
                    k_du=0;
                }
            }
        }
    }
    return time;
}

int main(){

    // Input
    int n;
    long long k;
    cin>>n>>k;
    getchar();


    // Input_full
    vector<pair<long long, long long>> custumer_ne, custumer_pos ;
    long long x,m;
    for (int i=1; i<= n; i++){
        cin>>x>>m;
        if (x<0) custumer_ne.push_back({-x,m});
        else custumer_pos.push_back({x,m});
    }

    //Output
    cout<< endTime(custumer_ne, k)+endTime(custumer_pos, k);

}

