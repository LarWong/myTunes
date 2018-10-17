#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "linked_list.h"
// ^^delete this after you make the header file
/**
insert nodes at the front
insert nodes in order
alphabetical by Artist then by Song
print the entire list
find and return a pointer to a node based on artist and song name
find and return a pointer to the first song of an artist based on artist name
Return a pointer to random element in the list.
remove a single specified node from the list
free the entire list
**/

char* to_lower(char* original){
  char * holder = (char *)malloc(100);
  strcpy(holder, original);
  for(int i = 0; holder[i]; i++){
    holder[i] = tolower(holder[i]);
  }
  return holder;
}

struct song_node * insert_front(struct song_node * p, char artist[100], char name[100]){
  struct song_node * new;
  strcpy(new->name, to_lower(name));
  strcpy(new->artist, to_lower(artist));
  new->next = p;
  return new;
}

struct song_node * insert_order(struct song_node * start, char artist[100], char name[100]){
  struct song_node * new;
  strcpy(new->name, to_lower(name));
  strcpy(new->artist, to_lower(artist));
  while(strcmp(new->artist, start->artist) > 0){
    start = start->next;
  }
  while(strcmp(new->name, start->name) > 0){
    start = start->next;
  }
  new->next = start->next;
  start->next = new;
  return new;
}

int main(){
  struct song_node * jon = insert_front(NULL, "bambino", "dsong");
  jon = insert_front(jon, "bambino", "asong");
  jon = insert_front(jon, "artist", "asongmysong");
  insert_order(jon, "bambino", "csong");
  while (jon){
    printf("artist: %s song: %s\n", jon->artist, jon->name);
    jon=jon->next;
  }
}

