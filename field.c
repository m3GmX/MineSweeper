//field header implementation!
#include <stdlib.h>
#include <stdio.h>
#include "field.h"

//Dati righe e colonne crea l'arrey multidimensionale della dimensione corretta e restituisce il puntatore 
int** create_field(int rows, int columns){
	int i;
	int **field = (int**)malloc(rows * sizeof(int *));

	if (field == NULL)
		return NULL;//errore nella malloc

	for(i = 0; i < rows; i++){
		field[i] = (int*)malloc(columns * sizeof(int));
		if (field[i] == NULL)
			return NULL;//errore nella malloc
	}
	return field;
	//si potrebbero aggiungere i controlli per malloc non andate a buon fine e restituire NULL
}

void print_field(int rows, int columns,int** field){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++)
			printf("%d ",field[i][j]);
		printf("\n");
	}
}

/* 
	--------------------------------------------------------------------------
	QUESTE FUNZIONI DEVONO ESSERE ANCORA COMPLETAMENTE IMPLEMENTATE E TESTATE
  	--------------------------------------------------------------------------
*/
// funzione inutile riempe semplicemente il campo con numeri da 0 a rxc-1. creata per testare inizialmente il funzionamento corretto del campo
void aux_cresc(int rows, int columns, int** field){
	int i,j, k=0;
	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++){
			field[i][j] = k;
			k++;
		}

}

//date dimensioni e field libera le aree di memoria precedentemente allocate
int delete_field(int rows, int columns, int** field){
	int i;
	if (!field)
		return 1;//errore campo inesistente
	for (i=0; i< rows;i++)
		free(field[i]);
	free(field);
	return 0;
}

//Dato un numero di righe, la dimensione del field e il numero di mine posiziona in maniera randomica le mine
//al termine genera un file in cui salva il campo appena generato (possibile nome con timestamp e caratterische?)
int generate_field(int mines){
	return 1;
}
