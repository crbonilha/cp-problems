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

    int ans = 1e9;
    ll cur = 0;
    for(int l=0, r=0; l<n; l++) {
        while(r < n and cur < s) {
            cur += v[r++];
        }

        if(cur >= s) {
            ans = min(ans, r-l);
        }

        cur -= v[l];
    }
    printf("%d\n", ans == 1e9 ? -1 : ans);
}
