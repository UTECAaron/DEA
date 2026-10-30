#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Función para verificar si dos palabras difieren en exactamente 1 letra
bool difieren_en_una(const string& a, const string& b, int L) {
    int diferencias = 0;
    for (int i = 0; i < L; ++i) {
        if (a[i] != b[i]) {
            diferencias++;
            // Si ya encontramos más de 1 diferencia, no es necesario seguir
            if (diferencias > 1) return false;
        }
    }
    return diferencias == 1;
}

int main() {
    // Para hacer la entrada/salida más rápida
    cin.tie(0)->sync_with_stdio(false);

    int n, L;
    if (!(cin >> n >> L)) return 0;

    vector<string> palabras(n);
    for (int i = 0; i < n; ++i) {
        cin >> palabras[i];
    }

    // Guardaremos la cantidad de vecinos de cada palabra
    vector<int> grado(n, 0);
    int total_aristas = 0;

    // Comparamos todos los pares únicos (i, j)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (difieren_en_una(palabras[i], palabras[j], L)) {
                grado[i]++;
                grado[j]++;
                total_aristas++;
            }
        }
    }

    int grado_maximo = 0;
    int aisladas = 0;

    // Analizamos los grados de todas las palabras
    for (int i = 0; i < n; ++i) {
        grado_maximo = max(grado_maximo, grado[i]);
        if (grado[i] == 0) {
            aisladas++;
        }
    }

    // Imprimimos el número de aristas, grado máximo y palabras aisladas
    cout << total_aristas << " " << grado_maximo << " " << aisladas << "\n";

    return 0;
}