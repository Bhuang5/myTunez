#ifndef DEF
#define DEF

#include <stdio.h>
#include <stdlib.h>

typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node *insert_front( song_node *front, char n[256], char a[256] );

song_node *insert_order( song_node *front, char n[256], char a[256] );

song_node *insert( song_node *front, char n[256], char a[256] );

void print_list( song_node *front );

song_node *seach_n( song_node *front, char n[256] );

song_node *search_a( song_node *front, char a[256] );

song_node *rand_node( song_node *front );

song_node *remove_song( song_node *fist, char n[256], char a[256] );

song_node *free_list( song_node *front );

#endif
