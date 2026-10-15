#include <bits/stdc++.h>  // Thư viện tổng hợp mọi thứ (chỉ dùng cho thi code, không dùng trong dự án lớn)
using namespace std;

// Hàm sắp xếp Merge Sort: sắp xếp đoạn từ chỉ số l đến r trong mảng a
void mergeSort(vector<int>& a, int l, int r){
    if(l >= r) return;  // Trường hợp cơ bản: mảng chỉ còn 1 phần tử

    int m = (l + r) / 2;  // Tìm chỉ số giữa

    mergeSort(a, l, m);      // Đệ quy sắp xếp nửa trái
    mergeSort(a, m + 1, r);  // Đệ quy sắp xếp nửa phải

    vector<int> c;  // Mảng tạm để lưu kết quả trộn
    int i = l, j = m + 1;

    // Trộn hai nửa đã sắp xếp
    while(i <= m && j <= r){
        if(a[i] <= a[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(a[j]);
            j++;
        }
    }

    // Thêm các phần tử còn lại của nửa trái (nếu còn)
    while(i <= m){
        c.push_back(a[i]);
        i++;
    }

    // Thêm các phần tử còn lại của nửa phải (nếu còn)
    while(j <= r){
        c.push_back(a[j]);
        j++;
    }

    // Gán lại kết quả đã trộn vào mảng a ban đầu (từ vị trí l đến r)
    for(int i = 0; i < c.size(); i++){
        a[l + i] = c[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); // Tăng tốc độ nhập/xuất
    cin.tie(nullptr);                 // Không đồng bộ cin/cout với stdio

    int n, m, k;
    cin >> n >> m >> k;  // Nhập số lượng phần tử mảng a, b và giá trị k

    vector<int> a(n), b(m);  // Khai báo 2 mảng a và b

    for(int i = 0; i < n; i++){
        cin >> a[i];  // Nhập mảng a
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];  // Nhập mảng b
    }

    mergeSort(a, 0, n - 1);  // Sắp xếp mảng a
    mergeSort(b, 0, m - 1);  // Sắp xếp mảng b

    int i = 0, j = 0, res = 0;

    // Duyệt hai mảng sau khi đã sắp xếp để tìm số cặp phù hợp
    // Mỗi cặp gồm a[i] và b[j] sao cho: |a[i] - b[j]| <= k
    while(i < n && j < m){
        if(a[i] - k > b[j]) j++;              // b[j] quá nhỏ, tăng j
        else if(a[i] + k < b[j]) i++;         // b[j] quá lớn, tăng i
        else{
            res++;  // Tìm được một cặp phù hợp
            i++;
            j++;
        }
    }

    cout << res;  // In ra số cặp phù hợp tìm được

    return 0;
}
