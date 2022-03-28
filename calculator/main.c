// calculator.cpp : définit le point d'entrée de l'application.
//

#include "main.h"




int main()
{

	char* expression_char = "5+3+1\0";

	char* result = perform(expression_char);

	printf("\nresult: %s\n", result);



	printf("\nresult: %s", addition("999", "999"));
	
	return 0;
}
