#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

song_node *insert_front( song_node *L, char n[256], char a[256] ) {
  song_node *new = (song_node *)malloc(sizeof(song_node));
  strcpy(new->name,n);
  strcpy(new->artist,a);
  new->next = L;

  return new;
}

song_node *insert_order( song_node *L, char n[256], char a[256] ) {
  if (!L || strcmp(a, L->artist) < 0)
    return insert_front( L, n, a );

  if (strcmp(a, L->artist) == 0 && strcmp(n, L->name) < 0)
    return insert_front( L, n, a );

  L->next = insert_order( L->next, n, a );

  return L;
}

song_node *insert( song_node *L, char n[256], char a[256] ) {
  return insert_order( L, n, a );
}

void print_list( song_node *L ) {
  while (L) {
    printf("%s - %s ", L->artist, L->name);
    L = L->next;
  }
  printf("\n");
}

song_node *find_songN( song_node *L, char n[256] ) {
  while (L) {
    if (strcmp(n, L->name) == 0)
      return L;
    L = L->next;
  }
  return 0;
}

song_node *find_songA( song_node *L, char a[256] ) {
  while (L) {
    if (strcmp(a, L->artist) < 0) {
      return 0;
    }
    if (strcmp(a, L->artist) == 0)
      return L;
    L = L->next; 
  }
  return 0;
}

int len( song_node *L ) {
  int i = 0;
  while (L) {
    L = L->next;
    i++;
  }
  return i;
}

song_node *rand_node( song_node *L ) {
  int i = rand() % len(L);
  while (i) {
    L = L->next;
    i--;
  }
  return L;
}

song_node *remove_node( song_node *L, char n[256], char a[256] ) {
  song_node *tmp = L;
  song_node *prev = 0;
  song_node *s = find_name(L, n);
  if (!s)
    return L;
  if (tmp == s) {
    L = tmp->next;
    free(tmp);
    tmp = 0;
    return L;
  }
  while(tmp != s && tmp->next) {
    prev = tmp;
    tmp = tmp->next;
  }
  prev->next = tmp->next;
  free(tmp);
  tmp = 0;
  return L;
}

song_node *free_list( song_node *L ) {
  song_node *curr = L;
  song_node *next = 0;
  while (curr) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  free(curr);
  free(next);
  return L;
}
