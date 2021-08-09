#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

const int MAXN = 1e5;

int n, s;
ii v[MAXN];

int main() {
    scanf("%d", &n);
    scanf("%d", &s);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i].first);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i].second);
    }

    ll ans = 0;
    int w = 0;
    ll cur = 0;
    for(int l=0, r=0; l<n; l++) {
        w = max(w, 0);
        cur = max(cur, ll(0));
        r = max(r, l);
        while(r < n and w+v[r].first <= s) {
            w += v[r].first;
            cur += v[r++].second;
        }

        ans = max(ans, cur);

        w -= v[l].first;
        cur -= v[l].second;
    }
    printf("%lld\n", ans);
}
