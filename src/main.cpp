#include <iostream>
#include "../include/KnapSackProblem.hpp"
#include "../include/BinarySearch.hpp"
#include "../include/QuickSelect.hpp"
#include "../include/FractionalKnapSack.hpp"
using namespace std;

int main(int argc, char **argv)
{
    string filename;
    KnapSackProblem *k;
    FractionalKnapSack *fk;
    BinarySearch *bs;
    bool inMenu = true;
    QuickSelect *qs;
    string op;
    if (argc < 3)
    {
        cout << "-------------MENU---------------------------- \n Escolha uma opcao : \n 1 - Problema da mochila(KnapSack problem) \n 2 - Busca binaria \n 3 - QuickSelect \n 4 - Problema da mochila fracionaria" << endl;
        cout << "Digite sua opcao e pressione enter: ";
        cin >> op;
        while (inMenu)
        {
            switch (atoi(op.c_str()))
            {
            case 1:
                cout << "Problema da mochila" << endl;
                cout << "Entre o nome (+ extensao) do arquivo de entrada" << endl;
                cin >> filename;
                k = new KnapSackProblem();
                k->solveProblem(filename);
                inMenu = false;
                break;
            case 2:
                cout << "Busca binaria" << endl;
                cout << "Entre o nome (+ extensao) do arquivo de entrada" << endl;
                cin >> filename;
                bs = new BinarySearch();
                bs->solveProblem(filename);
                inMenu = false;
                break;
            case 3:
                cout << "QuickSelect" << endl;
                cout << "Entre o nome (+ extensao) do arquivo de entrada" << endl;
                cin >> filename;
                qs = new QuickSelect();
                qs->solveProblem(filename);
                inMenu = false;
                break;
            case 4:
                cout << "Problema da mochila fracionaria" << endl;
                cout << "Entre o nome (+ extensao) do arquivo de entrada" << endl;
                cin >> filename;
                fk = new FractionalKnapSack();
                fk->solveProblem(filename);
                inMenu = false;
                break;
            default:
                cout << "Opcao invalida! Digite novamente" << endl;
                cin >> op;
            }
        }
    }
    else
    {
        op = argv[1];
        filename = argv[2];
        switch (atoi(op.c_str()))
        {
        case 1:
            cout << "Problema da mochila" << endl;
            k = new KnapSackProblem();
            k->solveProblem(filename);
            inMenu = false;
            break;
        case 2:
            cout << "Busca binaria" << endl;
            bs = new BinarySearch();
            bs->solveProblem(filename);
            inMenu = false;
            break;
        case 3:
            cout << "QuickSelect" << endl;
            qs = new QuickSelect();
            qs->solveProblem(filename);
            inMenu = false;
            break;
        case 4:
            cout << "Problema da mochila fracionaria" << endl;
            fk = new FractionalKnapSack();
            fk->solveProblem(filename);
            inMenu = false;
            break;
        default:
            cout << "Opcao invalida! Digite novamente" << endl;
        }
    }

    return 0;
}