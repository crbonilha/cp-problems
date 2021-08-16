#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree {
    int size;
    vector<ll> node;

    ll merge(ll valA, ll valB) {
        return valA + valB;
    }

    ll init(vector<ll>& v, int idx, int l, int r) {
        if(l == r) {
            return node[idx] = l <= v.size() ? v[l-1] : 0;
        }

        int mid = (l+r)/2;
        return node[idx] = merge(
            init(v, idx*2, l, mid),
            init(v, idx*2+1, mid+1, r)
        );
    }

    ll update(int idx, int l, int r, int pos, ll val) {
        if(pos < l or pos > r) {
            return node[idx];
        }

        if(pos == l and pos == r) {
            return node[idx] = val;
        }

        int mid = (l+r)/2;
        return node[idx] = merge(
            update(idx*2, l, mid, pos, val),
            update(idx*2+1, mid+1, r, pos, val)
        );
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        if(ql > r or qr < l) {
            return 0;
        }

        if(ql <= l and r <= qr) {
            return node[idx];
        }

        int mid = (l+r)/2;
        return merge(
            query(idx*2, l, mid, ql, qr),
            query(idx*2+1, mid+1, r, ql, qr)
        );
    }
public:
    SegmentTree(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        node.assign(size * 2, 0);
    }

    void init(vector<ll>& v) {
        init(v, 1, 1, size);
    }

    ll update(int pos, ll val) {
        update(1, 1, size, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 1, size, l, r);
    }
};

int n, q;
vector<ll> v;

int main() {
    scanf("%d %d", &n, &q);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }
    SegmentTree st = SegmentTree(n);
    st.init(v);

    while(q--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if(a == 1) {
            st.update(b+1, c);
        }
        else {
            printf("%lld\n", st.query(b+1, c));
        }
    }
}
