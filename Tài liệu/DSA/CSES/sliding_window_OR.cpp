// Biên dịch với tối ưu hóa mạnh cho hiệu năng
// compile: g++ -O3 -march=native -funroll-loops -std=gnu++17 fast_or_xor.cpp -o fast
#include <bits/stdc++.h>
using namespace std;

// Hàm đọc nhanh số nguyên không dấu từ stdin (bỏ qua khoảng trắng và ký tự không phải số)
static inline unsigned int fast_read_uint() {
    unsigned int x = 0;
    int c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked(); // bỏ qua ký tự không phải số
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        x = x * 10u + (c - '0');
    return x;
}

int main() {
    // Đọc input bằng hàm đọc nhanh
    unsigned int n = fast_read_uint();  // số phần tử
    unsigned int k = fast_read_uint();  // kích thước cửa sổ
    unsigned long long xu = fast_read_uint(); // giá trị khởi tạo
    unsigned long long a = fast_read_uint();  // hệ số a của công thức sinh số
    unsigned long long b = fast_read_uint();  // hệ số b
    unsigned long long c = fast_read_uint();  // modulo c

    // Cấp phát bộ nhớ cho buffer vòng (lưu k phần tử của cửa sổ)
    unsigned int *win = (unsigned int*)malloc(sizeof(unsigned int) * (size_t)k);

    unsigned long long ans = 0; // kết quả XOR cuối cùng
    unsigned int wpos = 0;      // vị trí ghi tiếp theo trong buffer vòng
    unsigned int filled = 0;    // số phần tử hiện tại trong cửa sổ
    unsigned int cur_or = 0;    // giá trị OR hiện tại của cửa sổ

    if (k <= 8) {
        // Trường hợp đặc biệt: k nhỏ (<= 8)
        // Tính toán lại OR toàn bộ k phần tử mỗi lần vì k nhỏ nên nhanh
        for (unsigned int i = 0; i < n; ++i) {
            unsigned int val = (unsigned int)xu;
            win[wpos] = val;
            wpos = (wpos + 1u) % k;
            if (filled < k) ++filled;

            // Chỉ tính OR khi cửa sổ đã đủ k phần tử
            if (filled == k) {
                unsigned int tmp = 0;
                // Xác định vị trí phần tử cũ nhất
                unsigned int start = (wpos + k - filled) % k;
                // OR toàn bộ k phần tử
                for (unsigned int j = 0; j < k; ++j) {
                    tmp |= win[(start + j) % k];
                }
                ans ^= tmp; // XOR vào kết quả
            }

            // Sinh số tiếp theo (tránh làm ở vòng lặp cuối)
            if (i + 1 < n) xu = (a * xu + b) % c;
        }
    } else {
        // Trường hợp tổng quát: k lớn
        // Sử dụng đếm bit (bit count) để cập nhật OR nhanh
        int bitcnt[31]; // Đếm số phần tử set ở từng bit (0..30)
        for (int i = 0; i <= 30; ++i) bitcnt[i] = 0;

        for (unsigned int i = 0; i < n; ++i) {
            unsigned int val = (unsigned int)xu;
            if (filled < k) {
                // Chưa đủ k phần tử -> chỉ thêm mới
                unsigned int v = val;
                while (v) {
                    unsigned int lb = v & -v;           // lấy bit 1 thấp nhất
                    int bit = __builtin_ctz(lb);       // vị trí bit
                    ++bitcnt[bit];                     // tăng số lượng bit này
                    v ^= lb;                           // xóa bit đó khỏi v
                }
                win[wpos] = val;
                ++filled;
                wpos = (wpos + 1u) % k;

                // Khi đủ k phần tử, tính OR ban đầu từ bitcnt
                if (filled == k) {
                    unsigned int tmp = 0;
                    for (int bit = 0; bit <= 30; ++bit)
                        if (bitcnt[bit]) tmp |= (1u << bit);
                    cur_or = tmp;
                    ans ^= cur_or;
                }
            } else {
                // Cửa sổ đã đầy -> ghi đè phần tử cũ nhất
                unsigned int old = win[wpos];

                // Xóa bit của phần tử cũ
                unsigned int vrem = old;
                while (vrem) {
                    unsigned int lb = vrem & -vrem;
                    int bit = __builtin_ctz(lb);
                    --bitcnt[bit];
                    if (bitcnt[bit] == 0) cur_or &= ~(1u << bit); // nếu hết bit này thì xóa khỏi OR
                    vrem ^= lb;
                }

                // Thêm bit của phần tử mới
                unsigned int vadd = val;
                while (vadd) {
                    unsigned int lb = vadd & -vadd;
                    int bit = __builtin_ctz(lb);
                    ++bitcnt[bit];
                    cur_or |= (1u << bit); // đảm bảo bit này có trong OR
                    vadd ^= lb;
                }

                win[wpos] = val;                  // ghi đè vào buffer
                wpos = (wpos + 1u) % k;           // di chuyển con trỏ
                ans ^= cur_or;                    // XOR giá trị OR hiện tại vào kết quả
            }

            // Sinh số tiếp theo nếu chưa phải vòng cuối
            if (i + 1 < n) xu = (a * xu + b) % c;
        }
    }

    // In kết quả
    printf("%llu\n", ans);
    free(win); // giải phóng bộ nhớ
    return 0;
}
