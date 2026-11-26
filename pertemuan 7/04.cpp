
#include <array>
#include <iostream>
#include <stdexcept>

// Mengembalikan nilai pada indeks tertentu,
// atau -1 bila indeks tidak sah.
int ambilAman(const int data[], int ukuran, int indeks) {
    if (indeks < 0 || indeks >= ukuran) {
        return -1;
    }

    return data[indeks];
}

int main() {
    int data[4] = {10, 20, 30, 40};
    const int N = 4;

    std::cout << "data[2] = "
              << ambilAman(data, N, 2) << '\n';

    std::cout << "data[4] (di luar) = "
              << ambilAman(data, N, 4)
              << " (penanda indeks tidak sah)\n";

    std::cout << "data[-1] (di luar) = "
              << ambilAman(data, N, -1)
              << " (penanda indeks tidak sah)\n";

    // std::array::at() memeriksa batas
    // dan melempar exception jika indeks tidak sah.
    std::array<int, 4> aman = {1, 2, 3, 4};

    try {
        std::cout << "aman.at(10) = "
                  << aman.at(10) << '\n';
    }
    catch (const std::out_of_range& e) {
        std::cout << "aman.at(10) ditolak: "
                  << e.what() << '\n';
    }

    // Baris berikut SENGAJA tidak dijalankan
    // karena dapat menyebabkan undefined behavior:
    // data[4] = 99;
    // std::cout << data[4];

    // Jangan pernah mengandalkan "kebetulan berjalan"
    // pada kode seperti itu.
    std::cout << "\nSelalu gunakan indeks 0 sampai "
              << N - 1 << ".\n";

    return 0;
}
