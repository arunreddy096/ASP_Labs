#include<stdio.h>
#include<stdlib.h>


void display(int * p, int size)
{
	printf("\nThe elements of the array are\n");
	for(int i=0;i<size;i++)
	{
	printf("%d",p[i]);
	} 

 printf("\nThe elements of the  reversed array are\n");
    int temp;
    for(int i = 0; i<size/2; i++){
        temp = p[i];
        p[i] = p[size-i-1];
        p[size-i-1] = temp;
    }
    for(int i = 0; i < size; i++){
        printf("%d", p[i]);
    }

}
int main(void)
{
int *arr,n;
int *ptr;
printf("\nEnter the number of elements in the array\n");
scanf("%d",&n);
arr=malloc(n*sizeof(int)); 

	for(int i=0;i<n;i++)
	{
	scanf("%d",&arr[i]); 
	} 
	ptr=arr; // dereferncing
	
//display(ptr,n)

void (*fp1)(int *,int);
fp1 = display;
fp1(ptr,n);

free(arr);


}