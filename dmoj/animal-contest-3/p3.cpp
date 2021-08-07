#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e6;

int n;
int v[MAXN];

int ans[MAXN];
char anss[MAXN+1];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    sort(v, v+n);

    for(int i=0, l=0, r=n-1; l<=r; l++, r--) {
        if(l == r) {
            ans[i] = v[l];
            anss[i] = 'E';
        }
        else {
            ans[i] = v[l];
            ans[i+1] = v[r];
            anss[i] = 'B';
            anss[i+1] = 'S';
            i += 2;
        }
    }

    for(int i=0; i<n; i++) {
        printf("%d%c", ans[i], " \n"[i+1 == n]);
    }
    anss[n] = 0;
    printf("%s\n", anss);
}
