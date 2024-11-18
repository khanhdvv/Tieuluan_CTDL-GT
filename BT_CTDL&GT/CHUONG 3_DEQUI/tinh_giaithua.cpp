#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        cout << "Buoc 1: 0! = 1" << endl;
        return 1;
    } else {
        int result = factorial(n - 1) * n;
        cout << "Buoc " << n << ": " << n << "! = (" << n - 1 << "!) * " << n << " = " << result << endl;
        return result;
    }
}

int main() {
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;

    int result = factorial(n);
    cout << "Ket qua: " << n << "! = " << result << endl;

    return 0;
}
