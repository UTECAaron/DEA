#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    // Para lectura y escritura ultrarrápida
    cin.tie(0)->sync_with_stdio(false);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    // Estructura para contar cuántos cables hay entre cada par (u, v)
    map<pair<int, int>, int> cables;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        // Garantizamos que el menor esté en primer lugar
        int menor = min(u, v);
        int mayor = max(u, v);

        // Sumamos un cable a esta conexión
        cables[{menor, mayor}]++;
    }

    // Procesamos las q preguntas
    while (q--) {
        int u, v;
        cin >> u >> v;

        int menor = min(u, v);
        int mayor = max(u, v);

        // Si la conexión existe, imprimimos su cantidad; si no existe, mapa devuelve 0
        cout << cables[{menor, mayor}] << "\n";
    }

    return 0;
}