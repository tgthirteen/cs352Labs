//Habib Rehman
//Trevor Griffin
// CS352 Lab1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned short u_short;
typedef unsigned int u_int32;
typedef unsigned long u_int64;

char fName[255];

char test_file[255];

char user_decision;

//u_int64 *buf;

unsigned char *buf;

u_int32 code;

int filelen;
int _again = 1;
int notFirstTime = 0;


u_int32 getCode(unsigned char *buffer, int count) // changed return type to void
{
  register u_int64 total = 0;

  u_int32 tmp;

  u_int32 test[32];

  //u_int32 tot[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  u_int32 tot = 0;

  //printf("The size of the char array is: %lu\n", sizeof(buffer)/sizeof(char*));

  while(count--)
  {

    tmp = (u_int32) buffer[count]; //this is already 4 bytes

    tot += tmp;

    if(tot > 255) //(pow(2, 32) - 1)
    {
      tot -= 255;//(pow(2, 32) - 1);
    }

    printf("%d ", tmp);

    printf("%d ", tot);

    // int i;
    //
    // for(i = 31; i >= 0; i--)
    // {
    //   //printf("%d", !!(0x80 & (tmp << i))); // buffer[count];
    //
    //   test[i] = !!(0x300 & (tot << i));
    //
    //   printf("%d", test[i]); // at this point, I have an array of all the bits that are in the byte #12
    //
    //   //printf("%d", tot[i]); // at this point, I have an array of all the bits that are in the byte #12
    // }

    // printf(" %d", test[0]);

    printf("\n");

    //lets take the count the first time this loop iterates. Count is going to be 12

    //printf("The size of tmp is: %lu\n", sizeof(tmp));

		//printf("%d\n", test);
  }

  printf("%x\n", ~tot);

  return ~tot;
}

//This will need to compare the hex code from getCode with the code from the entered filename
void testValidity(u_int32 code, unsigned char *fname, int filelen) {

u_int32 test_code;

u_int32 a = 211;

u_int32 b = 44;



test_code = getCode(fname, filelen);

test_code = test_code | code;
printf("%d\n", test_code);

if(test_code == 255)
{
  printf("yay\n");
}

else printf("Fuck\n");

}


int main()
{
  FILE *fPointer;
  char fName[255];

  char test_file[255];

  char user_decision;

  //u_int64 *buf;

  unsigned char *buf;

  u_int32 code;

  int filelen;
  int _again = 1;
  int notFirstTime = 0;

  while(_again)
  {
    printf("Enter filename for validation: ");

    scanf("%s", &fName);

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

      buf = (unsigned char *)malloc((filelen + 1) * sizeof(unsigned char)); //changed from int

      //fread(&buf, sizeof(buf), 1, fPointer);

      //read into  buf, filelen bytes, 1 time, passto fPointer
      fread(buf, filelen, 1, fPointer);

      printf("The number of bytes in the file are: %d\n", filelen);

			code = getCode(buf, filelen);

      printf("Enter filename for validation with: %x", code);

      scanf("%s", &fName);

      fPointer = fopen(fName, "rb");

      filelen = ftell(fPointer);
      rewind(fPointer);

      free(buf);

      buf = (unsigned char *)malloc((filelen + 1) * sizeof(unsigned char)); //changed from int
      fread(buf, filelen, 1, fPointer);

      testValidity(code, buf, filelen);

      free(buf);
			notFirstTime = 1;
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
