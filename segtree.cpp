template<typename T>
class SegTree {
public:
    SegTree(vector<int> &A)
    :   tree(4 * A.size(), 0), N(A.size())
    {
        if (N > 0) build(A, 0, 0, N - 1);
    };

    int query(int L, int R) {
        return query_(L, R, 0, N - 1, 0);
    }

    void update(int L, int R, int val) {
        update_(L, R, val, 0, N - 1, 0);
    }
private:
    int N;
    vector<T> tree;

    T build(vector<int> &A, int i, int L, int R) {
        if (L == R) {
            tree[i] = A[L];
            return A[L];
        }

        int mid = (L + R) / 2;

        tree[2*i + 1] = build(A, 2*i + 1, L, mid);
        tree[2*i + 2] = build(A, 2*i + 2, mid + 1, R);

        tree[i] = merge(tree[2*i + 1], tree[2*i + 2]);

        return tree[i];
    }

    void update_(int L_upd, int R_upd, const T &val, int L, int R, int i) {
        if (L_upd == L && R_upd == R) {
            tree[i] = val;
            return;
        }

        int mid = (L + R) / 2;

        if (L_upd <= mid && R_upd <= mid) {
            update_(L_upd, R_upd, val, L, mid, 2*i + 1);
        } else if (L_upd > mid && R_upd > mid) {
            update_(L_upd, R_upd, val, mid + 1, R, 2*i + 2);
        } else {
            update_(L_upd, mid, val, L, mid, 2*i + 1);
            update_(mid + 1, R_upd, val, mid + 1, R, 2*i + 2);
        }

        tree[i] = merge(tree[2*i + 1], tree[2*i + 2]);
    }

    T query_(int L, int R, int l, int r, int i) {
        if (L == l && R == r) {
            return tree[i];
        }

        int mid = (l + r) / 2;

        if (L <= mid && R <= mid) {
            return query_(L, R, l, mid, 2*i + 1);
        } else if (L > mid && R > mid) {
            return query_(L, R, mid + 1, r, 2*i + 2);
        } else {
            return merge(query_(L, mid, l, mid, 2*i + 1), query_(mid + 1, R, mid + 1, r, 2*i + 2));
        }
    }

    T merge(const T &leftRes, const T &rightRes) {
        return leftRes + rightRes;
    }
};
