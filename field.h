#ifndef FIELD_H
#define FIELD_H

//All field functions are declared here. 
//New field creation,field delete (remember to call it before ending the program)
//and others. For more info check field.c file

int** create_field(int rows, int columns);
void print_field(int rows, int columns, int** field);
void delete_field(int rows, int columns, int** field);

/* 
	--------------------------------------------------------------------------
	QUESTE FUNZIONI DEVONO ESSERE ANCORA COMPLETAMENTE IMPLEMENTATE E TESTATE
  	--------------------------------------------------------------------------
*/
void zero(int rows, int columns,int** field);

int generate_field(int rows, int columns, int **field, int mines);

#endif
