
#include <iostream>

// Fungsi untuk membalik urutan array
void balik(int data[], int n) {
    int kiri = 0;
    int kanan = n - 1;

    while (kiri < kanan) {
        int sementara = data[kiri];
        data[kiri] = data[kanan];
        data[kanan] = sementara;

        ++kiri;
        --kanan;
    }
}

// Fungsi untuk memeriksa apakah array merupakan palindrom
bool palindrom(const int data[], int n) {
    int kiri = 0;
    int kanan = n - 1;

    while (kiri < kanan) {
        if (data[kiri] != data[kanan]) {
            return false;
        }

        ++kiri;
        --kanan;
    }

    return true;
}

// Fungsi untuk menampilkan isi array
void cetak(const int data[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << data[i] << (i + 1 < n ? " " : "\n");
    }
}

int main() {
    // Array nilai awal
    int nilai[] = {10, 20, 30, 40, 50};

    const int N = static_cast<int>(
        sizeof(nilai) / sizeof(nilai[0])
    );

    // Menampilkan array sebelum dibalik
    std::cout << "Sebelum dibalik : ";
    cetak(nilai, N);

    // Membalik urutan array
    balik(nilai, N);

    // Menampilkan array setelah dibalik
    std::cout << "Setelah dibalik : ";
    cetak(nilai, N);

    // Membuat dua array untuk pengujian palindrom
    int a[] = {1, 2, 3, 2, 1};
    int b[] = {1, 2, 3, 4, 5};

    // Memeriksa array pertama
    std::cout << "\n{1,2,3,2,1} palindrom? "
              << (palindrom(a, 5) ? "ya" : "tidak")
              << '\n';

    // Memeriksa array kedua
    std::cout << "{1,2,3,4,5} palindrom? "
              << (palindrom(b, 5) ? "ya" : "tidak")
              << '\n';

    return 0;
}
