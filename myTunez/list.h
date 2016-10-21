#ifndef DEF
#define DEF

#include <stdio.h>
#include <stdlib.h>

typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node *insert_front( song_node *L, char n[256], char a[256] );

song_node *insert_order( song_node *L, char n[256], char a[256] );

song_node *insert( song_node *L, char n[256], char a[256] );

void print_list( song_node *L );

song_node *find_songN( song_node *L, char n[256] );

song_node *find_songA( song_node *L, char a[256] );

song_node *rand_node( song_node *L );

song_node *remove_node( song_node *L, char n[256], char a[256] );

song_node *free_list( song_node *L );

#endif
