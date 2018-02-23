/*
gen_random_arr.c:
	This code generates multiple random arrays.
	Usage: gen_random_arr {array size} {number of array samples}

	Let n <= array size
	Let m <= number of array samples

	This code would generate m number of n-sized random arrays
	and output them into one text file each. 
	Output File Naming convention for the i^th sample: "input_n_i.txt"
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define LIMIT 10
#define SOME_BIG_PRIME 7907

int main(int argc, char *argv[]) {
	
	int n=0;
	int num_arrays=0;
	int sign = 0;
	int i,j;
	int element;
	unsigned int *seed=NULL;
	char op_file_name[100];
	FILE *fp;

	if(argc!=3)  {
		printf("Usage: gen_random_arr {array size} {number of arrays}\n");
		return 1;
	}

	n = atoi(argv[1]);
	assert(n>=0); // make sure n is always >= 0.. 
	num_arrays = atoi(argv[2]);
	assert(num_arrays>=1); // make sure number of arrays to be generates >= 1

	//Note: the assert function is a great way to avoid 
	//		crowding your program with lots of error-checking printfs!

	// create num_array number of seeds
	seed = (int *)malloc(sizeof(unsigned int)*num_arrays);
	assert(seed!=NULL);

	for(i=0;i<num_arrays;i++) {
		seed[i] = rand()%SOME_BIG_PRIME;
	}



	for(i=0;i<num_arrays;i++) {
		// create a new file to write the array
		sprintf(op_file_name,"input_%d_%d.txt",n,i);
		fp = fopen(op_file_name,"w");
		assert(fp!=NULL);
		
		// init seed for this array
		//	 the idea is:
		//		each time you want a new sample you start with a new seed

		srand(seed[i]);

		// generate the array
		for(j=0;j<n;j++) {
			element = rand()%LIMIT;	// generates a random number between 0 and 9
			sign = rand()%2;		// generates 0 or 1 randomly (used to determine sign)

			if(sign==0) {
				element = 0 - element;
			}
			fprintf(fp,"%d\n",element);
		}// end for j	
		fclose(fp);
	}// end for i

	return 1;
	
} // end main
