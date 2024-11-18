#include <iostream>
using namespace std;

int fibonacci_n(int n) {
    // Nếu n là 0 hoặc 1, trả về n (0 hoặc 1) và hiển thị bước đầu tiên
    if (n <= 1) {
        cout << "Buoc 1: F(" << n << ") = " << n << endl;
        return n;
    }

    // Khởi tạo mảng để lưu các giá trị Fibonacci từ 0 đến n
    int f[n + 1];
    f[0] = 0; // f(0) = 0
    f[1] = 1; // f(1) = 1

    // Hiển thị các bước đầu tiên
    cout << "Buoc 1: F(0) = 0" << endl;
    cout << "Buoc 2: F(1) = 1" << endl;

    // Tính các số Fibonacci từ 2 đến n, bắt đầu hiển thị từ bước 3
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        cout << "Buoc " << i + 1 << ": F(" << i << ") = " << f[i] << " ( F(" << i-1 << ") + F(" << i-2 << "))" << endl;
    }

    // Trả về kết quả của Fibonacci tại vị trí n
    return f[n];
}

int main() {
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;

    int result = fibonacci_n(n);
    cout << "So Fibonacci thu " << n << " la: " << result << endl;

    return 0;
}
