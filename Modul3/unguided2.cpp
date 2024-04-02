#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string namaProduk;
    double harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string namaProduk, double harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pushAt(int pos, string namaProduk, double harga) {
        if (pos < 1) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;

        if (pos == 1) {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            } else {
                tail = newNode;
            }
            head = newNode;
            return;
        }

        Node* current = head;
        int count = 1;
        while (current != nullptr && count < pos - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        
        delete temp;
    }

    void popAt(int pos) {
        if (pos < 1) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        if (pos == 1) {
            if (head == nullptr) {
                return;
            }
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = head;
        int count = 1;
        while (current != nullptr && count < pos) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        current->prev->next = current->next;
        delete current;
    }

    bool update(string oldNamaProduk, string newNamaProduk, double newHarga) {
        Node* current = head;
        
        while (current != nullptr) {
            if (current->namaProduk == oldNamaProduk) {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        cout << "Nama Produk     Harga" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << current->namaProduk << "     " << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "Toko Tambah Ganteng Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        
        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string namaProduk;
                double harga;
                cout << "Masukkan Nama Produk: ";
                cin.ignore(); 
                getline(cin, namaProduk);
                cout << "Masukkan Harga Produk: ";
                cin >> harga;
                list.push(namaProduk, harga);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                string oldNamaProduk, newNamaProduk;
                double newHarga;
                cout << "Masukkan Nama Produk Lama: ";
                cin.ignore(); 
                getline(cin, oldNamaProduk);
                cout << "Masukkan Nama Produk Baru: ";
                getline(cin, newNamaProduk);
                cout << "Masukkan Harga Produk Baru: ";
                cin >> newHarga;
                bool updated = list.update(oldNamaProduk, newNamaProduk, newHarga);
                if (!updated) {
                    cout << "Produk tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                int pos;
                string namaProduk;
                double harga;
                cout << "Masukkan posisi: ";
                cin >> pos;
                cout << "Masukkan Nama Produk: ";
                cin.ignore(); 
                getline(cin, namaProduk);
                cout << "Masukkan Harga Produk: ";
                cin >> harga;
                list.pushAt(pos, namaProduk, harga);
                break;
            }
            case 5: {
                int pos;
                cout << "Masukkan posisi untuk menghapus: ";
                cin >> pos;
                list.popAt(pos);
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
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