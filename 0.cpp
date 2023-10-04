#include <iostream>
using namespace std;
int main(){
    int anzahl = 0;
    float sum;
    cout << "Anzahl eingeben: \n" ;
    cin >> anzahl;
    int arr[anzahl];

for (int i = 0 ; i < anzahl; i++){
    cout << "Zahl eingeben: \n";
    cin >> arr[i];
    sum+= arr[i];
}
for (int j = 0 ; j < anzahl; j++){
    cout << "Zahl["<<j<<"]: " << arr[j] <<"\n";
}

cout << "Durchschnitt: " << sum / anzahl;
return 0;
}