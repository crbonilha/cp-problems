#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

class FancyQueue {
    stack<ll> fs, ss;
    stack<ll> maxFs, maxSs;
    stack<ll> minFs, minSs;

    void move() {
        while(!ss.empty()) {
            fs.push(ss.top());
            ss.pop();

            maxFs.push(
                max(
                    fs.top(),
                    maxFs.empty() ? -INF : maxFs.top()
                )
            );
            maxSs.pop();

            minFs.push(
                min(
                    fs.top(),
                    minFs.empty() ? INF : minFs.top()
                )
            );
            minSs.pop();
        }
    }
public:
    void push(ll v) {
        ss.push(v);

        maxSs.push(
            max(
                v,
                maxSs.empty() ? -INF : maxSs.top()
            )
        );

        minSs.push(
            min(
                v,
                minSs.empty() ? INF : minSs.top()
            )
        );
    }
    ll getMax() {
        return max(
            maxFs.empty() ? -INF : maxFs.top(),
            maxSs.empty() ? -INF : maxSs.top()
        );
    }
    ll getMin() {
        return min(
            minFs.empty() ? INF : minFs.top(),
            minSs.empty() ? INF : minSs.top()
        );
    }
    ll pop() {
        if(fs.empty()) {
            this -> move();
        }
        ll ans = fs.top();
        fs.pop();
        maxFs.pop();
        minFs.pop();
        return ans;
    }
};

const int MAXN = 1e5;

int n;
ll k;
ll v[MAXN];

int main() {
    scanf("%d %lld", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }

    ll ans = 0;
    FancyQueue fq = FancyQueue();
    for(int l=0, r=0; l<n; l++) {
        while(r < n and max(v[r], fq.getMax()) - min(v[r], fq.getMin()) <= k) {
            fq.push(v[r++]);
        }

        ans += r-l;

        fq.pop();
    }
    printf("%lld\n", ans);
}
