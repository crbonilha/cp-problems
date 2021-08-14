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
        int val;

        Node() {}
        Node(int v) {
            this -> val = v;
        }

        Node operator+(const Node& other) {
            return Node(this -> val + other.val);
        }
    };

    int n;
    scanf("%d", &n);
    vector<Node> v(n, Node(1));

    SegmentTree<Node> st(n, v, Node(0));

    vector<int> in(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &in[i]);
    }

    vector<int> ans(n);
    for(int i=n-1; i>=0; i--) {
        int ini=1, mid, fim=n+1;
        while(ini < fim) {
            mid = (ini+fim)/2;

            int cand = st.query(mid+1, n).val;
            if(cand <= in[i]) {
                ans[i] = mid;
                fim = mid;
            }
            else {
                ini = mid+1;
            }
        }

        st.update(ans[i], Node(0));
    }

    for(int i=0; i<n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
