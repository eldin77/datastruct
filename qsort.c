#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 5
#define DATASIZE 15

#if 0
//오름차순 내림차순은 부호 반대로:
int compare const(vonst void *first, const void *second)
{
	if(*(int *)first > *(int *)second){
		return 1;
	} else if(*(int *)first < *(int *)second){
		return -1;
	} else{
		return 0;
	}
}	
#endif
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
