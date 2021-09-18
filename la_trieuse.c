#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int returns_string_length(char *arr)
{
    int i = 0;
    while(arr[i] != '\0')
    {
        i++;
    }
    return i;
}

int error_handling_1(int nbr_elements)
{
    if(nbr_elements == 0 || nbr_elements > MAX)
    {
        return 1;
    }
    return 0;
}

int error_handling_2(int argc, char *argv[], int *arg_lengths)
{
    for(int i = 1; i < argc; i++)
    {
        arg_lengths[i-1] = returns_string_length(argv[i]);
        for(int j = 0; j < arg_lengths[i-1]; j++)
        {
            if((int)argv[i][j] < 48 || (int)argv[i][j] > 57)
            {
                return 2;
            }
        }
    }
    return 0;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void merge_sort(int *arr, int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void assigns_arg_values_in_array(char *argv[], int argc, int *arg_lengths, int *arg_values)
{
    int sum = 0;
    for(int i = 1; i < argc; i++)
    {
        for(int j = 0; j < arg_lengths[i-1]; j++)
        {
            sum = sum * 10 + (int)argv[i][j] - (int)'0';
        }
        arg_values[i-1] = sum;
        sum = 0;
    }
}

void displays_array(int *arr, int length_arr)
{
    for(int i = 0; i < length_arr; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main(int argc, char *argv[])
{
    int length_arr = argc - 1;
    if(error_handling_1(length_arr) == 1)
    {
        printf("error : wrong nbr of arguments\n");
        return 1; 
    }
    int *arg_lengths = malloc(sizeof(int)*(length_arr));
    if(error_handling_2(argc,argv,arg_lengths) != 0)
    {
        printf("error : character representing anything other than an int found\n");
        return 2;
    }
    int *arg_values = malloc(sizeof(int)*(length_arr));
    assigns_arg_values_in_array(argv,argc,arg_lengths,arg_values);
    merge_sort(arg_values,0,length_arr-1);
    displays_array(arg_values,length_arr);
    printf("\n%d\n",length_arr);
    free(arg_lengths); 
    free(arg_values);
    return 0; 
}