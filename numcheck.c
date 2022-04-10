#include<stdio.h>
#include <string.h>
#include <ctype.h>

int parse(unsigned char* in, size_t len, char **a, char **b){

  char new[50] = "";


  //iterate over string
  int i;
  for (i = 0; i < len; i++) {
    char ptr = in[i]; 
    if (isdigit(in[i])) {
        strncat(new, &ptr, 1);
    }

    char j = ',';

    if ( in[i] == j ) {
        strncat(new, &ptr, 1);
    }
  }

  char * separator = ",";
  char * one = strtok(new, separator);
  char * two = strtok(NULL, "");


  *a = one;
  *b = two;

}



int main() {

  char *in1 = "{'x':18,'y':29}";

  char in[50] = "";
  
  strcpy(in, in1);

  char * a, * b;

  parse(in, strlen(in), &a, &b);

  printf("%s", a);

   return 0;
}

/*
  char * separator = ",";
  char * b = strtok(a, separator);
  char * c = strtok(NULL, "");
*/

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
  
    char arr[3][20]; 
    strcpy(arr[0], "blah");
    strcpy(arr[1], "yo");

    printf("%s", arr[1]);

    return 0;
}
*/