
#include <iostream>

using namespace std;

// Deklarasi fungsi
void cetak(const int data[], int n);
int jumlah(const int data[], int n);
double rataRata(const int data[], int n);
void gandakan(int data[], int n);

int main() {
    // Array nilai
    int nilai[] = {60, 75, 80, 95, 70};

    const int N = sizeof(nilai) / sizeof(nilai[0]);

    // Menampilkan data awal
    cout << "Data awal : ";
    cetak(nilai, N);

    // Menghitung jumlah nilai
    cout << "Jumlah : " << jumlah(nilai, N) << endl;

    // Menghitung rata-rata
    cout << "Rata-rata : " << rataRata(nilai, N) << endl;

    // Menggandakan setiap nilai
    gandakan(nilai, N);

    cout << "Setelah gandakan : ";
    cetak(nilai, N);

    // Menampilkan ukuran array
    cout << "\nsizeof(nilai) di main = "
         << sizeof(nilai) << " byte" << endl;

    return 0;
}

// Fungsi untuk mencetak isi array
void cetak(const int data[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << data[i] << (i + 1 < n ? " " : "\n");
    }
}

// Fungsi untuk menghitung jumlah nilai
int jumlah(const int data[], int n) {
    int total = 0;

    for (int i = 0; i < n; ++i) {
        total += data[i];
    }

    return total;
}

// Fungsi untuk menghitung rata-rata
double rataRata(const int data[], int n) {
    if (n <= 0) {
        return 0.0;
    }

    return static_cast<double>(jumlah(data, n)) / n;
}

// Fungsi untuk menggandakan nilai
void gandakan(int data[], int n) {
    for (int i = 0; i < n; ++i) {
        data[i] *= 2;
    }
}
