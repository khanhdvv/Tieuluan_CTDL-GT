#include <iostream>
using namespace std;

// Hàm tìm kiếm tuần tự
bool SequentialSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) 
            return true; // Trả về true nếu tìm thấy
    }
    return false; // Trả về false nếu không tìm thấy
}

int main() {
    int n;
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;

    int a[n]; // Khai báo mảng với kích thước n
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    // Gọi hàm tìm kiếm tuần tự
    if (SequentialSearch(a, n, x)) {
        cout << "Gia tri " << x << " duoc tim thay trong mang.\n";
    } else {
        cout << "Gia tri " << x << " khong ton tai trong mang.\n";
    }

    return 0;
}
