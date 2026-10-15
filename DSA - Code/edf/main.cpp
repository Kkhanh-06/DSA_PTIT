#include <bits/stdc++.h>
using namespace std;

// Khai báo node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Thêm node vào cuối danh sách
void pushBack(Node*& head, int x) {
    Node* newNode = new Node(x);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newNode;
}

// Xóa tất cả node có giá trị bằng x
int deleteValue(Node*& head, int x) {
    int count = 0;

    // Xóa các node đầu danh sách
    while (head != NULL && head->data == x) {
        Node* temp = head;

        head = head->next;

        delete temp;

        count++;
    }

    // Xóa các node còn lại
    Node* p = head;

    while (p != NULL && p->next != NULL) {

        if (p->next->data == x) {
            Node* temp = p->next;

            p->next = temp->next;

            delete temp;

            count++;
        }
        else {
            p = p->next;
        }
    }

    return count;
}

// In danh sách
void printList(Node* head) {
    Node* p = head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;

    // Nhập danh sách
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pushBack(head, x);
    }

    // Giá trị cần xóa
    int x;
    cin >> x;

    // Xóa
    int deleted = deleteValue(head, x);

    // Nếu đề yêu cầu số lượng phần tử đã xóa
    // cout << deleted << '\n';

    // In danh sách còn lại
    printList(head);

    return 0;
}