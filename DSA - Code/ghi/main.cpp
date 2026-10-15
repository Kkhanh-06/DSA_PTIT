#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Thêm phần tử vào cuối danh sách
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

// Xóa các phần tử bị trùng
void removeDuplicates(Node* head) {

    Node* cur = head;

    while (cur != NULL) {

        Node* p = cur;

        while (p->next != NULL) {

            // Nếu phần tử phía sau trùng cur
            if (p->next->data == cur->data) {

                Node* temp = p->next;

                p->next = temp->next;

                delete temp;
            }
            else {
                p = p->next;
            }
        }

        cur = cur->next;
    }
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

    // Lọc phần tử trùng
    removeDuplicates(head);

    // In kết quả
    printList(head);

    return 0;
}