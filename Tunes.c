#include <stdio.h>
#include <stdlib.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


//and later:

song_node *table[26];

int print_songs(struct node *start){  
  song_node *k;
  int i = 0;
  while (i < 26){
    print_list(table[i]);
  }
}

int print_list(song_node *start){
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
*/

song_node* insert_song(song_node *front, char n[256], char a[]){
  song_node *k = (song_node *)calloc(1, sizeof(song_node *));
  int i = 0;
  while (i < 26){
    if (n[0] == table[i]) 
      k->next = front;
      }
  //Insert
  return k;
}

/*
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
*/
