#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int i,vul =5;
	pid_t pid;
	for(i=1;i<=3;i++){
		pid=fork();
		vul=vul+5;
		if (pid!=0)
			break;
	}
	printf("i=%d\n",i);
	printf("p=%d\n",pid);
	printf("value=%d\n",vul);

	return (0);
}
