#ifndef PROBLEMINPUTGENERATOR_H
#define PROBLEMINPUTGENERATOR_H

#include <string>
#include <fstream>
#include <cstdio>
#include "ProblemSetterToolBox.h"
#include "PSTBConfig.h"

using std::string;
using std::ofstream;

class ProblemSetterToolBox;

class ProblemInputGenerator
{
    public:
        virtual ~ProblemInputGenerator();

        friend ProblemSetterToolBox;

        ProblemInputGenerator & operator << ( string text );

    private:
        ofstream input_file;

        ProblemInputGenerator(
            string base_path,
            string base_name,
            int input_number
        );
};

#endif // PROBLEMINPUTGENERATOR_H
