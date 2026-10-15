#include <iostream>     
#include <cstring>
#include <algorithm>    
using namespace std;

int main() {
    char S[1000001];         // Mảng lưu chuỗi đầu vào (tối đa 1 triệu ký tự)
    int freq[26] = {0};      // Mảng đếm tần số các chữ cái từ 'A' đến 'Z'

    cin >> S;                // Nhập chuỗi từ bàn phím

    int n = strlen(S);       // Lấy độ dài chuỗi (C-style)

    // Đếm tần số xuất hiện của từng chữ cái trong chuỗi
    for (int i = 0; i < n; i++) {
        freq[S[i] - 'A']++;  // Chuyển ký tự thành chỉ số (A=0, B=1, ..., Z=25)
    }

    int odd = -1;            // Lưu vị trí ký tự có tần số lẻ (nếu có)

    // Kiểm tra số lượng ký tự có tần số lẻ
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {        // Nếu ký tự i xuất hiện số lẻ lần
            if (odd != -1) {           // Nếu đã có 1 ký tự lẻ khác trước đó → không tạo được palindrome
                cout << "NO SOLUTION\n";
                return 0;
            }
            odd = i;                   // Ghi nhận chỉ số ký tự lẻ đầu tiên
        }
    }

    string half = "";      // Nửa đầu của chuỗi palindrome
    string center = "";    // Phần giữa (nếu có ký tự xuất hiện lẻ lần)

    // Nếu có 1 ký tự lẻ, thêm 1 ký tự đó vào phần giữa, giảm tần số đi 1 để còn lại là số chẵn
    if (odd != -1) {
        center = string(1, 'A' + odd);  // Tạo 1 ký tự làm phần giữa
        freq[odd]--;                    // Giảm tần số để đưa vào 2 bên
    }

    // Tạo nửa đầu của palindrome từ các ký tự còn lại
    for (int i = 0; i < 26; i++) {
        half += string(freq[i] / 2, 'A' + i);  // Thêm freq[i]/2 lần ký tự 'A'+i vào nửa đầu
    }

    // In ra kết quả: nửa đầu + giữa (nếu có) + nửa sau (là nửa đầu đảo ngược)
    cout << half << center;
    reverse(half.begin(), half.end());  // Đảo ngược nửa đầu để thành nửa sau
    cout << half << endl;

    return 0;
}
