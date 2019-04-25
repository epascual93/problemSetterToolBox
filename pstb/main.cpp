#include <bits/stdc++.h>
#include "ProblemSetterToolBox.h"
#include "ProblemInputGenerator.h"
using namespace std;

int main()
{
    ProblemSetterToolBox pstb(".\\input");

    auto input1 = pstb.getNewProblemInputGenerator();

    (*input1) << "a" << " " << "b" << "\n";
    auto input2 = pstb.getNewProblemInputGenerator();
    (*input2) << "csd";

    return 0;
}
