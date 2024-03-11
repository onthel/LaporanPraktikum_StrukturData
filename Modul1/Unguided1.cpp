#include <iostream>
using namespace std;

void inputMhs(string &mhs){
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, mhs);
}

void outputMhs(string mhs){
    cout << "Nama Mahasiswa yang anda masukkan adalah: " << mhs;
}

int main (){
    string mhs ;
    inputMhs (mhs);
    outputMhs(mhs);
    return 0;
}