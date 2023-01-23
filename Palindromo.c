#include <stdio.h>
#include <string.h>
char letrasReverso[26] =
  { 'A', 'B', 'C', 'D', '3', 'F', 'G', 'H', 'I', 'L', 'K','J',
  'M', 'N', 'O', 'P', 'Q', 'R', '2', 'T',
  'U', 'V', 'W', 'X', 'Y', '5'
};
char numerosReverso[6] = { 'O', '1','S', 'E', '4', 'Z' };


char ExtraerReverso(char letra) {

  int numero = (letra);
  char resultado;

  if (numero >= 65 && numero <= 90){
      resultado = letrasReverso[numero - 65];
  }
    
  else
    {
      if (numero >= 48 && numero <= 53) resultado = numerosReverso[numero - 48];
      else if (numero >= 54 && numero <= 59) resultado=letra;
	}
	






}

	int evaluarCadReflejada (char *cadena, int longitud,
				 char *cadenaInvertida)
      {

	char letra, reverso;

	for (int i = 0; i < longitud; i++)
	  {

	    letra = cadenaInvertida[i];
	    //printf("letra ES %c \n",letra);
	    reverso = ExtraerReverso(letra);
	    //printf("letra INVERTIDA ES %c \n",reverso);
	    cadenaInvertida[i] = reverso;

	  }
	  cadenaInvertida[longitud]=0; 
     //printf("INVERTIDA ES %s \n",cadenaInvertida);
	if (strcmp(cadena, cadenaInvertida) == 0)
	  return 1;
	else return 0;
      }

 void evaluarPalindromo (char *cadena, int longitud,
			      char *cadenaInvertida)
      {

	//invertir cadena
	int i = 0;
	int j = longitud - 1;
	int palRegular = 0;	//0 si no lo es
	int cadReflejada = 0;
	for (int i = 0; i < longitud; i++)
	  {

	    cadenaInvertida[i] = cadena[j];
	    j--;
	  }
	  cadenaInvertida[longitud]=0;
	  //printf("INVERTIDA ES %s \n",cadenaInvertida);
	if (strcmp (cadena, cadenaInvertida) == 0)
	  palRegular = 1;

	//evaluar si la cadena es cadena reflejada

	cadReflejada =evaluarCadReflejada(cadena, longitud, cadenaInvertida);

	if (palRegular && cadReflejada)
	  printf ("%s - is a mirrored palindrome \n", cadena);
	else if (palRegular)
	  printf ("%s -  is a regular palindrome\n", cadena);
	else if (cadReflejada){
	    printf ("%s - is a mirrored string. \n", cadena);
	    //printf ("EL RESULTADO DE REFLEJADA ES %s \n", cadenaInvertida);
	}
	else 
	 printf ("%s - is not a palindrome \n", cadena);
	  

      }

int main (){
	int longitud;
	char cadena[100];
	char cadenaInvertida[100];

	printf ("Ingresa cadena . escribe solo - para salir \n");

	while (1)
	  {

	    scanf ("%s", cadena);
	    longitud = strlen (cadena);
	    cadena[longitud]=0;
	    if (cadena[0] == '-')
	      break;

	    evaluarPalindromo(cadena, longitud, cadenaInvertida);

	  }
	return 0;
}