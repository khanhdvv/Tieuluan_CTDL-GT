#include <iostream>
using namespace std;

// Hàm Selection Sort với minh họa từng bước
void SelectionSorting(int a[], int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min_index] > a[j]) {
                min_index = j;
            }
        }
        tmp = a[min_index];
        a[min_index] = a[i];
        a[i] = tmp;

        // In trạng thái mảng sau mỗi vòng lặp bên ngoài
        cout << "Buoc " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

// Hàm Insertion Sort với minh họa từng bước
void InsertionSorting(int a[], int n) {
    int x, i, j;
    for (i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;
        while (j >= 0 && x < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;

        // In trạng thái mảng sau mỗi vòng lặp bên ngoài
        cout << "Buoc " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

// Hàm Bubble Sort với minh họa từng bước
void BubbleSorting(int a[], int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = true;
            }
        }
        // In trạng thái mảng sau mỗi vòng lặp bên ngoài
        cout << "Buoc " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;

        // Dừng sớm nếu không còn hoán đổi
        if (!swapped) break;
    }
}

// Hàm Quick Sort với minh họa từng bước
void QuickSort(int a[], int l, int r, int step = 1) {
    int tmp;
    int i = l, j = r;
    int x = a[(l + r) / 2];
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

    if (l < j) QuickSort(a, l, j, step);
    if (i < r) QuickSort(a, i, r, step);
}

// Hàm Heap Sort với minh họa từng bước
void SetupHeap(int a[], int k, int n) {
    int x = a[k];
    while (k < n / 2) {
        int j = 2 * k + 1;
        if (j + 1 < n && a[j] < a[j + 1]) j++;
        if (x >= a[j]) break;
        a[k] = a[j];
        k = j;
    }
    a[k] = x;
}

void MakeHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        SetupHeap(a, i, n);
    }
}

void Heapsort(int a[], int n) {
    int tmp;
    MakeHeap(a, n);
    cout << "Mang sau khi tao Heap: ";
    for (int k = 0; k < n; k++) {
        cout << a[k] << " ";
    }
    cout << endl;

    for (int i = n - 1; i > 0; i--) {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        SetupHeap(a, 0, i);

        // In trạng thái mảng sau mỗi bước
        cout << "Buoc " << n - i << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
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
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int choice;
    bool continueMenu = true; // Biến kiểm soát vòng lặp menu

    while (continueMenu) {
        cout << "\nMang ban dau: ";
        printArray(a, n);

        cout << "\n===============Menu============";
        cout << "\n1. Selection Sort\n";
        cout << "\n2. Insertion Sort\n";
        cout << "\n3. Bubble Sort\n";
        cout << "\n4. Quick Sort\n";
        cout << "\n5. Heap Sort\n";
        cout << "\n6. Thoat chuong trinh\n";
        cout <<"\n==============================";
        cout << "\nNhap lua chon: ";
        cin >> choice;

        // Tạo bản sao mảng gốc để không thay đổi dữ liệu khi thực hiện lại
        int temp[n];
        for (int i = 0; i < n; i++) {
            temp[i] = a[i];
        }

        switch (choice) {
            case 1:
                cout << "Selection Sort:\n";
                SelectionSorting(temp, n);
                break;
            case 2:
                cout << "Insertion Sort:\n";
                InsertionSorting(temp, n);
                break;
            case 3:
                cout << "Bubble Sort:\n";
                BubbleSorting(temp, n);
                break;
            case 4:
                cout << "Quick Sort:\n";
                QuickSort(temp, 0, n - 1);
                break;
            case 5:
                cout << "Heap Sort:\n";
                Heapsort(temp, n);
                break;
            case 6:
                cout << "Thoat chuong trinh.\n";
                continueMenu = false; // Thoát vòng lặp
                break;
            default:
                cout << "Lua chon khong hop le! Vui long nhap lai.\n";
        }

        if (choice >= 1 && choice <= 5) {
            cout << "Mang sau khi sap xep: ";
            printArray(temp, n);
        }
    }

    return 0;
}
