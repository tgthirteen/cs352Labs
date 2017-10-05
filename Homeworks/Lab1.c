#include <stdio.h>
#include <string.h>

typedef unsigned short u_short;
typedef unsigned int u_int32;
typedef unsigned long u_int64;

char string[255];
FILE* filename;
char* filetext;
int filesize = 0;

u_int64 getCode(char* buffer, int count) {

	
	//register u_int64 total = 0;
	
	printf("hi");

	//while (count--){


//	}
	return 0;
}

int main() {

/* Ask for filename from user and put contents in buffer. Update the count of bytes/words */ 
	
	printf("Enter Filename: " );
	scanf("%s", string);
	
//	printf( "%s", string);

	char* txt = ".txt";
	
	strcat(string, txt);
  printf( "%s", string);	
	filename = fopen(string, "rb");
/*
	if(filename == NULL){
		printf("You dun fucked up");
	}
*/

	while(!feof(filename)){
		fscanf(filename, "%s", filetext);
		filesize++;
	}

//  getCode(filetext, filesize); 

	


/*
- Call getCode function to calculate code using 1's compliment
*/

/*
	getFname(...);
	code = getCode(buffer, count);
*/

/* use code to validate any user-specified file */

/*	
	getFname(...);
	testValidity(code, Fname);
*/
}


