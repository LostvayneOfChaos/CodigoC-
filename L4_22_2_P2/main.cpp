/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 9 de junio de 2023, 02:11 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
typedef struct elemento
{   
    int anio;
    int stock;
} Elemento;

typedef struct nodo
{   Elemento elem;      // dato
    struct nodo *hizq;  // puntero al hijo izquierdo
    struct nodo *hder;  // puntero al hijo derecho
} NodoABB;

typedef NodoABB * ABB;
/*
 * 
 */
void construir( ABB &pA )
{
    pA = NULL;  // todo arbol empieza vacio
}

NodoABB* crearNodo( Elemento e )
{
    // todo nodo que sea crea es siempre una hoja
    NodoABB *p;
    p = new NodoABB;  // se crea el nodo en memoria
    p->hizq = NULL;
    p->elem = e;
    p->hder = NULL;
    return p; // se retorna la direccion del nodo creado
}

void insertar( ABB &pA, Elemento e )
{
    NodoABB *p, *q, *pq;
    p = crearNodo( e );     // se crea el nodo como hoja
    if ( pA == NULL ) // arbol vacio
        pA = p;  // el nodo insertado se convierte en la raiz del árbol
    else  // el árbol no está vacío
    {
        // hay que encontrar la ubicación que le corresponde al nuevo nodo
        q = pA;
        pq = NULL;
        while ( q != NULL )
        {
            pq = q;
            if ( e.anio < (q->elem.anio) )
                q = q->hizq;
            else
                q = q->hder;
        }
        if ( e.anio < (pq->elem.anio) )
            pq->hizq = p;
        else
            pq->hder = p;
    }
}

NodoABB* buscarElemento(NodoABB* pR , Elemento e){
	NodoABB* p;
	p=pR;//asignamos el puntero a la raiz del árbol a un puntero aux.
        if (p == NULL) return NULL;
	if (p!=NULL){//Mientras el puntero no sea nulo
		if (e.anio==p->elem.anio)//Encontramos el elemento en la raiz
			return p;
		else//Si no encontramos el elemento en la raiz, buscamos en sus hijos
			if ((e.anio)<(p->elem.anio))//si es menor a la raiz, vamos a la izquierda
				p=buscarElemento(p->hizq,e);
			else
				p=buscarElemento(p->hder,e);//si es mayor, vamos a la derecha
	}
       return p;
}
/*
NodoABB* buscarElemento(NodoABB* pR , Elemento e){
	NodoABB* p;
	p=pR;//asignamos el puntero a la raiz del árbol a un puntero aux.

	while (p!=NULL){//Mientras el puntero no sea nulo
		if (e.anio==p->elem.anio)//Encontramos el elemento en la raiz
			return p;
		else//Si no encontramos el elemento en la raiz, buscamos en sus hijos
			if (e.anio<p->elem.anio)//si es menor a la raiz, vamos a la izquierda
				p=p->hizq;
			else
				p=p->hder;//si es mayor, vamos a la derecha
	}
	return NULL;//No se encontró el elemento.
}*/

int contarNodos(NodoABB* pR){
	NodoABB* p;
	NodoABB *pAI, *pAD;
	p=pR;
	
	int nodosAI, nodosAD;
	
	if (pR==NULL)
		return 0;
	else {
		pAI=pR->hizq;//puntero al subarbol izquierdo
		pAD=pR->hder;//puntero al subarbol derecho
		nodosAI=contarNodos(pAI);//contamos los nodos del subarbol izquierdo
		nodosAD=contarNodos(pAD);//contamos los nodos del subarbol derecho
		return nodosAI+nodosAD + 1; //contamos el nodo mas la cantidad de nodos de sus subarboles izquierdo y derecho
	}
}


void fusionar(ABB &origen,ABB & destino){
    
    NodoABB *pAI, *pAD,*pR,*valor;
    pR=origen;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        fusionar(pAI,destino);// se recorre en postorden el subarbol izquierdo
        fusionar(pAD,destino);// se recorre en postorden el subarbol derecho
        //mostrarEnPostOrden( pAI);  
        //mostrarEnPostOrden( pAD);  
        valor=buscarElemento(destino,pR->elem);
        if(valor==NULL){
            insertar(destino,pR->elem);
        }
        else 
            (valor->elem.stock)=(valor->elem.stock)+(pR->elem.stock);
        //cout << pR->elem << " ";   // se visita la raiz
    }
    
}
void mostrarEnPreOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        cout << pR->elem.anio << " "<< pR->elem.stock <<endl ;  // se visita la raiz
        mostrarEnPreOrden( pAI);  // se recorre en preorden el subarbol izquierdo
        mostrarEnPreOrden( pAD);  // se recorre en preorden el subarbol derecho
    }
}

void mostrarEnOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnOrden( pAI);  // se recorre en orden el subarbol izquierdo
        cout << pR->elem.anio << " "<< pR->elem.stock <<endl ;  // se visita la raiz
        mostrarEnOrden( pAD);  // se recorre en orden el subarbol derecho
    }
}


int main(int argc, char** argv) {
    
    ABB arbol1,arbol2;
    
    construir(arbol1);
    construir(arbol2);
    
    Elemento valor;
    valor.anio=20170620;
    valor.stock=20;
    insertar(arbol1,valor);
    
    valor.anio=20170810;
    valor.stock=20;
    insertar(arbol1,valor);
    
    valor.anio=20180211;
    valor.stock=20;
    insertar(arbol1,valor);
    
    valor.anio=20180409;
    valor.stock=10;
    insertar(arbol1,valor);
    
    //ahora el arbol2
    valor.anio=20170811;
    valor.stock=5;
    insertar(arbol2,valor);
    
    valor.anio=20180211;
    valor.stock=10;
    insertar(arbol2,valor);
    
    valor.anio=20180410;
    valor.stock=15;
    insertar(arbol2,valor);
    
    //ahora se evalua quien sera el arbol destino
    int val1,val2;
    
    val1=contarNodos(arbol1);
    val2=contarNodos(arbol2);
    
    ABB destino,origen;
    if(val1 > val2){
        destino=arbol1;
        origen=arbol2;
    }
    else{
        origen=arbol1;
        destino=arbol2;
    }
    /*
    mostrarEnOrden(origen);
    cout<<"e"<<endl;
    mostrarEnOrden(destino);
    cout<<"e"<<endl;
    mostrarEnOrden(arbol1);
    cout<<"e"<<endl;
    mostrarEnOrden(arbol2);
    
    NodoABB* p=buscarElemento(origen,valor);
    cout<<p->elem.stock<<endl;*/
    //hacemos la fusion
    
    fusionar(origen,destino);
    mostrarEnOrden(destino);
    
    
    return 0;
}

