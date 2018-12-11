#include "../include/KnapSackProblem.hpp"

KnapSackProblem::KnapSackProblem()
{
}

void KnapSackProblem::solveProblem(string filename)
{
    fstream input;
    fstream output;
    clock_t start, end;
    input.open(filename, fstream::in);
    if (input.is_open())
    {
        //open the file
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
        start = clock();
        //creates the matrix
        int **t = new int *[numItems + 1];
        for (int i = 0; i <= numItems; i++)
        {
            t[i] = new int[bpWeight + 1];
        }
        for (int i = 0; i <= numItems; i++)
        {
            t[i][0] = 0;
        }
        for (int j = 0; j <= bpWeight; j++)
        {
            t[0][j] = 0;
        }
        //solve the problem
        for (int i = 1; i <= numItems; i++)
        {
            for (int j = 1; j <= bpWeight; j++)
            {
                if (w[i - 1] <= j)
                    t[i][j] = max(t[i - 1][j - w[i - 1]] + v[i - 1], t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        //get the elements
        int a = numItems;
        int b = bpWeight;
        vector<int> result;
        while (a > 0)
        {
            if (w[a - 1] <= b)
            {
                if (t[a - 1][b - w[a - 1]] + v[a - 1] > t[a - 1][b])
                {
                    result.push_back(a);
                    a = a - 1;
                    b = b - w[a];
                }
                else
                {
                    a = a - 1;
                }
            }
            else
                a = a - 1;
        }
        end = clock();
        //saving result
        string outFilename;
        int size = filename.find_last_of('.');
        if (size <= filename.size())
            outFilename = filename.substr(0, size) + "_result.txt";
        else
            outFilename = filename + "_result.txt";
        output.open(outFilename, fstream::out);
        cout.precision(15);
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
            for (int i = result.size() - 1; i >= 0; i--)
                output << result[i] << "    ";
            output << endl;
            output << fixed << "Tempo: " << (end - start) << " milisegundos | " << (end - start) / CLOCKS_PER_SEC << " segundos" << endl;
            cout << "Resultado salvo em: " << outFilename << endl;
        }
        /*
        output << "result Matrix" << endl;
        for (int i = 0; i <= numItems; i++)
        {
            for (int j = 0; j <= bpWeight; j++)
            {
                output << t[i][j] << " ";
            }
            output << endl;
        }
        */
        cout << "Resultado: " << endl;
        for (int i = result.size() - 1; i >= 0; i--)
            cout << result[i] << "    ";
        cout << endl;
        cout << fixed << "Tempo: " << (end - start) << " milisegundos | " << (end - start) / CLOCKS_PER_SEC << " segundos" << endl;
    }
    else
    {
        cout << "Erro! Falha ao abrir o arquivo " << filename << endl;
    }
}