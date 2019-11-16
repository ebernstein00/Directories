#include <stdlib.h>
#include <stdio.h>

struct file{
  char i[250];
  struct file* next;
};

void print_files(struct file* node){
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

struct file* insert_file(struct file* node, char x[250]){
  //struct node front;
  struct file* ptr = malloc(sizeof(struct node));//&front;
  //ptr->i = x;
  int m;
  for (m = 0; m < 250; m++){
    ptr->i[m] = x[m];
  }
  ptr->next = node;
  return ptr;
}

struct file* free_files(struct file* node){
  struct file* ph;
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

struct file* remove_file(struct file* front, char data[250]){
  struct file* leader = front->next;
  struct file* follower = front;
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