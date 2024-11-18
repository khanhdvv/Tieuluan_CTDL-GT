#include <iostream>
using namespace std;

// Hàm điều chỉnh phần tử thứ k trong đống
void SetupHeap(int a[], int k, int n) {
    int x = a[k];
    while (k < n / 2) {
        int j = 2 * k + 1; // Con trái
        if (j + 1 < n && a[j] < a[j + 1]) j++; // Chọn con lớn hơn
        if (x >= a[j]) break;
        a[k] = a[j];
        k = j;
    }
    a[k] = x;
}

// Hàm tạo đống
void MakeHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        SetupHeap(a, i, n);
    }
}

// Hàm Heap Sort
void Heapsort(int a[], int n) {
    MakeHeap(a, n); // Tạo đống
    int tmp;

    // Sắp xếp
    for (int i = n - 1; i > 0; i--) {
        // Đổi chỗ phần tử lớn nhất (gốc) với phần tử cuối
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        // Điều chỉnh đống cho phần còn lại
        SetupHeap(a, 0, i);

        // In trạng thái mảng sau mỗi bước
        cout << "Buoc " << n - i << ": ";
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

    int a[n]; // Khai báo mảng với kích thước n

    // Nhập các phần tử của mảng từ bàn phím
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Hiển thị mảng ban đầu
    cout << "Mang ban dau: ";
    printArray(a, n);

    // Sắp xếp bằng Heap Sort
    Heapsort(a, n);

    // Hiển thị mảng sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    printArray(a, n);

    return 0;
}
