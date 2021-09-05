#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2;

int n;
char s[MAXN+1];

bool isVowel(char c) {
    return c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U';
}

int solve() {
    scanf("%s", s);
    n = strlen(s);

    int ans = 1e9;
    for(int target=0; target<26; target++) {
        int cand = 0;
        for(int i=0; i<n; i++) if(s[i] != target+'A') {
            if(isVowel(target+'A') ^ isVowel(s[i])) {
                cand++;
            }
            else {
                cand += 2;
            }
        }
        ans = min(ans, cand);
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
