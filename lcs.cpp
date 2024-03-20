#include <bits/stdc++.h>

int **longest_common_subsequence(std::string a, std::string b)
{
    int size_one = a.length() + 1;
    int size_two = b.length() + 1;
    int **arr = new int *[size_one];
    for (int i = 0; i < size_one; i++)
    {
        arr[i] = new int[size_two];
        memset(arr[i], 0, size_two * sizeof(int));
    }

    for (int i = 1; i < size_one; i++)
    {
        for (int j = 1; j < size_two; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    return arr;
}

std::string get_lcs_from_array(int **arr, int size_one, int size_two, std::string a)
{
    std::string lcs = "";
    int i = size_one - 1;
    int j = size_two - 1;
    while (i > 0 && j > 0)
    {
        if (arr[i][j] == arr[i - 1][j])
        {
            i--;
        }
        else if (arr[i][j] == arr[i][j - 1])
        {
            j--;
        }
        else
        {
            lcs = a[j - 1] + lcs;
            i--;
            j--;
        }
    }
    return lcs;
}

int main()
{
    std::string a = "aaaabbbcccddd";
    std::string b = "aabbccdd";
    int **result = longest_common_subsequence(a, b);

    int size_one = a.length() + 1;
    int size_two = b.length() + 1;
    std::cout << get_lcs_from_array(result, size_one, size_two, b) << std::endl;
    for (int i = 0; i < size_one; i++)
    {
        for (int j = 0; j < size_two; j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < size_one; i++)
    {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
