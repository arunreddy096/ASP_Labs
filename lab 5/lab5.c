#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char **argv)
{
  int i,status;
  char *args1[] = {"cat", "input.txt", NULL};
  char *args2[] = {"grep", "COMP8567", NULL};
  char *args3[] = {"wc", "-w", NULL};

  int pipes[4];
  pipe(pipes);
  pipe(pipes + 2); 

  if (fork() == 0)
  {
    dup2(pipes[1], 1);
    close(pipes[0]);
    close(pipes[1]);
    close(pipes[2]);
    close(pipes[3]);
    execvp(*args1, args1);
  }
  else
  {

    if (fork() == 0)
    {

      dup2(pipes[0], 0);
      dup2(pipes[3], 1);
      close(pipes[0]);
      close(pipes[1]);
      close(pipes[2]);
      close(pipes[3]);
      execvp(*args2, args2);
    }
    else
    {
      if (fork() == 0)
      {
        dup2(pipes[2], 0);
        close(pipes[0]);
        close(pipes[1]);
        close(pipes[2]);
        close(pipes[3]);
        execvp(*args3, args3);
      }
    }
  }
  close(pipes[0]);
  close(pipes[1]);
  close(pipes[2]);
  close(pipes[3]);

  for (i = 0; i < 3; i++)
    wait(&status);
}