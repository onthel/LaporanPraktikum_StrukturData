#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama;
    int nim;
    Node* next;
};

Node* head;
Node* tail;

void init() {
    head = NULL;
    tail = NULL;
}

bool isEmpty() {
    return head == NULL;
}

void insertDepan(string nama, int nim) { 
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim; 
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, int nim) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList() {
    Node* hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

void insertTengah(string nama, int nim, int posisi) {
    if (posisi < 1 || posisi > hitungList() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node* baru = new Node();
        baru->nama = nama;
        baru->nim = nim;
        Node* bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusTengah(int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi diluar jangkauan" << endl;
        } else {
            Node* hapus;
            Node* bantu = head;
            Node* prev = nullptr;
            int nomor = 1;
            while (nomor < posisi) {
                prev = bantu;
                bantu = bantu->next;
                nomor++;
            }
            hapus = bantu;
            if (prev != nullptr) {
                prev->next = bantu->next;
            } else {
                head = bantu->next;
            }
            if (bantu == tail) {
                tail = prev;
            }
            delete hapus;
            cout << "Node pada posisi " << posisi << " berhasil dihapus" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(string nama, int nim, string nama_lama) {
    if (!isEmpty()) {
        Node* bantu = head;
        while (bantu != nullptr && bantu->nama != nama_lama) {
            bantu = bantu->next;
        }
        if (bantu != nullptr) {
            bantu->nama = nama;
            bantu->nim = nim;
            cout << "Node dengan nama '" << nama_lama << "' berhasil diubah menjadi '" << nama << "' dengan NIM baru " << nim << endl;
        } else {
            cout << "Node dengan nama '" << nama_lama << "' tidak ditemukan" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void hapusDepan() {
    if (!isEmpty()) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Node pertama berhasil dihapus" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void hapusBelakang() {
    if (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = NULL;
        }
        cout << "Node terakhir berhasil dihapus" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void hapusList() {
    while (!isEmpty()) {
        hapusDepan();
    }
}

void tampil() {
    cout << "DATA MAHASISWA\n\n";
    cout << "---------------------------------\n";
    cout << setw(15) << left << "NAMA" << setw(10) << "NIM" << endl;
    cout << "---------------------------------\n";
    if (!isEmpty()) {
        Node* bantu = head;
        while (bantu != NULL) {
            cout << setw(15) << left << bantu->nama << setw(10) << bantu->nim << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
    cout << "---------------------------------\n";
}


int main() {
    init();
    string nama;
    int nim;
    int choice;
    cout << "Masukkan nama anda: ";
    cin >> nama;
    cout << "Masukkan NIM anda: ";
    cin >> nim;
    insertBelakang(nama, nim); 

    while (true) {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;

        cout << "Pilih Operasi: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "-Tambah Depan\n" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                insertDepan(nama, nim);
                cout << "Data telah ditambahkan";
                break;
            }
            case 2: {
                cout << "-Tambah Belakang\n" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                insertBelakang(nama, nim);
                cout << "Data telah ditambahkan";
                break;
            }
            case 3: {
                cout << "-Tambah Tengah\n" << endl;
                int posisi;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                insertTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan";
                break;
            }
            case 4: {
                cout << "-Ubah Depan\n" << endl;
                string nama_baru;
                int nim_baru;
                cout << "Masukkan nama baru: ";
                cin >> nama_baru;
                cout << "Masukkan NIM baru: ";
                cin >> nim_baru;
                string nama_lama = head->nama;
                ubahTengah(nama_baru, nim_baru, head->nama);
                cout << "Data (" << nama_lama << ") telah terganti dengan data '" << nama_baru << "'" << endl;
                break;
            }
            case 5: {
                cout << "-Ubah Belakang\n" << endl;
                string nama_baru;
                int nim_baru;
                cout << "Masukkan nama baru: ";
                cin >> nama_baru;
                cout << "Masukkan NIM baru: ";
                cin >> nim_baru;
                string nama_lama = tail->nama;
                ubahTengah(nama_baru, nim_baru, tail->nama);
                cout << "Data (" << nama_lama << ") telah terganti dengan data '" << nama_baru << "'" << endl;
                break;
            }
            case 6: {
                cout << "-Ubah Tengah\n" << endl;
                if (!isEmpty()) {
                    int posisi;
                    cout << "Masukkan posisi yang ingin diubah: ";
                    cin >> posisi;
                    string nama_baru;
                    int nim_baru;
                    cout << "Masukkan nama baru: ";
                    cin >> nama_baru;
                    cout << "Masukkan NIM baru: ";
                    cin >> nim_baru;
                    Node* bantu = head;
                    int nomor = 1;
                    while (nomor < posisi) {
                        bantu = bantu->next;
                        nomor++;
                    }
                    string nama_lama = bantu->nama;
                    ubahTengah(nama_baru, nim_baru, bantu->nama);
                    cout << "Data pada posisi " << posisi << " berhasil diubah." << endl;
                    cout << "Data (" << nama_lama << ") telah terganti dengan data (" << nama_baru << ")" << endl;
                } else {
                    cout << "List masih kosong!" << endl;
                }
                break;
            }
            case 7: {
                cout << "-Hapus Depan\n" << endl;
                if (!isEmpty()) {
                    string nama_hapus = head->nama;
                    hapusDepan();
                    cout << "Data (" << nama_hapus << ") berhasil dihapus." << endl;
                } else {
                    cout << "List masih kosong!" << endl;
                }
                break;
            }
            case 8: {
                cout << "-Hapus Belakang\n" << endl;
                if (!isEmpty()) {
                    string nama_hapus = tail->nama;
                    hapusBelakang();
                    cout << "Data (" << nama_hapus << ") berhasil dihapus." << endl;
                } else {
                    cout << "List masih kosong!" << endl;
                }
                break;
            }
            case 9: {
                cout << "-Hapus Tengah\n" << endl;
                if (!isEmpty()) {
                    int posisi;
                    cout << "Masukkan posisi: ";
                    cin >> posisi;
                    hapusTengah(posisi);
                } else {
                    cout << "List masih kosong!" << endl;
                }
                break;
            }
            case 10: {
                cout << "-Hapus List\n" << endl;
                hapusList();
                break;
            }
            case 11: {
                cout << "-Tampilkan\n" << endl;
                tampil();
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }

    return 0;
}//2311102072syarief