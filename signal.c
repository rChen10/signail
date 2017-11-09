#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if( signo == SIGINT ){
    int fd = open("errors", O_CREAT | O_APPEND | O_WRONLY, 644);
    write(fd, "Trying to send me a SIGINT? Rude!\n", 34);
    close(fd);
    printf("SIGINT error written to errors\n");
    exit(1);
  }
  if ( signo == SIGUSR1 ){
    printf("The parent PID is: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1){
    printf("My PID is:%d\n", getpid());
    sleep(1);
  }
}
