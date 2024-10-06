#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <fstream>

// Define a type alias for the matrix
using matrix = std::shared_ptr<std::shared_ptr<int[]>[]>;


matrix make_graph(std::ifstream& file, int E, int V)
{
    matrix graph(new std::make_shared<int[]>);



    return graph;
}

int main()
{
    std::ifstream in("graphinput.txt");
    std::ofstream out("graphoutput.txt");

    // Example usage: Call make_graph to get the matrix as a shared pointer
    int num_edges = 3; // Example value, change as needed
    int num_vertices = 3; // Example value, change as needed
    auto graph = make_graph(in, num_edges, num_vertices);

    // Use the shared pointer to access elements of the matrix
    // For example, graph[i][j] gives the element at row i, column j

    return 0;
}
