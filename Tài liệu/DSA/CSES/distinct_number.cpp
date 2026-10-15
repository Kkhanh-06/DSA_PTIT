#include <iostream> 
#include <vector> 
using namespace std;

// Hàm mergeSort: Sắp xếp mảng a từ chỉ số l đến r bằng thuật toán Merge Sort
void mergeSort(vector<int> &a, int l, int r){
    if(l >= r) return;  // Trường hợp cơ sở: chỉ còn 1 phần tử hoặc không còn gì để sắp

    int m = (l + r)/2;  // Chia đôi mảng

    mergeSort(a, l, m);     // Đệ quy sắp xếp nửa trái
    mergeSort(a, m+1, r);   // Đệ quy sắp xếp nửa phải

    // Trộn hai nửa đã sắp xếp lại thành mảng c
    vector<int> c;
    int i = l, j = m+1;
    while(i <= m && j <= r){
        if(a[i] <= a[j]){
            c.push_back(a[i]);  // Chọn phần tử nhỏ hơn để thêm vào mảng kết quả
            i++;
        }
        else{
            c.push_back(a[j]);
            j++;
        }
    }

    // Thêm các phần tử còn lại từ nửa trái (nếu còn)
    while(i <= m){
        c.push_back(a[i]);
        i++;
    }

    // Thêm các phần tử còn lại từ nửa phải (nếu còn)
    while(j <= r){
        c.push_back(a[j]);
        j++;
    }

    // Ghi đè kết quả đã trộn từ mảng c vào lại đoạn [l, r] của mảng a
    for(int i = 0; i < c.size(); i++){
        a[l+i] = c[i];
    }
}

int main(){
    int n, distinct = 1;  // distinct đếm số phần tử khác nhau, khởi đầu là 1

    cin >> n;             // Nhập số lượng phần tử
    vector<int> a(n);     // Khởi tạo mảng a có n phần tử

    for(int i = 0; i < n; i++){
        cin >> a[i];      // Nhập từng phần tử vào mảng
    }

    mergeSort(a, 0, a.size()-1);  // Gọi merge sort để sắp xếp mảng

    // Duyệt qua mảng đã sắp xếp để đếm số phần tử khác nhau (mỗi lần giá trị thay đổi thì tăng biến đếm)
    for(int i = 0; i < n-1; i++){
        if(a[i] != a[i+1]){
            distinct += 1;
        }
    }

    cout << distinct;  // In ra kết quả: số phần tử khác nhau trong mảng

    return 0;
}
