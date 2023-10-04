#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int j;
    char fillChar = '+';
    double d = 1.234;
    cout << setw(3) << "Nr" << " "
         << setw(3) << "Oct" << " "
         << setw(4) << "Hex" << " "
         << setw(6) << "String" << " "
         << setw(6) << "Fixed" << " "
         << setw(14) << "Scientific" << endl;
    
    for (int k = 1; k < 11; k++)
    {
        j = k % 5 + 1;
        cout << setw(3) << dec << k << " "
             << setw(1) << setfill('0');
             if (k > 7 ){
                cout << setw(3) << oct << k << " ";
             }
            else { cout << " " << setw(2) << oct << k << " "; }
            cout << setw(3) << setfill(' ') << hex << "0x" << hex << nouppercase << k << " "
             << setw(k % 5 + 1) << setfill('*') << "" 
             << setw(7 - j ) << setfill('+') << "" << " "
             << (d >= 0 ? "+" : "-") << setw(8) << setfill(' ') << fixed << setprecision(3) << abs(d) << setfill(' ');

             cout << setw(11) << setfill(' ') << scientific << setprecision(3) << uppercase << d << endl;
             fillChar = (fillChar == '+') ? '-' : '+';
             d = d * -2;
    }
    return 0;
}
