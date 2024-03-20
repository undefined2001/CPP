#include <iostream>
#include <fstream>
#include <vector>

int intconverter(char a)
{
    return a - '0';
}

std::vector<std::pair<int, int>> *graph_list(std::ifstream &myfile, int num_edges, int num_vertices)
{
    std::vector<std::pair<int, int>> *arr = new std::vector<std::pair<int, int>>[num_vertices];

    std::string line;
    for (int i = 0; i < num_edges; i++)
    {
        getline(myfile, line);
        int source = intconverter(line[0]);
        int destination = intconverter(line[2]);
        int weight = intconverter(line[4]);
        arr[source - 1].push_back({destination - 1, weight}); // subtract 1 from indices to convert to 0-based indexing
    }
    return arr;
}

int main()
{
    std::ifstream in("graphinput.txt");
    std::ofstream out("graphlistoutput.txt");

    // Read the number of vertices and edges
    std::string line;
    getline(in, line);
    int num_vertices = intconverter(line[0]);
    int num_edges = intconverter(line[2]);

    std::vector<std::pair<int, int>> *arr = graph_list(in, num_edges, num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        std::cout << "Adjacency list of vertex " << i + 1 << ": ";
        for (std::pair<int, int> neighbor : arr[i])
        {
            std::cout << neighbor.first << " (weight " << neighbor.second << ") ";
        }
        std::cout << std::endl;
    }

    delete[] arr;
    return 0;
}
