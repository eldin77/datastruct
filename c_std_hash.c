#include <stdio.h>
#include <search.h>

int main(void)
{
	ENTRY item;
	ENTRY *result;

	hcreate(5); //5개의 table 을 만든다.

	item.key = "Linux";
	item.data = "Linux";
	hsearch(item, ENTER);//item을 찾지못하면 insert

	item.key = "C";
	item.data = "C";
	hsearch(item, ENTER); //ENTER insert
	
	item.key = "Programming";
	item.data = "Programming";
	hsearch(item, ENTER);
	
	item.key = "Linux";
	item.data = "Linux";

	if((result = hsearch(item, FIND)) == NULL){ //FIND searh
		printf("Not fount\n");
	} else {
		printf("Found : %s\n", result->data);
	}

	item.key = "JAVA";
	item.data = "JAVA";

	if((result = hsearch(item, FIND)) == NULL){ //FIND searh
		printf("Not fount\n");
	} else {
		printf("Found : %s\n", result->data);
	}

	return 0;
}
