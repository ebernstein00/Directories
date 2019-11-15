#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int isDirectory(char filename[250]){
  DIR *tester = opendir(filename);
  if (tester != NULL){
    close(tester);
    return 1;
  }
  if (errno == ENOTDIR){
    return 0;
  }
  return -1;
}

int main(){
  //Print list of files in current directory...
  struct dirent *di;
  DIR *dr = opendir(".");
  if (dr == NULL){
    printf("Error #%d: %s\n", errno, strerror(errno));
    printf("Could not open directory...\n");
    return 0;
  }
  char **directories = malloc(16);
  char **others = malloc(16);
  di = readdir(dr);
  int fd;
  while (di != NULL){
    //fd = open(di, O_RDONLY);
    if (isDirectory(di)){
      
  }
