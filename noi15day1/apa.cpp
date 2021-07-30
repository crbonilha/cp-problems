#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 1e5;
const int MAXV = 1e9;

int n;

unordered_map<int, int> us;
int getUnionSet(int u) {
    if(!us.count(u)) {
        return us[u] = u;
    }

    if(us[u] == u) {
        return u;
    }
    return us[u] = getUnionSet(us[u]);
}

bool tc() {
    us.clear();

    vector<ii> diffs;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a, b, e;
        scanf("%d %d %d", &a, &b, &e);

        if(e) {
            us[ getUnionSet(a) ] = getUnionSet(b);
        }
        else {
            diffs.push_back({a, b});
        }
    }

    for(ii diff: diffs) {
        if(getUnionSet(diff.first) == getUnionSet(diff.second)) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        printf("%s\n", tc() ? "YES" : "NO");
    }
}
