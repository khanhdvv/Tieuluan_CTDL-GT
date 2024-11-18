#include <iostream>
#include <vector>

using namespace std;

void Warshall(vector<vector<int>>& A, vector<vector<int>>& P, int n) {
    // Khởi tạo P = A
    P = A;

    // Ba vòng lặp để tính toán bội số truyền (transitive closure)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
            }
        }
    }
}

int main() {
    int n;  // Số lượng đỉnh (hoặc kích thước ma trận)
    
    cout << "Nhap so dinh (n): ";
    cin >> n;

    // Khởi tạo ma trận A
    vector<vector<int>> A(n, vector<int>(n));
    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Khởi tạo ma trận P
    vector<vector<int>> P(n, vector<int>(n));

    // Tính toán bội số truyền
    Warshall(A, P, n);

    // In ma trận kết quả P
    cout << "Ma tran P (Boi so truyen):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
