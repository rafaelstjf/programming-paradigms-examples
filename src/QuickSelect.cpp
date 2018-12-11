#include "../include/QuickSelect.hpp"

QuickSelect::QuickSelect()
{
}
QuickSelect::~QuickSelect()
{
}
void QuickSelect::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int QuickSelect::partition(int array[], int l, int r)
{
    int pivot = array[r];
    int i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (array[j] <= pivot)
        {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[r]);
    return i;
}
int QuickSelect::solveAux(int array[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int index = partition(array, l, r);
        if (index - l == k - 1)
            return array[index];
        if (index - l > k - 1)
            return solveAux(array, l, index - 1, k);
        return solveAux(array, index + 1, r, k - index + l - 1);
    }
}
void QuickSelect::solveProblem(string filename)
{
    fstream input;
    fstream output;
        clock_t start, end;
    int arraySize = 0;
    int element = 0;
    int k = 0;
    int *array;

    input.open(filename, fstream::in);
    if (input.is_open())
    {
        //getting the data from the file
        string line;
        getline(input, line);
        k = atoi(line.c_str());
        getline(input, line);
        arraySize = atoi(line.c_str());
        array = new int[arraySize];
        getline(input, line);
        element = atoi(line.c_str());
        for (int i = 0; i < arraySize; i++)
        {
            getline(input, line);
            array[i] = atoi(line.c_str());
        }
        //solving
        start = clock();
        int solution = solveAux(array, 0, arraySize - 1, k);
        end = clock();

        //saving the result
        string outFilename;
        int size = filename.find_last_of('.');
        if (size <= filename.size())
            outFilename = filename.substr(0, size) + "_result.txt";
        else
            outFilename = filename + "_result.txt";
        output.open(outFilename, fstream::out);
        if (output.is_open())
        {

            output << "Problema:" << endl;
            output << k << endl;
            output << arraySize << endl;
            for (int i = 0; i < arraySize; i++)
            {
                output << array[i] << endl;
            }
            output << "Resultado: " << solution << endl;
            cout << "Resultado: " << solution << endl;
            output << fixed << "Tempo: " << (end - start) << " milisegundos | " << (end - start) / CLOCKS_PER_SEC << " segundos" << endl;
            cout << fixed << "Tempo: " << (end - start) << " milisegundos | " << (end - start) / CLOCKS_PER_SEC << " segundos" << endl;
            cout << "Resultado salvo em: " << outFilename << endl;
        }
    }
    else
    {
        cout << "Erro! abrir arquivo " << filename << endl;
    }
}