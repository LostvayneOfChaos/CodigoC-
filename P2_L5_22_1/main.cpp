/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 23 de junio de 2023, 11:10 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

const int N=100;
const int M=100;
#define numMov 3
int mov[numMov][2];

/*
 * 
 */




void imprimetablero(char a[N][M], int n,int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            cout<<a[i][j];
        cout<<endl;
    }
}

void inicializatablero(char a[N][M], int n,int m) {
    int i, j;
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < m; j++ )
            a[i][j] = ' ';
}

void cargaminas(char tabla[N][M]){

	tabla[0][4]='*';
	tabla[3][2]='*';
	tabla[4][1]='*';
	tabla[4][2]='*';
	tabla[4][4]='*';
	tabla[5][1]='*';
	tabla[5][2]='*';
	tabla[5][4]='*';
	///					
}
void generamovimientos(){
	mov[0][0]= 0; mov[0][1] = 1;
	mov[1][0]= 1; mov[1][1] = 0;
	mov[2][0]= 1; mov[2][1] = 1;
}

int es_valido(int x,int y,char solu[N][M],int n,int m){
	
	if(x<n && x>=0 && y<m && y>=0 && solu[x][y]==' ') return 1;
	return 0;
	
}
void descubreminas(int x,int y,char tabla[N][M],char solu[N][M],int n,int m){
	int i,newx,newy;
	
	for(i=0;i<numMov;i++){
		newx = x + mov[i][0];
		newy = y + mov[i][1];					
		
		if(es_valido(newx,newy,solu,n,m))
			if(tabla[newx][newy]=='*') solu[newx][newy]='*';
		
	}
}



int busca_minas(int x,int y,int n,int m,char tabla[N][M],
	char solu[N][M],char paso) {
	int i,newx,newy;
	if(x==n-1 && y==m-1){
            cout<<"solucion es"<<endl;
            imprimetablero(solu,n,m);
            //return 1;
	}
	descubreminas(x,y,tabla,solu,n,m);
	for(i=0;i<numMov;i++){
		newx = x + mov[i][0];
		newy = y + mov[i][1];
		if(es_valido(newx,newy,solu,n,m)){
			solu[newx][newy]=paso;
			if(busca_minas(newx,newy,n,m,tabla,solu,paso+1))
				return 1;
			else	
				solu[newx][newy]=' ';// el punto donde estoy nunca se evaluo, luego por el for ,procedo a evaluar un nuevoX,nuevoY
		}
	}
	return 0;
	
	
}


int main(){
	int n=9,m=5;
	char paso='A';
	char solu[N][M];
	
	//inicializatablero(tabla,n,m);
	//cargaminas(tabla);
        char tabla[N][M]={{' ',' ',' ',' ','*'},
                      {' ',' ',' ',' ',' '},
                      {' ',' ','*',' ',' '},
                      {' ',' ',' ',' ',' '},
                      {' ','*','*',' ','*'},
                      {' ','*','*',' ','*'},
                      {' ','*',' ','*',' '},
                      {'*','*','*','*',' '},
                      {' ',' ',' ',' ',' '}};
        
	generamovimientos();

	inicializatablero(solu,n,m);
	solu[0][0]=paso; 
	busca_minas(0,0,n,m,tabla,solu,paso+1);
	//imprimetablero(solu,n,m);
	return 0;
}