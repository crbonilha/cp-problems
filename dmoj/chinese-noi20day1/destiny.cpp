#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 10;

int n, q;
vector<ii> adj[MAXN+1];
ii cond[MAXN];

bool visi[MAXN+1];
int dfs(int u, int p, int target, int mask) {
    if(u == target) {
        return 1;
    }
    visi[u] = true;

    int ans = 0;
    for(ii aux: adj[u]) {
        int v = aux.first;
        int e = aux.second;

        if(v == p) {
            continue;
        }
        if(visi[v]) {
            continue;
        }

        int cand = dfs(v, u, target, mask);
        if(cand >= 1) {
            ans = cand;

            if(mask & (1 << e)) {
                ans = 2;
            }
        }
    }

    visi[u] = false;
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        scanf("%d %d", &cond[i].first, &cond[i].second);
    }

    int ans = 0;
    for(int mask=0; mask<(1 << (n-1)); mask++) {
        bool valid = true;

        for(int i=0; i<q; i++) {
            if(dfs(cond[i].first, cond[i].first, cond[i].second, mask) <= 1) {
                valid = false;
                break;
            }
        }

        if(valid) {
            ans++;
        }
    }
    printf("%d\n", ans);
}
