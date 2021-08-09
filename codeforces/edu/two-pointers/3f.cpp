#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5;

int n, m;
char s[MAXN+1], cards[MAXN+1];

int c[26];
int cur[26];

bool isEnough(int cand) {
    for(int i=0; i<26; i++) {
        if(cur[i]+(cand == i) > c[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%s", s);
    scanf("%s", cards);

    for(int i=0; i<m; i++) {
        c[ cards[i]-'a' ]++;
    }

    ll ans = 0;
    for(int l=0, r=0; l<n; l++) {
        for(int i=0; i<26; i++) {
            cur[i] = max(cur[i], 0);
        }
        r = max(r, l);

        while(r < n and isEnough(s[r]-'a')) {
            cur[ s[r++]-'a' ]++;
        }

        ans += r-l;

        cur[ s[l]-'a' ]--;
    }
    printf("%lld\n", ans);
}
