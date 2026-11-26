
#include <iostream>

// Fungsi Binary Search Iteratif
int binaryIteratif(const int data[], int n, int target, int& langkah) {
    int kiri = 0;
    int kanan = n - 1;
    langkah = 0;

    while (kiri <= kanan) {
        ++langkah;

        int tengah = kiri + (kanan - kiri) / 2;

        if (data[tengah] == target) {
            return tengah;
        }

        if (data[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return -1;
}

// Fungsi Binary Search Rekursif
int binaryRekursif(
    const int data[],
    int kiri,
    int kanan,
    int target,
    int& langkah
) {
    if (kiri > kanan) {
        return -1;
    }

    ++langkah;

    int tengah = kiri + (kanan - kiri) / 2;

    if (data[tengah] == target) {
        return tengah;
    }

    if (data[tengah] < target) {
        return binaryRekursif(
            data, tengah + 1, kanan, target, langkah
        );
    }

    return binaryRekursif(
        data, kiri, tengah - 1, target, langkah
    );
}

// Fungsi Utama
int main() {
    const int N = 10;

    int data[N] = {
        11, 22, 30, 33, 45,
        57, 60, 78, 90, 99
    };

    std::cout << "Data terurut: ";

    for (int x : data) {
        std::cout << x << ' ';
    }

    std::cout << "\n\n";

    int target[] = {30, 33, 100};

    for (int t : target) {
        int langkah = 0;

        // Pencarian Iteratif
        int posisi = binaryIteratif(
            data, N, t, langkah
        );

        std::cout << "Iteratif cari " << t
                  << " -> indeks " << posisi
                  << " (" << langkah << " langkah)\n";

        // Pencarian Rekursif
        langkah = 0;

        posisi = binaryRekursif(
            data, 0, N - 1, t, langkah
        );

        std::cout << "Rekursif cari " << t
                  << " -> indeks " << posisi
                  << " (" << langkah << " langkah)\n";
    }

    return 0;
}
