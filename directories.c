#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int isDirectory(char filename[250]){
  DIR *tester = opendir(filename);
  if (tester != NULL){
    closedir(tester);
    return 1;
  }
  if (errno == ENOTDIR){
    return 0;
  }
  return -1;
}

int main(int argc, char *argv[]){
  //Print list of files in current directory...
  char dirs[250][250];
  char files[250][250];
  struct dirent *di;
  if (argc > 1){
    DIR *dr = opendir(argv[1]);
  }
  else{
    DIR *dr = opendir(".");
  }
  if (dr == NULL){
    printf("Error #%d: %s\n", errno, strerror(errno));
    printf("Could not open directory...\n");
    return 0;
  }
  int fd;
  int diri = 0;
  int fili = 0;
  while ((di = readdir(dr)) != NULL){
    if (isDirectory(di->d_name)){
      strcpy(dirs[diri], di->d_name);
      diri++;
    }
    else{
      strcpy(files[fili], di->d_name);
      fili++;
    }
  }
  closedir(dr);
  printf("Directories:\n");
  int i;
  for (i = 0; i < 10; i++){
    if (dirs[i][0] == '\0') break;
    printf("%s\n", dirs[i]);
  };
  printf("\nFiles:\n");
  for (i = 0; i < 10; i++){
    if (files[i][0] == '\0') break;
    printf("%s\n", files[i]);
  };
  printf("\n");
  return 0;
}