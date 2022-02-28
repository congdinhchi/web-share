//
// Created by DINH CHI CONG on 12/27/2021.
//

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n,m,num[100005],low[100005], x,cnt,d[100005],dd[100005],f[100005];
long long res;

vector<int> g[100005],g2[100005];

stack<int >s;

void input(){
    cin >> n >> m;
}

int find_brigde(int u){
    int t = 1;
    for(auto v:g2[u]){
        if(!dd[v]){
            dd[v] = 1;
            t += find_brigde(v);
        }
    }
    return t;
}

void to_hop(int u,int p){
    num[u] = low[u] = ++cnt;
    s.push(u);
    for(int v:g[u]){
        if(v == p || f[v]) continue;
        if(num[v]){
            low[u] = min(low[u],num[v]);
        }else{
            to_hop(v,u);
            low[u] = min(low[u],low[v]);
        }
    }
    if(num[u] == low[u]){
        ++x;
        while(s.top() != u){
            int v = s.top();
            f[v] = x;
            s.pop();
            d[x] = 1;
        }
        f[u] = x;
        s.pop();
    }
}

int main()
{
    input();
    for(int i = 1; i <= m; ++i){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 1; i <= n; ++i){
        if(!num[i]){
            to_hop(i,i);
        }
    }

    for(int u = 1; u <= n ; ++u){
        if(d[f[u]]) continue;
        for(auto v:g[u]){
            if(f[v] != f[u]){
                g2[u].pb(v);
                g2[v].pb(u);
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        if(!dd[i]){
            dd[i] = 1;
            int t = find_brigde(i);
            if(t > 1){
                res += 1ll*(t-2)*(t-1)/2;
            }
        }
    }
    cout << res;

    return 0;
}