#include <iostream>
using namespace std;

// Hàm Bubble Sort
void BubbleSorting(int a[], int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) { // Lặp qua từng phần tử
        for (int j = 0; j < n - i - 1; j++) { // So sánh từng cặp lân cận
            if (a[j] > a[j + 1]) { // Nếu phần tử trước lớn hơn phần tử sau
                // Hoán đổi vị trí
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
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

    int a[n]; // Khai báo mảng động với kích thước n

    // Nhập các phần tử của mảng từ bàn phím
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Hiển thị mảng ban đầu
    cout << "Mang ban dau: ";
    printArray(a, n);

    // Sắp xếp bằng Bubble Sort
    BubbleSorting(a, n);

    // Hiển thị mảng sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    printArray(a, n);

    return 0;
}
