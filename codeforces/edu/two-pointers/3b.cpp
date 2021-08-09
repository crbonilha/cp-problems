#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5;

int n;
ll s;
int v[MAXN];

int main() {
    scanf("%d", &n);
    scanf("%lld", &s);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    ll ans = 0;
    ll cur = 0;
    for(int l=0, r=0; l<n; l++) {
        cur = max(cur, ll(0));
        r = max(l, r);
        while(r < n and cur+v[r] <= s) {
            cur += v[r++];
        }

        ll len = r-l;
        ans += len*(len+1)/2;

        cur -= v[l];
    }
    printf("%lld\n", ans);
}
