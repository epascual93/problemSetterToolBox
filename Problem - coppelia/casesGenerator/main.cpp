#include <bits/stdc++.h>
#include "pstb/ProblemSetterToolBox.h"
using namespace std;

typedef pair<int,int> ii;

ProblemSetterToolBox pstb("..\\testcases");

const int MN = 100;
struct DATA {
    int A[4], B[4], C[4];
};

void dataset_to_files(DATA data){
    auto data_file = pstb.getNewProblemInputGenerator();

    for (int i=0; i < 4; i++){
        (*data_file) << data.A[i] << " "
                     << data.B[i] << " "
                     << data.C[i] << "\n";
    }
}

void generate_sample(){
    DATA sample;
    sample.A[0]=1; sample.B[0]=0; sample.C[0]=4;
    sample.A[1]=0; sample.B[1]=3; sample.C[1]=3;
    sample.A[2]=0; sample.B[2]=3; sample.C[2]=2;
    sample.A[3]=2; sample.B[3]=2; sample.C[3]=2;
    dataset_to_files(sample);
}


void generate_borders(){
    {//Block for variable scope
        DATA border_case;
        for (int i=0; i < 4; i++){
            border_case.A[i] = border_case.B[i] = border_case.C[i] = 0;
        }
        dataset_to_files(border_case);
        for (int i=0; i < 4; i++){
            border_case.A[i] = border_case.B[i] = border_case.C[i] = 1;
        }
        dataset_to_files(border_case);
        for (int i=0; i < 4; i++){
            border_case.A[i] = border_case.B[i] = border_case.C[i] = MN;
        }
        dataset_to_files(border_case);
        for (int i=0; i < 4; i++){
            border_case.A[i] = border_case.B[i] = border_case.C[i] = MN-i;
        }
        dataset_to_files(border_case);
    }
}

void make_random_dataset(DATA &data, int M){
    for (int i=0; i < 4; i++){
        data.A[i] = rand()%M;
        data.B[i] = rand()%M;
        data.C[i] = rand()%M;
    }
}

void generate_random_datasets(){
    int ranges[] = {3,5,9,15,25,45,60,72,80,95,101, 0};

    for (int i=0; ranges[i]; i++){
        DATA random_data;
        make_random_dataset(random_data, ranges[i]);
        dataset_to_files(random_data);
        make_random_dataset(random_data, ranges[i]);
        dataset_to_files(random_data);
        make_random_dataset(random_data, ranges[i]);
        dataset_to_files(random_data);
    }
}

int main()
{
    pstb.makeOutputGeneratorBAT(true);

    srand(2019);

    generate_sample();
    generate_random_datasets();
    generate_borders();

    return 0;
}
