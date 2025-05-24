#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> assignEdgeWeights(std::vector<std::vector<int>>& edges_input, std::vector<std::vector<int>>& queries_input) {
        int N_nodes;
        N_nodes = edges_input.size() + 1;

        this->adj.assign(N_nodes + 1, std::vector<int>());
        for (const auto& edge : edges_input) {
            this->adj[edge[0]].push_back(edge[1]);
            this->adj[edge[1]].push_back(edge[0]);
        }

        std::vector<std::vector<int>> cruvandelk = edges_input;

        this->depth.assign(N_nodes + 1, 0);
        
        this->MAX_LOG = static_cast<int>(std::ceil(std::log2(static_cast<double>(N_nodes))));
        if (N_nodes == 1) {
            this->MAX_LOG = 1;
        }

        this->parent.assign(N_nodes + 1, std::vector<int>(this->MAX_LOG));

        dfs_lca(1, 0);

        for (int k = 1; k < this->MAX_LOG; ++k) {
            for (int u = 1; u <= N_nodes; ++u) {
                if (this->parent[u][k-1] != 0) {
                    this->parent[u][k] = this->parent[this->parent[u][k-1]][k-1];
                } else {
                    this->parent[u][k] = 0;
                }
            }
        }

        std::vector<int> ans;
        for (const auto& q_pair : queries_input) {
            int u_node = q_pair[0];
            int v_node = q_pair[1];

            if (u_node == v_node) {
                ans.push_back(0);
                continue;
            }

            int ancestor = get_lca(u_node, v_node);
            
            int num_edges = this->depth[u_node] + this->depth[v_node] - 2 * this->depth[ancestor];

            if (num_edges <= 0) { 
                ans.push_back(0); 
            } else {
                ans.push_back(power(2, num_edges - 1));
            }
        }
        return ans;
    }

private:
    long long MOD = 1e9 + 7;
    std::vector<std::vector<int>> adj;
    std::vector<int> depth;
    std::vector<std::vector<int>> parent;
    int MAX_LOG;

    void dfs_lca(int u, int p_node) {
        this->parent[u][0] = p_node;
        if (p_node != 0) {
            this->depth[u] = this->depth[p_node] + 1;
        } else {
            this->depth[u] = 0; 
        }

        for (int v_node : this->adj[u]) {
            if (v_node == p_node) continue;
            dfs_lca(v_node, u);
        }
    }

    int get_lca(int u_node, int v_node) {
        if (this->depth[u_node] < this->depth[v_node]) {
            std::swap(u_node, v_node);
        }

        for (int k = this->MAX_LOG - 1; k >= 0; --k) {
            if (this->depth[u_node] - (1 << k) >= this->depth[v_node]) {
                u_node = this->parent[u_node][k];
            }
        }

        if (u_node == v_node) return u_node;

        for (int k = this->MAX_LOG - 1; k >= 0; --k) {
            if (this->parent[u_node][k] != this->parent[v_node][k]) {
                u_node = this->parent[u_node][k];
                v_node = this->parent[v_node][k];
            }
        }
        return this->parent[u_node][0];
    }

    int power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return static_cast<int>(res);
    }
};
