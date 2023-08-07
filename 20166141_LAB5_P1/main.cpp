/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 24 de junio de 2023, 03:02 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#define MAX 10
#define MAX 10
#define MAXREQUISITOS 3
#define N 8
/*
 * 
 */// basado en 2020_1-L5-P1-ProyectosPredecesor.cpp de semana 12
int lista[MAX]; //arreglo para almacenar los elementos que forman la solución
int solucion[MAX]; //arreglo que almacena  mayor beneficio
int y=0; //variable para hacer el seguimiento a los elementos de lista[];
int x=0; //contador de soluciones encontradas
int maximo=0;//es el maximo beneficio guardado de todas las soluciones
int suma=0;//guarda la suma de cada solucion
int contadorListaMaximo=0; //es el total de elementos en lista para cuando beneficio de una solucion supera al maximo
// basado en 2020_1-L5-P1-ProyectosPredecesor.cpp de semana 12
int valida (int k, int n, int predecesor[N][MAXREQUISITOS], int proyecto[])//función que me indica si mi predecesor está ya incluido en mi lista solución (lista[])
{
    int encontro=0; //contador de predecesores encontrados
    int cont=0;
    for (int p=0; p<MAXREQUISITOS; p++){
        if (predecesor[k][p]!=-1){//hay un predecesor que no es -1
            cont++; //contador de predecesores diferentes a -1
            break;
        }
        
    }
    if(cont==0) return 1; //no hay predecesores para ese proyecto
    for (int j=0; j<MAXREQUISITOS; j++){//en caso hay predecesores
        encontro=0;//aun no encuentro predecesor,por lo que es 0 como para empezar
        for (int i=0; i<n; i++){
            if (((predecesor[k][j])==lista[i])&&(predecesor[k][j]!=-1)){//Si encuentro el predecesor en la lista que va teniendo los proyectos de mi solución y ese predecesor no es -1
                //comparo lista con predecesor asi ,porque en lista estoy guardando los indices de proyecto de 0 a 7 pero sumados con  1   
                encontro=1;//encontre el predecesor en lista
            }
            else if(predecesor[k][j]==-1)encontro=1; //si el predecesor es -1, es como que no hay ese predecesor para el proyecto y encontro es 1
        }
        if(!encontro) return 0; //no encontro predecesor
    }
    return 1;//Entonces se puede adicionar en la solución porque no cayo en return 0
}

int empaca (int i, int n, int presupuesto, int inversion[], 
        int predecesor[N][MAXREQUISITOS], int proyecto[],int beneficio[])//Devuelve 1 si pudo armar una solución y 0 en caso contrario.
{
	//CASO BASE
	if (i==n || presupuesto<0){//cuando hemos recorrido todos los elementos O 
					   //cuando el peso es negativo, es decir la suma de los paquetes sobrepasa la capacidad
		return 0;//Retornamos 0, es decir que el camino tomado no es una solución
	}
	if (inversion[i]-presupuesto==0 && valida (i,y,predecesor, proyecto)){//--------ENCONTRAMOS UNA SOLUCIÓ
            lista[y]=proyecto[i];//guardamos el proyecto que forma parte de la solución
            suma+=beneficio[i];
            //Mostramos la solución encontrada
            int z;
            cout<<"Solucion: ";
            for (z=0;z<=y;z++)
		cout<<"P"<<lista[z]<< " ";
            cout<<endl;
            cout<<"Beneficio es: "<<suma<<" "<<endl;
            if(suma>maximo){
                maximo=suma;
                contadorListaMaximo=0; //inicializa contador cuando un beneficio de solucion supera al maximo
                for (int p=0;p<=y;p++){
                    solucion[p]=lista[p];
                    contadorListaMaximo++;
                }    
            }
            x++;
            //return 1;//se encontró la solución y terminan las llamadas recursivas.
            suma-=beneficio[i];//esto hace que siga buscando mas soluciones luego de hallar el que tiene el presupuesto
            //es lo mismo cuando no sumas a y el 1 para que se reeemplace en ese mismo dato
        }
	lista[y]=proyecto[i];//Como se asume que el camino es el correcto, incluímos en la lista solución
	y++;
        suma+=beneficio[i];
	if (valida (i,y,predecesor, proyecto) && empaca (i+1, n, presupuesto-inversion[i], inversion, predecesor,
                proyecto,beneficio)){//asumimos que es el camino con una solución
		//OJO: primero se invoca a la función valida(), si es que retorna FALSO, ya no se llama a la función recursiva empaca()
		return 1;
	}
	else{
            suma-=beneficio[i];
            y--;//Como empaca()=0, es decir no es una solución, se "borra" el elemento considerado en la solución
            return empaca(i+1, n, presupuesto, inversion, predecesor, proyecto,beneficio);//para probar i+2
	}
}


// basado en 2020_1-L5-P1-ProyectosPredecesor.cpp de semana 12
int main(int argc, char** argv) {
    
    int proyecto[]={1,2,3,4,5,6,7,8};//según enunciado
    int inversion[]={32,8,40,40,20,4,20,20};//según enunciado
    int predecesor[8][3]={{-1,-1,-1},{-1,-1,-1},
        {-1,1,2},{-1,-1,-1},{-1,-1,-1},{-1,-1,2},{-1,-1,6},{-1,-1,6}};//según enunciado
    int beneficio[]={60,32,120,60,32,20,48,60};
    int presupuesto=100;//según enunciado y todo esta en miles
    int n=8;//según enunciado
    cout<<"presupuesto es "<<presupuesto<<endl;
    empaca (0, n, presupuesto, inversion, predecesor, proyecto,beneficio);
    if (x){
	cout<<"Hay solucion"<<endl;
        cout<<" solucion con mejor ganancia "<<maximo<<endl;
        for (int p=0;p<contadorListaMaximo;p++)
            cout<<"P"<<solucion[p]<< " ";
        cout<<endl;
    }    
    else 
	cout<<"NO hay solucion"<<endl;
    return 0;
}

