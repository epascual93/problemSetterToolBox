#include <bits/stdc++.h>
#include "ProblemSetterToolBox.h"
#include "ProblemInputGenerator.h"
#include <random>
using namespace std;

int main()
{
    /*int a,b; cin >> a >> b;
    cout << a + b << "\n";
    return 0;*/
    ProblemSetterToolBox pstb(".\\input");
    pstb.makeOutputGeneratorBAT(true);

    //Simple Use Case
    for (int i=1; i <= 5; i++){
        for (int j=1; j <= 5; j++){
            auto inputFile = pstb.getNewProblemInputGenerator();
            (*inputFile) << i << " " << j;
        }
    }

    return 0;
}
