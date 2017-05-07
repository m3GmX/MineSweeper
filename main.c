//Main with ncurses eventually
#include <stdlib.h>
#include <stdio.h>
#include "field.h"

int main(){
	int **field;
	
	field = create_field(6,6);
	if (field == NULL)
		printf("ERRORE: impossibile creare il campo!");//errore nella malloc

	aux_cresc(6,6,field);
	print_field(6,6,field);

	delete_field(6,6,field);
	return EXIT_SUCCESS;
}
