#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double readValidatedDouble(string prompt, double minVal) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minVal) return value;
        cout << "Input tidak valid. Masukkan nilai >= " << fixed << setprecision(2) << minVal << ".\n";
        clearInputBuffer();
    }
}

int readValidatedInt(string prompt, int minVal) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minVal) return value;
        cout << "Input tidak valid. Masukkan bilangan bulat >= " << minVal << ".\n";
        clearInputBuffer();
    }
}

// Prakondisi: hargaSatuan >= 0, jumlah >= 0. Pascakondisi: Mengembalikan subtotal.
double calculateSubtotal(double hargaSatuan, int jumlah) {
    return hargaSatuan * jumlah;
}

// Prakondisi: totalSubtotal >= 0. Pascakondisi: Mengembalikan persentase diskon.
double determineDiscountRate(double totalSubtotal) {
    if (totalSubtotal >= 500000) return 0.15;
    if (totalSubtotal >= 250000) return 0.10;
    if (totalSubtotal >= 100000) return 0.05;
    return 0.0;
}

// Prakondisi: totalSubtotal >= 0, discountRate >= 0. Pascakondisi: Mengembalikan nilai diskon.
double calculateDiscountValue(double totalSubtotal, double discountRate) {
    return totalSubtotal * discountRate;
}

// Prakondisi: baseAmount >= 0. Pascakondisi: Mengembalikan nominal pajak 11%.
double calculateTax(double baseAmount) {
    return baseAmount * 0.11;
}

string formatRupiah(double amount) {
    stringstream ss;
    ss << "Rp " << fixed << setprecision(2) << amount;
    return ss.str();
}

// Prakondisi: Semua parameter numerik valid. Pascakondisi: Menampilkan struk.
void printStruk(double totalSubtotal, double discountRate, double discountValue, double netTotal, double tax, double grandTotal, double pembayaran, double kembalian, int totalItems) {
    cout << "\n=========================================\n";
    cout << "             STRUK PEMBELIAN\n";
    cout << "=========================================\n";
    cout << "Total Item: " << totalItems << "\n";
    cout << left << setw(22) << "Total Kotor" << " : " << formatRupiah(totalSubtotal) << "\n";
    cout << left << setw(22) << "Diskon (" + to_string((int)(discountRate * 100)) + "%)" << " : -" << formatRupiah(discountValue) << "\n";
    cout << left << setw(22) << "Total Diskon" << " : " << formatRupiah(netTotal) << "\n";
    cout << left << setw(22) << "PPN (11%)" << " : " << formatRupiah(tax) << "\n";
    cout << "-----------------------------------------\n";
    cout << left << setw(22) << "GRAND TOTAL" << " : " << formatRupiah(grandTotal) << "\n";
    cout << left << setw(22) << "Tunai" << " : " << formatRupiah(pembayaran) << "\n";
    cout << left << setw(22) << "Kembali" << " : " << formatRupiah(kembalian) << "\n";
    cout << "=========================================\n";
}

void processTransaction() {
    int numItems = readValidatedInt("Masukkan jumlah jenis barang (min 1): ", 1);
    double grandSubtotal = 0;
    int totalItems = 0;

    for (int i = 1; i <= numItems; ++i) {
        cout << "\nBarang ke-" << i << "\n";
        cout << "Nama Barang: ";
        string nama;
        cin.ignore();
        getline(cin, nama);

        double harga = readValidatedDouble("Harga Satuan: Rp ", 0.0);
        int qty = readValidatedInt("Jumlah: ", 1);

        grandSubtotal += calculateSubtotal(harga, qty);
        totalItems += qty;
    }

    double discRate = determineDiscountRate(grandSubtotal);
    double discVal = calculateDiscountValue(grandSubtotal, discRate);
    double netTotal = grandSubtotal - discVal;
    double tax = calculateTax(netTotal);
    double grandTotal = netTotal + tax;

    cout << "\nGrand Total (inc. PPN): " << formatRupiah(grandTotal) << "\n";

    double pembayaran;
    do {
        pembayaran = readValidatedDouble("Pembayaran Tunai: Rp ", 0.0);
        if (pembayaran < grandTotal) cout << "Uang kurang! Silakan ulangi.\n";
    } while (pembayaran < grandTotal);

    printStruk(grandSubtotal, discRate, discVal, netTotal, tax, grandTotal, pembayaran, pembayaran - grandTotal, totalItems);
}

int main() {
    int menu;
    do {
        cout << "\n[1] Transaksi Baru\n[2] Keluar\nPilih menu: ";
        if (!(cin >> menu) || (menu != 1 && menu != 2)) {
            cout << "Pilihan tidak valid.\n";
            clearInputBuffer();
            continue;
        }
        if (menu == 1) processTransaction();
    } while (menu != 2);
    
    cout << "Program selesai.\n";
    return 0;
}