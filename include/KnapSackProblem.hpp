#ifndef KNAPSACKPROBLEM_HPP
#define KNAPSACKPROBLEM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

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