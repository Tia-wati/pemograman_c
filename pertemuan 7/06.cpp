
#include <iostream>

// Mengembalikan indeks kemunculan pertama,
// atau -1 jika target tidak ditemukan.
int cariPertama(const int data[], int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (data[i] == target) {
            return i;
        }
    }

    return -1;
}

// Menghitung berapa kali target muncul.
int hitungKemunculan(const int data[], int n, int target) {
    int jumlah = 0;

    for (int i = 0; i < n; ++i) {
        if (data[i] == target) {
            ++jumlah;
        }
    }

    return jumlah;
}

// Mencetak semua posisi kemunculan target.
void cetakPosisi(const int data[], int n, int target) {
    bool ada = false;

    std::cout << "Posisi " << target << " : ";

    for (int i = 0; i < n; ++i) {
        if (data[i] == target) {
            std::cout << i << ' ';
            ada = true;
        }
    }

    if (!ada) {
        std::cout << "(tidak ada)";
    }

    std::cout << '\n';
}

int main() {
    const int N = 8;

    int data[N] = {25, 7, 40, 7, 18, 7, 90, 33};

    // Menampilkan data array.
    std::cout << "Data: ";

    for (int x : data) {
        std::cout << x << ' ';
    }

    std::cout << "\n\n";

    // Mencari angka 7.
    int target = 7;

    int posisi = cariPertama(data, N, target);

    std::cout << "cariPertama(" << target << ") = "
              << posisi << '\n';

    std::cout << "hitungKemunculan(" << target << ") = "
              << hitungKemunculan(data, N, target) << '\n';

    cetakPosisi(data, N, target);

    // Mencari angka 99.
    target = 99;

    posisi = cariPertama(data, N, target);

    std::cout << "\ncariPertama(" << target << ") = "
              << posisi << " (tidak ditemukan)\n";

    return 0;
}
