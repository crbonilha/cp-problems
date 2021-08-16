#include <bits/stdc++.h>
using namespace std;

template <class T>
class SegmentTree {
    int size;
    vector<T> node;
    T opposite;

    T merge(T a, T b) {
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

    T update(int idx, int l, int r, int pos, T val) {
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

    T query(int idx, int l, int r, int ql, int qr) {
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
    SegmentTree(int n, vector<T>& v, T opposite) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        node.assign(size * 2, opposite);

        this -> opposite = opposite;

        init(v);
    }

    void update(int pos, T val) {
        update(1, 1, size, pos, val);
    }

    T query(int l, int r) {
        return query(1, 1, size, l, r);
    }

    int customQuery(int idx, int l, int r, int k) {
        if(node[idx].val < k) {
            return 0;
        }

        if(l == r) {
            return l;
        }

        int mid = (l+r)/2;
        int ans = customQuery(idx*2, l, mid, k);
        if(ans == 0) {
            ans = customQuery(idx*2+1, mid+1, r, k);
        }
        return ans;
    }
    int customQuery(int k) {
        return customQuery(1, 1, size, k);
    }
};

int main() {
    class Node {
    public:
        int val;

        Node operator+(const Node& other) {
            Node ans;
            ans.val = max(this -> val, other.val);
            return ans;
        }
    };

    int n, q;
    scanf("%d %d", &n, &q);
    vector<Node> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i].val);
    }

    SegmentTree<Node> st(n, v, Node());

    while(q--) {
        int a, b, c;
        scanf("%d", &a);

        if(a == 1) {
            scanf("%d %d", &b, &c);

            v[b].val = c;
            st.update(b+1, v[b]);
        }
        else {
            scanf("%d", &b);

            printf("%d\n", st.customQuery(b)-1);
        }
    }
}
