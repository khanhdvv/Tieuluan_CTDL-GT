#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

node *makeNode(int x) {
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void duyet(node *head) {
    while (head != NULL) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

void themdau(node **head, int x) {
    node *newNode = makeNode(x);
    newNode->next = (*head);
    if (*head != NULL)
        (*head)->prev = newNode;
    (*head) = newNode;
}

void themcuoi(node **head, int x) {
    node *newNode = makeNode(x);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void delete_dau(node **head) {
    if (*head == NULL) {
        cout << "Danh sach rong, khong the xoa!\n";
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    delete temp;
    cout << "Da xoa nut o dau danh sach.\n";
}

void delete_cuoi(node **head) {
    if (*head == NULL) {
        cout << "Danh sach rong, khong the xoa!\n";
        return;
    }
    if ((*head)->next == NULL) {
        delete *head;
        *head = NULL;
        cout << "Da xoa nut o cuoi danh sach.\n";
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
    cout << "Da xoa nut o cuoi danh sach.\n";
}
void delete_X(node **head, int x) {
    if (*head == NULL) {
        cout << "Danh sach rong, khong the xoa!\n";
        return;
    }
    node *temp = *head;
    if (temp->data == x) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        delete temp;
        cout << "Da xoa nut dau tien co gia tri " << x << ".\n";
        return;
    }
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Gia tri " << x << " khong ton tai trong danh sach!\n";
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    delete temp;
    cout << "Da xoa nut dau tien co gia tri " << x << ".\n";
}

int main() {
    node *head = NULL;
    while (1) {
        cout << "\n-----------------MENU--------------------";
        cout << "\n1. Them mot nut vao dau danh sach";
        cout << "\n2. Them mot nut vao cuoi danh sach";
        cout << "\n3. Xoa mot nut o dau danh sach";
        cout << "\n4. Xoa mot nut o cuoi danh sach";
        cout << "\n5. Xoa nut dau tien co gia tri X";
        cout << "\n6. Duyet";
        cout << "\n0. Thoat!";
        cout << "\n-----------------------------------------";
        cout << "\nNhap lua chon :";
        int luachon;
        cin >> luachon;
        if (luachon == 1) {
            int x;
            cout << "Nhap gia tri x :";
            cin >> x;
            themdau(&head, x);
        } else if (luachon == 2) {
            int x;
            cout << "Nhap gia tri x :";
            cin >> x;
            themcuoi(&head, x);
        } else if (luachon == 3) {
            delete_dau(&head);
        } else if (luachon == 4) {
            delete_cuoi(&head);
        } else if (luachon == 5) {
            int x;
            cout << "Nhap gia tri X can xoa: ";
            cin >> x;
            delete_X(&head, x);
        }
		else if (luachon == 6) {
            duyet(head);
        }
		else {
            break;
        }
    }
    return 0;
}
