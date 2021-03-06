#include "types.h"
#include "stat.h"
#include "user.h"

#define BIGSIZE (10000)
#define TIMES (100)

char buf[BIGSIZE];
char read_sentence[BIGSIZE];
char big_file[BIGSIZE];

int 
main(int argc, char *argv[])
{
  int fd;
  int n;
  int i;

  char char_var = '1';
 for (int i=0;i<BIGSIZE;i++){
    if((i%512) == 0){
      if(char_var == '9')
        char_var = '0';
      else
        char_var ++;
    }
    buf[i] = char_var;
  }

  printf(1,"Stress test for big file (size:1,000,000) Start\n");
  for (i = 0;i < TIMES; i++){
    if((fd = open("stress.out",0x202)) < 0){
        printf(1, "stress: cannot open %s\n", "stress.out");
        exit();
    }

    for (int i=0;i<100;i++){
      if((n = write(fd,buf,BIGSIZE)) < 0)
        printf(1,"[proc]writing failed\n");
    }
    close(fd);
    printf(1,"Test[%d] Finished\n",i+1);
    unlink("stress.out");
  }
  printf(1,"Stress test for big file (size:1,000,000) Passed\n");

  exit();  
}
