#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;

int n, k;
int ore[MAXN];
vector<int> adj[MAXN];
vector<int> children[MAXN];

int dpAux[MAXN+1][MAXN];

int dp[MAXN][MAXN];
int solve(int u, int p, int k) {
    int& ans = dp[u][k];
    if(ans != -1) return ans;

    if(children[u].empty()) {
        return ans = ore[u];
    }
    else if(children[u].size() == 1) {
        return ans = ore[u] + solve(children[u][0], u, k);
    }

    for(int v: children[u]) {
        for(int i=0; i<=k; i++) {
            solve(v, u, i);
        }
    }

    for(int j=children[u].size(); j>=0; j--) {
        for(int i=0; i<=k; i++) {
            if(j == children[u].size()) {
                dpAux[j][i] = 0;
            }
            else {
                dpAux[j][i] = max(
                    i ? dpAux[j][i-1] : 0,
                    dp[ children[u][j] ][i] + dpAux[j+1][k-i]
                );
            }
        }
    }
    return ans = dpAux[0][k] + ore[u];
}

void dfs(int u, int p) {
    for(int v: adj[u]) {
        if(v == p) {
            continue;
        }

        children[u].push_back(v);
        dfs(v, u);
    }
}

int solve() {
    for(int i=0; i<MAXN; i++) {
        adj[i].clear();
        children[i].clear();
    }

    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &ore[i]);
    }
    for(int i=0; i<n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);

    if(k == 0) {
        return ore[0];
    }

    memset(dp, -1, sizeof(dp));
    return solve(0, 0, k-1);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++) {
        printf("Case #%d: %d\n", tt, solve());
    }
}
