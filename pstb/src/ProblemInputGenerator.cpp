#include "ProblemInputGenerator.h"

ProblemInputGenerator::ProblemInputGenerator(
    string base_path,
    string base_name,
    int input_number
)
{
    char cad[10];
    sprintf(cad,"%.3d",input_number);
    string filePath = base_path + PATH_SEPARATOR + base_name + cad + INPUT_EXTENSION;

    input_file.open(filePath);
}

ProblemInputGenerator::~ProblemInputGenerator()
{
    input_file.close();
}
