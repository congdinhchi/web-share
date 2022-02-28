
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    int P, N, R;
    cin >> P >> N >> R;
    long long sum = N;
    int cnt = 0;

    do{
        sum = sum + N * R;
        N = N * R;
        cnt ++;
    } while(sum <= P);

    cout << cnt;
    return 0;
}