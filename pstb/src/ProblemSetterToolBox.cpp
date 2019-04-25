#include "ProblemSetterToolBox.h"

ProblemSetterToolBox::ProblemSetterToolBox(
    string input_files_base_path,
    string input_files_base_name
){
    this->input_files_base_path = input_files_base_path;
    this->input_files_base_name = input_files_base_name;
    file_counter = 0;
}

ProblemSetterToolBox::~ProblemSetterToolBox()
{
    for (auto generatorPtr : generatorsList){
        delete generatorPtr;
    }
}

ProblemInputGenerator* ProblemSetterToolBox::getNewProblemInputGenerator()
{
    ProblemInputGenerator *generator = new ProblemInputGenerator(
        input_files_base_path,
        input_files_base_name,
        file_counter
    );
    generatorsList.push_back(generator);
    file_counter++;
    return generator;
}
