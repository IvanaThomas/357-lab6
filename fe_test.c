#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>

void limit_fork(rlim_t max_procs){
	struct rlimit rl;
	if (getrlimit(RLIMIT_NPROC, &rl)){
		perror("getrlimit");
		exit(-1);
	}

	rl.rlim_cur = max_procs;

	if (setrlimit(RLIMIT_NPROC, &rl)){
		perror("setrlimit");
		exit(-1);
	}
}

int main(int argc, char* argv[]){
	limit_fork(50);
	if (argc < 2) {
		printf("Error: Not enough args provided");
		exit(1);
	}

	int N;
	sscanf(argv[1], "%d", &N);
	
	//fork
	pid_t pid = fork();

	if (pid == -1) {
		perror("Error creating  fork");
		exit(1);
	}

	//child process
	else if (pid == 0){
		execl("./odds.out", "odds", argv[1],  NULL);
		perror("execl");
		return 1;
	}

	else {
		execl("./evens.out", "evens", argv[1], NULL);
		perror("execl");
		return 1;
	}
	
}
