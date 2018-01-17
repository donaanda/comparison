#include <stdio.h>
#include <stdbool.h>
#define E 100000

int array[E];

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int n, int i, int array[])
{
    int a = (2*i)+1;
    int b = (2*i)+2;
    int smallest = array[i];
    bool left = true;
    if (a < n)
    {
	int leftChild = array[a];
	int ret1 = COMPARE(leftChild, smallest);
	if (ret1 == 2)
	{
            smallest = leftChild;
	}
    }
    
    if (b < n)
    {
	int rightChild = array[b];
	int ret2 = COMPARE(rightChild, smallest);
	if (ret2 == 2)
        {
            smallest = rightChild;
	    left = false;
        }
    }
    
    if (smallest != array[i])
    {
        if (left == true)
        {
            swap(&array[i], &array[(2*i)+1]);
            smallest = (2*i)+1;
            heapify(n, smallest, array);
        }
        else
        {
            swap(&array[i], &array[(2*i)+2]);
            smallest = (2*i)+2;
            heapify(n, smallest, array);
        }
    }
}

void heapSort(int n, int array[])
{
    int i, j;
    for (i = (n/2) - 1; i >= 0; i--)
    {
        heapify(n, i, array);
    }
    
    
    for (j = n-1; j >= 0; j--)
    {
        swap(&array[0], &array[j]);
        heapify(j, 0, array);
    }
    

}

int doalg(int n, int k, int Best[])
{    
    if (n < 10 || n > 10000 || k > 100 || k < 1)
    {
	return 0;
    }
    
    //COMPARE(0,n);
    int i, j;

    for (i = 0; i < n; i++)
    {
	array[i] = i+1;
    }
    
    heapSort(n, array); 

    for (j = 0; j < k; j++)
    {   
 	Best[j] = array[j];
    }
      
    return 1;  
}
