
template <class T>
class LazySegmentTree {
    int size;
    vector<T> node;
    vector<T> lazy;
    T opposite;

    T merge(T a, T b) {
        if(a == opposite and b == opposite) {
            return opposite;
        }
        else if(a == opposite) {
            return b;
        }
        else if(b == opposite) {
            return a;
        }
        return a + b;
    }

    T init(vector<T>& v, int idx, int l, int r) {
        if(l == r) {
            return node[idx] = l <= v.size() ? v[l-1] : opposite;
        }

        int mid = (l+r)/2;
        return node[idx] = merge(
            init(v, idx*2, l, mid),
            init(v, idx*2+1, mid+1, r)
        );
    }
    void init(vector<T>& v) {
        init(v, 1, 1, size);
    }

    void propagate(int idx, int l, int r) {
        if(lazy[idx] == opposite) {
            return;
        }

        node[idx] = node[idx] + lazy[idx];
        if(l < r) {
            lazy[idx*2] = lazy[idx*2] + lazy[idx];
            lazy[idx*2+1] = lazy[idx*2+1] + lazy[idx];
        }
        lazy[idx] = opposite;
    }

    T update(int idx, int l, int r, int pos, T val) {
        propagate(idx, l, r);

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

    T updateRange(int idx, int l, int r, int ql, int qr, T val) {
        propagate(idx, l, r);

        if(ql > r or qr < l) {
            return node[idx];
        }

        if(ql <= l and r <= qr) {
            lazy[idx] = val;
            propagate(idx, l, r);
            return node[idx];
        }

        int mid = (l+r)/2;
        return merge(
            updateRange(idx*2, l, mid, ql, qr, val),
            updateRange(idx*2+1, mid+1, r, ql, qr, val)
        );
    }

    T query(int idx, int l, int r, int ql, int qr) {
        propagate(idx, l, r);

        if(ql > r or qr < l) {
            return opposite;
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
    LazySegmentTree(int n, vector<T>& v, T opposite) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        node.assign(size * 2, opposite);
        lazy.assign(size * 2, opposite);

        this -> opposite = opposite;

        init(v);
    }

    void update(int pos, T val) {
        update(1, 1, size, pos, val);
    }

    void updateRange(int l, int r, T val) {
        updateRange(1, 1, size, l, r, val);
    }

    T query(int l, int r) {
        return query(1, 1, size, l, r);
    }
};
