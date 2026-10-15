#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 5;
vector<ll> seg(4 * MAXN); // Segment Tree
vector<ll> arr;

// Xây cây Segment Tree
void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

// Cập nhật giá trị tại vị trí pos thành val
void update(int id, int l, int r, int pos, ll val) {
    if (l == r) {
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(id * 2, l, mid, pos, val);
    else
        update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

// Truy vấn tổng từ u đến v
ll query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0; // Ngoài phạm vi
    if (u <= l && r <= v) return seg[id]; // Nằm trong đoạn cần truy vấn
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    build(1, 0, n - 1); // Xây cây từ mảng

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k;
            ll u;
            cin >> k >> u;
            k--; // Chuyển về 0-based
            update(1, 0, n - 1, k, u);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            a--; b--; // Chuyển về 0-based
            cout << query(1, 0, n - 1, a, b) << '\n';
        }
    }

    return 0;
}
