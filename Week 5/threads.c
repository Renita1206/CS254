#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread(s) */
int product;

void *runner(void *param); /* threads call this function */
void *runner1(void *p1);

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */
	pthread_t tid1;
	pthread_attr_t attr1;

	if (argc != 3) // arg count - a, x, y => x and y are numbers to be added/multiplied
	{
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}

	if (atoi(argv[1]) < 0) 
	{
		fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
		return -1;
	}

	/* get the default attributes */
	pthread_attr_init(&attr);
	pthread_attr_init(&attr1);

	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);

	pthread_create(&tid1,&attr1,runner1,argv[2]);
	pthread_join(tid1,NULL);

	printf("sum = %d\n",sum);
	printf("product = %d\n",product);
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i, a = atoi(param);
	sum = a;
	product = a;

	pthread_exit(0);
}

void *runner1(void *p1)
{
	int a = atoi(p1);
	sum = sum+a;
	product = product*a;

	pthread_exit(0);
}
