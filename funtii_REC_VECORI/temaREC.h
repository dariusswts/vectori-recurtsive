#ifndef temaREC.h
#define temaREC.h
#include <iostream>
#include <fstream>
using namespace std;
void citire_vector_f(int v[],int &dim){
    ifstream citire("data.txt");
    citire>>dim;
    for(int i=0;i<dim;i++){
        citire>>v[i];
    }
}

void afisareVec(int v[],int dim){
    for(int i=0;i<dim;i++){
        cout<<v[i]<<" ";
    }
}
///prob 1
//Se dă un șir cu n elemente, numere naturale. Determinați diferența în valoare absolută dintre numărul de valori pare din șir și numărul de valori impare din șir.


int ValoareAbsoluta(int i,int n,int v[]){
    if(i==n){
        return 0;
    }
    if(v[i]%2==0){
        return 1+ValoareAbsoluta(i+1,n,v);
    }
    else return -1+ValoareAbsoluta(i+1,n,v);
}


///prob 2
//Se citește un vector cu n elemente, numere naturale. Să se afișeze elementele din vector care sunt multipli ai ultimului element.

void afisareMultiplu(int i,int n,int v[]){
    if(i==n){
        return ;
    }
    if(v[i]%v[n-1]==0){
        cout<<v[i]<<" ";
    }
    afisareMultiplu(i+1,n,v);

}

///prob 3
//Se citește un vector cu n elemente, numere naturale. Să se înlocuiască ultimul element prim din vector cu 0, apoi să se afișeze vectorul.

bool prim(int x) {
    if (x < 2) return false;
    for (int i=2; i*i<=x;i++){
        if (x % i == 0)
            return false;
    }
    return true;
}

void inlocuireUltimPrim(int i,int v[]){
    if(i<2){
        return;
    }
    if(prim(v[i])){
        v[i]=0;
        return;
    }
    inlocuireUltimPrim(i-1,v);
}


///prob 4
//Se citește un vector cu n elemente, numere naturale. Să se înlocuiască fiecare element prim din vector cu 0, apoi să se afișeze vectorul

void inlocuirePrime(int i,int n,int v[]) {
    if (i == n)
        return;

    if (prim(v[i]))
        v[i] = 0;

    inlocuirePrime(i + 1,n,v);
}

///prob 5
//Să se determine maximul şi minimul valorilor elementelor unui vector.
int maximREC(int v[],int dim){
    if(dim==1){
        return v[0];
    }
    else{
        int m=maximREC(v,dim-1);
        if(v[dim-1]>m){
            return v[dim-1];
        }
        else
            return m;
    }
}

int minimREC(int v[], int dim){
    if(dim==1){
        return v[0];
    }
    else{
        int m=minimREC(v,dim-1);
        if(v[dim-1]<m){
            return v[dim-1];
        }
        else
            return m;
    }
}
void minMAxV(){
    int v[100],dim;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    cout<<endl;
    cout<<"Maximul si minimul :"<<endl;
    cout<<maximREC(v,dim);
    cout<<" ";
    cout<<minimREC(v,dim);
}

///prob7
//Se citește un vector cu n elemente, numere naturale. Să se determine câte elemente ale vectorului sunt egale cu diferența dintre cea mai mare și cea mai mică valoare din vector.
int numarare(int i,int dif,int n,int v[]) {
    if (i==n)
        return 0;

    if (v[i]==dif){
        return 1+numarare(i+1,dif,n,v);
    }
    return numarare(i+1,dif,n,v);
}
void rezolvareprob7(){
    int v[100],dim;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    int maxVal=maximREC(v,dim);
    int minVAl=minimREC(v,dim);
    int dif =maxVal-minVAl;
    cout<<numarare(0,dif,dim,v);
}

///9
//Se citește un vector cu n elemente, numere naturale distincte. Să se afișeze elementele cuprinse între elementul cu valoarea minimă și cel cu valoare maximă din vector, inclusiv acestea.

void afisare1(int i, int stop,int v[]) {
    if (i > stop)
        return;
    cout<<v[i]<< " ";
    afisare1(i+1,stop,v);
}
void rezolvare9(){
    int v[100],dim;
    citire_vector_f(v,dim);
    int pMin = minimREC(v,dim);
    int pMax = maximREC(v,dim);

   // int start = maximREC(pMin, pMax);
//    int stop = minimREC(pMin, pMax);

//    afisare1(start, stop,v);
}

///10
//Se dă un vector cu n numere naturale. Să se determine câte dintre elemente au valoarea strict mai mare decât media aritmetică a elementelor vectorului.


int suma(int i,int n,int v[100]) {
    if (i == n)
        return 0;
    return v[i] + suma(i + 1,n,v);
}


double media() {
    int i;
    int n;
    int v[100];
    return (double)suma(i,n,v)/ n;
}

int numaraMaiMari(int i, double medie,int n,int v[100]) {
    if (i == n)
        return 0;

    if (v[i] > medie)
        return 1 + numaraMaiMari(i + 1, medie,n,v);

    return numaraMaiMari(i + 1, medie,n,v);
}

