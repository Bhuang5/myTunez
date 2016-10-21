#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "list.h"

void add( char n[256], char a[256] ) {
  printf("\nadding %s\n",  n);
  table[a[0]-97] = insert(table[a[0]-97],n,a);
  //takes the first letter inserts into corresponding letter
}

song_node *find_song( char n[256] ) {
  int i = 0; 
  song_node *song = 0;
  while (!song && i < 26) {
    song = find_songN(table[i],n);
    i++;
    //look for song under each letter
  }
  
  if (song) { //if found
    printf("found %s - %s\n", song->artist, song->name);
  }

  else printf("song not in library\n"); //if not found

  return song;
}

song_node *find_artist(char a[256]) {
  song_node *list = find_songA(table[a[0]-97],a);
  if (list) { //if the artist is in the library
    while (list) {
      printf("%s - %s ", list->artist, list->name);
      list = find_songA(list->next,a);
      //removes each song after printing
    }
    printf("\n");
  }
  else printf("artist not in libary\n");
  return list;
}

void print_letter( char a ) {
  printf("%c: \n", a);
  print_list(table[a-97]);
}

void print_artist( char a[256] ) {
  song_node *list = table[a[0]-97];
  list = find_songA(list, a);
  while (list) {
    printf("%s - %s ", list->artist, list->name);
    list = find_songA(list->next, a);
  }
  printf("\n");
}

void print_lib() {
  int i = 0;
  while (i < 26) {
    if (table[i])
      print_letter(i+97);
    i++;
  }
}

void shuffle() {
  song_node *n = 0;
  int i = 0;
  while (i < 26) {
    song_node *list = table[i];
    while(list) {
      n = insert_front(n,list->name,list->artist);
      list = list->next;
    }
    i++;
  }
  int j = 8;
  while (j--) {
    song_node *rand = rand_node(n);
    printf("%s - %s\n", rand->artist, rand->name);
    n = remove_node(n, rand->name, rand->artist);
  }
  printf("\n");
}


void delete_song( char n[256], char a[256] ) {
  printf("\ndelete %s \n", n);
  table[a[0]-97] = remove_node(table[a[0]-97], n, a);
  printf( "New libary: \n" );
  print_lib();
}

void delete_lib( ) {
  int i = 0;
  for ( ; i < 26; i++ ) {
    table[i] = free_list( table[i] );
    table[i] = 0;
  }
  print_lib();
  printf("\n");
}
