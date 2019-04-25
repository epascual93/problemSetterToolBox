# Problem Setter Tool Box
A set of tools with the purpose of making the problem setter work easier!
For now only provides minimal features for C++, but is intended to grow!

## Simple Use Case
With the following chunk of code you create 100 data set files, each one containing a diferent pair of integers from 1 to 10.

    ProblemSetterToolBox pstb(".\\input");
    for (int i=1; i <= 10; i++){
        for (int j=1; j <= 10; j++){
            auto inputFile = pstb.getNewProblemInputGenerator();
            (*inputFile) << i << " " << j << "\n";
        }
    }

The data sets will be created inside a folder called `input` of the actual directory, and they will be named 001.in, ... 100.in
The __input folder__ must exits.