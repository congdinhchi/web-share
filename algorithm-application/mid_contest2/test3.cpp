#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000005;

long long ans;
int n;
long long reult[MAX];
struct conf{
    int s, f, w;
};
conf ph[1000005];
bool check(conf x, conf y){
    return x.f < y.f;
}

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> ph[i].s >> ph[i].f >> ph[i].w;
    }
    sort(ph, ph + n, check);
}

long long solution(){
    for (int i = 1; i < n; i++){
        reult[i] = ph[i].w;
        for (int j =0; j < i; j++) {
            if (ph[i].s > ph[j].f) {
                reult[i] = max(reult[i], reult[j] + ph[i].w);
            }
        }
        ans = max(ans, reult[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    input();
    reult[0] = ph[0].w;
    ans = ph[0].w;

    cout << solution();
}