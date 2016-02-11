/* Run as 
 $ gcc -fno-stack-protector q1.c -o q1.c
 $ ./q1 mywrongsecret
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int grant_root(char* buffer){
  // Reserve 6 byte of buffer plus the
  // terminating NULL....should allocate 8 bytes = 2 double words due to padding
  // to overflow, need more than 8 bytes...
  // so, if more than 8 characters input by user,
  // there will be access violation, segmentation fault etc.
  char user_buffer[6];
  int pass=0;
  // copy the data received from user without any bound check
  // to secure use strcpy_s()
  strcpy(user_buffer, buffer);
  printf("User buffer contains = %s\n", user_buffer);

  if(strcmp(user_buffer, "secret")){
    printf ("\n Wrong Password Entered \n");
  }
  else
  {
    printf ("\nCorrect Password \n");
    pass = 1;
  }
  if(pass){
    //....
    printf("Granted root privilege to User\n");
    //.....
  }
  return pass;
}
int main(int argc, char *argv[])
{
  // Usage instructions
  if (argc < 2)
  {
        printf("Check usage below\n");
        printf("Syntax: %s <password>\n", argv[0]);
        exit(0);
  }
  grant_root(argv[1]);
  return 0;
}