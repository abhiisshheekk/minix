#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	char* printThis = "Hello World";
	int rc = fork();
	for (int i=0; i<strlen(printThis); i++) {
		if (rc == 0) {
			printf("%c %d\n", *(printThis + i), getpid());
			sleep(rand()%4 + 1);
			rc = fork();
			if (rc == 0)
				continue;
		} 
		else
			wait(NULL);
	}
	return 0;
}
