#include <iostream>
using namespace std;

void SelectionSorting(int a[], int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min_index] > a[j]) {  // Sửa lỗi so sánh
                min_index = j;  // Lỗi trong phần gán min_index
            }
        }
        // Hoán đổi a[i] với a[min_index]
        tmp = a[min_index];
        a[min_index] = a[i];
        a[i] = tmp;
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

    // Sắp xếp bằng Selection Sort
    SelectionSorting(a, n);

    // Hiển thị mảng sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    printArray(a, n);

    return 0;
}
