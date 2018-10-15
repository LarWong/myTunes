struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};


//and later:
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct song_node * table[27];
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
  char * holder = malloc(100);
  strcpy(holder, original);
  for(int i = 0; holder[i]; i++){
    holder[i] = tolower(holder[i]);
  }
  return holder;
}

struct song_node * insert_front(struct song_node * p, char name[100], char artist[100]){
  struct song_node * new;
  strcpy(new->name, to_lower(name));
  strcpy(new->artist, to_lower(artist));
  new->next = p;
  return new;
}

struct song_node * insert_order(struct song_node * start, char name[100], char artist[100]){
  struct song_node * new;
  strcpy(new->name, to_lower(name));
  strcpy(new->artist, to_lower(artist));
  while(strcmp(new->name

