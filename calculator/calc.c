#include "calc.h"

int len(char* tab)
{
	int i = 0;
	while (tab[i] != '\0')
	{
		i++;
	}
	return i;
}

int numbOfNode(char* expre_char)
{
	int numb = 0;
	bool isNumberBefore = false;
	for (int i = 0; i < len(expre_char); i++)
	{
		if (expre_char[i] == '+')
		{
			numb++;
			isNumberBefore = false;
		}
		else
		{
			if (isNumberBefore == false)
			{
				numb++;
				isNumberBefore = true;
			}
		}
		
	}
	return numb;
}

void parser(char* expre_char)
{
	printf("%i", numbOfNode(expre_char));
	struct expre_node *parsed_expr = malloc( sizeof(struct expre_node) * numbOfNode(expre_char) );
	if (parsed_expr == NULL)
	{
		return;
	}


	for (int i = 0; i < len(expre_char); i++)
	{
		if (expre_char[i] == '+')
		{
			printf("\nc'est un: +\n");
			struct expre_node bffNode;
			bffNode.value = &(char*) { expre_char[i] };
			bffNode.priority = 1;
			parsed_expr[0] = bffNode;
		}
		printf("%c", expre_char[i]);
	}

	printf("\n\nelse: ");
	printf("%s", parsed_expr[0].value);
	free(parsed_expr);
}


