#include <stdio.h>

void quicksort(int * numbers, int array_size);
void q_sort(int * numbers, int left, int right);

int main(int argc, char **argv)
{
	const int array_size = 6;
	int array[array_size] = {3,8,11,2,1,4};

	quicksort(array, array_size);
	for(int i = 0;i <array_size; i++){
		printf("array[%d] = %d\n",i, array[i]);
	}
}

void quicksort(int * numbers, int array_size)
{
	q_sort(numbers, 0, array_size-1);
}	

void q_sort(int * numbers, int left, int right)
{
	int pivot, l_hold, r_hold;

	l_hold = left;
	r_hold = right;
	pivot = numbers[left];

	while(left < right){
		while((numbers[right] >= pivot) && (left < right))
			right--;

		if(left != right){
			numbers[left] = numbers[right];

		}

		while((numbers[left] <= pivot)&& (left < right))
			left++;

		if(left != right){
			numbers[right] = numbers[left];
			right--;
		}
		
	}

	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;

	if(left < pivot){
		q_sort(numbers, left, pivot -1);
	}
	if(right > pivot){
		q_sort(numbers, pivot+1, right);
	}
}
