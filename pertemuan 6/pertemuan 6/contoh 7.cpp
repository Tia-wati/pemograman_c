#include <iostream>

void hitungPanggilan() {
	int biasa = 0;         // diinalisasi ulang pada setiap panggilan
	static int statis = 0; // diinalisasi sekali, lalu nilainya bertahan
	
	++biasa,
	++statis;
	
	std::cout << "biasa = " << biasa
	          << " , statis = " << statis << '\n';
}

void cetakIdSesi() {
	static int id = 100;  // id sesi yang konsisten selama program berjalan 
	++id;
	std::cout << "ID sesi berikutnya: " << id << '/n';
}

int main() {
	std::cout << "=== Demo id sesi ===\n";
	cetakIdSesi();
	cetakIdSesi();
	cetakIdSesi();
	
	return 0;
	
}