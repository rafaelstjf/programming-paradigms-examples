#include <iostream>
#include "../include/KnapSackProblem.hpp"
using namespace std;

int main()
{
    string filename;
    cout << "Knapsack problem" << endl;
    cout << "Enter the file name" << endl;
    cin >> filename;
    KnapSackProblem *k = new KnapSackProblem();
    k->solveProblem(filename);
    return 0;
}