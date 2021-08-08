#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class FancyQueue {
    stack<ll> sa, sb;
    stack<ll> ga, gb;
public:
    void push(ll v) {
        sb.push(v);
        gb.push(__gcd(gb.empty() ? 0 : gb.top(), v));
    }
    ll top() {
        return __gcd(
            ga.empty() ? 0 : ga.top(),
            gb.empty() ? 0 : gb.top()
        );
    }
    void pop() {
        if(sa.empty()) {
            while(!sb.empty()) {
                sa.push(sb.top());
                sb.pop();

                ga.push(__gcd(ga.empty() ? 0 : ga.top(), sa.top()));
                gb.pop();
            }
        }
        sa.pop();
        ga.pop();
    }
};

const int MAXN = 1e5;

int n;
ll v[MAXN];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }

    int ans = 1e9;
    FancyQueue fq = FancyQueue();
    for(int l=0, r=0; l<n; l++) {
        while(r < n and fq.top() != 1) {
            fq.push(v[r++]);
        }

        if(fq.top() == 1) {
            ans = min(ans, r-l);
        }

        fq.pop();
    }
    printf("%d\n", ans == 1e9 ? -1 : ans);
}
