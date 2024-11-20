#include<iostream>
using namespace std;

struct Plano{
    int x=0; 
    int y=0;
}p;

int main (){
    int n;
    cout << "Ingrese la candidad de puntos en el plano: " << endl;
    cin >>n;
    Plano ejes[n];

    for (int i=0; i<n; i++){
        cout << "Ingrese la cooredenada de x: " << i+1 << ": ";
        cin >> ejes[i].x;
        cout << "Ingrese las coordenadas de y: " << i+1 << ": ";
        cin >> ejes[i].y;

        if(ejes[i].x > 0 && ejes[i].y > 0){
            cout << "El punto (" << ejes[i].x << ", " << ejes[i].y << ") se encuentra en el primer cuadrante." << endl;
        } else if (ejes[i].x < 0 && ejes[i].y > 0) {
            cout << "El punto (" << ejes[i].x << ", " << ejes[i].y << ") se encuentra en el segundo cuadrante." << endl;
        } else if (ejes[i].x < 0 && ejes[i].y < 0) {
            cout << "El punto (" << ejes[i].x << ", " << ejes[i].y << ") se encuentra en el tercer cuadrante." << endl;
        } else if (ejes[i].x > 0 && ejes[i].y < 0) {
            cout << "El punto (" << ejes[i].x << ", " << ejes[i].y << ") se encuentra en el cuarto cuadrante." << endl;
        } else if (ejes[i].x == 0 && ejes[i].y != 0) {
            cout << "El punto (" << ejes[i].x << ", " << ejes[i].y << ") se encuentra en el eje Y." << endl;
        } else if (ejes[i].y == 0 && ejes[i].x != 0) {
            cout << "El punto (" << ejes[i].x << ", " << ejes[i].y << ") se encuentra en el eje X." << endl;
        } else {
            cout << "El punto (" << ejes[i].x << ", " << ejes[i].y << ") es el origen." << endl;
        }
    };
    return 0;
};