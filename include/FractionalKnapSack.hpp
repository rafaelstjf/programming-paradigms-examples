#ifndef FRACTIONALKNAPSACK_HPP
#define FRACTIONALKNAPSACK_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <climits>

using namespace std;
class FractionalKnapSack{
private:
int comparisons;
int* sort(int *v, int *w, int size);
int* sortAux(int *a, int *b, int size);
void swap(int &a, int &b);

public:
FractionalKnapSack();
~FractionalKnapSack();
void solveProblem(string filename);

};


#endif
