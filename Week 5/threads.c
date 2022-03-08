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

	if (argc != 3) 
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

	/* create the thread */
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_create(&tid1,&attr1,runner1,argv[2]);

	/* wait for the thread to exit */
	pthread_join(tid,NULL);
	pthread_join(tid1,NULL);
	printf("sum = %d\n",sum);
	printf("product = %d\n",product);
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;

	for (i = 1; i <= upper; i++)
		sum += i;

	pthread_exit(0);
}

void *runner1(void *p1)
{
	int a = atoi(p1);
	//int b = atoi(p2[1]);
	product = a*5;

	pthread_exit(0);
}
