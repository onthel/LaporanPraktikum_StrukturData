#include <iostream>
using namespace std;

struct Node {
    string nama;
    int usia;
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

void insertDepan(string nama, int usia) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, int usia) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
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

void insertTengah(string nama, int usia, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node* baru = new Node();
        baru->nama = nama;
        baru->usia = usia;
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

void hapusTengah(string nama) {
    if (!isEmpty()) {
        Node* hapus;
        Node* bantu = head;
        Node* prev = nullptr;
        while (bantu != nullptr && bantu->nama != nama) {
            prev = bantu;
            bantu = bantu->next;
        }
        if (bantu == nullptr) {
            cout << "Nama tidak ditemukan dalam list" << endl;
            return;
        }
        if (prev != nullptr) {
            prev->next = bantu->next;
        } else {
            head = bantu->next;
        }
        if (bantu == tail) {
            tail = prev;
        }
        delete bantu;
        cout << "Node dengan nama '" << nama << "' berhasil dihapus" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(string nama, int usia, string nama_lama) {
    if (!isEmpty()) {
        Node* bantu = head;
        while (bantu != nullptr && bantu->nama != nama_lama) {
            bantu = bantu->next;
        }
        if (bantu != nullptr) {
            bantu->nama = nama;
            bantu->usia = usia;
            cout << "Node dengan nama '" << nama_lama << "' berhasil diubah menjadi '" << nama << "' dengan usia baru " << usia << endl;
        } else {
            cout << "Node dengan nama '" << nama_lama << "' tidak ditemukan" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void tampil() {
    if (!isEmpty()) {
        Node* bantu = head;
        while (bantu != NULL) {
            cout << bantu->nama << " " << bantu->usia << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    string nama;
    int usia, choice;
    cout << "Masukkan nama anda: ";
    cin >> nama;
    cout << "Masukkan usia anda: ";
    cin >> usia;
    insertBelakang(nama, usia);

    while (true) {
        cout << "1. Tambah Node di depan" << endl;
        cout << "2. Tambah Node di belakang" << endl;
        cout << "3. Tambah Node di posisi tengah" << endl;
        cout << "4. Hapus Node berdasarkan nama" << endl;
        cout << "5. Ubah data Node berdasarkan nama" << endl;
        cout << "6. Tampilkan semua data Node di list" << endl;
        cout << "7. Keluar" << endl;

        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan usia: ";
                cin >> usia;
                insertDepan(nama, usia);
                break;
            }
            case 2: {
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan usia: ";
                cin >> usia;
                insertBelakang(nama, usia);
                break;
            }
            case 3: {
                int posisi;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan usia: ";
                cin >> usia;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                insertTengah(nama, usia, posisi);
                break;
            }
            case 4: {
                cout << "Masukkan nama yang ingin dihapus: ";
                cin >> nama;
                hapusTengah(nama);
                break;
            }
            case 5: {
                string nama_lama;
                cout << "Masukkan nama lama: ";
                cin >> nama_lama;
                cout << "Masukkan nama baru: ";
                cin >> nama;
                cout << "Masukkan usia baru: ";
                cin >> usia;
                ubahTengah(nama, usia, nama_lama);
                break;
            }
            case 6: {
                tampil();
                break;
            }
            case 7: {
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