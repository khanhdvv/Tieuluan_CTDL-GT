#include<bits/stdc++.h>
using namespace std;

void ThapHN(int n, int a, int b, int c)
{
    if(n == 1)
    {
        cout << a << " -> " << c <<endl;
        return;
    }
    
    ThapHN(n - 1, a, c, b); // Chuyển n - 1 đĩa từ cọc 1 sang cọc 2, cọc 3 là trung gian.
    ThapHN(1, a, b, c); // Chuyển 1 đĩa còn lại từ cọc 1 sang cọc 3.
    ThapHN(n - 1, b, a, c); // Chuyển n - 1 đĩa từ cọc 2 sang cọc 3, cọc 1 là trung gian.
}

int main()
{
    int n;
    cout <<"Nhap n: ";
    cin >> n;

    int a = 1, b = 2, c = 3;
    ThapHN(n, a, b, c); // Giải bài toán với n đĩa.

}
