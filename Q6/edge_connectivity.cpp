#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#define INT_MAX 2147483647

bool bfs(int s, int t, int par[]);

int V;
std::vector<std::vector<int>> g, c;

int main()
{

    std::vector<std::vector<int>> original;
    std::vector<int> temp;
    int u, v, max_flow, output = INT_MAX;

    std::ios::sync_with_stdio(false);

    std::cin >> V;
    g.resize(V);
    temp.assign(V, 0);
    c.assign(V, temp);
    while (std::cin >> u >> v)
    {

        c[u][v] = 1;
        c[v][u] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    original = c;

    for (int i = 1; i < V; i++)
    {
        int u, v;
        max_flow = 0;
        int par[V];
        for (int i = 0; i < V; i++)
            par[i] = -1;
        while (bfs(0, i, par))
        {

            for (v = i; v != 0; v = u)
            {
                u = par[v];
                c[u][v]--;
                c[v][u]++;
            }

            max_flow++;
        }

        if (max_flow < output)
            output = max_flow;
        c.clear();
        c = original;
    }
    std::cout << output;
    return 0;
}

bool bfs(int s, int t, int par[])
{

    bool visited[V];
    memset(visited, 0, sizeof(visited));

    std::queue<int> q;
    q.push(s);

    visited[s] = true;
    par[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < g[u].size(); v++)
        {
            int adj = g[u][v];
            if (visited[adj] == false && c[u][adj] > 0)
            {

                par[adj] = u;
                visited[adj] = true;
                q.push(adj);

                if (adj == t)
                    return true;
            }
        }
    }

    return false;
}