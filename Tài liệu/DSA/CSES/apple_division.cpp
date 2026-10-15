#include <bits/stdc++.h>
using namespace std;

// Tổng của 2 nhóm A và B
long long sumA = 0, sumB = 0;

// Biến lưu hiệu tuyệt đối nhỏ nhất giữa sumA và sumB
long long min_AB = 2e9 + 5;

// Danh sách các quả táo (trọng lượng hoặc giá trị)
vector<long long> apples;

// Hàm quay lui (backtrack) để thử tất cả cách chia apples thành 2 nhóm
void backtrack(long long i) {
    // Nếu đã xét hết các quả táo
    if(i == apples.size()) {
        // Cập nhật giá trị chênh lệch nhỏ nhất giữa 2 nhóm
        min_AB = min(min_AB, abs(sumA - sumB));
        return;
    }

    // Nhánh 1: Đưa quả táo thứ i vào nhóm A
    sumA += apples[i];
    backtrack(i + 1);
    sumA -= apples[i];  // Hoàn tác để thử nhánh khác

    // Nhánh 2: Đưa quả táo thứ i vào nhóm B
    sumB += apples[i];
    backtrack(i + 1);
    sumB -= apples[i];  // Hoàn tác
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;  // Nhập số lượng quả táo

    // Nhập trọng lượng từng quả táo
    for(int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        apples.push_back(a);
    }

    // Gọi hàm quay lui để xét tất cả trường hợp chia nhóm
    backtrack(0);

    // In ra hiệu nhỏ nhất giữa tổng 2 nhóm
    cout << min_AB;

    return 0;
}








// void backtrack(int step) {
//     if (đã đạt trạng thái đích) {
//         xử lý kết quả;
//         return;
//     }

//     for (tất cả các lựa chọn hợp lệ tại bước step) {
//         nếu lựa chọn là hợp lệ:
//             thực hiện lựa chọn;
//             backtrack(step + 1);  // chuyển sang bước tiếp theo
//             hoàn tác lựa chọn;    // quay lui (undo) để thử phương án khác
//     }
// }
