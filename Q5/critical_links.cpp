#include <iostream>
#include <vector>
#include <algorithm>

typedef struct vertex
{
    int u, v;
} vertex;

std::vector<std::vector<int>> adj;
std::vector<vertex> bridges;
std::vector<int> disc, low;
std::vector<bool> visited;
int tim;
// void dfs(int, int);
// bool CMP(vertex, vertex);

void dfs(int u, int parent)
{
    disc[u] = low[u] = tim++;
    int child = 0;
    visited[u] = true;
    for (auto element : adj[u])
    {
        if (!visited[element])
        {
            child++;
            dfs(element, u);
            low[u] = std::min(low[u], low[element]);
            if (disc[u] < low[element])
            {
                bridges.push_back({u, element});
            }
        }
        else if (element != parent)
        {
            low[u] = std::min(low[u], disc[element]);
        }
    }
}

bool CMP(vertex v1, vertex v2)
{
    return v1.u < v2.u;
}

int main(void)
{
    int n, u, v;
    std::cin >> n;
    adj.resize(n, std::vector<int>());
    disc.resize(n, 0);
    low.resize(n, 0);
    visited.resize(n, false);
    tim = 1;

    while (std::cin >> u >> v)
    {
        if (u == 0 && v == 0)
            break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i, -1);
    }

    std::sort(bridges.begin(), bridges.end(), CMP);
    for (int j = 0; j < bridges.size(); j++)
    {
        std::cout << bridges.at(j).u << " " << bridges.at(j).v << std::endl;
    }

    return 0;
}