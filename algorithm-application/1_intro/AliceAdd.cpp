/* Cấp độ
 * 1: dùng int
 * 2: dùng unsign long long
 * 3: dùng thuật toán như bên dưới
 */


#include<bits/stdc++.h>
using namespace std;
int p[30];
int main(){
    unsigned long long a, b, save, k=0,i=0;
    cin>>a>>b;
    while (a>0&&b>0){
        save=a%10+b%10+k;
        p[i++]=save%10;
        if (save>=10){
            k=1;
        }
        else{
            k=0;
        }
        a=a/10;
        b=b/10;
    }
    if (max(a,b)+k>0) cout<<max(a,b)+k;
    for (int j=i-1;j>=0;j--){
        cout<<p[j];
    }
}
