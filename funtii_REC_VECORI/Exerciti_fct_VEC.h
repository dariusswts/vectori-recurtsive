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

void citire_rec(int v[], int dim,int i,ifstream &cit){
    if(i==dim){
        return;
    }
    cit>>v[i];
    citire_rec(v,dim,i+1,cit);
}

void afisareREC(int v[],int dim,int i){
    if(i>=dim){
        return;
    }
    cout<<v[i]<<" ";
    afisareREC(v,dim,i+1);
}














#endif // EXERCITI_FCT_VEC_H_INCLUDED
