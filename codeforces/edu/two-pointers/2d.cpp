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
        while(r<n and cur+v[r]<s) {
            cur += v[r++];
        }

        ans += n-r;

        if(r > l) {
            cur -= v[l];
        }
        else {
            r++;
        }
    }
    printf("%lld\n", ans);
}
