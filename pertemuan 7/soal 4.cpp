#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[6] = {29, 10, 14, 37, 13, 5};

    for (int i = 0; i < 2; ++i) {
        int m = i;

        for (int j = i + 1; j < 6; ++j) {
            if (a[j] < a[m]) {
                m = j;
            }
        }

        swap(a[i], a[m]);
    }

    cout << a[0] << ' '
         << a[1] << ' '
         << a[2];

    return 0;
}
