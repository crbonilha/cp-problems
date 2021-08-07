#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5;

int n, k;
int v[MAXN];

int c[MAXN+1];

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    if(k == 0) {
        printf("%d\n", 0);
        return 0;
    }

    ll ans = 0;
    int unique = 0;
    for(int l=0, r=0; l<n; l++) {
        while(r < n and unique + (c[ v[r] ] ? 0 : 1) <= k) {
            unique += (c[ v[r++] ]++ ? 0 : 1);
        }

        ans += r-l;

        unique -= (c[ v[l] ]-- == 1 ? 1 : 0);
    }
    printf("%lld\n", ans);
}
