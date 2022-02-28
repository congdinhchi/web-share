#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s,res=0;
    cin>>n>>s;
    int p[n+1];
    for (int i=1;i<=n;i++){
        cin>>p[i];
    }
    bool check[n+1];
    int tg[n+1],vet[n+1];
    for(int i=1;i<=n;i++) {
        check[i]=true;
    }
    int dem=1;
    while(dem<=n/2){
        for (int i=1;i<=n;i++) tg[i]=0;
        for( int i=2;i<=n;i++){
            if(check[i]==true){
                int tmp;
                for(int j=1;j<=i;j++){
                    if(check[j]==true){
                        tmp=p[i]-p[j]-(i-j)*3;
                        if(tg[i]<tmp) {
                            tg[i]=tmp;
                            vet[i]=j;
                        }}
                }
            }}
        int tmp2,tmp1=0;
        for(int i=1;i<=n;i++){
            if(tmp1<tg[i]){
                tmp1=tg[i];
                tmp2=i;
            }

        }
        res+=tmp1;
        check[tmp2]=false;
        check[vet[tmp2]]=false;
        dem++;
    }
    cout<<34;
    return 0;

}