void rezolvare10(){
    int v[100],dim,i;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    double medie = media();

    cout << numaraMaiMari(i,medie,dim,v);
}


///11
//Se dă un vector cu n numere naturale. Să se determine câte dintre perechile de elemente din vector sunt prime între ele.
int cmmdc(int a, int b) {
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}


///12
//Se dă un vector cu n numere naturale. Să se determine câte dintre elementele vectorului sunt prime cu ultimul element.
int numaraPrimeCuUltimul(int i, int ultim,int n,int v[100]) {
    if (i == n -1)
        return 0;

    if (cmmdc(v[i], ultim) == 1)
        return 1 + numaraPrimeCuUltimul(i +1,ultim,n,v);

    return numaraPrimeCuUltimul(i+1, ultim,n,v);
}


void rezolvare12(){
    int v[100],dim;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    int ultim = v[dim - 1];
    cout<<endl;
    cout << numaraPrimeCuUltimul(0, ultim,dim,v);
}

///14
//Se citește un vector cu n elemente, numere naturale. Să se înlocuiască ultimul element prim din vector cu 9, apoi să se afișeze vectorul.

void inlocuirePrimeCu9(int i,int n,int v[]) {
    if (i == n)
        return;

    if (prim(v[i]))
        v[i] = 9;

    inlocuirePrime(i + 1,n,v);
}

void rezolvare14(){
    int v[100],dim,i;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    inlocuirePrimeCu9(i,dim,v);
    cout<<endl;
    afisareVec(v,dim);
}

///15
//Se citește un vector cu n elemente, numere naturale.
//Să se afișeze elementele cu indici pari în ordinea crescătoare a indicilor, iar elementele cu indici impari în ordinea descrescătoare a indicilor.
void afisarePari(int i,int n,int v[]) {
    if (i == n)
        return;
    if (i % 2 == 0)
        cout << v[i] << " ";
    afisarePari(i + 1,n,v);
}

void afisareImpari(int i,int v[]) {
    if (i < 0)
        return;
    if (i % 2 == 1)
        cout << v[i] << " ";
    afisareImpari(i - 1,v);
}

void rezolvare15(){
    int v[100],dim,i;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    cout<<endl;
    afisarePari(i,dim,v);
    cout<<endl;
    afisareImpari(dim-1,v);
}

///16
//Se citește un vector cu n elemente, numere naturale. Să se afișeze elementele vectorului în următoarea ordine: primul, ultimul, al doilea, penultimul, etc.
void afisare(int st, int dr) {
    int v[100];
    if (st > dr)
        return;

    cout<<v[st]<< " ";

    if (st != dr)
        cout<<v[dr]<< " ";

    afisare(st+1,dr-1);
}
void rezolvare16(){
    int v[100],dim;
    citire_vector_f(v,dim);
    afisare(0,dim-1);

}

///17
//Se dă un șir cu n elemente, numere reale. Să se determine câte dintre elemente se află în afara intervalului închis determinat de primul și ultimul element.


void interval(int a[], int n, int &mn, int &mx)
{
    if(a[0] < a[n-1])
    {
        mn=a[0];
        mx=a[n-1];
    }
    else
    {
        mn= a[n-1];
        mx= a[0];
    }
}

int numara(int a[], int n, int i, int mn, int mx)
{
    if(i == n)return 0;

    if(a[i]<mn||a[i]> mx)
        return 1 + numara(a,n,i+1,mn,mx);
    else
        return numara(a,n,i+1,mn,mx);
}

void rezolvare17(){
    int v[100],dim,a,n;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    int mn, mx;
    interval(v, dim, mn, mx);

    int rezultat = numara(v, dim, 0, mn, mx);

    cout << rezultat;
}


//19
//Se citește un vector cu n elemente, numere naturale. Să se afișeze elementele din vector care sunt multipli ai ultimului element.

void afisareMultipluElmMijloc(int i,int n,int v[]){
    if(i==n){
        return ;
    }
    if(v[i]%v[n%2]==0){
        cout<<v[i]<<" ";
    }
    afisareMultiplu(i+1,n,v);

}
void rezolvare19(){
    int v[100],dim,i;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    cout<<endl;
    afisareMultipluElmMijloc(i,dim,v);
}

///20
//Se dă un vector cu n numere naturale. Să se determine câte dintre elemente au valoarea strict mai mare decât media aritmetică a elementelor vectorului.
int suma(int a[],int n,int i){
    if(i==n)return 0;
    return a[i]+suma(a,n,i+1);
}

int numara(int a[],int n,int i,double med){
    if(i==n)return 0;
    if(a[i]>med)return 1+numara(a,n,i+1,med);
    return numara(a,n,i+1,med);
}

void rezolvare20(){
    int v[100],dim;
    citire_vector_f(v,dim);
    afisareVec(v,dim);
    cout<<endl;
    double med=suma(v,dim,0)/dim;
    cout<<numara(v,dim,0,med);
}





#endif // temaREC.h
