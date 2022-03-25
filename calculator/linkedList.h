#pragma once
#include <stdlib.h>

struct linkedList
{
	struct expression* first_node;

	void (*append)();
	struct linkedList_node (*at)();
};
struct linkedList_node
{
	char* valOpp;
	struct expression* next_node;

};

void linkedList_append()
{
}

struct linkedList_node linkedList_at()
{
	struct linkedList_node node;
	node.next_node = NULL;
	node.valOpp = "";
	printf("struct linkedList_node linkedList_at(int index) : ");
	//printf(index);
	return node;
}


struct linkedList* linkedList()
{

	struct linkedList* llist = (struct linkedList*)malloc(sizeof(struct linkedList));

	if (llist)
	{
		llist->append = &linkedList_append;
		llist->at = &linkedList_at;

		return llist;
	}
	return NULL;
}

