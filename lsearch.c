#include <stdio.h>
#include <search.h>
#include <string.h>

int compare(const void *s, const void *b);

void print_tree(const void *node, const VISIT order, const int depth);

int main(void)
{
	void *root;
	root = NULL;

	tsearch("Hello", &root, compare);
	tsearch("Linux", &root, compare);
	tsearch("C", &root, compare);

	twalk(root, print_tree);
	tdelete("Hello", &root, compare);
	twalk(root, print_tree);
	return 0;
}

int compare(const void *s, const void *b)
{
	return strcmp((char *)s, (char *)b);
}

void print_tree(const void *node, const VISIT order, const int depth)
{
	char *str;
	str = *(char **)node;

	if(order == postorder || order == leaf)
		printf("string : %s\n", str);
	
}
