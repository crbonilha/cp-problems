#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 5000;

int n, m, k;
int d[MAXN];

vector<vector<int>> tc() {
    vector<vector<int>> ans;

    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &d[i]);
    }

    for(int i=0; i<n; i++) {
        if(d[i] == k) {
            ans.push_back({i+1, k});
        }
    }

    set<ii> s;
    for(int i=0; i<n; i++) {
        if(d[i] != k) {
            s.insert({d[i], i+1});
        }
    }

    while(!s.empty()) {
        set<ii>::iterator eq = s.lower_bound({k, -1});
        if(eq != s.end() and eq -> first == k) {
            ans.push_back({eq -> second, k});
            s.erase(eq);
            continue;
        }

        set<ii>::iterator le = s.begin();
        if(le -> first > k) {
            ans.push_back({le -> second, k});
            s.insert({le -> first - k, le -> second});
            s.erase(le);
            continue;
        }

        set<ii>::iterator mo = s.end();
        mo--;
        if(le -> first + mo -> first < k) {
            printf("wrong\n");
            return ans;
        }

        ans.push_back({le -> second, le -> first, mo -> second, k - le -> first});
        int rem = mo -> first - (k - le -> first);
        if(rem) {
            s.insert({rem, mo -> second});
        }
        s.erase(le);
        s.erase(mo);
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        vector<vector<int>> ans = tc();
        if(ans.empty()) {
            printf("%d\n", -1);
        }
        else {
            for(vector<int> ans: ans) {
                for(int i=0; i<ans.size(); i++) {
                    printf("%d%c", ans[i], " \n"[i+1 == ans.size()]);
                }
            }
        }
    }
}
