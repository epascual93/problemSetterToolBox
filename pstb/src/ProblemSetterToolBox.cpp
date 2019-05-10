#include "ProblemSetterToolBox.h"

ProblemSetterToolBox::ProblemSetterToolBox(
    string input_files_base_path,
    string input_files_base_name
){
    this->input_files_base_path = input_files_base_path;
    this->input_files_base_name = input_files_base_name;
    file_counter = 1;
}

ProblemSetterToolBox::~ProblemSetterToolBox()
{
    //Create .BAT for generating outputs using inputs and executable solution
    if (makeOutputGeneratorBAT_flag){
        generateOutputGeneratorBAT();
    }
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

void ProblemSetterToolBox::makeOutputGeneratorBAT(bool flag, string path){
    makeOutputGeneratorBAT_flag = flag;
    if (flag){
        outputGeneratorBAT_path = path;
    }
}

void ProblemSetterToolBox::generateOutputGeneratorBAT(){
    ofstream BAT_file;
    BAT_file.open(outputGeneratorBAT_path + "generate_output.bat");
    BAT_file << "ECHO: This BAT was generated automatically by Problem Setter Tool Box.\n";

    for (
        unsigned int input_number = INITIAL_COUNTER;
        input_number < INITIAL_COUNTER + generatorsList.size();
        input_number++
    ){
        char cad[10];
        sprintf(cad,"%.3d",input_number);

        string basePath = input_files_base_path + PATH_SEPARATOR + input_files_base_name;
        string inputFilePath = basePath + cad + INPUT_EXTENSION;
        string outputFilePath = basePath + cad + OUTPUT_EXTENSION;
        BAT_file << "solution.exe <"
                 << inputFilePath
                 << " >"
                 << outputFilePath
                 << "\n";
    }

    BAT_file.close();
}
