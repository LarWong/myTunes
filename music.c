#include "music.h"

struct song_node * table[27];

void add_song(struct song_node * table[], char artist[], char song[]){ 
  struct song_node * alpha;
  if (isalpha(artist[0])){
    alpha = table[tolower(artist[0])-'a'];
  }else{
    alpha = table[26];
  }
  printf("Adding: %s | %s:\n",artist,song);
  insert_order(alpha,artist,song);
}

struct song_node * search_song(struct song_node * table[], char song[], char artist[]){
  struct song_node * alpha;
  if (isalpha(artist[0])){
    alpha = table[tolower(artist[0])-'a'];
  }else{
    alpha = table[26];
  }
  printf("Searching for: %s | %s:\n",artist,song);
  struct song_node * position = find_song(alpha,artist,song);
  if (position){
    print_list(position);
  }
}

struct song_node * search_artist(struct song_node * table[], char artist[]){
  struct song_node * alpha;
  if (isalpha(artist[0])){
    alpha = table[tolower(artist[0])-'a'];
  }else{
    alpha = table[26];
  }
  return find_first(alpha,artist);
}

void print_letter(struct song_node * table[], char letter){
  struct song_node * alpha;
  if (isalpha(artist[0])){
    alpha = table[tolower(artist[0])-'a'];
  }else{
    alpha = table[26];
  }
  printf("%c List:",letter);
  print_list(alpha);
}

void print_artist(struct song_node * table[], char artist[]){
  struct song_node * alpha;
  if (isalpha(artist[0])){
    alpha = table[tolower(artist[0])-'a'];
  }else{
    alpha = table[26];
  }
  while(alpha){
    if (strcmp(alpha->artist,artist)){
      printf("Artist: %s | Name: %s \n",alpha->artist,alpha->name);
      alpha = alpha->next;
    }
  }

}

void print_lib(struct song_node * table[]){
  while(table){
    struct song_node * letter = *table;
    while(letter){
      printf("Artist: %s | Name: %s\n",letter->artist,letter->name);
      letter = letter->next;
    }
    table++;
  }
}

void print_shuffle(struct song_node * table[]){
  srand( time(NULL) );
  int num_songs = rand()%27;
  while(table && num_songs > 0){
    struct song_node * random_song = get_random(*table);
    printf("Artist: %s | Name: %s\n",random_song->artist,random_song->name);
    table++;
    num_songs--;
  }

}

void delete_song(struct song_node * table[], char artist[], char song[]){
  struct song_node * alpha;
  if (isalpha(artist[0])){
    alpha = table[tolower(artist[0])-'a'];
  }else{
    alpha = table[26];
  }
  remove_node(alpha,artist,song);
}

void clear_lib(struct song_node * table[]){
  while(table){
    free_list(*table);
  }
}
