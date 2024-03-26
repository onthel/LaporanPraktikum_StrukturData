#include <iostream>

using namespace std;

int bilanganMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int bilanganMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double avg(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int size;
    cout << "Masukkan panjang array: ";
    cin >> size;

    int arr[size];
    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Array " << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;
    do {
        cout << "\nPilih:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Cari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nilai maksimum: " << bilanganMax(arr, size) << endl;
                break;
            case 2:
                cout << "Nilai minimum: " << bilanganMin(arr, size) << endl;
                break;
            case 3:
                cout << "Nilai rata-rata: " << avg(arr, size) << endl;
                break;
            case 4:
                cout << "Terima kasih.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 4);

    return 0;
}//2311102072