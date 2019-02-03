#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int tau;
	float alpha;
	int *bursts;
} Process;

int main(int argc, char *argv[]) {

	FILE *fPtr;
	char *file;
	char buff[5];
	int tau;
	float alpha;
	int pid;

	// keep track of what's read in
	int count = 0;
	int ticks;
	int num_of_procs;
	int i;
	int j;

	if (argv[1] == NULL) {

		// no file
		printf("Please provide filename.\n");
		return(1);

	} else {

		file = argv[1];
		printf("Filename: %s\n", file);
	}

	// open file for reading and determine size of the 2 dimensional array
	fPtr = fopen(file, "r");

	if (fPtr) {

		fscanf(fPtr, "%d", &ticks);
		printf ("Ticks: %d\n", ticks);

		fscanf(fPtr, "%d", &num_of_procs);
		printf ("Number of Processes: %d\n", num_of_procs);


		// now we need to read the rest of the integers into an array
		// now create the two dimensional array
		int actual[ticks][num_of_procs];

		for (i=0; i<num_of_procs; i++) {
	
			// now create the process details
			// and store in a struct
			Process *proc_details = malloc(sizeof(Process) * num_of_procs);

			fscanf(fPtr, "%d", &proc_details[i].pid);
			printf ("PID: %d\n", proc_details[i].pid);

			fscanf(fPtr, "%d", &proc_details[i].tau);
			printf ("Tau: %d\n", proc_details[i].tau);

			fscanf(fPtr, "%f", &proc_details[i].alpha);
			printf ("Aplpha: %f\n", proc_details[i].alpha);

			proc_details[i].bursts = malloc(ticks * sizeof(int));

			for (j=0; j<ticks; j++) {
				fscanf(fPtr, "%d", &proc_details[i].bursts[j]);
				printf("Process: %d, burst: %d\n", proc_details[i].pid, proc_details[i].bursts[j]);
			}
		}
					
	} else {
		printf ("Unable to open the file.\n");
	}

	return(0);
}
