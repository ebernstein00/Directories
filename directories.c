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
    close(tester);
    return 1;
  }
  if (errno == ENOTDIR){
    return 0;
  }
  return -1;
}

int isRegFile(char path[250]){
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
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
  printf("made it here\n");
  //di = readdir(dr);
  int fd;
  int diri = 0;
  int dirj = 0;
  int fili = 0;
  int filj = 0;
  printf("here too\n");
  printf("current di: %s\n", di);
  while ((di = readdir(dr)) != NULL){
    //fd = open(di, O_RDONLY);
    if (isDirectory(di)){
      strcpy(dirs[diri][dirj], di->d_name);
      if (dirj < 250) dirj++;
      if (dirj >= 250) dirj = 0; diri++;
    }
    else{
      strcpy(files[fili][filj], di->d_name);
      if (filj < 250) filj++;
      if (filj >= 250) filj = 0; fili++;
    }
    di = readdir(dr);
  }
  closedir(dr);
  printf("Directories:\n");
  int i;
  int j;
  for (i = 0; i < 250; i++){
    for (j = 0; j < 250; j++){
      printf("%s\n", dirs[i][j]);
    }
  }
  printf("\nFiles:\n");
  for (i = 0; i < 250; i++){
    for (j = 0; j < 250; j++){
      printf("%s\n", files[i][j]);
    }
  }
  printf("\n");
  return 0;
}