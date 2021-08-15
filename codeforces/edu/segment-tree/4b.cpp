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
};

int main() {
    class Node {
    public:
        int a, b, c, d, r;
        Node() {}
        Node(int a, int b, int c, int d, int r) {
            this -> a = a % r;
            this -> b = b % r;
            this -> c = c % r;
            this -> d = d % r;
            this -> r = r;
        }
        Node operator+(Node other) {
            return Node(
                this -> a * other.a + this -> b * other.c,
                this -> a * other.b + this -> b * other.d,
                this -> c * other.a + this -> d * other.c,
                this -> c * other.b + this -> d * other.d,
                r
            );
        }
    };

    int r, n, q;
    scanf("%d %d %d", &r, &n, &q);

    vector<Node> v(n);
    for(int i=0; i<n; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        v[i] = Node(a, b, c, d, r);
    }

    SegmentTree<Node> st(n, v, Node(1, 0, 0, 1, r));

    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);

        Node ans = st.query(l, r);
        printf("%d %d\n%d %d\n\n", ans.a, ans.b, ans.c, ans.d);
    }
}
