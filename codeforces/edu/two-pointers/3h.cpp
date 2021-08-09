#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5;

ll n, m, s, wa, wb;
ll a[MAXN+1], b[MAXN];

int main() {
    scanf("%lld %lld %lld %lld %lld", &n, &m, &s, &wa, &wb);
    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i=0; i<m; i++) {
        scanf("%lld", &b[i]);
    }

    a[n++] = 0;
    sort(a, a+n, greater<ll>());
    sort(b, b+m, greater<ll>());

    ll cur = 0;
    for(int i=0; i<m; i++) {
        cur += b[i];
    }

    ll ans = 0;
    for(int l=0, r=m; l<n; l++) {
        while(r > 0 and l*wa + r*wb > s) {
            cur -= b[--r];
        }

        if(l*wa + r*wb <= s) {
            ans = max(ans, cur);
        }

        cur += a[l];
    }
    printf("%lld\n", ans);
}
