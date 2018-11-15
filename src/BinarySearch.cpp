#include "../include/BinarySearch.hpp"

BinarySearch::BinarySearch()
{
}
BinarySearch::~BinarySearch()
{
}
int BinarySearch::solveAux(int *array, int l, int u, int x)
{
    if (u >= l)
    {
        comparations++;
        int mid = l + (u - l) / 2;
        if (array[mid] == x)
        {
            comparations++;
            return mid;
        }
        if (array[mid] > x)
        {
            comparations++;
            return solveAux(array, l, mid - 1, x);
        }
        return solveAux(array, mid + 1, u, x);
    }
    return -1;
}
void BinarySearch::solveProblem(string filename)
{
    fstream input;
    fstream output;
    comparations = 0;
    input.open(filename, fstream::in);
    if (input.is_open())
    {
        string line;
        getline(input, line);
        int arrSize = atoi(line.c_str());
        int *array = new int[arrSize];
        getline(input, line);
        int x = atoi(line.c_str());
        for (int i = 0; i < arrSize; i++)
        {
            getline(input, line);
            array[i] = atoi(line.c_str());
        }
        int result = solveAux(array, 0, arrSize - 1, x);
        cout << "Result: " << endl;
        if (result == -1)
            cout << "Element not found in the array!" << endl;
        else
            cout << "Element position: " << result << endl;
        cout << "Comparations: " << comparations << endl;
        string outFilename;
        int size = filename.find_last_of('.');
        if (size <= filename.size())
            outFilename = filename.substr(0, size) + "_result.txt";
        else
            outFilename = filename + "_result.txt";
        output.open(outFilename, fstream::out);
        if (output.is_open())
        {
            output << "Result: " << endl;
            if (result == -1)
                output << "Element not found in the array!" << endl;
            else
                output << "Element position: " << result << endl;
            output << "Comparations: " << comparations << endl;
        }
    }
    else
    {
        cout << "Error! Impossible to open file " << filename << "." << endl;
    }
}
