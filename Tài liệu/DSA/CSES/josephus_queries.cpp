#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
int seg[4*MAXN + 5];  // cây segment lưu số trẻ còn sống ở mỗi đoạn

// build: ban đầu tất cả n trẻ đều sống (1)
void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(id<<1, l, m);
    build(id<<1|1, m+1, r);
    seg[id] = seg[id<<1] + seg[id<<1|1];
}

// update: đánh dấu pos đã bị loại (0)
void update(int id, int l, int r, int pos) {
    if (l == r) {
        seg[id] = 0;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) update(id<<1, l, m, pos);
    else          update(id<<1|1, m+1, r, pos);
    seg[id] = seg[id<<1] + seg[id<<1|1];
}

// kth: tìm vị trí (1-based) của đứa trẻ thứ k còn sống trong [l..r]
int kth(int id, int l, int r, int k) {
    if (l == r) return l;
    int m = (l + r) >> 1;
    if (seg[id<<1] >= k) 
        return kth(id<<1, l, m, k);
    else 
        return kth(id<<1|1, m+1, r, k - seg[id<<1]);
}

// trả về đứa thứ k bị loại
int solve(int n, int k) {
    build(1, 1, n);
    int cur = 0;  // số thứ tự trong vòng còn sống (1-based)
    for (int i = 1; i <= k; ++i) {
        int alive = seg[1];          // số trẻ còn lại
        cur = (cur + 1) % alive;     // nhảy 1 người rồi đến người bị loại
        if (cur == 0) cur = alive;
        int pos = kth(1, 1, n, cur); // lấy vị trí thực trong [1..n]
        if (i == k) return pos;
        update(1, 1, n, pos);        // loại người đó
        // cur bây giờ đang trỏ vào vị trí vừa xóa, 
        // nhưng sau xóa, đứa kế tiếp đã "đóng" vị trí cur, nên không cần chỉnh thêm.
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}
