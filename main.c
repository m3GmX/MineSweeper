//Main with ncurses eventually
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "field.h"

int main(){
	int **field;

	field = create_field(6,6);
  	//srandom ( time(NULL) ); SE SI USA RANDOM CAMBIARE
  	srand( time(NULL) );

	if (field == NULL)
		printf("ERRORE: impossibile creare il campo!");//errore nella malloc

	zero(6,6,field);
	//print_field(6,6,field);
	generate_field(6,6,field,5);
	print_field(6,6,field);

	delete_field(6,6,field);
	return EXIT_SUCCESS;
}
