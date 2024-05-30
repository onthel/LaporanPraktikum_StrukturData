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

int hitung_vokal(char kalimat[], int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (kalimat[i] == 'a' || kalimat[i] == 'e' || kalimat[i] == 'i' || kalimat[i] == 'o' || kalimat[i] == 'u' ||
            kalimat[i] == 'A' || kalimat[i] == 'E' || kalimat[i] == 'I' || kalimat[i] == 'O' || kalimat[i] == 'U')
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    const int MAX_LENGTH = 100;
    char kalimat[MAX_LENGTH];
    
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Masukkan sebuah kalimat : ";
    cin.getline(kalimat, MAX_LENGTH);
    
    int n = strlen(kalimat);
    
    cout << "\n Data diurutkan : ";
    selection_sort(kalimat, n);
    
    for(int x = 0; x < n; x++)
    {
        cout << setw(3) << kalimat[x];
    }
    cout << endl;

    int jumlah_vokal = hitung_vokal(kalimat, n);
    cout << "\n Jumlah huruf vokal dalam kalimat adalah: " << jumlah_vokal << endl;
    
    _getche();
    return EXIT_SUCCESS;
}//2311102072