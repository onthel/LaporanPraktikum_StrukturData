#include <iostream>
using namespace std;

class namaKereta {
public:
    string nama;
    
    void outputNama() {
        cout << "Nama kereta: " << nama << endl;
    }
};

struct tahunKereta {
    int tahun;
    void outputTahun(){
        cout << "Tahun pembuatan: " << tahun << endl;            
    }
};

int main() {
    namaKereta namaKereta1, namaKereta2;
    tahunKereta tahunKereta1, tahunKereta2;
    
    namaKereta1.nama = "Taksaka";
    tahunKereta1.tahun = 2024;
    namaKereta2.nama = "Logawa";
    tahunKereta2.tahun = 2020;
    
    namaKereta1.outputNama();
    tahunKereta1.outputTahun();
    namaKereta2.outputNama();
    tahunKereta1.outputTahun();
    
    return 0;//2311102072
}
