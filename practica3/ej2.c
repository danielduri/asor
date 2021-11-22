#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int scheduler = sched_getscheduler(0);

	if(scheduler==SCHED_FIFO){
		printf("Scheduler FIFO\n");
	}else if(scheduler==SCHED_RR){
		printf("Scheduler RR\n");
	}else{
		printf("Scheduler OTHER\n");
	}

	int max = sched_get_priority_max(scheduler);
	int min = sched_get_priority_min(scheduler);

	printf("Max: %i, Min: %i\n", max , min);

	struct sched_param param;
	sched_getparam(0, &param);

	int priority = param.sched_priority;

	printf("Priority %i\n", priority);



	return 0;
}
