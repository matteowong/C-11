#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



char ** parse_args(char * line) {
  printf("started\n");
  printf("%s\n",line);
  char local_line[strlen(line)+1];
  //printf("local line of size: %d\n",sizeof(local_line));
  strcpy(local_line,line);
  //printf("strcpy\n");
  char * s=local_line;
  //printf("%s\n",s);

  //should only malloc space for pointers, then later you malloc space to each of them
  char **ret=(char **)calloc(sizeof(char *),6);
  //printf("calloced\n");
  int i=0;
  while (i<5) {
    //printf("began while loop\n");
    char *temp=strsep(&s," ");
    //printf("made temp\n");
    if (!temp) {
      //printf("breaking from while loop\n");
      break;
    }
    char * word=(char *)malloc(sizeof(temp)+1);
    strcpy(word,temp);
    ret[i]=word;
    i++;
  }

  return ret;


}

void free_arg_list(char ** s) {

  int i=0;
  while (i) {

    free(s[i]);

    i++;
  }
  free(s);
  //printf("all freed\n");


}



int main() {
  int i;
    
  char**testtwo=parse_args("git add .");
  for (i=0;i<4;i++) {
    printf("%s\n",testtwo[i]);
  }
  free_arg_list(testtwo);

  char**testthree=parse_args("this is a test !");
  for (i=0;i<6;i++) {
    printf("%s\n",testthree[i]);
  }
  free_arg_list(testthree);

  char**test=parse_args("ls -a -l");
  for (i=0;i<4;i++) {
    printf("%s\n",test[i]);
  }
  execvp(test[0],test);

  return 0;
}
