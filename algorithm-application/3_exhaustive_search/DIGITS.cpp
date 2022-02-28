#include<bits/stdc++.h>
using namespace std;

int n;
int a[10];
bool visited[10];
long long sum;
int check;
void Try(int x){
    for(int i = 1; i<=9;i++){
        if (!visited[i]){
            a[x] = i;
            visited[i] = true;

            if (x == 7){
                sum=a[1]*100 + a[2]*10+2*a[3] - a[4]*100 + a[5]*1000+a[6]*100+a[7]*10 - 62;
                if (sum == n) check ++;
                sum = 0;
            }
            else{
                Try(x+1);
            }
            visited[i] = false;
        }
    }
}

int main(){
    cin>>n;
    Try(1);
    cout<< check;
}

