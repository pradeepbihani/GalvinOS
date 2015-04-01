#include<st0dio.h>
#include<sys/types.h>

int main(int argc, char **argv)
{
  pid_t pid;
  pid =fork();

  if(pid <  0)
    {printf("ERRROR in creating Process\n");}
  else if(pid==0)
    {
      if(argv[1][0]>=48&&argv[1][0]<=57)
	{
	  int n=argv[1][0]-48;
	  int i=0,f[n];
	  f[0]=0;
	  f[1]=1;
	  for(i=2;i<n;i++)
	    {
	      f[i]=f[i-1]+f[i-2];
	    }
	  printf("Fibonaci Number Corrspoding to n=%d is %d\n",n,f[n-1]+f[n-2]);
	}
      else{
	printf("Wrong Input please enter the correct Number\n");
      }
    }
  else
    {
      wait(NULL);
    }
  
}
