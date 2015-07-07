#include <stdio.h>

#define MAX 32
int result_array[MAX];

void mearge(int * array, int left, int right)
{
	int i,j,k,m;

	i = left;
	j = mid;
	k = left;

	while(i <= mid && j <= right){
		if(array[i] < array[j]){
			result_array[k] = array[i];
			i++;
			k++;
		} else {
			result_array[k] = array[j];
			j++;
			k++;
		}
	}
	if(i > mid){
		for(m = j; m <=right; m++){
			result_array[k] = array[m];
			k++;
		}
	} else {
		for(m = i; m<=mid;m++){
			result_array[k] = array[m];
			k++;
		}
	}
}

void mearge_sort(int * array, int left, int right)
{
	int mid;
	if(left < right){
		mid = (left+right)/2;
		mearge_sort(array, left, mid);
		mearge_sort(array, mid+1, right);
		mearge(array, left, right, mid);
	}
}
