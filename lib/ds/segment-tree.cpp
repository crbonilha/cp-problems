
class SegmentTree {
    int size;
    vector<ll> node;

    // probably update
    ll opposite() {
        return 0;
    }

    // probably update
    ll merge(ll valA, ll valB) {
        return valA + valB;
    }

    ll init(vector<ll>& v, int idx, int l, int r) {
        if(l == r) {
            return node[idx] = l <= v.size() ? v[l-1] : opposite();
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
            return opposite();
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
        node.assign(size * 2, opposite());
    }

    void init(vector<ll>& v) {
        init(v, 1, 1, size);
    }

    void update(int pos, ll val) {
        update(1, 1, size, pos, val);
    }

    ll query(int l, int r) {
        return query(1, 1, size, l, r);
    }
};
