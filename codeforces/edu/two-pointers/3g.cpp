#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e6;

int n;
ll c;
char s[MAXN+1];

ll newRudeness(ll a, ll b, ll prev, char c) {
    if(c == 'a') {
        return prev;
    }
    else if(c == 'b') {
        return prev + a;
    }
    return prev;
}

int main() {
    scanf("%d %lld", &n, &c);
    scanf("%s", s);

    int ans = 0;
    ll a = 0, b = 0;
    ll rudeness = 0;
    for(int l=0, r=0; l<n; l++) {
        a = max(a, ll(0));
        b = max(b, ll(0));
        rudeness = max(rudeness, ll(0));
        r = max(r, l);

        while(r < n and newRudeness(a, b, rudeness, s[r]) <= c) {
            if(s[r] == 'a') {
                a++;
            }
            else if(s[r] == 'b') {
                rudeness += a;
                b++;
            }
            r++;
        }

        ans = max(ans, r-l);

        if(s[l] == 'a') {
            rudeness -= b;
            a--;
        }
        else if(s[l] == 'b') {
            b--;
        }
    }
    printf("%d\n", ans);
}
