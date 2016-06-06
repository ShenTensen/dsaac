#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 40
#define LIMIT 10000

int main (void)
{	
    int a = 0;
    char arr[N];
    int i;
    
    srand(time(NULL));	
    for ( i = 0; i < N; i++)
        arr[i] = (rand () % LIMIT);
		//arr[i] = i + 3;           //为了验证正确性
    for ( i = 0; i < N; i++)      //检查数组里的内容
        printf ("%d  ",	arr[i]);
    
    for (int i = 0; i < N; i++)
	    for (int j = i + 1; j < N; j++)	
	        if (arr[i] < arr[j])
	        {
	        	int temp = arr[i];
		        arr[i] = arr[j];
	        	arr[j] = temp;
	        }
    
    printf ("\n第%d大的数是%d\n", N/2, arr[N/2]);

    return 0;
}	    	    

