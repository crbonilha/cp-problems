#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n;
vector<int> adj[MAXN];
int p[MAXN];

int installed;
bool state[MAXN];

void dfs(int u) {
    if(!state[u]) {
        return;
    }
    state[u] = false;
    installed--;

    for(int v: adj[u]) {
        dfs(v);
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d", &p[i]);

        adj[ p[i] ].push_back(i);
    }

    int q;
    scanf("%d", &q);
    while(q--) {
        char query[16];
        int x;
        scanf("%s %d", query, &x);

        int before = installed;
        if(query[0] == 'i') {
            while(!state[x]) {
                state[x] = true;
                installed++;
                x = p[x];
            }
        }
        else {
            dfs(x);
        }
        int after = installed;

        printf("%d\n", abs(after - before));
    }
}
