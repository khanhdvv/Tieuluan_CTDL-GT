#include <bits/stdc++.h>
using namespace std;

// Hàm thực hiện thuật toán Dijkstra
void Dijkstra(int v, vector<vector<int>>& COST, vector<int>& DIST, int n) {
    // Khởi tạo các mảng
    vector<int> S(n + 1, 0); // S[i] = 0 nếu i chưa được duyệt, 1 nếu đã duyệt
    DIST[v] = 0; // Khoảng cách từ v đến v là 0
    for (int i = 1; i <= n; i++) {
        if (i != v) {
            DIST[i] = COST[v][i]; // Khoảng cách từ v đến các đỉnh khác là trọng số trực tiếp
        }
    }

    S[v] = 1; // Đưa đỉnh v vào tập S (đỉnh đã duyệt)
    int k = 2; // Bắt đầu từ đỉnh thứ 2

    // Duyệt cho đến khi tất cả các đỉnh được duyệt
    while (k <= n) {
        int u = -1;
        int minDist = INT_MAX;

        // Chọn đỉnh u có DIST[u] nhỏ nhất và chưa được duyệt
        for (int i = 1; i <= n; i++) {
            if (S[i] == 0 && DIST[i] < minDist) {
                minDist = DIST[i];
                u = i;
            }
        }

        // Đánh dấu u đã được duyệt
        S[u] = 1;
        k++;

        // Cập nhật khoảng cách cho tất cả các đỉnh chưa duyệt
        for (int w = 1; w <= n; w++) {
            if (S[w] == 0 && COST[u][w] != INT_MAX) {
                DIST[w] = min(DIST[w], DIST[u] + COST[u][w]);
            }
        }
    }
}

int main() {
    int n, m; // n: số đỉnh, m: số cạnh
    cout << "Nhap so dinh (n): ";
    cin >> n;
    cout << "Nhap so canh (m): ";
    cin >> m;

    // Khởi tạo ma trận COST
    vector<vector<int>> COST(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) {
        COST[i][i] = 0; // Khoảng cách từ đỉnh đến chính nó là 0
    }

    cout << "Nhap cac canh (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        COST[u][v] = w; // Cạnh từ u đến v có trọng số w
        COST[v][u] = w; // Đồ thị vô hướng, vì vậy cần cập nhật cả chiều ngược lại
    }

    int source;
    cout << "Nhap dinh nguon: ";
    cin >> source;

    // Khởi tạo mảng DIST (khoảng cách từ đỉnh nguồn đến tất cả các đỉnh khác)
    vector<int> DIST(n + 1, INT_MAX);
    Dijkstra(source, COST, DIST, n);

    // In kết quả
    cout << "Khoang cach tu dinh " << source << " den cac dinh khac:\n";
    for (int i = 1; i <= n; i++) {
        if (DIST[i] == INT_MAX) {
            cout << "Dinh " << i << ": Khong co duong di\n";
        } else {
            cout << "Dinh " << i << ": " << DIST[i] << endl;
        }
    }

    return 0;
}
