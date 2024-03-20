#include <bits/stdc++.h>

int intconverter(char a)
{
    return a - '0';
}

int **graph_matrix(std::ifstream &myfile, int num_edges, int num_vertices)
{
    std::string line;

    int **arr = new int *[num_vertices];

    for (int i = 0; i < num_vertices; i++)
    {
        arr[i] = new int[num_vertices];
        memset(arr[i], 0, num_vertices * sizeof(int));
    }

    // Read in the edges
    for (int i = 0; i < num_edges; i++)
    {
        getline(myfile, line);
        int source = intconverter(line[0]);
        int destination = intconverter(line[2]);
        int weight = intconverter(line[4]);
        arr[source - 1][destination - 1] = weight;
    }

    return arr;
}

void print_matrix(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream in("graphinput.txt");
    std::ofstream out("graphoutput.txt");

    // Read the number of vertices
    std::string line;
    getline(in, line);
    int num_vertices = intconverter(line[0]);
    int num_edges = intconverter(line[2]);

    int **arr = graph_matrix(in, num_edges, num_vertices);
    print_matrix(arr, num_vertices);

    // delete[] arr;

    return 0;
}
