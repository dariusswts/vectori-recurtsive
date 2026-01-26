#ifndef EXERCITI_FCT_VEC_H_INCLUDED
#define EXERCITI_FCT_VEC_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;


void citire_vector_fis(int v[],int &dim){
    ifstream citire("data.txt");
    citire>>dim;
    for(int i=0;i<dim;i++){
        citire>>v[i];
    }
}

void afisareVector(int v[],int dim){
    for(int i=0;i<dim;i++){
        cout<<v[i]<<" ";
    }
}


















#endif // EXERCITI_FCT_VEC_H_INCLUDED
