#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 50;

int n, m;
int a, b;

bool possible;
int ans[MAXN][MAXN];

void solve() {
    scanf("%d %d %d %d", &n, &m, &a, &b);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans[i][j] = 1000;
        }
    }
    for(int i=0; i<n; i++) {
        ans[i][m-1] = 1;
    }
    for(int j=0; j<m; j++) {
        ans[0][j] = ans[n-1][j] = 1;
    }
    ans[0][0] = a - (n + (m-2));
    ans[n-1][0] = b - (n + (m-2));

    possible = true;
    if(ans[0][0] <= 0 or ans[n-1][0] <= 0 or ans[0][0] > 1000 or ans[n-1][0] > 1000) {
        possible = false;
    }

    printf("%s\n", possible ? "Possible" : "Impossible");
    if(possible) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                printf("%d%c", ans[i][j], " \n"[j+1 == m]);
            }
        }
    }
}

int main() {
    int t, tt=1;
    scanf("%d", &t);
    while(t--) {
        printf("Case #%d: ", tt++);
        solve();
    }
}
