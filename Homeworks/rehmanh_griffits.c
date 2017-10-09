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

u_int32 getCode(unsigned char *buffer, int count) // changed return type to void
{
  //register u_int64 total = 0;

  u_int32 tmp;

  u_int32 test[32];

  register u_int32 tot = 0;

  while(count--)
  {

    tmp = (u_int32) buffer[count]; //this is already 4 bytes

    tot += tmp;

    if(tot > (pow(2, 32) - 1)) //255
    {
      tot -= (pow(2, 32) - 1); //255
    }

    /*------test code---------*/

    //printf("%d ", tmp);

    //printf("%u ", tot);

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

		//printf("\n");

    /*-----------------------*/
  }

  return ~tot;
}

void testValidity(u_int32 code_to_test, char file_to_test[255])
{
  FILE* fp;
  int len;
  unsigned char *buf;
  u_int32 code;

  fp = fopen(file_to_test, "rb");

  if(fp == NULL)
  {
    printf("The file could not be found.\n");
  }
  else
  {
    fseek(fp, 0, SEEK_END);

    len = ftell(fp);

    rewind(fp);

    buf = (unsigned char *)malloc((len + 1) * sizeof(unsigned char));

    fread(buf, len, 1, fp);

    code = ~getCode(buf, len);

    free(buf);

    //printf("The addition is: %x\n", (code_to_test | code));

    if((code_to_test | code) == 0xffffffff)
    {
      printf("Validation: Success!\n");
    }
    else
    {
      printf("Validation: Fail\n");
    }

  }

}


int main()
{
  FILE *fPointer;
  char fName[255];
  char test_file[255];
  char user_decision;
  unsigned char *buf;
  u_int32 code;
  int filelen;
  int _again = 1;
  int notFirstTime = 0;

  while(_again)
  {
    printf("Enter filename: ");

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

      fread(buf, filelen, 1, fPointer);

      printf("The number of bytes in the file are: %d\n", filelen);

      code = getCode(buf, filelen);

      printf("Calculated code: %x\n", code);

      free(buf);

      printf("Enter filename for validation with %x: ", code);

      scanf("%s", test_file);

      testValidity(code, &test_file);

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
