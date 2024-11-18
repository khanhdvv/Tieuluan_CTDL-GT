#include <bits/stdc++.h>
using namespace std;

int n, m; // n: số đỉnh, m: số cạnh
vector<int> adj[1001]; // Danh sách kề
bool visited[1001];    // Mảng đánh dấu các đỉnh đã được thăm

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

// Hàm BFS sử dụng hàng đợi
void BFS(int v) {
    queue<int> q;         // Tạo hàng đợi để lưu các đỉnh sẽ được duyệt
    visited[v] = true; // Đánh dấu đỉnh bắt đầu là đã thăm
    q.push(v);        // Đưa đỉnh bắt đầu vào hàng đợi

    while (!q.empty()) {  // Trong khi hàng đợi không rỗng
        int w = q.front(); // Lấy đỉnh ở đầu hàng đợi
        q.pop();           // Xóa đỉnh đó khỏi hàng đợi
        cout << w << " ";  // In ra đỉnh đang được duyệt

        // Duyệt các đỉnh kề của w
        for (int x : adj[w]) {
            if (!visited[x]) {  // Nếu đỉnh kề chưa được thăm
                visited[x] = true; // Đánh dấu đã thăm
                q.push(x);         // Đưa đỉnh đó vào hàng đợi
            }
        }
    }
}

int main() {
    inp(); // Nhập đồ thị
    cout << "Thu tu cac dinh duoc tham (BFS): ";
    BFS(1); // Bắt đầu duyệt BFS từ đỉnh 1
    cout << endl;
    return 0;
}
