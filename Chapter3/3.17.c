#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define MAX_SEQUENCE 10

typedef struct {
  long fib_sequence[MAX_SEQUENCE];
  int sequence_size;
} shared_data;

int main(int argc,char** argv)
{
  int i,n=0;
  for(i=0; argv[1][i]!='\0'; ++i){n=10*n+(argv[1][i]-48);};
  
  //checking Max_Sequence Condition
  if(n>MAX_SEQUENCE) printf("Length of Sequence is Greater\n");
  else{

    int segment_id;
    shared_data *shared_memory,*child_memory,*parent_memory;

    /* the size (in bytes) of the shared memory segment*/
    const int size = sizeof(shared_data);

    /* allocate a shared memory segment */
    segment_id = shmget(IPC_PRIVATE, size, (IPC_CREAT | 00666));
 
    switch(fork())
      {
      case -1:
	perror("Bad fork()"); exit(1);
      case 0:
	shared_memory =(shared_data *) shmat(segment_id, NULL, 0);
	if ((int *) shared_memory == (int *) -1)
	  {perror("Child cannot attach"); exit(1);}           

	child_memory = shared_memory;
	
	child_memory->fib_sequence[0]=0;
	child_memory->fib_sequence[1]=1;
	  for(i=2;i<n;i++)
	    {
	      child_memory->fib_sequence[i]=child_memory->fib_sequence[i-1]+child_memory->fib_sequence[i-2];
	    }
	  
	child_memory->sequence_size=n;
	
	shmdt(shared_memory);
	exit(0);
      default:
	  
	shared_memory = shmat(segment_id, NULL, 0);
	if ((int *) shared_memory == (int *) -1)
	  {perror("Child cannot attach"); exit(1);}

	wait((int *)0);
	parent_memory =shared_memory;
	printf("Fibonacii Sequence is :\n");
	for(i=0;i<parent_memory->sequence_size;i++)
	  {	printf("%ld \t", parent_memory->fib_sequence[i]);}
	printf("\n");
	
	shmdt(shared_memory);

	if (shmctl(segment_id, IPC_RMID, 0) <0)
	  { perror("cannot remove shared memory"); exit(1);}

	return 0;
      }
  }
}
