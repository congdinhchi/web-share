#include<bits/stdc++.h>
using namespace std;
string sKey[10] ={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"," "};
long long Dem(string sWord2){
    long long tmp =0;
    for (char c : sWord2){
            // Bat dau tim trong sKey
            for (long long k=0;k<9;k++){
                // Tim kiem tung phim
                for (long long q=0;q<sKey[k].length();q++){
                    if (c== sKey[k].at(q)){
                        tmp=tmp+q+1;
                        break;
                    }
                }
            }
        }
    return tmp;
}
int main(){
    string sWord;
    long long T;
    cin>>T;
    fflush(stdin);
    long long sum[T];
    for (long long i=1;i<=T; i++){
        getline (cin, sWord);
        // Bat dau xet tung ky tu
        sum[i]= Dem(sWord);
    }
    for (long long i=1;i<=T; i++) cout<<"Case #"<<i<<": "<<sum[i]<<endl;
}
