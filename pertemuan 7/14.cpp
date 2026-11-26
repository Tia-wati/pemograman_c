
#include <iomanip>
#include <iostream>

const int M = 2; // Baris matriks A
const int N = 3; // Kolom A = Baris B
const int P = 2; // Kolom matriks B

// Fungsi untuk mencetak matriks C dan B
void cetak(const int mat[][P], int baris) {
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < P; ++j) {
            std::cout << std::setw(5) << mat[i][j];
        }
        std::cout << '\n';
    }
}

// Fungsi untuk mencetak matriks A
void cetakA(const int mat[][N], int baris) {
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(5) << mat[i][j];
        }
        std::cout << '\n';
    }
}

int main() {
    // Membuat matriks A berukuran 2 x 3
    int a[M][N] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Membuat matriks B berukuran 3 x 2
    int b[N][P] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    // Matriks C sebagai hasil perkalian
    int c[M][P] = {};

    // Proses perkalian matriks A x B
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            for (int k = 0; k < N; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Menampilkan matriks A
    std::cout << "A (" << M << 'x' << N << "):\n";
    cetakA(a, M);

    // Menampilkan matriks B
    std::cout << "\nB (" << N << 'x' << P << "):\n";
    cetak(b, N);

    // Menampilkan hasil perkalian matriks
    std::cout << "\nC = A x B (" << M << 'x' << P << "):\n";
    cetak(c, M);

    // Verifikasi hasil perkalian
    std::cout << "\nC[0][0] seharusnya 58 -> "
              << c[0][0] << '\n';

    return 0;
}
