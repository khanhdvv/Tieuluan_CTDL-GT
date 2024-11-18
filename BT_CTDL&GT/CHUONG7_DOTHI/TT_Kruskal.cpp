#include <bits/stdc++.h>
using namespace std;

// Cấu trúc biểu diễn cạnh
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

// So sánh các cạnh theo trọng số (để sắp xếp)
bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

// Tìm đại diện của một tập hợp
int findSet(int u, vector<int>& parent) {
    if (u != parent[u]) {
        parent[u] = findSet(parent[u], parent); // Tìm gốc và nén đường đi
    }
    return parent[u];
}

// Hợp hai tập hợp
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findSet(u, parent);
    v = findSet(v, parent);

    if (u != v) {
        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main() {
    int n, m; // n: số đỉnh, m: số cạnh
    cout << "Nhap so dinh: ";
    cin >> n;
	cout << "Nhap so canh: ";
	cin >> m;
	
    vector<Edge> edges; // Danh sách các cạnh

    cout << "Nhap cac canh (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compare);

    // Cấu trúc dữ liệu cho Disjoint Set
    vector<int> parent(n + 1), rank(n + 1, 0);

    // Khởi tạo mỗi đỉnh là một tập hợp riêng lẻ
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<Edge> mst; // Danh sách các cạnh trong cây khung nhỏ nhất
    int totalWeight = 0; // Tổng trọng số của cây khung nhỏ nhất

    // Duyệt qua các cạnh
    for (Edge e : edges) {
        int u = e.u, v = e.v, w = e.w;

        // Nếu thêm cạnh này không tạo chu trình
        if (findSet(u, parent) != findSet(v, parent)) {
            mst.push_back(e); // Đưa cạnh vào cây khung
            totalWeight += w; // Cộng trọng số
            unionSet(u, v, parent, rank); // Hợp nhất hai tập hợp
        }

        // Nếu đã đủ (n - 1) cạnh, dừng lại
        if (mst.size() == n - 1) break;
    }

    // In kết quả
    cout << "Cac canh trong cay khung nho nhat:\n";
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " - " << e.w << endl;
    }
    cout << "Tong trong so cua cay khung nho nhat: " << totalWeight << endl;

    return 0;
}
