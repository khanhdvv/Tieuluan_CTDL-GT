#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    string value;
    vector<TreeNode*> children;  // Lưu trữ các nút con

    // Hàm tạo nút mới với giá trị cho trước
    TreeNode(string val) : value(val) {}

    // Thêm nút con
    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};

// Duyệt theo thứ tự trước (Preorder)
void preOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->value << " ";  // Thăm gốc
    for (TreeNode* child : node->children) {
        preOrderTraversal(child);  // Duyệt các cây con theo thứ tự trước
    }
}

// Duyệt theo thứ tự giữa (Inorder)
void inOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    if (!node->children.empty()) {
        inOrderTraversal(node->children[0]);  // Duyệt cây con đầu tiên
    }
    cout << node->value << " ";  // Thăm gốc
    for (size_t i = 1; i < node->children.size(); ++i) {
        inOrderTraversal(node->children[i]);  // Duyệt các cây con còn lại
    }
}

// Duyệt theo thứ tự sau (Postorder)
void postOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    for (TreeNode* child : node->children) {
        postOrderTraversal(child);  // Duyệt tất cả các cây con
    }
    cout << node->value << " ";  // Thăm gốc sau khi duyệt cây con
}

// Hàm nhập cây tổng quát
TreeNode* buildTree() {
    string rootValue;
    cout << "Nhap gia tri cua nut goc: ";
    cin >> rootValue;

    // Tạo nút gốc
    TreeNode* root = new TreeNode(rootValue);

    int numChildren;
    cout << "Nhap so luong nut con cua nut goc: ";
    cin >> numChildren;

    // Nhập các nút con cho nút gốc
    for (int i = 0; i < numChildren; ++i) {
        string childValue;
        cout << "Nhap gia tri cua nut con " << i + 1 << ": ";
        cin >> childValue;
        TreeNode* child = new TreeNode(childValue);
        root->addChild(child);

        // Nhập các cây con cho nút con hiện tại
        int childNumChildren;
        cout << "Nhap so luong nut con cua nut con " << childValue << ": ";
        cin >> childNumChildren;
        for (int j = 0; j < childNumChildren; ++j) {
            string grandChildValue;
            cout << "Nhap gia tri cua nut con " << j + 1 << " cua nut con " << childValue << ": ";
            cin >> grandChildValue;
            TreeNode* grandChild = new TreeNode(grandChildValue);
            child->addChild(grandChild);
        }
    }

    return root;
}

// Menu
void menu() {
    TreeNode* root = buildTree();  // Xây dựng cây

    int choice;
    while (true) {
        cout << "\n=============== MENU ============\n";
        cout << "1. Duyet theo thu tu truoc (Preorder)\n";
        cout << "2. Duyet theo thu tu giua (Inorder)\n";
        cout << "3. Duyet theo thu tu sau (Postorder)\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Duyet theo thu tu truoc (Preorder): ";
                preOrderTraversal(root);
                cout << endl;
                break;
            case 2:
                cout << "Duyet theo thu tu giua (Inorder): ";
                inOrderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Duyet theo thu tu sau (Postorder): ";
                postOrderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Thoat chuong trinh.\n";
                return;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    }
}

int main() {
    menu();  // Hiển thị menu
    return 0;
}
