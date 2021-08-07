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

    int ans = 0;
    ll cur = 0;
    for(int l=0, r=0; r<n; r++) {
        cur += v[r];
        while(l<=r and cur>s) {
            cur -= v[l++];
        }

        ans = max(ans, r-l+1);
    }
    printf("%d\n", ans);
}
