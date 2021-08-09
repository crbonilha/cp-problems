#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 3e5;

int n, k;
int v[MAXN];

int main() {
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    ll ans = 0;
    for(int l=0, r=0; l<n; l++) {
        while(r < n and v[r]-v[l] <= k) {
            r++;
        }

        if(r < n) {
            int choices = n-r;
            ans += choices;
        }
    }
    printf("%lld\n", ans);
}
