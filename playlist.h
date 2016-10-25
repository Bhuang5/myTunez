#include <stdio.h>
#include <stdlib.h>

#include "list.h"

song_node *table[26];

void add( char n[256], char a[256] );

song_node *find_song( char n[256] );

song_node *find_artist( char a[256] );

void print_letter( char a );

void print_artist( char a[256] );

void print_lib( );

void shuffle( );

void delete_song( char n[256], char a[256] );

void delete_lib( );
