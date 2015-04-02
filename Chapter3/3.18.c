#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
  char write_msg[BUFFER_SIZE]="Hi There";
  char read_msg[BUFFER_SIZE];
  char new_msg[BUFFER_SIZE];
  int fd[2],i;
  pid_t pid;

  if (pipe(fd) == -1) {
    fprintf(stderr,"Pipe failed");
    return 1;
  }
  
  switch(pid = fork())
    {
    case -1:  
      fprintf(stderr, "Fork Failed");
      return 1;
    case 0:
      sleep(1);
      read(fd[READ_END], read_msg, BUFFER_SIZE);
      printf ("read %s\n", read_msg);
      close(fd[READ_END]);
      for(i=0;i<strlen(read_msg);i++)
	{
	  if(read_msg[i]==32){i++;}
	  else if(read_msg[i]<91){read_msg[i]=read_msg[i]+32;}
	  else{read_msg[i]=read_msg[i]-32; }
	}
       write(fd[WRITE_END], read_msg, strlen(write_msg)+1);
       close(fd[WRITE_END]);
       exit(0);
    default:
      write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
      close(fd[WRITE_END]);
      wait(NULL);
      read(fd[READ_END], new_msg, BUFFER_SIZE);
      printf ("new message %s\n", new_msg);
      close(fd[READ_END]);
    }
  
  return 0;
}
