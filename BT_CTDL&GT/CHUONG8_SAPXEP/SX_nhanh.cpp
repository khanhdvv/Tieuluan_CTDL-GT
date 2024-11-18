#include <iostream>
using namespace std;

void QuickSort(int a[], int l, int r, int &step) { // Dùng tham chiếu để giữ giá trị step
    int tmp;
    int i = l, j = r;
    int x = a[(l + r) / 2]; // Chọn pivot
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    // In trạng thái mảng sau mỗi lần chia mảng
    cout << "Buoc " << step++ << ": ";
    for (int k = l; k <= r; k++) {
        cout << a[k] << " ";
    }
    cout << endl;

    // Đệ quy để sắp xếp các mảng con
    if (l < j) QuickSort(a, l, j, step);
    if (i < r) QuickSort(a, i, r, step);
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

    // Biến đếm bước
    int step = 1;

    // Sắp xếp bằng QuickSort
    QuickSort(a, 0, n - 1, step);

    // Hiển thị mảng sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    printArray(a, n);

    return 0;
}
