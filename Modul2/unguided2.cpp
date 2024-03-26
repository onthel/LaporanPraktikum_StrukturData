#include <iostream>

using namespace std;

int main()
{
    int xx, yy, zz;
    cout << "Masukkan panjang array dalam dimensi X: ";
    cin >> xx;
    cout << "Masukkan panjang array dalam dimensi Y: ";
    cin >> yy;
    cout << "Masukkan panjang array dalam dimensi Z: ";
    cin >> zz;

  int arr[xx][yy][zz];
  // Input elemen
  for (int x = 0; x < xx; x++)
  {
    for (int y = 0; y < yy; y++)
    {
      for (int z = 0; z < zz; z++)
      {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }
  // Output Array
  for (int x = 0; x < xx; x++)
  {
    for (int y = 0; y < yy; y++)
    {
      for (int z = 0; z < zz; z++)
      {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;
  // Tampilan array
  for (int x = 0; x < xx; x++)
  {
    for (int y = 0; y < yy; y++)
    {
      for (int z = 0; z < zz; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }
}//2311102072