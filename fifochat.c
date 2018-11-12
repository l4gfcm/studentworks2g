#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc,char* argv[]) {
    
  int isSecond = 0;
  int wr,rd;
  int thread;
  char firstChannel[] = "firstChannel.fifo";
  char secondChannel[] = "secondChanell.fifo";
  char input[100];
  char readed[100];
  size_t size;
  size_t rsize;

  if(argc==2) {
    if(strcmp(argv[1],"-ch")==0){
      isSecond = 1; 
    }
  }

  (void)umask(0);
  printf("@: Creating chanel...\n");

  if(!isSecond && (mknod(firstChannel, S_IFIFO | 0666, 0)<0 ||
                      mknod(secondChannel, S_IFIFO | 0666, 0)<0)) {
    printf("@: Can`t create chanel\n");
    exit(-1);
  } 
  else {
    printf("@: Chanel created\n");
  }
  
  printf("@: Connecting to channel...\n");
  if(!isSecond) {
    if((wr = open(firstChannel,O_WRONLY))<0) {
      printf("@: Can`t connect to channel\n");
      exit(-1);
    }
    if((rd = open(secondChannel,O_RDONLY))<0) {
      printf("@: Can`t connect to channel\n");
      close(wr);
      unlink(firstChannel);
      exit(-1);
    }
  }
  else {
    if((rd = open(firstChannel,O_RDONLY))<0) {
      printf("@: Can`t connect to channel\n");
      exit(-1);
    }
    if((wr = open(secondChannel,O_WRONLY))<0) {
      printf("@: Can`t connect to channel\n");
      close(wr);
      unlink(secondChannel);
      exit(-1);
    }
  }

  printf("@: Connected\n");
  
  if((thread=fork())<0) {
    printf("@: Can`t create reading process");
    close(rd);
    close(wr);
    unlink(firstChannel);
    unlink(secondChannel);
    exit(-1);
  }

  if(thread>0) { 
  //writing process

   while(1) {
      scanf("%s", input);

      if(strcmp(input, "exit") == 0){
        printf("@: Program closed\n");
        kill(thread,SIGKILL);
        break;
      } 
      size = write(wr, input, strlen(input));

      if(size < strlen(input)) {
        printf("@: Can`t write message\n");
        kill(thread,SIGKILL);
        break;
      }
      printf("\nUser1: %s\n",input);
    }
  }
  else {  
  //reading process
     while(1) {
     
      rsize = read(rd, readed, 100);
      if(rsize > 0) {
        printf("\nUser2: %s\n",readed);
      }
      if(rsize == 0) {
        printf("User2 disconnected\n");
        break;
      }
    } 
  }

  close(rd);
  close(wr);
  unlink(firstChannel);
  unlink(secondChannel);

  return 0;
	
}
