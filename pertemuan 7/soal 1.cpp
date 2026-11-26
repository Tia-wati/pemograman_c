
#include <iostream>
using namespace std;

int main() {
    int a[5] = {3, 6};
    int s = 0;

    for (int i = 0; i < 5; ++i) {
        s += a[i];
    }

    cout << "Hasil penjumlahan = " << s << endl;

    return 0;
}

