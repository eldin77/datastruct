#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 32
int array_result[MAX];

int string_token(char * string_array, 
		char * sep, 
		//char ** return_word, 
		int * value)
{
	
	char *word, *phrase, *brkt, *brkb;
	unsigned count = 0, tmp_count = 0;
	char *delim = "-";
	char tmp_value[2] = {0};
	for(word = strtok_r(string_array, sep, &brkt);
			word;
			word = strtok_r(NULL, sep, &brkt)){
		//strcpy(return_word[count],word);

		for(phrase = strtok_r(word, delim, &brkb);
				phrase;
				phrase = strtok_r(NULL, delim, &brkb)){
			tmp_value[tmp_count] = *phrase;
			tmp_count++;
		}
		
		value[count] = atoi(tmp_value);
		tmp_count = 0;
	//	printf("%d count = %d\n",value[count],count);
		count++;
	}
	return count;
}

void merge(int array[], int left, int mid, int right)
{
	int i, j, k, m;

	i = left;
	j = mid+1;
	k = left;

	while(i <= mid && j <=right){
		if(array[i] < array[j]){
			array_result[k] = array[i];
			i++;
			k++;
		} else {
			array_result[k] = array[j];
			j++;
			k++;
		}
	}

	if(i > mid){
		for( m = j; m <=right; m++){
			array_result[k] = array[m];
			k++;
		}
	} else {
		for(m = i; m<=mid; m++){
			array_result[k] = array[m];
			k++;
		}
	}
}

void merge_sort(int array[], int left, int right)
{
	int mid;

	if(left < right){
		mid = (left + right)/2;
		merge_sort(array, left, mid);
		merge_sort(array, mid+1, right);
		merge(array, left, mid, right);
	}
}

int main(void)
{
	char *sep = ",";
	char *delim = "-";

	//char p_word[MAX] = "1-2,4-5,1-5,6-3";
	char p_word[MAX]= {0}; 
	char o_word[MAX] = "1-2,4-5,1-5,6-3";

	char result[MAX] = {0};
	char **return_word;
	int *value;
	int count;
	char buf[MAX][3]= {0}; 
	char tmp_buf[MAX]= {0}; 

	strcpy(p_word, o_word);	
	value = (int *)malloc(sizeof(int)*MAX);
	memset(value, 0, sizeof(int)*MAX);
#if 0
	return_word = (char **)malloc(sizeof(char)*MAX);
	for(int i = 0; i < MAX; i++){
		return_word[i] = (char *)malloc(sizeof(char)*3);
	}
#else
#endif

	//string_token(p_word, sep, return_word, value);
	count = string_token(p_word, sep, value);
	merge_sort(value, 0, count -1);
		
	for(int i = 0; i< count; i++){
		sprintf(buf[i], "%d", array_result[i]);
		tmp_buf[0] = buf[i][0];
		tmp_buf[1] = *delim; 
		tmp_buf[2] = buf[i][1];
		strcat(result, tmp_buf);
		
		if(i != count-1){
			strcat(result, sep);
		}
	}
	//free(return_word);
	printf("%s -> %s\n",o_word, result);
	free(value);
}
