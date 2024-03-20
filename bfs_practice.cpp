#include <iostream>
#include <vector>

class Graph
{
    int m_V;
    std::vector<int> *m_Graph;

public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
    void bfs(int);
};

Graph::Graph(int V) : m_V(V + 1), m_Graph(new std::vector<int>[m_V]) {}

void Graph::addEdge(int u, int v)
{
    m_Graph[u].push_back(v);
    m_Graph[v].push_back(u);
}

void Graph::bfs(int source = 1)
{
    
}

void Graph::printGraph()
{
    for (int i = 1; i < m_V; i++)
    {
        std::cout << i << ": ";
        std::vector<int>::iterator it;
        for (it = m_Graph[i].begin(); it != m_Graph[i].end(); it++)
        {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.printGraph();

    return 0;
}