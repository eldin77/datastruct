#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 5
#define DATASIZE 15

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int main()
{
	int i;
	char table[TABLESIZE][DATASIZE]={"Hello", "Linux", "C", "Programming", "JAVA"};

	qsort(table, TABLESIZE, DATASIZE, compare);

	for(i=0; i<TABLESIZE; i++){
		printf("%s\n",table[i]);
	}
	return 0;
}
