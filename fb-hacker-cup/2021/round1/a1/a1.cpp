#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 8e5;

const int LH = 1, AH = 2, RH = 3;

int n;
char s[MAXN+1];

int solve() {
    scanf("%d %s", &n, s);

    int hand = AH;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 'X') {
            if(hand != LH) {
                if(hand != AH) {
                    ans++;
                }
                hand = LH;
            }
        }
        else if(s[i] == 'F') {
        }
        else {
            if(hand != RH) {
                if(hand != AH) {
                    ans++;
                }
                hand = RH;
            }
        }
    }
    return ans;
}

int main() {
    int t, tt=1;
    scanf("%d", &t);
    while(t--) {
        printf("Case #%d: %d\n", tt++, solve());
    }
}
