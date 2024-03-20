#include <iostream>
// This Header is for file input output
#include <fstream>
#include <vector>
#include <queue>

std::vector<std::pair<int, int>> *adj_list(std::ifstream &fileobj, int num_edge, int num_vertex)
{
    std::vector<std::pair<int, int>> *arr = new std::vector<std::pair<int, int>>[num_vertex + 1];
    for (int i = 0; i < num_edge; i++)
    {
        int u, v, w;
        fileobj >> u >> v >> w;
        arr[u].push_back(std::make_pair(v, w));
        // std::cout << u << " " << v << " " << w << std::endl;
    }
    return arr;
}




int main()
{

    std::ifstream in("graphinput.txt");
    std::ofstream out("adjacency_list_output.txt");
    int num_edge, num_vertex;
    in >> num_vertex >> num_edge;
    std::vector<std::pair<int, int>> *arr = adj_list(in, num_edge, num_vertex);
    for (int i = 0; i <= num_vertex; i++)
    {
        std::cout << i << ": ";
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (j < arr[i].size() - 1)
            {
                std::cout << "(" << arr[i][j].first << ", " << arr[i][j].second << "), ";
            }
            else
            {
                std::cout << "(" << arr[i][j].first << ", " << arr[i][j].second << ")";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
