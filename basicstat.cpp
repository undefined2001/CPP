#include <bits/stdc++.h>

double mean(int arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

double standard_deviation(int arr[], int size)
{
    double sd_sum = 0;
    double m = mean(arr, size);
    for (int i = 0; i < size; i++)
    {
        sd_sum += std::pow(arr[i] - m, 2);
    }

    return std::sqrt(sd_sum / (size - 1));
}

/*
def standard_deviation_away(arr):
  newarr = []

  for i in arr:
    if i > above or i < below:
      newarr.append(i)

  return newarr
*/

std::vector<int> standard_deviation_away(int arr[], int size)
{
    std::vector<int> temparr;
    float above = mean(arr, size) + 1.5 * (standard_deviation(arr, size));
    float below = mean(arr, size) - 1.5 * (standard_deviation(arr, size));
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > above || arr[i] < below)
        {
            temparr.push_back(arr[i]);
        }
    }

    return temparr;
}

void print_vec(std::vector<int> myarr)
{
    std::cout << "standard_deviation_away: {";

    for (int i = 0; i < myarr.size(); i++)
    {
        if (i != myarr.size() - 1)
        {
            std::cout << myarr[i] << ", ";
        }
        else
        {
            std::cout << myarr[i];
        }
    }
    std::cout << "}" << std::endl;
}

int main()
{

    int arr[] = {10, 8, 13, 9, 14, 25, -5, 20, 7, 7, 4};

    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Size: " << size << std::endl;
    std::cout << "Mean: " << mean(arr, size) << std::endl;
    std::cout << "Standard_deviation: " << standard_deviation(arr, size) << std::endl;

    std::vector<int> myarr = standard_deviation_away(arr, size);
    print_vec(myarr);

    return 0;
}