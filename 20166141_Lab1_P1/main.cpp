/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 22 de abril de 2023, 03:06 PM
 */
//falto el cstdlib y el io
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

void cargaBinaria(int numero,int cromosoma[],int longitud_cromosoma){
	int i, aux;
	for (i=0; i<longitud_cromosoma; i++){
		cromosoma[i] = 0;
	}
	i = 0;
	while (numero>0){
		aux = numero%2;
		numero = numero/2;
		cromosoma[i] = aux;
		i++;
	}
}

/*
 * 
 */
int main(int argc, char** argv) {
    int combinaciones;
    int M,N;
    cout << "Numero de camiones: ";
    cin >> M;
    cout << "Numero de paquetes: ";
    cin >> N;
    combinaciones = pow(2,N);
    int cromosoma[];
    for (int i=1; i<combinaciones; i++){ //recorremos cada combinacion
		cargaBinaria(i,cromosoma,N); //convertimos la combinacion a binario
		peso_mochila = 0; //inicializo en 0 el peso de la combinacion
		for (int j=0; j<N; j++){//Voy a calcular el peso de la combinacion
			if (cromosoma[j]==1)//cada vez que encuentre un objeto/caja asignado, acumulo el peso
				peso_mochila = peso_mochila + objetos[j];//acumulo el peso
		}
		
		if (peso_mochila<=peso_maximo && mejor_peso_mochila <= peso_mochila){//Cuando el peso de la mochila es menor igual a mi limitante  Y encontramos un nuevo mejor peso
			mejor_peso_mochila=peso_mochila;
			mejor_combinacion=i;
		}
	}
    
    
    
    return 0;
}

