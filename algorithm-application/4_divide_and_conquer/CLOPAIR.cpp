#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> vt;
long long N;
double khoangcach[50001][50001];
pair<long long, long long> save[50001][50001];

void merge(long long L, long long R){
    int M;
    M=(L+R)/2;
    if (M==L || M==R){
        khoangcach[L][R] = sqrt(pow(vt[L].first - vt[R].first, 2) + pow(vt[L].second - vt[R].second, 2));
        save[L][R] = {L,R} ;
        return;
    }
    merge(L,M);
    merge(M,R);
    khoangcach[M][M+1] = sqrt(pow(vt[M].first - vt[M+1].first, 2) + pow(vt[M].second - vt[M+1].second, 2));

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    for (int i=0;i<N;i++){
        long long tmp1, tmp2;
        cin>>tmp1>>tmp2;
        vt.push_back({tmp1, tmp2});
    }
    sort(vt.begin(),vt.end());
    merge(0,N-1);
    cout<<save-1<<" "<<save<<" "<<khoangcach;
}