#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5;

int n, m;
int a[MAXN], b[MAXN];

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }

    ll ans = 0;
    for(int i=0, j=0; i<n; i++) {
        int lasti = i;
        while(lasti < n and a[i] == a[lasti]) {
            lasti++;
        }

        int countj = 0;
        while(j < m and b[j] <= a[i]) {
            countj += b[j++] == a[i];
        }

        ans += ll(lasti - i) * ll(countj);

        i = lasti-1;
    }
    printf("%lld\n", ans);
}
