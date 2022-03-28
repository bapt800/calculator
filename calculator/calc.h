#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int len(char*);
char* slice(char*, int, int);

int numbOfNode(char*);
void set_priority(struct expre_node*);

struct expre* parser(char*);

char* perform(char*);

char* addition(char*, char*);

struct expre
{
	int nb_nodes;
	struct expre_node* nodes;
};

struct expre_node
{
	char* value;
	int priority;
};

