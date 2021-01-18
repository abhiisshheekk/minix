#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	char* printThis = "Hello World";
	for (int i=0; i<strlen(printThis); i++) {
		int rc = fork();
		if (rc == 0) {
			printf("%c %d\n", *(printThis + i), getpid());
			sleep(rand()%4 + 1);
			exit(1);
		} 
		else {
			wait(NULL);
		}
	}
	return 0;
}
