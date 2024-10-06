#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#define DIRECTED true
std::vector<std::vector<int>> graph_arr(std::ifstream &in, int size, bool directed = false)
{
    std::vector<std::vector<int>> adj_list(size + 1);
    int u, v;
    while (in >> u >> v)
    {
        adj_list[u].push_back(v);
        if (!directed)
        {
            adj_list[v].push_back(u);
        }
    }
    return adj_list;
}

void print_list(std::vector<std::vector<int>> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        std::cout << i << ": ";
        for (int j = 0; j < arr[i].size(); j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void bfs(std::vector<std::vector<int>> arr, int source, int destination)
{
    std::vector<bool> visited(arr.size(), false);
    std::queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        std::cout << u << " ";
        if (u == destination)
        {
            return;
        }
        for (int i = 0; i < arr[u].size(); i++)
        {
            int v = arr[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    std::ifstream in("bfsinput.txt");
    int v, e;
    in >> v >> e;
    std::vector<std::vector<int>> adj_list = graph_arr(in, v, DIRECTED);
    in.close();
    print_list(adj_list);

    bfs(adj_list, 1, adj_list.size());

    return 0;
}
