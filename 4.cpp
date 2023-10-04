

#include <iostream>
using namespace std;
int function(int i_1)
{
    cout << "Funktion  1: i_1=" << i_1 << endl;
    return 0;
}
// weil die den gleichen Variable bekommen
// void function(int i_1)
// {
//     cout << "Funktion  2: i_1=" << i_1 << endl;
// }
// char function(int i_1)
// {
//     cout << "Funktion  3: i_1=" << i_1 << endl;
//     return 'a';
// }

// int function(int &i_1)
// {
//     cout << "Funktion  4: i_1=" << i_1 << endl;
//     return 1;
// }
int function(int i_1, int i_2)
{
    cout << "Funktion  5: i_1=" << i_1 << " i_2=" << i_2 << endl;
    return 1;
}
int function(char c_1, int i_1)
{
    cout << "Funktion  6: c_1=" << c_1 << " i_1=" << i_1 << endl;
    return 1;
}
// ist wie Funktion  5 unf das = 0 geht nicht
// int function(int i_1, int i_2 = 0)
// {
//     cout << "Funktion  7: i_1=" << i_1 << " i_2=" << i_2 << endl;
//     return 1;
// }
int function(double d_1, int i_1, char c_1 = 'a')
{
    cout << "Funktion  8: d_1=" << d_1 << " i_1=" << i_1 << " c_1=" << c_1 << endl;
    return 1;
}

int function(double d_1, double d_2 = 1.1, int i_1 = 0)
{
    cout << "Funktion  9: d_1=" << d_1 << " d_2=" << d_2 << " i_1=" << i_1 << endl;
    return 1;
}
// geht nicht wegen double d_2 = 1.1
// int function(double d_1, double d_2 = 1.1, char c_1)
// {
//     cout << "Funktion 10: d_1=" << d_1 << " d_2=" << d_2 << " c_1=" << c_1 << endl;
//     return 1;
// }
int function(char c_1, char c_2, int i_1 = 2, char c_3 = 'c')
{
    cout << "Funktion 11: c_1=" << c_1 << " c_2=" << c_2 << " i_1=" << i_1 << " c_3=" << c_3 << endl;
    return 1;
}
int main(int argc, char* argv[]) 
{
    int i = 1;
    char c = 'a';
    // 1 weil es ein int bekommt
    function(1);
    // 1 weil ein char ist ein assci code int
    function(c);
    // 1 weil ein char ist ein assci code int
    function(i);
    // 1 weil ein char ist ein assci code int
    c = function('a');
    c = 'a';
    // 5 weil es 2  int's bekommt
    function(1, 2);
    // 6 c weil es ein char bekommt und i ist ein int
    function(c, i);
    // 9 weil 2 double ist und der dritte hat ein default wert
    function(1.0, 2.0);
    // 9 weill alle wariabeltuppen stimmen
    function(1.0, 2.0, 1);
    // 8 weill alle wariabeltuppen stimmen
    function(1.0, 1, 'a');
    // 8 weill alle wariabeltuppen stimmen und der dritte hat ein default wert
    function(1.0, 1);
    // 9 weill alle wariabeltuppen stimmen und der dritte hat ein default wert
    function(1.0, static_cast<double>(i));
    // 11 weill alle wariabeltuppen stimmen und der 4te hat ein default wert
    function(c, c, i);
    // 6 c weil es ein char bekommt und i ist ein int
    function(c, i);
    return 0;
}
