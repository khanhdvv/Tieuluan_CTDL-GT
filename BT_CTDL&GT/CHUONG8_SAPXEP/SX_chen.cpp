#include <iostream>
using namespace std;

void InsertionSorting(int a[], int n) {
    int x, i, j;
    for (i = 1; i < n; i++) {
        x = a[i];  // Sửa lỗi: phải gán a[i] vào x chứ không phải a[j]
        j = i - 1;

        // Di chuyển các phần tử lớn hơn x sang phía phải
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;  // Đặt x vào vị trí đúng của nó
        // In trạng thái mảng sau mỗi vòng lặp bên ngoài
        cout << "Buoc " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

// Hàm in mảng
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;

    int a[n];  // Khai báo mảng động với kích thước n

    // Nhập các phần tử của mảng từ bàn phím
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Hiển thị mảng ban đầu
    cout << "Mang ban dau: ";
    printArray(a, n);

    // Sắp xếp bằng Insertion Sort
    InsertionSorting(a, n);

    // Hiển thị mảng sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    printArray(a, n);

    return 0;
}
