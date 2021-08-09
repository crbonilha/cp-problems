#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1001;

class FancyQueue {
    stack<int> sa, sb;
    stack<bitset<MAXS>> msa, msb;
public:
    void push(int v, int target) {
        sb.push(v);

        bitset<MAXS> prev = msb.empty() ? bitset<MAXS>(1) : msb.top();
        prev |= prev << v;
        for(int i=target+1; i<MAXS; i++) {
            prev[i] = false;
        }
        msb.push(prev);
    }
    bool match(int target) {
        if(sa.empty() and sb.empty()) {
            return false;
        }
        else if(sa.empty() ^ sb.empty()) {
            if(sa.empty()) {
                return msb.top()[target];
            }
            else {
                return msa.top()[target];
            }
        }
        else {
            bitset<MAXS> a = msa.top(), b = msb.top();
            for(int l=0, r=target; l<r; l++, r--) {
                bool aux = a[l];
                a[l] = a[r];
                a[r] = aux;
            }
            a &= b;
            return a.any();
        }
    }
    void pop(int target) {
        if(sa.empty()) {
            while(!sb.empty()) {
                sa.push(sb.top());
                sb.pop();

                bitset<MAXS> prev = msa.empty() ? bitset<MAXS>(1) : msa.top();
                prev |= prev << sa.top();
                for(int i=target+1; i<MAXS; i++) {
                    prev[i] = false;
                }
                msa.push(prev);
                msb.pop();
            }
        }
        sa.pop();
        msa.pop();
    }
};

const int MAXN = 1e5;

int n, s;
int v[MAXN];

int main() {
    scanf("%d", &n);
    scanf("%d", &s);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    int ans = 1e9;
    FancyQueue fq = FancyQueue();
    for(int l=0, r=0; l<n; l++) {
        while(r < n and !fq.match(s)) {
            fq.push(v[r++], s);
        }

        if(fq.match(s)) {
            ans = min(ans, r-l);
        }

        fq.pop(s);
    }
    printf("%d\n", ans == 1e9 ? -1 : ans);
}
