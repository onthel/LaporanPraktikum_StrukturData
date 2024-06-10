#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    int simpul_2311102072;
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> simpul_2311102072;

    string simpul[simpul_2311102072];
    int bobot[simpul_2311102072][simpul_2311102072];
    cout << "Silakan masukkan nama simpul\n";
    for (int i = 0; i < simpul_2311102072; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    cout << "Silakan masukkan bobot antar simpul\n";
    for (int i = 0; i < simpul_2311102072; i++) {
        for (int j = 0; j < simpul_2311102072; j++) {
            cout << simpul[i] << " --> " << simpul[j] << " : ";
            cin >> bobot[i][j];
        }
    }

    cout << endl << setw(10) << " ";
    for (int i = 0; i < simpul_2311102072; i++) {
        cout << setw(10) << simpul[i];
    }
    cout << endl;

    for (int i = 0; i < simpul_2311102072; i++) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < simpul_2311102072; j++) {
            cout << setw(10) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}//2311102072