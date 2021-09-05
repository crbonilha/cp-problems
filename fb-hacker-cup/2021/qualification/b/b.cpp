#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 50;

int n;
char grid[MAXN][MAXN+1];

ii solve() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", grid[i]);
    }

    set<vector<ii>> solutions;
    for(int i=0; i<n; i++) {
        bool valid = true;
        vector<ii> cand;
        for(int j=0; j<n; j++) {
            if(grid[i][j] == '.') {
                cand.push_back({i, j});
            }
            else if(grid[i][j] == 'O') {
                valid = false;
                break;
            }
        }

        if(!valid) {
            continue;
        }

        if(!solutions.empty() and (*solutions.begin()).size() > cand.size()) {
            solutions.clear();
        }
        if(solutions.empty() or (*solutions.begin()).size() == cand.size()) {
            solutions.insert(cand);
        }
    }
    for(int i=0; i<n; i++) {
        bool valid = true;
        vector<ii> cand;
        for(int j=0; j<n; j++) {
            if(grid[j][i] == '.') {
                cand.push_back({j, i});
            }
            else if(grid[j][i] == 'O') {
                valid = false;
                break;
            }
        }

        if(!valid) {
            continue;
        }

        if(!solutions.empty() and (*solutions.begin()).size() > cand.size()) {
            solutions.clear();
        }
        if(solutions.empty() or (*solutions.begin()).size() == cand.size()) {
            solutions.insert(cand);
        }
    }

    if(solutions.empty()) {
        return {-1, -1};
    }
    else {
        return {(*solutions.begin()).size(), solutions.size()};
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++) {
        ii ans = solve();
        if(ans.first == -1) {
            printf("Case #%d: Impossible\n", tt);
        }
        else {
            printf("Case #%d: %d %d\n", tt, ans.first, ans.second);
        }
    }
}
