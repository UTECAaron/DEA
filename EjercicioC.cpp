#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    // Para lectura y escritura ultrarrápida
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Arreglo para contar cuántos seguidores tiene cada usuario (de 1 a n)
    vector<int> seguidores(n + 1, 0);

    // Conjunto para guardar las relaciones (a, b) y buscar rápido
    set<pair<int, int>> conexiones;

    int parejas_mutuas = 0;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        // a sigue a b -> b gana un seguidor
        seguidores[b]++;

        // Verificamos si b ya seguía a a previamente
        if (conexiones.count({b, a})) {
            parejas_mutuas++;
        }

        // Guardamos la conexión actual (a -> b)
        conexiones.insert({a, b});
    }

    // Buscamos el usuario con más seguidores
    int mejor_usuario = 1;
    int max_seguidores = seguidores[1];

    for (int i = 2; i <= n; ++i) {
        if (seguidores[i] > max_seguidores) {
            max_seguidores = seguidores[i];
            mejor_usuario = i;
        }
        // Nota: si son iguales, no actualizamos para conservar el ID menor
    }

    // Imprimimos: parejas mutuas, ID del más seguido, cantidad de seguidores
    cout << parejas_mutuas << " " << mejor_usuario << " " << max_seguidores << "\n";

    return 0;
}