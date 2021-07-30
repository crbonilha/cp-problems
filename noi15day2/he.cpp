#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const int MAXN = 1e5;
const int MAXK = 9;
const ll MAXW = 1e11;

int n, k;
ll w[MAXN];

vector<int> adj[MAXN*10];
int nxtNode;

ll encodeLength, maxHeight;
void dfs(int u, ll curHeight) {
    maxHeight = max(maxHeight, curHeight);
    
    if(adj[u].empty()) {
        encodeLength += w[u] * curHeight;
    }
    else {
        for(int v: adj[u]) {
            dfs(v, curHeight+1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%lld", &w[i]);
    }

    nxtNode = n;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for(int i=0; i<n; i++) {
        pq.push({w[i], i});
    }

    while(pq.size() > 1) {
        ll sum = 0;
        for(int i=0; i<k and !pq.empty(); i++) {
            ii f = pq.top(); pq.pop();

            adj[nxtNode].push_back(f.second);
            sum += f.first;
        }

        pq.push({sum, nxtNode++});
    }

    dfs(nxtNode-1, 0);
    printf("%lld\n%lld\n", encodeLength, maxHeight);
}
