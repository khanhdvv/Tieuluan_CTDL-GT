#include <iostream>
using namespace std;

class Queue {
private:
    int* QArray;    // Mảng để chứa các phần tử trong queue
    int QMax;       // Kích thước tối đa của queue
    int QFront;     // Vị trí phần tử đầu tiên trong queue
    int QRear;      // Vị trí phần tử cuối cùng trong queue
    int QNumItems;  // Số phần tử hiện có trong queue

public:
	// Khởi tạo queue với kích thước cho trước
    Queue(int size) {
        QArray = new int[size];
        QMax = size;
        QFront = QRear = -1;
        QNumItems = 0;
    }
	// Hàm hủy để giải phóng bộ nhớ
    ~Queue() {
        delete[] QArray;
    }
	// Kiểm tra queue có rỗng không
    bool IsEmpty() {
        return (QNumItems == 0);
        return true;//Queue rỗng
        return false;//Queue 0 rỗng
    }

    // Kiểm tra queue có đầy không
    bool IsFull() {
        return (QNumItems == QMax);
        return true;//Queue đầy
        return false;//Queue 0 đầy
    }
	// Thêm phần tử vào cuối queue
    bool Append(int newItem) {
        if (IsFull()) return false;
        if (QNumItems == 0) QFront = 0;
        QRear = (QRear + 1) % QMax;
        QArray[QRear] = newItem;
        QNumItems++;
        return true;
    }
	// Lấy ra phần tử ở đầu queue
    bool Take(int &itemOut) {
        if (IsEmpty()) return false;
        itemOut = QArray[QFront];
        QFront = (QFront + 1) % QMax;
        QNumItems--;
        if (QNumItems == 0) QFront = QRear = -1;
        return true;
    }
	// Hiển thị các phần tử trong queue
    void Display() {
        if (IsEmpty()) {
            cout << "Queue rong.\n";
        } else {
            cout << "Cac phan tu trong queue: ";
            int count = QNumItems;
            int index = QFront;
            while (count > 0) {
                cout << QArray[index] << " ";
                index = (index + 1) % QMax;
                count--;
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Nhap kich thuoc cua queue: ";
    cin >> size;
    Queue myQueue(size);

    int choice, value, numElements;

    do {
        cout << "\n-------------------MENU-------------------\n";
        cout << "1. Them phan tu vao queue\n";
        cout << "2. Lay phan tu khoi queue\n";
        cout << "3. Hien thi cac phan tu trong queue\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap so luong phan tu muon them: ";
                cin >> numElements;
                for (int i = 0; i < numElements; i++) {
                    cout << "Nhap gia tri phan tu " << i + 1 << ": ";
                    cin >> value;
                    if (myQueue.Append(value)) {
                        cout << "Them thanh cong.\n";
                    } else {
                        cout << "Queue da day, khong the them phan tu " << value << ".\n";
                        break;
                    }
                }
                break;

            case 2:
                if (myQueue.Take(value)) {
                    cout << "Phan tu lay ra: " << value << endl;
                } else {
                    cout << "Queue rong, khong the lay ra phan tu.\n";
                }
                break;

            case 3:
                myQueue.Display();
                break;

            case 0:
                cout << "Thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    } while (choice != 0);

    return 0;
}
