#include <stdio.h>
#include <regex.h>
#include "./nxjson/nxjson.h"
#include "./strutils.c"

int main(int argc, char **argv)
{

    char msg1[] = "{'x':18,'y':23}";
    char *msg = msg1;

    
    char src[] = "";
    strcpy(src, msg);
    char *point = src;


    struct str_split_info info;
    info.source = point;
    info.delimiter = ",";

    char * substr;
    for (int i=0; i<info.splitStringsCount; i++) {
      substr = info.splitStrings[i];
      printf("substring: '%s'\n", substr);
    }


    




    return 0;

}