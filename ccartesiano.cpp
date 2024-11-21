#include<iostream>
using namespace std;

struct Plano{
    int x = 0; 
    int y = 0;
};

bool sonColineales(Plano p1, Plano p2, Plano p3){
    return (p1.y - p2.y) * (p2.x - p3.x) == (p2.y - p3.y) * (p1.x - p2.x);
}
void imprimirEcuacion(Plano p1, Plano p2) {
    if (p2.x - p1.x != 0) {
        double m = static_cast<double>(p2.y - p1.y) / (p2.x - p1.x); 
        double b = p1.y - m * p1.x; 
        cout << "La ecuación de la recta que pasa por los puntos ("
             << p1.x << ", " << p1.y << ") y (" << p2.x << ", " << p2.y << ") es: y = "
             << m << "x + " << b << endl;
    } else {
        cout << "La recta es vertical, ecuación: x = " << p1.x << endl;
    }
}

int main (){
    int n;
    cout << "Ingrese la candidad de puntos en el plano: " << endl;
    cin >>n;
    Plano ejes[n];

    for (int i=0; i<n; i++){
        cout << "Ingrese la coordenada de x: " << i+1 << ": ";
        cin >> ejes[i].x;
        cout << "Ingrese la coordenada de y: " << i+1 << ": ";
        cin >> ejes[i].y;
    };
    for (int i = 0; i<n; i++){ 
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
        } else if (ejes[i].x ==0 && ejes[i].y == 0){
            cout << "El punto (" << ejes[i].x << ", " << ejes[i].y << ") es el origen." << endl;
        } else {
            cout<<"El punto (" << ejes[i].x << ", " << ejes[i].y << ") no se encuentra en un solo cuadrante o no es valida" << endl;
        }
    };

    if (n >= 2) {
        bool colineales = true;
        for (int i = 1; i < n - 1; i++) {
            if (!sonColineales(ejes[0], ejes[i], ejes[i + 1])) {
                colineales = false;
                break;
            }
        }
        if (colineales) {
            cout << "Todos los puntos son colineales." << endl;
        } else {
            cout << "Los puntos no son colineales." << endl;
        }
    } else {
        cout << "Se necesitan al menos 2 puntos para verificar colinealidad." << endl;
    }

    for(int i; i<n; i++){
        float fx = ejes[i].x + 1;
        if(ejes[i].y == fx) {
            cout << "La coordenada: (" << ejes[i].x << "," << ejes[i].y << ") pertenece a la ecuacion f(x)= x+1" << endl;
        } else if (ejes[i].y != fx) {
            cout << "La coordenada: (" << ejes[i].x << "," << ejes[i].y << ") no pertenece a la ecuacion f(x)= x+1" << endl;
        } else {
            cout << "La coordenada: (" << ejes[i].x << "," << ejes[i].y << ") no es valida" << endl;
        }
    }
    return 0;
};