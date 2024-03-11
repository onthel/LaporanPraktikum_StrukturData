#include <iostream>
#include <map>
using namespace std;

int main (){
    map <string, int> dataBank;

    dataBank ["Rekening1"] = 20202021;
    dataBank ["Rekening2"] = 20212022;
    dataBank ["Rekening3"] = 20222023;

    cout << "Nomer Rekening 1 : " << dataBank ["Rekening1"] << endl
         << "Nomer Rekening 2 : " << dataBank ["Rekening2"] << endl
         << "Nomer Rekening 3 : " << dataBank ["Rekening3"];


    return 0;//2311102072
}