#include <bits/stdc++.h>
using namespace std;

// Hàm merge sort đệ quy, sắp xếp đoạn a[l..r]
void mergeSort(vector<int> &a, int l, int r){
    if(l >= r) return; // Nếu đoạn chỉ có 1 phần tử thì đã được sắp xếp

    int m = (l + r) / 2; // Chia đôi mảng
    mergeSort(a, l, m);     // Sắp xếp nửa trái
    mergeSort(a, m+1, r);   // Sắp xếp nửa phải

    // Trộn hai nửa đã sắp xếp lại thành mảng tạm thời c
    vector<int> c;
    int i = l, j = m+1;
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

    // Đẩy nốt các phần tử còn lại từ hai nửa vào mảng c
    while(i <= m){
        c.push_back(a[i]);
        i++;
    }
    while(j <= r){
        c.push_back(a[j]);
        j++;
    }

    // Ghi đè lại phần đã sắp xếp vào mảng a
    for(int i = 0; i < c.size(); i++){
        a[i + l] = c[i]; // Ghi từ vị trí l
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, res = 0;
    cin >> n >> x; // Nhập số lượng phần tử và tổng tối đa cho mỗi cặp

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i]; // Nhập mảng

    }

    mergeSort(a, 0, n - 1); // Sắp xếp mảng tăng dần bằng merge sort

    // Two pointer để ghép các phần tử lại với nhau sao cho tổng <= x
    int i = 0, j = a.size() - 1;
    while(i <= j){
        if((a[i] + a[j]) <= x){
            // Nếu ghép được phần tử nhỏ nhất và lớn nhất hiện tại thì ghép lại
            res++;
            i++;
            j--;
        }
        else{
            // Nếu không ghép được thì phải để phần tử lớn nhất đứng riêng
            res++;
            j--;
        }
    }

    cout << res; // In ra số lượng nhóm tối thiểu
    return 0;
}
