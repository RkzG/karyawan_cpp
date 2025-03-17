#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct Karyawan {
    int id;
    string nama;
    string tempatLahir;
    string tanggalLahir;
    string jabatan;
    Karyawan* next;
};

Karyawan* head = nullptr;
int jumlahData = 0;
const int MAX_KARYAWAN = 5;

bool validasiID(int id) {
    return (id > 0 && id <= 99999);
}

bool validasiPanjang(const string& str, int maxLength) {
    return (str.length() <= maxLength);
}

void tambahKaryawan() {
    if (jumlahData >= MAX_KARYAWAN) {
        cout << "\nDatabase sudah penuh!\n";
        return;
    }
    
    int id;
    string nama, tempat, tanggal, jabatan;
    
    cout << "Masukkan ID Karyawan (max 5 angka): ";
    cin >> id;
    if (!validasiID(id)) {
        cout << "ID tidak valid!\n";
        return;
    }
    
    cin.ignore();
    cout << "Masukkan Nama Lengkap (max 30 karakter): ";
    getline(cin, nama);
    if (!validasiPanjang(nama, 30)) {
        cout << "Nama terlalu panjang!\n";
        return;
    }
    
    cout << "Masukkan Tempat Lahir (max 30 karakter): ";
    getline(cin, tempat);
    if (!validasiPanjang(tempat, 30)) {
        cout << "Tempat lahir terlalu panjang!\n";
        return;
    }
    
    cout << "Masukkan Tanggal Lahir (DD-MM-YYYY): ";
    getline(cin, tanggal);
    
    cout << "Masukkan Jabatan (max 50 karakter): ";
    getline(cin, jabatan);
    if (!validasiPanjang(jabatan, 50)) {
        cout << "Jabatan terlalu panjang!\n";
        return;
    }
    
    Karyawan* baru = new Karyawan{id, nama, tempat, tanggal, jabatan, nullptr};
    
    if (!head) {
        head = baru;
    } else {
        Karyawan* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    jumlahData++;
    cout << "\nKaryawan berhasil ditambahkan!\n";
}

void tampilkanKaryawan() {
    if (!head) {
        cout << "\nDatabase kosong!\n";
        return;
    }
    
    cout << "\nDaftar Karyawan:\n";
    Karyawan* temp = head;
    while (temp) {
        cout << "ID: " << temp->id << "\nNama: " << temp->nama
             << "\nTempat/Tgl Lahir: " << temp->tempatLahir << ", " << temp->tanggalLahir
             << "\nJabatan: " << temp->jabatan << "\n\n";
        temp = temp->next;
    }
}

void hapusKaryawan() {
    if (!head) {
        cout << "\nDatabase kosong!\n";
        return;
    }
    
    int id;
    cout << "Masukkan Employee ID yang akan dihapus: ";
    cin >> id;
    
    if (!validasiID(id)) {
        cout << "ID tidak valid!\n";
        return;
    }
    
    Karyawan* temp = head;
    Karyawan* prev = nullptr;
    
    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    if (!temp) {
        cout << "Karyawan dengan ID " << id << " tidak ditemukan!\n";
        return;
    }
    
    if (!prev) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    delete temp;
    jumlahData--;
    cout << "Karyawan berhasil dihapus!\n";
}

void hapusSemua() {
    while (head) {
        Karyawan* temp = head;
        head = head->next;
        delete temp;
    }
    jumlahData = 0;
    cout << "\nSemua data karyawan telah dihapus!\n";
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Karyawan\n";
        cout << "2. Tampilkan Semua Karyawan\n";
        cout << "3. Hapus Karyawan berdasarkan ID\n";
        cout << "4. Hapus Semua Data Karyawan\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (pilihan) {
            case 1: tambahKaryawan(); break;
            case 2: tampilkanKaryawan(); break;
            case 3: hapusKaryawan(); break;
            case 4: hapusSemua(); break;
            case 5: cout << "Keluar dari program...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}
