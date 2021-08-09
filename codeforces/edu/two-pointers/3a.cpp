#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e3;

int n;
ll p;
ll v[MAXN*2];

int main() {
    scanf("%d", &n);
    scanf("%lld", &p);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
        v[i+n] = v[i];
    }

    ll sum = 0;
    for(int i=0; i<n; i++) {
        sum += v[i];
    }

    ll extra = 0;
    if(p >= sum) {
        extra = p/sum*n;
        p %= sum;
    }

    int start = -1, ans = 1e9;
    ll cur = 0;
    for(int l=0, r=0; l<n*2; l++) {
        while(r < n*2 and cur < p) {
            cur += v[r++];
        }

        if(cur >= p) {
            int cand = r-l;
            if(cand < ans) {
                ans = cand;
                start = l+1;
            }
        }

        cur -= v[l];
    }

    printf("%d %lld\n", start, ans+extra);
}
