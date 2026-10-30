#include <iostream>
#include <vector>

using namespace std;

// Matriz de adyacencia global para ahorrar memoria en el stack
bool matriz[3005][3005];

int main() {
    // Lectura y escritura ultrarrápida
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        matriz[a][b] = true;
        matriz[b][a] = true;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long trios = 0;

    // Recorremos cada nodo u
    for (int u = 1; u <= n; ++u) {
        // Buscamos un vecino v mayor que u
        for (int v : adj[u]) {
            if (v > u) {
                // Buscamos un vecino w del nodo v que sea mayor que v
                for (int w : adj[v]) {
                    if (w > v) {
                        // Si w también es amigo de u, formamos el trío {u, v, w}
                        if (matriz[u][w]) {
                            trios++;
                        }
                    }
                }
            }
        }
    }

    cout << trios << "\n";

    return 0;
}