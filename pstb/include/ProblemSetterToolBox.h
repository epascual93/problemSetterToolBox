#ifndef PROBLEMSETTERTOOLBOX_H
#define PROBLEMSETTERTOOLBOX_H

#include <string>
#include <list>
#include "ProblemInputGenerator.h"
#include "PSTBConfig.h"

class ProblemInputGenerator;

using std::string;
using std::list;

class ProblemSetterToolBox
{
    public:
        ProblemSetterToolBox(
            string input_files_base_path,
            string input_files_base_name = ""
        );
        virtual ~ProblemSetterToolBox();

        ProblemInputGenerator* getNewProblemInputGenerator();

        void makeOutputGeneratorBAT(bool flag, string path="");

    private:
        string input_files_base_path;
        string input_files_base_name;
        int file_counter;

        list<ProblemInputGenerator*> generatorsList;

        bool makeOutputGeneratorBAT_flag;
        string outputGeneratorBAT_path;
        void generateOutputGeneratorBAT();
};

#endif // PROBLEMSETTERTOOLBOX_H
