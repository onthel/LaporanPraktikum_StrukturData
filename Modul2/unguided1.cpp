#include <iostream>

using namespace std;

int main() {
    int length;
    
    cout << "Masukkan jumlah panjang array: ";
    cin >> length;
    
    int arr[length];
    
    cout << "Masukkan angka : " << endl;
    for (int i = 0; i < length; ++i) {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "Data dalam array:" << endl;
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Bilangan ganjil: " << endl;
    for (int i = 0; i < length; ++i) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;
    
    cout << "Bilangan genap: " << endl;
    for (int i = 0; i < length; ++i) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;
    
    return 0;
}//2311102072
