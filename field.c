//field header implementation!
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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

//date dimensioni e field libera le aree di memoria precedentemente allocate
void delete_field(int rows, int columns, int** field){
	int i;
	for (i=0; i< rows;i++)
		free(field[i]);
	free(field);
	return;
}

/* 
	--------------------------------------------------------------------------
	QUESTE FUNZIONI DEVONO ESSERE ANCORA COMPLETAMENTE IMPLEMENTATE E TESTATE
  	--------------------------------------------------------------------------
*/
// inizializzo a zero il campo
void zero(int rows, int columns, int** field){
	int i,j;
	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			field[i][j] = 0;
}

int casuale(int min, int max){
	int x;
	unsigned int seed = time(NULL); 
	//printf("%d %d\n",min,max);
	x = rand_r(&seed) % (max + 1 - min) + min;
	//x = rand() % max; 
	return x;
}

// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long ra(long max) {
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;


  do {
   x = random();
  }
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)x);

  // Truncated division is intentional
  return x/bin_size;
}



//Dato un numero di righe, la dimensione del field e il numero di mine posiziona in maniera randomica le mine
//al termine genera un file in cui salva il campo appena generato (possibile nome con timestamp e caratterische?)
int generate_field(int rows, int columns, int **field, int mines){
	int r, c,i,j;

	if(mines >= rows*columns)
		return 1;

	while (mines > 0){
		r = rand() % rows;//ra(rows-1);
		c = rand() % columns;//ra(columns-1);
		printf("%d %d\n",r,c);
		
		//INGUARDABILE sarebbe meglio trovare una soluzione piu elegante
		if (field[r][c] != -1){
			field[r][c] = -1;
			for (i=-1;i<2;i++){
				if(r+i >= 0 && r+i < rows){
					for(j=-1;j<2;j++)
						if(c+j >= 0 && c+j < columns){
							if(field[r+i][c+j] != -1)
								field[r+i][c+j]++;
					}
				}
			}
			mines--;
		}
	}
	return 0;
}
