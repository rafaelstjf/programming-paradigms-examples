#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include<ctime>

using namespace std;

class QuickSelect
{
  public:
    QuickSelect();
    ~QuickSelect();
    void solveProblem(string filename);

  private:
    int partition(int array[], int l, int r);
    int solveAux(int array[], int l, int r, int k);
    void swap(int &a, int &b);
};

#endif