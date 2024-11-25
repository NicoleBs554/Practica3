#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
    int x = 0; 
    int y = 0;
};

float calcularDistancia(const Punto& p1, const Punto& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool estaEnCuadrante(const Punto& p, int cuadrante) {
    switch (cuadrante) {
        case 1: return (p.x > 0 && p.y > 0);
        case 2: return (p.x < 0 && p.y > 0);
        case 3: return (p.x < 0 && p.y < 0);
        case 4: return (p.x > 0 && p.y < 0);
        default: return false;
    }
}

void calcularDistanciaMaxima(const Punto* ejes, int n, int cuadrante, float& distanciaMax, int& punto1, int& punto2) {
    distanciaMax = 0; 
    punto1 = -1; 
    punto2 = -1;

    for (int i = 0; i < n; i++) {
        if (estaEnCuadrante(ejes[i], cuadrante)) {
            for (int j = i + 1; j < n; j++) { 
                if (estaEnCuadrante(ejes[j], cuadrante)) {
                    float distancia = calcularDistancia(ejes[i], ejes[j]);
                    if (distancia > distanciaMax) {
                        distanciaMax = distancia;
                        punto1 = i;
                        punto2 = j;
                    }
                }
            }
        }
    }
}

int main() {
    int n = 0;
    float distanciaMax = 0;
    int punto1, punto2;
    cout << "Inserte la cantidad de coordenadas que quiere insertar: " << endl;
    cin >> n;

    Punto ejes[n];

    for (int i = 0; i < n; i++) {
        cout << "Ingrese la coordenada de x: " << i+1 << ": ";
        cin >> ejes[i].x;
        cout << "Ingrese la coordenada de y: " << i+1 << ": ";
        cin >> ejes[i].y;
    }

    cout << "Elija un cuadrante como limite:" << endl;
    cout << "1. Primer cuadrante" << endl;
    cout << "2. Segundo cuadrante" << endl;
    cout << "3. Tercer cuadrante" << endl;
    cout << "4. Cuarto cuadrante" << endl;
    int cuadrante;
    cin >> cuadrante;

    calcularDistanciaMaxima(ejes, n, cuadrante, distanciaMax, punto1, punto2);
    
    for (int i = 0; i < n; i++) {
        if (estaEnCuadrante(ejes[i], cuadrante)) {
            for (int j = i + 1; j < n; j++) { 
                if (estaEnCuadrante(ejes[j], cuadrante)) {
                    float distancia = calcularDistancia(ejes[i], ejes[j]);
                    if (distancia > distanciaMax) {
                        distanciaMax = distancia;
                        punto1 = i;
                        punto2 = j;
                    }
                }
            }
        }
    }

    if (distanciaMax > 0) {
        cout << "La distancia máxima entre los puntos en el cuadrante " << cuadrante << " es: " << distanciaMax << endl;
        cout << "Entre los puntos: (" << ejes[punto1].x << ", " << ejes[punto1].y << ") y (" << ejes[punto2].x << ", " << ejes[punto2].y << ")" << endl;

        int indicePunto;
        cout << "Ingrese el índice del punto desde el cual calcular las distancias (1 a " 
             << n << "): ";
        cin >> indicePunto;
        indicePunto--; 

        if (estaEnCuadrante(ejes[indicePunto], cuadrante)) {
            cout << "Distancias desde el punto (" << ejes[indicePunto].x << ", " << ejes[indicePunto].y << ") a los demás puntos en el cuadrante " << cuadrante << ":" << endl;

            for (int i = 0; i < n; i++) {
                if (i != indicePunto && estaEnCuadrante(ejes[i], cuadrante)) {
                    float distancia = calcularDistancia(ejes[indicePunto], ejes[i]);
                    cout << "Distancia al punto (" << ejes[i].x << ", " 
                         << ejes[i].y << "): " << distancia << endl;
                }
            }
        } else {
            cout << "El punto seleccionado no está en el cuadrante especificado." << endl;
                    }
    } else {
        cout << "No se encontraron puntos en el cuadrante especificado." << endl;
    }

    return 0;
}
