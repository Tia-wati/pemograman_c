
#include <iostream>
using namespace std;

void ubah(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        a[i] += i;
    }
}

int main() {
    int a[] = {10, 20, 30};

    ubah(a, 3);

    cout << a[0] << ' ' << a[2];

    return 0;
}
