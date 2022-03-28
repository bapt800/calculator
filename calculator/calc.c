#include "calc.h"

char* perform(char* expression_char)
{
	struct expre* expr = parser(expression_char);
	printf("parsed:\n");
	for (int i = 0; i < expr->nb_nodes; i++)
	{
		printf("value: %s, priority: %i\n", expr->nodes[i].value, expr->nodes[i].priority);
	}

	return (char*)"WHAT\0";
}

char* addition(char* a, char* b)
{



	char* str_out = NULL;

	int maxLen = 0;
	if (len(a) > len(b))
	{
		maxLen = len(a);
	}
	else
	{
		maxLen = len(a);
	}

	str_out = malloc(sizeof(char) * (maxLen + 1));
	for (int i = 0; i <= maxLen; i++)
	{
		str_out[i] = '0';
	}
	str_out[(maxLen + 1)] = '\0';

	int retenue = 0;
	int index_strOut = maxLen;
	int index_a = len(a) - 1;
	int index_b = len(b) - 1;
	while (index_a >= 0 || index_b >= 0 || retenue != 0)
	{
		char cA, cB;
		if (index_a >= 0)
		{
			cA = a[index_a];
		}
		else
		{
			cA = '0';
		}
		if (index_b >= 0)
		{
			cB = b[index_b];
		}
		else
		{
			cB = '0';
		}
		index_a--;
		index_b--;

		int buffCalc = (cA - 48) + (cB - 48) + retenue;
		if (buffCalc >= 10)
		{
			retenue = buffCalc / 10;
			buffCalc -= retenue * 10;
		}
		else
		{
			retenue = 0;
		}

		str_out[index_strOut] = (char)(buffCalc + 48);
		index_strOut--;



		printf("\ncA: %c, cB: %c, buffCalcul(int): %i", cA, cB, buffCalc);

	}

	return str_out;

}

//len of str, without '\0'
int len(char* tab)
{
	int i = 0;
	while (tab[i] != '\0')
	{
		i++;
	}
	return i;
}

char* slice(char* str, int begin, int end)
{
	int sizeTest = (end - begin + 1);
	char* newStr = (char*)malloc(sizeof(char) * (end - begin + 2));
	if (newStr)
	{
		int newStr_ind = 0;
		for (int str_ind = begin; str_ind <= end; str_ind++)
		{
			newStr[newStr_ind] = str[str_ind];
			newStr_ind++;
		}
		newStr[(end - begin + 1)] = '\0';
		return newStr;
	}
	return NULL;
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

void set_priority(struct expre_node* node)
{
	if (len(node->value) != 1)
	{
		node->priority = 0;
	}
	else
	{
		switch (node->value[0])
		{
		case '+':
			node->priority = 1;
			break;

		default:
			node->priority = 0;
			break;
		}
	}
}



struct expre* parser(char* expre_char)
{
	struct expre* expre= malloc(sizeof(struct expre));
	expre->nb_nodes = numbOfNode(expre_char);
	expre->nodes = malloc(sizeof(struct expre_node) * expre->nb_nodes);
	if (expre == NULL)
	{
		if (expre->nodes)
		{
			return;
		}
		return;
	}

	int ind_node = 0;
	int j = 0;
	for (int i = 0; i < len(expre_char); i++)
	{
		if (expre_char[i] == '+')
		{
			struct expre_node nodeBefore;
			nodeBefore.value = slice(expre_char, j, (i - 1));
			set_priority(&nodeBefore);
			expre->nodes[ind_node] = nodeBefore;

			j = i;
			ind_node++;

			struct expre_node actualNode;
			actualNode.value = slice(expre_char, j, i);
			set_priority(&actualNode);
			expre->nodes[ind_node] = actualNode;
			ind_node++;

			j++;
		}
	}
	struct expre_node afterNode;
	afterNode.value = slice(expre_char, j, len(expre_char));
	set_priority(&afterNode);
	expre->nodes[ind_node] = afterNode;


	
	return expre;
}




