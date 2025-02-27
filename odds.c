#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>	

int main(int argc, char* argv[]){

	if (argc < 2) {
		printf("Error: Not enough args provided");
		exit(1);
	}

	int N;
	sscanf(argv[1], "%d", &N);
	
	for (int i = 1; i <= N; i+=2){
		printf("%d\n", i);
	}
}
