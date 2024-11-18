#include <iostream>
#include <algorithm> // Thư viện để sử dụng hàm sort
using namespace std;

// Hàm tìm kiếm nhị phân
int BinarySearch(int a[], int l, int r, int x) {
    while (l <= r) {
        int m = (l + r) / 2; // Tìm chỉ số phần tử ở giữa
        if (a[m] == x) 
            return m; // Tìm thấy giá trị x tại vị trí m
        if (x < a[m]) 
            r = m - 1; // Thu hẹp phạm vi tìm kiếm về bên trái
        else 
            l = m + 1; // Thu hẹp phạm vi tìm kiếm về bên phải
    }
    return -1; // Không tìm thấy x trong mảng
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

    int a[n];
    cout << "Nhap cac phan tu cua mang (khong can sap xep): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Hiển thị mảng ban đầu
    cout << "Mang ban dau: ";
    printArray(a, n);

    // Sắp xếp mảng trước khi thực hiện tìm kiếm nhị phân
    sort(a, a + n); // Hàm sort trong thư viện <algorithm>
    cout << "Mang sau khi sap xep: ";
    printArray(a, n);

    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    // Gọi hàm tìm kiếm nhị phân
    int result = BinarySearch(a, 0, n - 1, x);

    // Hiển thị kết quả
    if (result != -1) {
        cout << "Gia tri " << x << " duoc tim thay tai vi tri " << result ;
    } else {
        cout << "Gia tri " << x << " khong ton tai trong mang.\n";
    }

    return 0;
}
