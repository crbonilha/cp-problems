#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 8e5;

int n;
vector<int> adj[MAXN+1];
int f[MAXN+1];
unordered_map<int, vector<int>> um;
unordered_map<int, int> points;

int maxHeight;
int height[MAXN+1];
int parent[MAXN+1];
void dfs(int u, int p, int h) {
    parent[u] = p;
    height[u] = h;
    maxHeight = max(maxHeight, h);

    for(int v: adj[u]) {
        if(v == p) {
            continue;
        }

        dfs(v, u, h+1);
    }
}

int sparent[MAXN+1];
int step;
void dfs2(int u, int p, int sp) {
    sparent[u] = sp;
    if(height[u]%step == 0) {
        sp = u;
    }

    for(int v: adj[u]) {
        if(v == p) {
            continue;
        }

        dfs2(v, u, sp);
    }
}

int findLca(int u, int v) {
    while(sparent[u] != sparent[v]) {
        if(height[u] >= height[v]) {
            u = sparent[u];
        }
        else {
            v = sparent[v];
        }
    }
    while(u != v) {
        if(height[u] >= height[v]) {
            u = parent[u];
        }
        else {
            v = parent[v];
        }
    }
    return u;
}

int ans;
int dp[MAXN+1];
int blocked(int u) {
    for(int v: adj[u]) {
        if(parent[u] == v) {
            continue;
        }

        points[u] += blocked(v);
    }

    // printf("%d points = %d\n", u, points[u]);
    if(!points[u]) {
        ans++;
    }

    return points[u];
}

int solve() {
    scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &f[i]);
    }

    maxHeight = 0;
    dfs(1, 1, 0);
    step = int(sqrt(maxHeight));
    dfs2(1, 1, 1);
    for(int i=1; i<=n; i++) {
        um[ f[i] ].push_back(i);
    }

    for(auto it: um) { // improve
        if(it.second.size() <= 1) {
            continue;
        }

        int lca = it.second[0];
        for(int i=1; i<it.second.size(); i++) {
            lca = findLca(lca, it.second[i]);
        }

        for(int i=0; i<it.second.size(); i++) {
            points[ it.second[i] ]++;
        }
        points[ lca ] -= it.second.size();
    }

    ans = -1;
    blocked(1);

    // clean
    for(int i=1; i<=n; i++) {
        adj[i].clear();
    }
    um.clear();
    points.clear();

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++) {
        printf("Case #%d: %d\n", tt, solve());
    }
}
