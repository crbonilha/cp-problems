#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int n;
char s[MAXN+1];
int k;
vector<int> adj[26];

int dist[26][26];

int solve() {
    for(int i=0; i<26; i++) {
        adj[i].clear();
    }

    scanf("%s", s);
    n = strlen(s);

    scanf("%d", &k);
    while(k--) {
        char aux[4];
        scanf("%s", aux);

        adj[ aux[0]-'A' ].push_back(aux[1]-'A');
    }

    memset(dist, 0x3f, sizeof(dist));
    for(int i=0; i<26; i++) {
        queue<int> q;
        
        dist[i][i] = 0;
        q.push(i);

        while(!q.empty()) {
            int u = q.front(); q.pop();

            for(int v: adj[u]) {
                if(dist[i][v] > dist[i][u]+1) {
                    dist[i][v] = dist[i][u]+1;
                    q.push(v);
                }
            }
        }
    }

    int ans = 1e9;
    for(int target=0; target<26; target++) {
        int cand = 0;
        bool valid = true;
        for(int i=0; i<n; i++) {
            if(dist[ s[i]-'A' ][target] >= 0x3f) {
                valid = false;
            }
            else {
                cand += dist[ s[i]-'A' ][target];
            }
        }
        if(valid) {
            ans = min(ans, cand);
        }
    }
    return ans == 1e9 ? -1 : ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++) {
        printf("Case #%d: %d\n", tt, solve());
    }
}
