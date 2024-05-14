#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 10;
string NIM;
int nilai;

class HashNode {
public:
    string NIM;
    int nilai;
    HashNode(string NIM, int nilai) {
        this->NIM = NIM;
        this->nilai = nilai;
    }
};

class HashTable {
private:
    vector<HashNode *> table[TABLE_SIZE];
public:
    int hash(string key) {
        int hashVal = 0;
        for (char c : key)
        {
            hashVal += c;
        }
        return hashVal % TABLE_SIZE;
    }

    void tambah(string NIM, int nilai) {
        int hashVal = hash(NIM);
        for (auto node : table[hashVal]) {
            if (node->NIM == NIM) {
                node->NIM = NIM;
                return;
            }
        }
        table[hashVal].push_back(new HashNode(NIM, nilai));
    }

    void hapus(string NIM) {
        int hashVal = hash(NIM);
        for (auto it = table[hashVal].begin(); it != table[hashVal].end(); it++) {
            if ((*it)->NIM == NIM) {
                table[hashVal].erase(it);
                return;
            }
        }
    }

    int searchByNIM(string NIM) {
        int hashVal = hash(NIM);
        for (auto node : table[hashVal])
        {
            if (node->NIM == NIM)
            {
                return node->nilai;
            }
        }
        return -1;
    }

    void searchByNilai(int scores[2]) {
        if (scores[0] > scores[1]) {
            int temp = scores[0];
            scores[0] = scores[1];
            scores[1] = temp;
        }
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr && pair->nilai >= scores[0] && pair->nilai <= scores[1])
                {
                    cout << "[" << pair->NIM << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }

    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i + 1 << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->NIM << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};

string inNIM() {
    string NIM;
    cout << "Masukkan NIM: ";
    cin >> NIM;
    return NIM;
}

int inScore(int batas = 0) {
    int nilai;
    if (batas <= 0) {
        cout << "Masukkan nilai: ";
    }
    else {
        cout << "Masukkan batas ke-" << batas << " : ";
    }
    cin >> nilai;
    return nilai;
}


int main() {
    HashTable hashTable;
    int choice;
    bool run = true;

    while(run) {
        cout << "===[Data Mahasiswa]===" << endl;
        hashTable.print();
        cout << "===[PILIHAN MENU]===" << endl;
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Cari data mahasiswa dengan NIM\n";
        cout << "4. Cari data mahasiswa dengan nilai\n";
        cout << "0. Keluar";
        cout << "\nMasukkan pilihan : ";
        cin >> choice;

        switch(choice) {
            case 0: return 0; break;
            case 1: {
                string NIM = inNIM();
                int nilai = inScore();
                hashTable.tambah(NIM, nilai);
                break;
            }
            case 2: {
                string NIM = inNIM();
                hashTable.hapus(NIM);
                break;
            }
            case 3: {
                string NIM = inNIM();
                int nilai = hashTable.searchByNIM(NIM);
                cout << "\nMahasiswa NIM " << NIM << " memiliki nilai " << nilai << endl;
                break;
            }
            case 4: {
                int scores[] = {inScore(1), inScore(2)};
                hashTable.searchByNilai(scores);
                break;
            }
            default: cout << "Pilihan salah, Masukkan pilihan menu dengan benar\n";
        }
    }
    return 0;
}//2311102072