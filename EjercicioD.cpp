#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Para lectura y escritura rápida de datos grandes
    cin.tie(0)->sync_with_stdio(false);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    // Lista de adyacencia: adj[u] guarda la lista de contactos de u
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Es un grafo no dirigido
    }

    // Ordenamos la lista de contactos de cada persona
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // Procesamos las q consultas
    while (q--) {
        int tipo, u;
        cin >> tipo >> u;

        if (tipo == 1) {
            int k;
            cin >> k;
            // Si tiene menos de k contactos, respuesta es -1
            if (k > (int)adj[u].size()) {
                cout << -1 << "\n";
            } else {
                // k-ésimo menor elemento (índice k - 1)
                cout << adj[u][k - 1] << "\n";
            }
        } else if (tipo == 2) {
            int x;
            cin >> x;
            // upper_bound nos da la cantidad de elementos <= x
            auto it = upper_bound(adj[u].begin(), adj[u].end(), x);
            int cantidad = distance(adj[u].begin(), it);
            cout << cantidad << "\n";
        }
    }

    return 0;
}