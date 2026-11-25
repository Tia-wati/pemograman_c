#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string namaBarang;
    double hargaSatuan, persenDiskon;

    int jumlahBeli;

    const double PPN = 0.11;

    std::cout << "Nama barang : ";
    std::cin >> namaBarang;

    std::cout << "Harga satuan : ";
    std::cin >> hargaSatuan;

    std::cout << "Jumlah beli : ";
    std::cin >> jumlahBeli;

    std::cout << "Diskon (%) : ";
    std::cin >> persenDiskon;

    double subtotal = hargaSatuan * jumlahBeli;
    double potonganDiskon = subtotal * persenDiskon / 100.0;
    double setelahDiskon = subtotal - potonganDiskon;
    double ppn = setelahDiskon * PPN;
    double totalBayar = setelahDiskon + ppn;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n===== STRUK PEMBELIAN =====\n";

    std::cout << std::left
              << std::setw(18) << "Barang"
              << ": " << namaBarang << '\n';

    std::cout << std::setw(18) << "Harga satuan"
              << ": Rp " << hargaSatuan << '\n';

    std::cout << std::setw(18) << "Jumlah"
              << ": " << jumlahBeli << '\n';

    std::cout << std::setw(18) << "Subtotal"
              << ": Rp " << subtotal << '\n';

    std::cout << std::setw(18) << ("Diskon (" + std::to_string((int)persenDiskon) + "%)")
              << ": Rp " << potonganDiskon << '\n';

    std::cout << std::setw(18) << "Setelah diskon"
              << ": Rp " << setelahDiskon << '\n';

    std::cout << std::setw(18) << "PPN 11%"
              << ": Rp " << ppn << '\n';

    std::cout << std::setw(18) << "Total bayar"
              << ": Rp " << totalBayar << '\n';

    std::cout << "===========================\n";

    return 0;
}