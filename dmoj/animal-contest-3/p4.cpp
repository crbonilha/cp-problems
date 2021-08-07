#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 5e5;

int n, m;
int row[MAXN+1];
int col[MAXN+1];

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &row[i]);
    }
    for(int i=1; i<=m; i++) {
        scanf("%d", &col[i]);
    }

    multiset<ii> ms;
    for(int i=1; i<=m; i++) {
        if(col[i] == -1) {
            continue;
        }
        ms.insert({col[i]-(i-1), i});
    }

    ll ans = 0;
    for(int i=1; i<=n; i++) {
        if(row[i] == -1) {
            continue;
        }

        int target = row[i]-(i-1);
        multiset<ii>::iterator it = ms.lower_bound({target, 0});
        if(it == ms.end()) {
            continue;
        }

        if((*it).first == target) {
            ans++;
            ms.erase(it);
        }
    }
    printf("%lld\n", ans);
}
