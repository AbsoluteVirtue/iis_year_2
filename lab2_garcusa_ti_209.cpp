#include<stdio.h>
#include<math.h>
#define N 10

main()
{
	float arr[N] = {-22., -45., 13., 0., 100., 156., -23., 55., 0., -44.};
	int i;
	// for( i=0; i<N; i++ )
	// {
	// 	printf("arr[%d] = ", i);
    //     scanf("%f", &arr[i]);
	// }
	
	printf("\n************[Your input in array is]************\n");
	for( i=0; i<N; i++ )
		printf("arr[%d]=%.2f\n", i, arr[i]);
		
	float min;
	min=arr[0];
	for( i=0; i<N; i++ )
	{
		if (abs(min)>abs(arr[i]))
			min=arr[i];
	}
	
	float sum=0;
    for( i=0; i<N; i++ ) 
    {
    	if(arr[i]==0)
    	{
	    	for( i=i+1; i<N; i++ ) 
		    	sum += abs(arr[i]);
		}
	}

	printf("\n************[Your Result is]************\n");
	printf("\t     |min|=%.2f\n", min);
	printf("\t     sum=%.2f\n", sum);
	
	float arr2[N];
	int j=0;
    for (i = 1; i < N; i=i+2)
    {
    	arr2[j]=arr[i];
    	j++;
	}
	
	    for (i = 0; i < N; i=i+2)
    {
    	arr2[j]=arr[i];
    	j++;
	}
	
	printf("\n************[Sorted array]************\n");
    for (int j = 0; j < N; j++)
		printf("\t     arr[%d]= %.2f \n", j, arr2[j]);
	
return 0;
}
