//Main with ncurses eventually
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "field.h"

void generate_from_input(int *rows, int *columns, int *mines){
	do{
		printf("Insert rows:");
		scanf("%d",rows);
	}while(*rows<1);
	do{
		printf("Insert columns:");
		scanf("%d",columns);
	}while(*columns<1);
	do{
		printf("Insert mines:");
		scanf("%d",mines);
	}while(*mines<1);
}

int main(){
	int **field;
	int rows, columns, mines;
	//srandom ( time(NULL) ); SE SI USA RANDOM CAMBIARE
	srand( time(NULL) );


	generate_from_input(&rows, &columns, &mines);

	field = create_field(rows,columns);
	if (field == NULL)
		printf("ERRORE: impossibile creare il campo!");//errore nella malloc

	zero(rows,columns,field);
	generate_field(rows,columns,field,mines);
	print_field(rows,columns,field);

	delete_field(rows,columns,field);
	return EXIT_SUCCESS;
}
