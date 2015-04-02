#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h> // external int errno

#define ACC_RIGHT 0644 /* User: Read+Write, Group and Other: Read */

int main(int argc, char *argv[])
{
    
  printf("input file name= %s\n", argv[1]); 
  printf("output file name= %s\n", argv[2]);
     
  int copyf; // file descriptor
  int pastef;      
     
  char c;
  char pc[512];
  int nread;
  
  
  if ((copyf = open(argv[1], O_RDONLY)) == -1)
    {
      printf("Couldn't open test.txt \n");
    } else {
    printf("file is open!\n");
  }

  if ((pastef = open(argv[2], O_WRONLY)) == -1)
    {
      printf("Couldn't open copy.txt \n");
    } else {
    printf("file is open!\n");
  }
  
     
  /* read in loop until EOF */
  while (nread = read(copyf, pc, 512) > 0)
    {
      write(pastef,pc,512);
      printf("char=%s\n", pc);
    }
  
     
  return 0;
}
