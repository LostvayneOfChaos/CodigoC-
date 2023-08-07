/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 5 de mayo de 2023, 04:36 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
const int n=7,m=8;

/*
 * 
 */
int max(int a,int b){
	return (a>b)?a:b;
}
int maxDe3(int a,int b,int c){
	return max(max(a,b),c);
}

int busca(int*arr,int ini,int fin,int*pos){
    int iz,der,centro,Valorcentro;
    int posIz,posDer,posCent;
    if(ini>=fin){
        *pos=ini;
        return arr[ini];
    } 
    centro=(ini+fin)/2;
    Valorcentro=arr[centro];
    posCent=centro;
    iz=busca(arr,0,centro-1,&posIz);
    der=busca(arr,centro+1,fin,&posDer);
    
    if(iz>=max(Valorcentro,der)){
        *pos=posIz;
        return iz;
    }
    else if(der>=max(iz,Valorcentro)){
        *pos=posDer;
        return der;
    }
    else if(Valorcentro>=max(iz,der)){
        *pos=posCent;
        return Valorcentro;
    }
    
    
    
}
int resolver(int matriz[m][n], int *arregloMax,int*maxCol){
    int centro,ini,fin;
    int col;
    int maxPotencia=0,potencia=0;
    for (int i = 0; i < m; i++) {//para filas
        ini=0;
        fin=n-1;
        centro=(ini+fin)/2;
        if(matriz[i][centro]==0){
            if(matriz[i][centro-1]!=0) potencia=busca(matriz[i],centro-1,fin,&col);
            else if (matriz[i][centro+1]!=0) potencia= busca(matriz[i],centro+1,fin,&col);
            else potencia=0;
        }
        else{
            if(matriz[i][centro-1]!=0) potencia=busca(matriz[i],centro-1,fin,&col);
            else if (matriz[i][centro+1]!=0) potencia=busca(matriz[i],centro+1,fin,&col);
            else potencia=0;
        }
        arregloMax[i]=potencia;
        if(potencia>maxPotencia){
            maxPotencia=potencia;
            (*maxCol)=(col);
        }
    }
    return maxPotencia;
}




int main(int argc, char** argv) {
    /*int matriz[m][n]={{0 ,0 ,0 ,0 ,0 ,0, 0},
    {0 ,0, 0, 0, 0, 0, 0},
    {0 ,0, 0, 0 ,0 ,0, 0},
    {0 ,0 ,0 ,0, 0 ,0, 0},
    {0, 0, 0 ,0 ,1, 1, 1},
    {0, 0,0 ,0, 1 ,2, 2},
    {0, 0, 0, 0 ,1, 2 ,3},
    {0, 0, 0 ,0, 1 ,2 ,2},
    {0, 0, 0, 0 ,1 ,1, 1},
    {0, 0, 0, 0, 0 ,0, 0}};*/
    
    int matriz[m][n]={{0 ,0 ,0 ,0 ,0 ,0, 0},
    {0 ,0, 0, 0, 0, 0, 0},
    {0 ,0, 0, 0 ,0 ,0, 0},
    {0 ,0 ,0 ,0, 0 ,0, 0},
    {0, 1, 1 ,1 ,0, 0, 0},
    {0, 1, 2 , 1, 0 ,0, 0},
    {0, 1, 1, 1 ,0, 0 ,0},
    {0, 0, 0 ,0, 0 ,0 ,0}};
    
    int arregloMax[m];//guardara los maximos de cada fila
    int columna,fila;
    int maxPotencia;
    maxPotencia=resolver(matriz,arregloMax,&columna);
    cout<<"columna "<<columna+1<<endl;
    cout<<"potencia de bomba que al estallar disminuye en sus alrededores"<<maxPotencia<<endl;
    
    int maxVal;
    maxVal=busca(arregloMax,0,m-1,&fila);
    
    if (fila==-1)
		cout<<"El elemento no se encuentra."<<endl;
	else 
		cout<<"El elemento se encuentra en la fila : "<<fila+1<<endl;
    
    return 0;
}

