
#include <iomanip>
#include <iostream>

const int BARIS = 3;
const int KOLOM = 4;

// Fungsi untuk mencetak matriks
void cetakMatriks(const int m[][KOLOM], int baris) {
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < KOLOM; ++j) {
            std::cout << std::setw(5) << m[i][j];
        }
        std::cout << '\n';
    }
}

int main() {
    // Membuat matriks berukuran 3 x 4
    int m[BARIS][KOLOM] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 11, 22, 33}
    };

    // Menampilkan matriks
    std::cout << "Matriks " << BARIS << 'x' << KOLOM << ":\n";
    cetakMatriks(m, BARIS);

    // Menghitung total seluruh elemen
    int total = 0;

    for (int i = 0; i < BARIS; ++i) {
        for (int j = 0; j < KOLOM; ++j) {
            total += m[i][j];
        }
    }

    std::cout << "\nTotal seluruh elemen: " << total << '\n';

    // Menghitung jumlah setiap baris
    std::cout << "Jumlah per baris:\n";

    for (int i = 0; i < BARIS; ++i) {
        int jumlahBaris = 0;

        for (int j = 0; j < KOLOM; ++j) {
            jumlahBaris += m[i][j];
        }

        std::cout << "Baris " << i << " = "
                  << jumlahBaris << '\n';
    }

    // Menghitung jumlah setiap kolom
    std::cout << "Jumlah per kolom:\n";

    for (int j = 0; j < KOLOM; ++j) {
        int jumlahKolom = 0;

        for (int i = 0; i < BARIS; ++i) {
            jumlahKolom += m[i][j];
        }

        std::cout << "Kolom " << j << " = "
                  << jumlahKolom << '\n';
    }

    // Transpose matriks (menukar baris dan kolom)
    int t[KOLOM][BARIS];

    for (int i = 0; i < BARIS; ++i) {
        for (int j = 0; j < KOLOM; ++j) {
            t[j][i] = m[i][j];
        }
    }

    // Menampilkan hasil transpose
    std::cout << "\nTranspose "
              << KOLOM << 'x' << BARIS << ":\n";

    for (int i = 0; i < KOLOM; ++i) {
        for (int j = 0; j < BARIS; ++j) {
            std::cout << std::setw(5) << t[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}
