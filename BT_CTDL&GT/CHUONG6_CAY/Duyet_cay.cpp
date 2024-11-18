#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        // Hàm chèn nút vào cây nhị phân
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }
                return root;
            }
        }

        // Duyệt cây theo thứ tự trước (NLR)
        void preOrder(Node *root) {
            if (root != NULL) {
                cout << root->data << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }

        // Duyệt cây theo thứ tự giữa (LNR)
        void inOrder(Node *root) {
            if (root != NULL) {
                inOrder(root->left);
                cout << root->data << " ";
                inOrder(root->right);
            }
        }

        // Duyệt cây theo thứ tự sau (LRN)
        void postOrder(Node *root) {
            if (root != NULL) {
                postOrder(root->left);
                postOrder(root->right);
                cout << root->data << " ";
            }
        }
}; // End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    cout << "Nhap so luong phan tu: ";
    cin >> t;

    cout << "Nhap cac phan tu: ";
    while(t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }

    cout << "\nDuyet cay theo thu tu truoc (NLR): ";
    myTree.preOrder(root);

    cout << "\nDuyet cay theo thu tu giua (LNR): ";
    myTree.inOrder(root);

    cout << "\nDuyet cay theo thu tu sau (LRN): ";
    myTree.postOrder(root);

    return 0;
}
