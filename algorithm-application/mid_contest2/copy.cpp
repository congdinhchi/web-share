#include <bits/stdc++.h>
using namespace std;

long long sol[105][105];
int r, s;
string c[105][105];

void input(){
    cin >> r >> s;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= s; j++){
            cin >> c[i][j];
            sol[i][j] = 0;
        }
}

long long calc(string x, int i, int j){
    if (sol[i][j] != 0)
        return sol[i][j];
    long long ans = 0;
    if (x[0] != '='){
        long long ans = 0;
        for (int i = 0; i < x.length(); i++){
            ans = ans * 10 + (x[i] - '0');
        }
        sol[i][j] = ans % 2147483648;
    }
    else{
        sol[i][j] = calc(c[x[2] - '0'][x[1] - 'A' + 1], x[2] - '0', x[1] - 'A' + 1);
    }
    return sol[i][j];
}

int main()
{
    input();
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= s; j++)
            if (sol[i][j] == 0){
                sol[i][j] = calc(c[i][j], i, j);
            }
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= s; j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}
