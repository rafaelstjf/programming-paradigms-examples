#include "../include/FractionalKnapSack.hpp"

FractionalKnapSack::FractionalKnapSack()
{
}
FractionalKnapSack::~FractionalKnapSack()
{
}
int *FractionalKnapSack::sort(int *v, int *w, int size)
{
    int *array = new int[size];
    int *indArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (w[i] == 0)
            array[i] = INT_MAX;
        else
            array[i] = v[i] / w[i];
        indArray[i] = i;
    }
    return sortAux(array, indArray, size);
}
void FractionalKnapSack::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int *FractionalKnapSack::sortAux(int *a, int *b, int size)
{
    //selection sort
    int i, j, minIdx;
    for (int i = 0; i < size - 1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[minIdx], a[i]);
        swap(b[minIdx], b[i]);
    }
    return b;
}

void FractionalKnapSack::solveProblem(string filename)
{
    fstream input;
    fstream output;
    clock_t start, end;
    comparisons = 0;
    input.open(filename, fstream::in);
    if (input.is_open())
    {
        //get Data
        string line;
        getline(input, line);
        int numItems = atoi(line.c_str());
        getline(input, line);
        int bpWeight = atoi(line.c_str());
        int *v = new int[numItems];
        int *w = new int[numItems];
        for (int i = 0; i < numItems; i++)
        {
            getline(input, line);
            int index = line.find(';');
            string temp1 = line.substr(0, index);
            string temp2 = line.substr(index + 1, line.size());
            w[i] = atoi(temp1.c_str());
            v[i] = atoi(temp2.c_str());
        }
        //sort the elements
        int *indArray = sort(v, w, numItems);
        start = clock();
        //solve the problem
        double *used = new double[numItems];
        int j = numItems - 1;
        int bpW = bpWeight;
        cout << bpW << endl;
        while (j >= 0 && w[indArray[j]] <= bpW)
        {
            used[indArray[j]] = 1;
            bpW = bpW - w[indArray[j]];
            j = j - 1;
        }
        if (j >= 0)
        {
            used[indArray[j]] = (double)bpW / w[indArray[j]];
            for (int i = j - 1; i >= 0; i--)
            {
                used[indArray[i]] = 0;
            }
        }
        double sum = 0;
        for (int i = 0; i < numItems; i++)
        {
            sum += used[i] * v[i];
        }
        end = clock();
        //print
        cout << "Resultado:" << endl;
        for (int i = 0; i < numItems; i++)
        {
            cout << "Proporcao usada do item"
                 << "[" << i << "]: " << used[i] << endl;
        }
        cout << "Valor total: " << sum << endl;
        cout << "Tempo: " << (end - start) << " milisegundos | " << (end - start) / CLOCKS_PER_SEC << " segundos" << endl;
        //save the file
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
            output << numItems << endl;
            output << bpWeight << endl;
            for (int i = 0; i < numItems; i++)
            {
                output << w[i] << ";" << v[i] << endl;
            }
            output << "Resultado: " << endl;
            for (int i = 0; i < numItems; i++)
            {
                output << "Proporcao usada do item"
                       << "[" << i << "]: " << used[i] << endl;
            }
            output << "Valor total: " << sum << endl;
            output << "Tempo: " << (end - start) << " milisegundos | " << (end - start) / CLOCKS_PER_SEC << " segundos" << endl;
            cout << "Resultado salvo em: " << outFilename << endl;
        }
    }
    else
    {
        cout << "Erro! Falha ao abrir o arquivo" << filename << endl;
    }
}