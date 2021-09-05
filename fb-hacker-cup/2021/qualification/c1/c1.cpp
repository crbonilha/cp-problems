#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;

int n;
int ore[MAXN];
vector<int> adj[MAXN];

int dp[MAXN];
int dfs(int u, int p) {
    int ans = 0;
    for(int v: adj[u]) {
        if(v == p) {
            continue;
        }

        int cand = dfs(v, u);
        ans = max(ans, cand);
    }
    return dp[u] = ore[u] + ans;
}

int solve() {
    for(int i=0; i<MAXN; i++) {
        adj[i].clear();
    }

    scanf("%d", &n);
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

    if(adj[0].size() <= 1) {
        return dp[0];
    }
    else {
        vector<int> cand;
        for(int v: adj[0]) {
            cand.push_back(dp[v]);
        }
        sort(cand.begin(), cand.end(), greater<int>());
        return cand[0] + cand[1] + ore[0];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++) {
        printf("Case #%d: %d\n", tt, solve());
    }
}
