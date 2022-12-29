#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>

void* sum_1(void* p) 
{
int *arr = p;
int sum=0;
for(int i=0;i<100;i++){
    sum+=a[i];
}
printf("\nSum of the 1st thread is %d", sum);
pthread_exit((void *)sum);

}
  
void* sum_2(void* p) 
{
  int *arr = p;
int sum=0;
for(int i=0;i<100;i++){
    sum+=a[i];
}
printf("\nSum of the 2nd thread is %d", sum);
pthread_exit((void *)sum);
    
}

void* sum_3(void* p) 
{
    int *arr = p;
int sum=0;
for(int i=0;i<100;i++){
    sum+=a[i];
}
printf("\nSum of the 3rd thread is %d", sum);
pthread_exit((void *)sum);
}
void* sum_4(void* p) 
{
  int *arr = p;
int sum=0;
for(int i=0;i<100;i++){
    sum+=a[i];
}
printf("\nSum of the 4th thread is %d", sum);
pthread_exit((void *)sum);
    
}
 
int main()
{
    int ia1[100],ia2[100],ia3[100], ia4[100];
    srand(time(0));

    for(int i=0;i<100;i++){
        ia1[i]=(rand() % 10)+10;
        ia2[i]=(rand() % 10)+10;
        ia3[i]=(rand() % 10)+10;
        ia4[i]=(rand() % 10)+10;
    }

    pthread_t thread_one, thread_two,thread_three,thread_four; 

    pthread_create(&thread_one, NULL, sum_1, ia1);    
    pthread_create(&thread_two, NULL, sum_2, ia2);    
    pthread_create(&thread_three, NULL, sum_3, ia3); 
    pthread_create(&thread_four, NULL, sum_4, ia4);

    void *r1, *r2, *r3, *r4;

    pthread_join(thread_one, &r1); 
    pthread_join(thread_two, &r2); 
    pthread_join(thread_three, &r3);
    pthread_join(thread_four, &r4);

    int sum1 = r1;
    int sum2 = r2;
    int sum3 = r3;
    int sum4 = r4;

    int sum = sum1+sum2+sum3+sum4;

    printf("\n \nSum of all threads is %d \n", sum);

}