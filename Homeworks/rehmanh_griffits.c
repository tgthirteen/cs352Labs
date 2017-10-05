#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short u_short;
typedef unsigned int u_int32;
typedef unsigned long u_int64;

u_int64 getCode(int* buffer, int count) // count is the number of bytes in a file
{
  register u_int64 total = 0;

  while(count--)
  {
		printf("%d", buffer[count]);
  }

  return 0;
}


/*

char* getFname(){


}

*/

char* testValidity(char* code, char* fname){

	
  return;
}


int main()
{
  FILE *fPointer;
  char fName[255];
  char user_decision;
  char *_txt = ".txt"; //not used at the moment
  int * bits; //changed from char string[size]
  int filelen;
  int _again = 1;
  int notFirstTime = 0;

  while(_again)
  {
    printf("Enter filename for validation: ");
    scanf("%s", &fName);
    //strcat(fName, _txt);

    fPointer = fopen(fName, "rb");

    if(fPointer == NULL)
    {
      printf("The file could not be opened!\n");
      notFirstTime = 0;
    }
    else
    {
      fseek(fPointer, 0, SEEK_END);
      filelen = ftell(fPointer);
      rewind(fPointer);

      bits = (int *)malloc((filelen + 1) * sizeof(int));
      fread(bits, filelen, 1, fPointer);
     // printf("%x\n",  &bits );


		/*
			for(int i = 0; i < filelen; i++){
				printf("%d", bits[i]);
			}
		*/

			getCode(bits, filelen);

      free(bits);
			notFirstTime = 1;
      // while(!feof(fPointer))
      // {
      //
      //   fread(string, filelen, 1, fPointer);
      //   printf("%u\n",  &string );
      //
      //   //fscanf(fPointer, "%s", &string);
      //   //printf("%s\n", &string);
      // }
    }

    if(notFirstTime)
    {
      printf("Again? ");
      scanf(" %c", &user_decision);

      if(user_decision == 'n' || user_decision == 'N')
      {
        _again = 0;
        printf("Goodbye!\n");
      }
    }

    notFirstTime++;

  }

  fclose(fPointer); //when the fuck am i supposed to close this???

}

/*

//use fgetc() for the actual file, but right now I am just testing the string
while (fgetc(file) != EOF)
{
  count++;
}

*/
