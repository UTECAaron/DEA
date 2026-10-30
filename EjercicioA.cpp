#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> mapa(n);
    for (int i = 0; i < n; ++i) {
        cin >> mapa[i];
    }

    int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    int df[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int f = 0; f < n; f++) {
        for (int c = 0; c < m; c++) {

            if (mapa[f][c] == '#') {
                int vecinos_tierra = 0;

                for (int i = 0; i < 4; ++i) {
                    int nf = f + df[i];
                    int nc = c + dc[i]; // Corregido: sumamos c + dc[i]

                    if (nf >= 0 && nf < n && nc >= 0 && nc < m) {
                        if (mapa[nf][nc] == '#') {
                            vecinos_tierra++;
                        }
                    }
                }

                if (vecinos_tierra == 0) c0++;
                else if (vecinos_tierra == 1) c1++;
                else if (vecinos_tierra == 2) c2++;
                else if (vecinos_tierra == 3) c3++;
                else if (vecinos_tierra == 4) c4++;
            }
        }
    }

    int perimetro_total = (4 * c0) + (3 * c1) + (2 * c2) + c3; // Corregido: 4 * c0
    cout << perimetro_total << " " << c0 << " " << c1 << " " << c2 << " " << c3 << " " << c4 << "\n";

    return 0;
}

//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Para hacer la entrada y salida más rápida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Leemos el mapa completo
    vector<string> mapa(n);
    for (int i = 0; i < n; i++) {
        cin >> mapa[i];
    }

    // Contadores para casillas de grado 0, 1, 2, 3 y 4
    int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    // Movimientos para revisar los 4 vecinos: arriba, abajo, izquierda, derecha
    int df[] = {-1, 1, 0, 0}; // cambio en fila
    int dc[] = {0, 0, -1, 1}; // cambio en columna

    // Recorremos cada casilla del mapa
    for (int f = 0; f < n; f++) {
        for (int c = 0; c < m; c++) {

            // Solo nos interesan las casillas de tierra
            if (mapa[f][c] == '#') {
                int vecinos_tierra = 0;

                // Revisamos sus 4 vecinos
                for (int i = 0; i < 4; i++) {
                    int nf = f + df[i]; // nueva fila del vecino
                    int nc = c + dc[i]; // nueva columna del vecino

                    // Verificamos si el vecino está dentro de los límites de la matriz
                    if (nf >= 0 && nf < n && nc >= 0 && nc < m) {
                        // Si está dentro y es tierra, sumamos un vecino
                        if (mapa[nf][nc] == '#') {
                            vecinos_tierra++;
                        }
                    }
                }

                // Clasificamos la casilla según su grado (cantidad de vecinos)
                if (vecinos_tierra == 0) c0++;
                else if (vecinos_tierra == 1) c1++;
                else if (vecinos_tierra == 2) c2++;
                else if (vecinos_tierra == 3) c3++;
                else if (vecinos_tierra == 4) c4++;
            }
        }
    }

    // Calculamos el perímetro total
    int perimetro_total = (4 * c0) + (3 * c1) + (2 * c2) + (1 * c3) + (0 * c4);

    // Imprimimos el resultado final separado por espacios
    cout << perimetro_total << " " << c0 << " " << c1 << " " << c2 << " " << c3 << " " << c4 << "\n";

    return 0;
}