#include <iostream>
using namespace std;

class Cstack {
private:
    int* stkArr;//Con trỏ kiểu int lưu trữ mảng phần tử của ngăn xếp.
    int stkTop;//Biến kiểu int lưu chỉ số phần tử trên đỉnh ngăn xếp.
    int stkMax;//Biến kiểu int lưu kích thước tối đa của ngăn xếp.

public:
    // Khởi tạo stack rỗng
    Cstack(int size) {
        stkArr = new int[size];
        stkMax = size;
        stkTop = -1;
    }

    // Hủy stack
    ~Cstack() {
        delete[] stkArr;
    }

    // Kiểm tra stack rỗng
    bool isEmpty() {
        return (stkTop == -1);
    }

    // Kiểm tra stack đầy
    bool isFull() {
        return (stkTop == stkMax - 1);
    }

    // Thêm "Push" một phần tử vào stack
    bool Push(int newItem) {
        if (isFull()) {
            return false;  // Stack đầy, không thể thêm phần tử
        }
        stkArr[++stkTop] = newItem;  // Thêm phần tử vào đỉnh stack
        return true;  // Thêm thành công
    }

    // Thao tác "Pop" lấy một phần tử từ đỉnh stack
    bool Pop(int &outItem) {
        if (isEmpty()) {
            return false;  // Stack rỗng, không lấy ra được
        }
        outItem = stkArr[stkTop--];  // Lấy phần tử ở đỉnh stack và giảm stkTop
        return true;  // Lấy ra thành công
    }

    // Lấy phần tử đỉnh mà không xóa (Peek)
    bool Peek(int &topItem) {
        if (isEmpty()) {
            return false;  // Stack rỗng, không thể lấy phần tử đỉnh
        }
        topItem = stkArr[stkTop];  // Gán phần tử đỉnh stack cho topItem
        return true;  // Trả về thành công
    }
};

// Hàm chuyển đổi thập phân sang nhị phân
void DecimalToBinary(int number) {
    Cstack stack(32); // Khởi tạo stack với kích thước đủ lớn để lưu các phần tử

    // Chuyển đổi số thập phân sang nhị phân bằng cách sử dụng stack
    while (number > 0) {
        stack.Push(number % 2); // Đẩy phần dư vào stack
        number /= 2;            // Chia số cho 2
    }

    // Hiển thị kết quả
    cout << "So nhi phan la: ";
    int bit;
    while (!stack.isEmpty()) {
        stack.Pop(bit);  // Lấy phần tử từ đỉnh stack
        cout << bit;
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Nhap so nguyen can chuyen doi: ";
    cin >> number;

    cout << "Chuyen doi so thap phan " << number << " sang nhi phan:\n";
    DecimalToBinary(number);

    return 0;
}
