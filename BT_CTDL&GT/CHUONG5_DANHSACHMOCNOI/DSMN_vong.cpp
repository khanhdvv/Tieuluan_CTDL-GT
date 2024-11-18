#include <iostream>
using namespace std;

// Định nghĩa node
struct Node {
    int data;
    Node* next;
};

// Con trỏ đầu danh sách
Node* L = NULL;  

// Hàm tạo node mới
Node* createNode(int value) { 
    Node* newNode = new Node(); 
    newNode->data = value; 
    newNode->next = newNode; // Trỏ đến chính nó để tạo vòng 
    return newNode; 
}

// Thêm 1 node vào đầu danh sách
void insert_dau(int value) { 	
    Node* newNode = createNode(value); 
    if (L == NULL) { 
        L = newNode; 
    } else { 
        Node* temp = L; 
        while (temp->next != L) { // Tìm node cuối cùng 
            temp = temp->next; 
        } 
        temp->next = newNode; 
        newNode->next = L; 
        L = newNode; 
    } 
}

// Thêm 1 node vào cuối danh sách
void insert_cuoi(int value) { 
    Node* newNode = createNode(value); 
    if (L == NULL) { 
        L = newNode; 
    } else { 
        Node* temp = L; 
        while (temp->next != L) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
        newNode->next = L; 
    } 
}

// Xóa 1 node ở đầu danh sách
void delete_dau() { 
    if (L == NULL) { 
        cout << "Danh sach trong\n"; 
    } else if (L->next == L) { // Chỉ có 1 node 
        delete L; 
        L = NULL; 
    } else { 
        Node* temp = L; 
        Node* tail = L; 
        while (tail->next != L) { // Tìm node cuối cùng 
            tail = tail->next; 
        } 
        tail->next = L->next; 
        L = L->next; 
        delete temp; 
    } 
}

// Xóa 1 node ở cuối danh sách
void delete_cuoi() { 
    if (L == NULL) { 
        cout << "Danh sach trong\n"; 
    } else if (L->next == L) { // Chỉ có 1 node 
        delete L; 
        L = NULL; 
    } else { 
        Node* temp = L; 
        Node* prev = NULL; 
        while (temp->next != L) { // Tìm node cuối cùng 
            prev = temp; 
            temp = temp->next; 
        } 
        prev->next = L; 
        delete temp; 
    }
}

// Xóa node có giá trị X
void delete_value(int value) { 
    if (L == NULL) { 
        cout << "Danh sach trong\n"; 
        return; 
    } 
    if (L->data == value) { // Nếu node đầu có giá trị cần xóa 			
        delete_dau(); 
        return; 
    } 
    Node* temp = L; 
    Node* prev = NULL; 
    do { 
        prev = temp; 
        temp = temp->next; 
        if (temp->data == value) { 
            prev->next = temp->next; 
            delete temp; 
            return; 
        } 
    } while (temp != L); 
    cout << "Gia tri " << value << " khong ton tai trong danh sach\n"; 
}

// In danh sách
void printList() {
    if (L == NULL) {
        cout << "Danh sach trong.\n";
        return;
    }

    Node* temp = L;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != L);
    cout << endl;
}

int main() {
    int choice, value;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Them node vao dau danh sach\n";
        cout << "2. Them node vao cuoi danh sach\n";
        cout << "3. Xoa node o dau danh sach\n";
        cout << "4. Xoa node o cuoi danh sach\n";
        cout << "5. Xoa node theo gia tri\n";
        cout << "6. In danh sach\n";
        cout << "7. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri node can them: ";
                cin >> value;
                insert_dau(value);
                break;
            case 2:
                cout << "Nhap gia tri node can them: ";
                cin >> value;
                insert_cuoi(value);
                break;
            case 3:
                delete_dau();
                break;
            case 4:
                delete_cuoi();
                break;
            case 5:
                cout << "Nhap gia tri node can xoa: ";
                cin >> value;
                delete_value(value);
                break;
            case 6:
                printList();
                break;
            case 7:
                cout << "Thoat chuong trinh.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}
