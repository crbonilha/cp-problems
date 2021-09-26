#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;
const int MAXM = 2e6;

int n, m;
int target;

char grid[MAXM+3];
char getPos(int r, int c) {
    if(r == -1 or r == n) {
        return '.';
    }
    return grid[r*m+c];
}

int above[MAXN];

int solve() {
    scanf("%d %d %d", &n, &m, &target);
    target--;
    for(int i=0; i<n; i++) {
        scanf("%s", grid+i*m);
    }

    int ans = 0;
    for(int j=0; j<m; j++) {
        if(getPos(target, j) == 'X') {
            ans++;
        }
    }

    memset(above, 0, sizeof(above));
    for(int i=0; i<=target; i++) {
        for(int j=0; j<m; j++) {
            above[j] += getPos(i, j) == 'X';
        }
    }
    for(int i=target+1; i<=n; i++) {
        int cand = 0;
        for(int j=0; j<m; j++) {
            cand += (getPos(i, j) == 'X') or above[j] > target;
        }

        ans = min(ans, cand + (i - target));

        for(int j=0; j<m; j++) {
            above[j] += getPos(i, j) == 'X';
        }
    }

    memset(above, 0, sizeof(above));
    for(int i=target; i<n; i++) {
        for(int j=0; j<m; j++) {
            above[j] += getPos(i, j) == 'X';
        }
    }
    for(int i=target-1; i>=-1; i--) {
        int cand = 0;
        for(int j=0; j<m; j++) {
            cand += (getPos(i, j) == 'X') or above[j] >= (n - target);
        }

        ans = min(ans, cand + (target - i));

        for(int j=0; j<m; j++) {
            above[j] += getPos(i, j) == 'X';
        }
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++) {
        printf("Case #%d: %d\n", tt, solve());
    }
}
