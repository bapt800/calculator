#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int len(char*);
int numbOfNode(char*);
void parser(char*);

struct expre_node
{
	char* value;
	int priority;
};