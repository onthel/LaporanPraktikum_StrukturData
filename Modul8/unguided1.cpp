#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>

using namespace std;

void selection_sort(char data[], int n)
{
    int temp, min, i, j;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(data[j] < data[min])
            {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binary_search(char data[], int n, char cari)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if(data[tengah] < cari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1)
    {
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    }
    else
    {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main()
{
    const int MAX_LENGTH = 100;
    char kalimat[MAX_LENGTH];
    char cari;
    
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Masukkan sebuah kalimat : ";
    cin.getline(kalimat, MAX_LENGTH);
    
    int n = strlen(kalimat);
    
    cout << "\n Data diurutkan : ";
    selection_sort(kalimat, n);
    
    // Tampilkan data setelah diurutkan
    for(int x = 0; x < n; x++)
    {
        cout << setw(3) << kalimat[x];
    }
    cout << endl;
    
    cout << "\n Masukkan karakter yang ingin Anda cari : ";
    cin >> cari;
    
    binary_search(kalimat, n, cari);
    
    _getche();
    return EXIT_SUCCESS;
}//2311102072