#include <iostream>
using namespace std;

int main (){
    int n = 10;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int jumlah_4 = 0;
    int i;

    //Algoritma Sequential Search
    for (i = 0; i < n; i++){
        if (data [i] == cari){
            jumlah_4++;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "Data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;

    cout << "\nJumlah angka " << cari << " dalam data adalah: " << jumlah_4 << endl;

    return 0;
}//2311102072