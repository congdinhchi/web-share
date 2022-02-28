// Nhánh cận

#include<bits/stdc++.h>
using namespace std;

int n,m;
int cost[21][21];
int start[21], length[21];
bool visited[21] ;
int lengthMin = INT_MAX;
int cMin = INT_MAX;

void input(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        int c;
        cin>>c;
        cost[tmp1][tmp2] = c;
        cMin = min(c,cMin);
    }
}

void Try(int x){
    for (int i=2; i<=n;i++){
        if (cost[start[x-1]][i]!=0 && !visited[i]) {

            //Tính vị trí mới có chi phí như nào
            length[x] = length[x - 1] + cost[start[x - 1]][i];
            visited[i] = true;
            start[x] = i;

            // Đi tiếp
            if (x == n) {
                if (cost[start[x]][1] != 0) {
                    length[x+1] = length [x] + cost[start[x]][1];
                    lengthMin = min(lengthMin, length[x+1]);
                }
            }
            else {
                if (length[x] + cMin * (n - x) < lengthMin) Try(x + 1);
            }

            // Thất bại rồi ,quay lại thôi
            visited[i] = false;
        }
    }
}

int main(){
    input();
    length[1] = 0;
    start[1] = 1;
    Try(2);
    cout<<lengthMin;
}