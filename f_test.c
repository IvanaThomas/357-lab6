#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char argv[]){
	if (argc < 2) {
		printf("Error: Not enough args provided");
		exit(1);
	}

	int N = argv[1];
	
	//fork
	pid_t pid = fork();

	if (pid == -1) {
		perror("Error creating  fork");
		exit(1);
	}

	//child process
	
}
