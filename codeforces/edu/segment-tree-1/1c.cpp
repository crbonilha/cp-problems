#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree {
    int size;
    vector<pair<ll, ll>> node;

    pair<ll, ll> merge(pair<ll, ll> valA, pair<ll, ll> valB) {
        if(valA.first == valB.first) {
            return {valA.first, valA.second + valB.second};
        }
        else if(valA.first < valB.first) {
            return valA;
        }
        else {
            return valB;
        }
    }

    pair<ll, ll> init(vector<ll>& v, int idx, int l, int r) {
        if(l == r) {
            return node[idx] = l <= v.size() ? pair<ll, ll>(v[l-1], 1) : pair<ll, ll>(1e9+1, 1);
        }

        int mid = (l+r)/2;
        return node[idx] = merge(
            init(v, idx*2, l, mid),
            init(v, idx*2+1, mid+1, r)
        );
    }

    pair<ll, ll> update(int idx, int l, int r, int pos, ll val) {
        if(pos < l or pos > r) {
            return node[idx];
        }

        if(pos == l and pos == r) {
            return node[idx] = {val, 1};
        }

        int mid = (l+r)/2;
        return node[idx] = merge(
            update(idx*2, l, mid, pos, val),
            update(idx*2+1, mid+1, r, pos, val)
        );
    }

    pair<ll, ll> query(int idx, int l, int r, int ql, int qr) {
        if(ql > r or qr < l) {
            return {1e9+1, 1};
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
        node.assign(size * 2, {1e9+1, 1});
    }

    void init(vector<ll>& v) {
        init(v, 1, 1, size);
    }

    void update(int pos, ll val) {
        update(1, 1, size, pos, val);
    }

    pair<ll, ll> query(int l, int r) {
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
            pair<ll, ll> ans = st.query(b+1, c);
            printf("%lld %lld\n", ans.first, ans.second);
        }
    }
}
