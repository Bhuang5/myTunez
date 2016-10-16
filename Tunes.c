#include <stdio.h>
#include <stdlib.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


//and later:

song_node *table[26];

int print_list(struct node *start){  
  //Base case 1 for empty linked list
  if(start == 0 ){
    printf("{}\n");
    return 0;
  }
  
  //Base case 2
  if(start->next == 0){
    printf("%d \n", start->i);
    return 0;
  }

  //Recursive call
  printf("%d, ", start->i);
  return print_list(start->next);
}

struct node* insert_front(struct node *front, int x){
  //The "constructor" for the new front k
  struct node *k = (struct node *)calloc(1, sizeof(struct node *));
  
  //Insert
  k->next = front;
  k->i = x;
  return k;
}

struct node* free_list(struct node *front){
  //Place holder
  struct node *p;  
  while(front != NULL){
    p = front->next; //Move p forward
    free(front); //Free the node before p
    front = p; //Move front from just freed node to p
  }
  return front;

}
