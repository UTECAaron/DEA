#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Para lectura y escritura ultrarrápida
    cin.tie(0)->sync_with_stdio(false);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    vector<vector<int>> adj(n + 1);

    // Leemos las m amistades
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Ordenamos la lista de amigos de cada persona
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // Procesamos las q consultas
    while (q--) {
        int u, v;
        cin >> u >> v;

        // Algoritmo de dos punteros para contar la intersección
        int i = 0, j = 0;
        int tam_u = adj[u].size();
        int tam_v = adj[v].size();
        int en_comun = 0;

        while (i < tam_u && j < tam_v) {
            if (adj[u][i] == adj[v][j]) {
                en_comun++;
                i++;
                j++;
            } else if (adj[u][i] < adj[v][j]) {
                i++;
            } else {
                j++;
            }
        }

        cout << en_comun << "\n";
    }

    return 0;
}