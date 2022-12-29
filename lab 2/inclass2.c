#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void) {
int f1=open("sample.txt",O_CREAT|O_RDWR,0777);

char buff[500];
for(int i=0;i<500;i++)
{
buff[i]='R';
if(i%25==0)
buff[i]='\n';
}
long int n;
n=write(f1,buff,200);

n = lseek(f1, 0, SEEK_SET);
char buff1[50];
n = read(f1, buff1, 200);
printf("Printing contents of file:");
for(int i=0;i<50;i++){
	printf("%c", buff1[i]);
}

char c[10]="**********";
n=lseek(f1,15,SEEK_SET);
n=write(f1,c,10);

n=lseek(f1,20,SEEK_CUR);
n=write(f1,c,10);

n=lseek(f1,-30,SEEK_END);
n=write(f1,c,10);

n=lseek(f1,25,SEEK_END);
n=write(f1,c,10);



char *c = (char *) calloc(1000, sizeof(char));

n = read(fd, c, 1000);

c[n] = '\0';
printf("\nNumber of characters in file:%d", n);

int count = 0;
for(int i=0;i<n;i++){
	if(c[i] == '\0'){
		count++;
	}
}
}





