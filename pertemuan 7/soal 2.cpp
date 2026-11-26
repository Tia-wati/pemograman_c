
#include <iostream>
using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5 / 2; ++i) {
        int t = a[i];
        a[i] = a[4 - i];
        a[4 - i] = t;
    }

    cout << a[1] << a[3];

    return 0;
}
