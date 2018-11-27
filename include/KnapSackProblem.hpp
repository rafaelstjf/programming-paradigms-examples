#ifndef KNAPSACKPROBLEM_HPP
#define KNAPSACKPROBLEM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include<ctime>


using namespace std;
class KnapSackProblem
{
  private:
  public:
    KnapSackProblem();
    ~KnapSackProblem();
    void solveProblem(string filename);
};
#endif