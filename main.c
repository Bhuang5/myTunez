#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "playlist.h"
#include "list.h"

int main() {
  printf("Add song: \n");
  add( "starboy", "the weeknd" );
  add( "closer", "the chainsmokers" );
  add( "let me love you", "dj snake" );
  add( "broccoli", "lil yachty" );
  add( "side to side", "ariana grande" );
  add( "the greatest", "sia");
  add( "cold water", "justin bieber");
  add( "dont let me down", "the chainsmokers");
  add( "into you", "ariana grande" );

  printf("\n\nPrint library: \n");
  print_lib();

/*
  printf("\n\nFind song:\n");
  find_song("starboy");
  find_song("closer");
  find_song("let me love you");
  find_song("abc");
*/

  printf("\n\nFind artist: \n");
  find_artist("the weeknd");
  find_artist("sia");
  find_artist("maroon 5");
  

  printf("\n\nPrint letter: \n");
  print_letter('s');
  print_letter('t');  
  print_letter('z');

  printf("\n\nPrint artist:\n");
  printf("the weeknd: ");
  print_artist("the weeknd");
  printf("lil yachty");
  print_artist("lil yachty");

  printf("\n\nShuffle: \n");
  printf("shuffle...\n");
  shuffle();
  printf("reshuffle...\n");
  shuffle();
  

  printf("\n\nDelete song: \n");
  delete_song("starboy", "the weeknd");
  delete_song("broccoli", "lil yachty");
  delete_song("you was right", "lil uzi vert");

  printf("\n\nDelete libary:\n");
  delete_lib();
  printf("\nprint_lib()\n\n");
  print_lib();
  
  return 0;
}
