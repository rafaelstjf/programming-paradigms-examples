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
        comparisons++;
        int mid = l + (u - l) / 2;
        if (array[mid] == x)
        {
            comparisons++;
            return mid;
        }
        if (array[mid] > x)
        {
            comparisons++;
            return solveAux(array, l, mid - 1, x);
        }
        return solveAux(array, mid + 1, u, x);
    }
    return -1;
}
void BinarySearch::solveProblem(string filename)
{
    clock_t start, end;
    fstream input;
    fstream output;
    comparisons = 0;
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
        start = clock();
        int result = solveAux(array, 0, arrSize - 1, x);
        end = clock();
        cout << "Resultado: " << endl;
        if (result == -1)
            cout << "Elemento nao encontrado no vetor!" << endl;
        else
            cout << "Posicao do elemento: " << result << endl;
        cout << "Comparacoes: " << comparisons << endl;
        cout << "Tempo: " << (end - start) << " milisegundos | " << (end - start) / CLOCKS_PER_SEC << " segundos" << endl;
        //saving in file
        string outFilename;
        int size = filename.find_last_of('.');
        if (size <= filename.size())
            outFilename = filename.substr(0, size) + "_result.txt";
        else
            outFilename = filename + "_result.txt";
        output.open(outFilename, fstream::out);
        if (output.is_open())
        {
            output << "Resultado: " << endl;
            if (result == -1)
                output << "Elemento nao encontrado no vetor!" << endl;
            else
                output << "Posicao do elemento: " << result << endl;
            output << "Comparacoes: " << comparisons << endl;
            output << "Tempo: " << (end - start) << " milisegundos | " << (end - start) / CLOCKS_PER_SEC << " segundos" << endl;
            cout << "Resultado salvo em: " << outFilename << endl;
        }
    }
    else
    {
        cout << "Erro! Falha ao abrir o arquivo" << filename << endl;
    }
}
