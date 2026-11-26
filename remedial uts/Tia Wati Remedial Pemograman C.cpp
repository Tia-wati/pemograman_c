#include <iostream>
#include <iomanip>

int main() {
    int n;
    int suku = 3;
    int jumlah = 0;
    int genap = 0;
    double rataRata;

    std::cout << "Masukkan jumlah suku: ";
    std::cin >> n;

    if (n < 1 || n > 40) {
        std::cout << "Input tidak valid";
        return 0;
    }

    std::cout << "Deret     : ";

    for (int i = 0; i < n; i++) {
        std::cout << suku << " ";

        jumlah += suku;

        if (suku % 2 == 0) {
            genap++;
        }

        suku += 5;
    }

    rataRata = static_cast<double>(jumlah) / n;

    std::cout << "\nJumlah    : " << jumlah << '\n';

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Rata-rata : " << rataRata << '\n';

    std::cout << "Genap     : " << genap << '\n';

    return 0;
}
