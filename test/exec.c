#include <stdio.h>
#include <unistd.h>
int main (){
	char *argv[]={"/usr/bin/ls","l",NULL};
	int vul =execve(argv[0],argv,NULL);
	if (vul==-1)
		perror("error");

	printf("done");
	return 0 ;
}
