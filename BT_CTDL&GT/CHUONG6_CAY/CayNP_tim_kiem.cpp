#include <bits/stdc++.h>
using namespace std;

// Khai báo cấu trúc của một nút trong cây BST
struct BSTNode {
    int data;
    BSTNode *pleft;  // Con trỏ đến nút con trái
    BSTNode *pright; // Con trỏ đến nút con phải
};

// Hàm tạo một nút mới
BSTNode *createNode(int data) {
    BSTNode *newNode = new BSTNode();
    if (!newNode) {
        cout << "Khong the cap phat bo nho.\n";
        return NULL;
    }
    newNode->data = data;
    newNode->pleft = newNode->pright = NULL;
    return newNode;
}

// Thêm 1 phần tử vào cây BST
int insert(int X, BSTNode *&root) {
    if (root == NULL) {
        root = createNode(X);
        if (root == NULL) {
            return -1; // Không thể cấp phát bộ nhớ
        }
        return 1; // Thêm thành công
    } else if (X == root->data) {
        return 0; // Đã tồn tại trong cây
    } else if (X < root->data) {
        return insert(X, root->pleft);
    } else {
        return insert(X, root->pright);
    }
}

// Tìm một nút có khóa X (đệ quy)
BSTNode *Find(int X, BSTNode *root) {
    if (root == NULL || root->data == X) {
        return root;
    }
    if (X < root->data) {
        return Find(X, root->pleft);
    } else {
        return Find(X, root->pright);
    }
}

// Tìm một nút có khóa nhỏ nhất
BSTNode *FindMin(BSTNode *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->pleft != NULL) {
        root = root->pleft;
    }
    return root;
}

// Tìm một nút có khóa lớn nhất
BSTNode *FindMax(BSTNode *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->pright != NULL) {
        root = root->pright;
    }
    return root;
}

// Xóa một nút có khóa X
int deleteNode(int X, BSTNode *&root) {
    if (root == NULL) {
        return 0; // Cây rỗng, không tìm thấy
    }
    if (X < root->data) {
        return deleteNode(X, root->pleft);
    } else if (X > root->data) {
        return deleteNode(X, root->pright);
    } else {
        // Nút có 2 con
        if (root->pleft != NULL && root->pright != NULL) {
            BSTNode *p = FindMax(root->pleft);
            root->data = p->data;
            return deleteNode(p->data, root->pleft);
        } else {
            // Nút có 1 con hoặc không có con
            BSTNode *temp = root;
            if (root->pleft == NULL) {
                root = root->pright;
            } else if (root->pright == NULL) {
                root = root->pleft;
            }
            delete temp;
        }
        return 1; // Xóa thành công
    }
}

// Duyệt cây theo Preorder
void preOrder(BSTNode *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->pleft);
        preOrder(root->pright);
    }
}

// Duyệt cây theo Inorder (Giữa)
void inOrder(BSTNode *root) {
    if (root != NULL) {
        inOrder(root->pleft);
        cout << root->data << " ";
        inOrder(root->pright);
    }
}

// Duyệt cây theo Postorder (Sau)
void postOrder(BSTNode *root) {
    if (root != NULL) {
        postOrder(root->pleft);
        postOrder(root->pright);
        cout << root->data << " ";
    }
}

int main() {
    BSTNode *root = NULL;
    int luachon,value, n;

    cout << "Nhap so luong phan tu cua cay: ";
    cin >> n;

    cout << "Nhap cac phan tu cua cay: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value, root);
    }

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Them phan tu vao cay\n";
        cout << "2. Xoa phan tu khoi cay\n";
        cout << "3. Tim kiem phan tu\n";
        cout << "4. Tim phan tu nho nhat\n";
        cout << "5. Tim phan tu lon nhat\n";
        cout << "6. Duyet cay theo thu tu truoc\n";
        cout << "7. Duyet cay theo thu tu giua\n";
        cout << "8. Duyet cay theo thu tu sau\n";
        cout << "9. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luachon;

        switch (luachon) {
        case 1:
            cout << "Nhap gia tri can them: ";
            cin >> value;
            if (insert(value, root) == 1) {
                cout << "Them thanh cong.\n";
            } else {
                cout << "Gia tri da ton tai hoac co loi.\n";
            }
            break;
        case 2:
            cout << "Nhap gia tri can xoa: ";
            cin >> value;
            if (deleteNode(value, root)) {
                cout << "Xoa thanh cong.\n";
            } else {
                cout << "Khong tim thay gia tri.\n";
            }
            break;
        case 3:
            cout << "Nhap gia tri can tim: ";
            cin >> value;
            if (Find(value, root)) {
                cout << "Gia tri co trong cay.\n";
            } else {
                cout << "Gia tri khong ton tai trong cay.\n";
            }
            break;
        case 4:
            if (BSTNode *minNode = FindMin(root)) {
                cout << "Phan tu nho nhat: " << minNode->data << endl;
            } else {
                cout << "Cay rong.\n";
            }
            break;
        case 5:
            if (BSTNode *maxNode = FindMax(root)) {
                cout << "Phan tu lon nhat: " << maxNode->data << endl;
            } else {
                cout << "Cay rong.\n";
            }
            break;
        case 6:
            cout << "Duyet cay theo thu tu truoc: ";
            preOrder(root);
            cout << endl;
            break;
        case 7:
            cout << "Duyet cay theo thu tu giua: ";
            inOrder(root);
            cout << endl;
            break;
        case 8:
            cout << "Duyet cay theo thu tu sau: ";
            postOrder(root);
            cout << endl;
            break;
        case 9:
            cout << "Thoat chuong trinh.\n";
            return 0;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}
