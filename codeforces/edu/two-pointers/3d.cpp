#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 1e5;

int n[4];
int v[4][MAXN];

ii a[MAXN*4];

int main() {
    for(int i=0; i<4; i++) {
        scanf("%d", &n[i]);
        for(int j=0; j<n[i]; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    int idx = 0;
    for(int i=0; i<4; i++) {
        for(int j=0; j<n[i]; j++) {
            a[idx++] = {v[i][j], i};
        }
    }

    sort(a, a+idx);

    int c[4] = {0, 0, 0, 0};
    int ans[4], last[4], diff = 1e9;
    for(int l=0, r=0; l<idx; l++) {
        while(r < idx and (!c[0] or !c[1] or !c[2] or !c[3])) {
            last[ a[r].second ] = a[r].first;
            c[ a[r++].second ]++;
        }

        if(c[0] and c[1] and c[2] and c[3]) {
            if(a[r-1].first - a[l].first < diff) {
                diff = a[r-1].first - a[l].first;
                for(int i=0; i<4; i++) {
                    ans[i] = last[i];
                }
            }
        }

        c[ a[l].second ]--;
    }
    printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
}
