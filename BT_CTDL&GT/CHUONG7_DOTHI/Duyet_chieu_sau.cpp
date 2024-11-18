#include <bits/stdc++.h>
using namespace std;

int n, m; // n: số đỉnh, m: số cạnh
vector<int> adj[1001]; // Danh sách kề
bool visited[1001];    // Mảng đánh dấu các đỉnh đã thăm

// Hàm nhập đồ thị
void inp() {
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;

    cout << "Nhap cac canh (dinh1 dinh2):\n";
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm cạnh x -> y
        adj[y].push_back(x); // Thêm cạnh y -> x (đồ thị vô hướng)
    }

    // Đặt tất cả các đỉnh là chưa được thăm
    memset(visited, false, sizeof(visited));
}

// Hàm DFS sử dụng đệ quy
void DFS(int v) {
    cout << v << " ";       // In đỉnh đang thăm
    visited[v] = true;      // Đánh dấu đỉnh u đã được thăm

    for (int w : adj[v]) {  // Duyệt các đỉnh kề của u
        if (!visited[w]) {  // Nếu đỉnh kề chưa được thăm
            DFS(w);         // Gọi DFS đệ quy trên đỉnh đó
        }
    }
}

int main() {
    inp(); // Nhập đồ thị
    cout << "Thu tu cac dinh duoc tham: ";
    DFS(1); // Bắt đầu duyệt DFS từ đỉnh 1
    cout << endl;
    return 0;
}
