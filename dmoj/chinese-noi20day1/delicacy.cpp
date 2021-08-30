#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

const int MAXN = 50;
const int MAXT = 52501;

int n, m, t, k;
ll c[MAXN];

vector<ii> adj[MAXN+1];

ll dp[MAXN+1][MAXT+1];

int main() {
    scanf("%d %d %d %d", &n, &m, &t, &k);
    for(int i=0; i<n; i++) {
        scanf("%lld", &c[i]);
    }

    if(k) {
        return 0;
    }

    while(m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u].push_back({v, w});
    }

    dp[1][0] = c[0];
    for(int ti=0; ti<t; ti++) {
        for(int i=1; i<=n; i++) {
            if(dp[i][ti]) {
                for(ii aux: adj[i]) {
                    int v = aux.first;
                    int tj = aux.second;

                    if(ti+tj <= t) {
                        dp[v][ti+tj] = max(
                            dp[v][ti+tj],
                            dp[i][ti] + c[v-1]
                        );
                    }
                }
            }
        }
    }
    printf("%lld\n", dp[1][t] ? dp[1][t] : -1);
}
