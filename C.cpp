

#include <bits/stdc++.h>
using namespace std;

template<typename key_type, typename value_type>
struct my_map {
    int m;
    vector<vector<pair<key_type, value_type>>> chains;

    my_map(int m) : m(m) {
        chains.resize(m);
    }

    value_type& operator [] (const key_type &key) {
        int chain_position = _hash(key);
        size_t at = 0;
        while (at < chains[chain_position].size() && chains[chain_position][at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            chains[chain_position].emplace_back(key, value_type());
        }
        return chains[chain_position][at].second;
    }

    bool has_key (const key_type &key) const {
        int chain_position = _hash(key);
        size_t at = 0;
        while (at < chains[chain_position].size() && chains[chain_position][at].first != key) {
            ++at;
        }
        return at != chains[chain_position].size();
    }

    int _hash(key_type key) const {
        // Para enteros
        const int B = 311;
        const int MOD = 1e9 + 7;
        long long hash_value = 0;
        if (key == 0) hash_value = 1;
        while (key > 0) {
            int d = key % 10;
            hash_value = (1ll * hash_value * B + (d + 1)) % MOD;
            key /= 10;
        }
        return hash_value % m;
    }

    void print() const {
        for (int i = 0; i < m; ++i) {
            cout << "Bucket " << i << ":\n";
            for (const auto &e : chains[i]) {
                cout << e.first << " --> " << e.second << "\n";
            }
            cout << "End bucket\n";
        }
    }
};


int main() {
    cin.tie(0) -> sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    unordered_set<long long> edge_hashes;
    vector<pair<int,int>> edges;
    vector<int> in_degree(n,0);

    for ( int i = 0 ; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u,v);
        edge_hashes.emplace(1ll * u * (n+1) + v );
        ++in_degree[v];
    }

    int res = 0;
    for (auto &e : edges) {
        int u ,v ;
        tie(u,v) = e;
        if (edge_hashes.find(1ll * v * (n+1) + u) != edge_hashes) {
            ++res;
        }
    }

    int best = max_element(in_degree.begin()+1, in_degree.begin);
    cout << (res>> 1)  << " " << best << " "  << in_degree[best];

    return 0;
}