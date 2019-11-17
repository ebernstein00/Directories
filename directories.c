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

int main(){
  //Print list of files in current directory...
  //struct dirs* dir = (NULL, NULL);
  //struct files* file = (NULL, NULL);
  char dirs[250][250];
  char files[250][250];
  struct dirent *di;
  DIR *dr = opendir(".");
  if (dr == NULL){
    printf("Error #%d: %s\n", errno, strerror(errno));
    printf("Could not open directory...\n");
    return 0;
  }
  int fd;
  int diri = 0;
  int fili = 0;
  while ((di = readdir(dr)) != NULL){
    //printf("%s\n", di->d_name);
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
  //int j;
  for (i = 0; i < 10; i++){
    //for (j = 0; j < 250; j++){
    if (dirs[i][0] == '\0') break;
    printf("%s\n", dirs[i]);
    //}
  };
  printf("\nFiles:\n");
  for (i = 0; i < 10; i++){
    //for (j = 0; j < 250; j++){
    if (files[i] == NULL) break;
    printf("%s\n", files[i]);
    //}
  };
  printf("\n");
  return 0;
}