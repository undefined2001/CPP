#include <iostream>
#include <vector>
#include <queue>

class Graph
{
    int m_V;
    bool *m_Visited;
    std::vector<std::pair<int, int>> *m_Graph;

public:
    Graph(int);
    void addEdge(int, int, int);
    void printGraph();
    void DijkastrasShortestPath(int source, int destination);
};

Graph::Graph(int V) : m_V(V + 1), m_Visited(new bool[m_V]), m_Graph(new std::vector<std::pair<int, int>>[m_V]) {}

void Graph::addEdge(int u, int v, int w)
{
    m_Graph[u].push_back({v, w});
}

void Graph::DijkastrasShortestPath(int source, int destination)
{
    std::deque < std::pair<int, int>, std::greater<std::pair<int, int>>> q;
    q.push_back((std::make_pair(source, 0)));
    while(!(q.empty()))
    {
        
    }

}

void Graph::printGraph()
{
    for (int i = 1; i < m_V; i++)
    {
        std::cout << i << ": ";
        std::vector<std::pair<int, int>>::iterator it;
        for (it = m_Graph[i].begin(); it != m_Graph[i].end(); it++)
        {
            std::cout << "(" << (*it).first << ", " << (*it).second << ") ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 20);
    g.addEdge(2, 3, 13);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 8);
    g.addEdge(5, 10, 11);
    g.printGraph();
    g.DFS();

    return 0;
}