#include <iostream>
#include <vector>

class Graph
{
    int m_V;
    std::vector<int> *m_Graph;

public:
    Graph(int V = 0); // Default argument for V
    ~Graph();
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
        for (int j : m_Graph[i])
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

Graph::~Graph()
{
    delete[] m_Graph;
}

int main()
{
    Graph g(5); // Provide the value of V
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.printGraph();

    return 0;
}
