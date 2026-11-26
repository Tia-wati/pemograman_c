
#include <iostream>
using namespace std;

int main() {
    int m[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int s = 0;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((i + j) % 2 == 0) {
                s += m[i][j];
            }
        }
    }

    cout << s;

    return 0;
}
