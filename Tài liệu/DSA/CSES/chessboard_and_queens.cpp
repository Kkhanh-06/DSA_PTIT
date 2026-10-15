#include <bits/stdc++.h>
using namespace std;

// Bảng cờ kích thước 8x8, mỗi ô là '.' (trống) hoặc '*' (chướng ngại vật)
char board[8][8];

// Đánh dấu các cột và 2 đường chéo (chéo chính và chéo phụ) đã đặt quân hậu
bool col[8], diag1[15], diag2[15];

// Biến đếm số cách đặt hợp lệ
int res = 0;

// Hàm đệ quy backtrack để thử đặt quân hậu tại hàng `row`
void backtrack(int row) {
    // Nếu đã đặt đủ 8 quân hậu (tức 8 hàng), thì tăng số cách lên
    if (row == 8) {
        res++;
        return;
    }

    // Thử đặt quân hậu ở mỗi cột của hàng hiện tại
    for (int c = 0; c < 8; ++c) {
        // Kiểm tra:
        // - Nếu ô hiện tại có chướng ngại (*)
        // - Hoặc đã có quân hậu ở cột `c`, chéo chính `row + c`, hoặc chéo phụ `row - c + 7`
        // → thì không được đặt quân hậu tại đây
        if (board[row][c] == '*' || col[c] || diag1[row + c] || diag2[row - c + 7]) 
            continue;

        // Đánh dấu là đã đặt quân hậu ở vị trí này
        col[c] = diag1[row + c] = diag2[row - c + 7] = true;

        // Gọi đệ quy để đặt quân hậu ở hàng tiếp theo
        backtrack(row + 1);

        // Quay lui: Bỏ đánh dấu để thử cách khác
        col[c] = diag1[row + c] = diag2[row - c + 7] = false;
    }
}

int main() {
    // Nhập vào bàn cờ 8x8
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> board[i][j];

    // Bắt đầu quay lui từ hàng đầu tiên
    backtrack(0);

    // In ra số cách đặt quân hậu thỏa mãn
    cout << res << endl;

    return 0;
}


// void backtrack(State current) {
//     if (đạt điều kiện kết thúc) {
//         xử lý hoặc lưu kết quả;
//         return;
//     }

//     for (mỗi lựa chọn khả thi từ trạng thái hiện tại) {
//         if (lựa chọn này hợp lệ) {
//             thực hiện lựa chọn;
//             backtrack(trạng thái mới);
//             quay lui (thu hồi lựa chọn);
//         }
//     }
// }
