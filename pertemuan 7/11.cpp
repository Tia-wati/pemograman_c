
#include <iostream>

// Fungsi untuk mengurutkan data menggunakan Bubble Sort
void bubbleSort(int data[], int n,
                long long& perbandingan,
                long long& pertukaran) {

    perbandingan = 0;
    pertukaran = 0;

    for (int lintasan = 0; lintasan < n - 1; ++lintasan) {
        bool adaTukar = false;

        // Membandingkan elemen yang bersebelahan
        for (int i = 0; i < n - 1 - lintasan; ++i) {
            ++perbandingan;

            if (data[i] > data[i + 1]) {
                int sementara = data[i];

                data[i] = data[i + 1];
                data[i + 1] = sementara;

                ++pertukaran;
                adaTukar = true;
            }
        }

        // Berhenti jika tidak ada pertukaran
        if (!adaTukar) {
            break;
        }
    }
}

// Fungsi untuk menampilkan isi array
void cetak(const int data[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << data[i];

        if (i + 1 < n) {
            std::cout << " ";
        }
    }

    std::cout << '\n';
}

// Fungsi utama program
int main() {
    // Data awal
    int data[] = {
        64, 34, 25, 12, 22, 11, 90, 45
    };

    const int N = sizeof(data) / sizeof(data[0]);

    // Menampilkan data sebelum diurutkan
    std::cout << "Sebelum : ";
    cetak(data, N);

    // Variabel untuk menghitung perbandingan dan pertukaran
    long long banding = 0;
    long long tukar = 0;

    // Memanggil fungsi Bubble Sort
    bubbleSort(data, N, banding, tukar);

    // Menampilkan data setelah diurutkan
    std::cout << "Sesudah : ";
    cetak(data, N);

    // Menampilkan jumlah perbandingan dan pertukaran
    std::cout << "\nPerbandingan : " << banding << '\n';
    std::cout << "Pertukaran : " << tukar << '\n';

    return 0;
}
