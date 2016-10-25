#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

song_node *insert_front( song_node *front, char n[256], char a[256] ) {
	song_node *new = (song_node *) malloc(sizeof(song_node));
  	strcpy(new->name,n);
  	strcpy(new->artist,a);
  	new->next = front;
  	return new;
}

song_node *insert(song_node *front, char n[256], char a[256]){
	song_node *new = (song_node *) malloc(sizeof(song_node));
	if(!front || strcmp(a, front -> artist) < 0)
		return insert_front(front, n, a);
 	if (strcmp(a, front->artist) == 0 && strcmp(n, front->name) < 0)
   		return insert_front( front, n, a );
	front->next = insert( front->next, n, a );
	return front;
}

void print_list(song_node *front){
	while(front){
		printf("%s - %s\n", front -> artist, front-> name );
		front = front -> next;
	}
}


song_node *search_n( song_node *front, char n[256] ) {
  while (front) {
    if (strcmp(front->name, n) == 0)
      return front;
    front = front->next;
  }
  return front;
}


song_node *search_a( song_node *front, char a[256] ) {
  while (front) {
    if (strcmp(a, front->artist) < 0) {
      return 0;
    }
    if (strcmp(a, front->artist) == 0)
      return front;
    front = front->next; 
  }
  return 0;
}

int len(song_node *n){
	int length = 0;
	while (n) {
		n=n->next;
		length++;
	}
	return length;
}

song_node *rand_node(song_node *front){
  int i = rand() % len(front);
  while (i) {
    front = front -> next;
    i--;
  }
  return front;
}

song_node * remove_song(song_node *front, char n[256], char a[256]) {
  song_node *tmp = front;
  song_node *prev = 0;
  song_node *s = search_n(front, n);
  if (!s)
    return front;
  if (tmp == s) {
    front = tmp->next;
    free(tmp);
    tmp = 0;
    return front;
  }
  while(tmp != s && tmp->next) {
    prev = tmp;
    tmp = tmp->next;
  }
  prev->next = tmp->next;
  free(tmp);
  tmp = 0;
  return front;
}



song_node *free_list( song_node *front ) {
  song_node *curr = front;
  song_node *next = 0;
  while (curr) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  free(curr);
  free(next);
  return front;
}


