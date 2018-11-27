
#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include <iostream>
#include <fstream>
#include <string>
#include<ctime>
using namespace std;

class BinarySearch
{
  private:
  int solveAux(int* arr, int l, int u, int x);
  int comparisons;
  public:
    BinarySearch();
    ~BinarySearch();
    void solveProblem(string filename);
};
#endif