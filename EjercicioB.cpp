#include<bits/stdc++.h>

using namespace::std;

int main() {
    cin.tie(0)-> sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> grado(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (u == v) {
            // Un lazo suma 2 al grado del mismo vértice
            grado[u] += 2;
        } else {
            // Un puente normal suma 1 a cada uno de sus extremos
            grado[u]++;
            grado[v]++;
        }
    }
    // Contamos cuántos vértices tienen grado impar
    int impares = 0;
    for (int i = 1; i <= n; i++) {
        if (grado[i] % 2 != 0) {
            impares++;
        }
    }

    // Determinamos la respuesta según la cantidad de vértices impares
    if (impares == 0) {
        cout << "CIRCUITO\n";
    } else if (impares == 2) {
        cout << "CAMINO\n";
    } else {
        cout << "IMPOSIBLE\n";
    }

    return 0;
}
