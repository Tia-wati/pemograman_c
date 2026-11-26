
#include <iostream>

int main() {
    const int N = 8;
    int data[N] = {12, 7, 19, 4, 25, 7, 30, 16};

    // 1. Menggunakan for dengan indeks
    std::cout << "1) for dengan indeks: ";

    for (int i = 0; i < N; ++i) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';

    // 2. Menggunakan while
    std::cout << "2) while : ";

    int i = 0;

    while (i < N) {
        std::cout << data[i] << ' ';
        ++i;
    }
    std::cout << '\n';

    // 3. Menggunakan range-based for
    std::cout << "3) range-based for : ";

    for (int x : data) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // Mengubah elemen asli menggunakan referensi
    for (int& x : data) {
        x *= 2;
    }

    // 4. Menampilkan array setelah setiap elemen dikali 2
    std::cout << "4) setelah x *= 2 : ";

    for (int x : data) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // Menghitung total dan jumlah elemen genap
    int total = 0;
    int genap = 0;

    for (int x : data) {
        total += x;

        if (x % 2 == 0) {
            ++genap;
        }
    }

    std::cout << "\nTotal semua elemen : " << total << '\n';
    std::cout << "Banyak elemen genap: " << genap << '\n';

    return 0;
}
