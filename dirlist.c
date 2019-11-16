#include <stdlib.h>
#include <stdio.h>

struct dir{
  char i[250];
  struct dir* next;
};

void print_dirs(struct dir* node){
  if (node == NULL){
    printf("[  ]\n");
    return;
  }
  printf("[ ");
  while(node->next != NULL){
    printf("%s ", node->i);
    node = node->next;
  }
  printf("]\n");
}

struct dir* insert_dir(struct dir* node, char x[250]){
  //struct node front;
  struct dir* ptr = malloc(sizeof(struct dir));//&front;
  //ptr->i = x;
  int m;
  for (m = 0; m < 250; m++){
    ptr->i[m] = x[m];
  }
  ptr->next = node;
  return ptr;
}

struct dir* free_dirs(struct dir* node){
  struct dir* ph;
  while (ph != NULL){
    ph = node->next;
    free(node);
    node = ph;
  }
  return ph;
  /*free(node);
  free_list(ph);
  return ph;*/
}

struct dir* remove_dir(struct dir* front, char data[250]){
  struct dir* leader = front->next;
  struct dir* follower = front;
  while (leader != NULL){
    if (leader->i == data){
      follower->next = leader->next;
      free(leader);
      return front;
    }
    follower = leader;
    leader = leader->next;
  }
  return front;
} 