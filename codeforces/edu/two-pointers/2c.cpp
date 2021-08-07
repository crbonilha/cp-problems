#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5;

int n;
ll s;

ll v[MAXN];

int main() {
    scanf("%d %lld", &n, &s);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }

    ll ans = 0;
    ll cur = 0;
    for(int l=0, r=0; l<n; l++) {
        r = max(r, l);
        cur = max(cur, ll(0));
        while(r < n and cur+v[r] <= s) {
            cur += v[r++];
        }

        ans += r-l;

        cur -= v[l];
    }
    printf("%lld\n", ans);
}
