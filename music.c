#include "music.h"


struct song_node * find_index(struct song_node * table[], char c){
  struct song_node * alpha;
  if (isalpha(c)){
      if (!table[tolower(c)-'a']){
          table[tolower(c)-'a'] = malloc(sizeof(100*sizeof(struct song_node)));
      }
    alpha = table[tolower(c)-'a'];
  }else{
      if (!table[26]){
          table[26] = malloc(sizeof(100*sizeof(struct song_node)));
      }
    alpha = table[26];
  } 
  return alpha;
}

void add_song(struct song_node * table[], char artist[], char song[]){ 
  printf("Adding: %s | %s:\n",artist,song);
  insert_order(find_index(table,artist[0]),artist,song);
    printf("okay %s | %s added!\n\n",artist,song);
}

struct song_node * search_song(struct song_node * table[], char song[], char artist[]){
  printf("Searching for: %s | %s:\n",artist,song);
  struct song_node * position = find_song(find_index(table,artist[0]),artist,song);
  if (position){
    printf("Found: %s | %s\n",position->artist,position->name);
  }else{
    printf("Not Found.\n");
  }
  return position;
}

struct song_node * search_artist(struct song_node * table[], char artist[]){
  printf("Searching for Artist: %s\n",artist);
  struct song_node * position = find_first(find_index(table,artist[0]),artist);
  if (position){
    printf("Found Artist.\n");
  }else{
    printf("No Such Artist.\n");
  }
  return position;
}

void print_letter(struct song_node * table[], char letter){
  printf("%c List:\n",letter);
  print_list(find_index(table,letter));
}

void print_artist(struct song_node * table[], char artist[]){
  struct song_node * alpha = find_index(table,artist[0]);
  while(alpha){
    if (strcmp(alpha->artist,artist)){
      printf("Artist: %s | Name: %s \n",alpha->artist,alpha->name);
      alpha = alpha->next;
    }
  }
}

void print_lib(struct song_node * table[]){
  printf("Printing lib:\n");
  for (int i = 0; i < 27; i++){
      if (*table){
          printf("Artists starting with letter: %c\n", i + 'a');
          print_list(*table);
          printf("\n");
      }
    table++;
  }
}

void print_shuffle(struct song_node * table[]){
  int num_songs = 10;
  struct song_node ** original = table;
  printf("Shuffled List:");
  while(num_songs > 0){
    if (table){
       struct song_node * random_song = get_random(*table);
       printf("Artist: %s | Name: %s\n",random_song->artist,random_song->name);
       table++;
       num_songs--;
    }else{
      table = original; 
    }
  }
}

void delete_song(struct song_node * table[], char artist[], char song[]){
  remove_node(find_index(table,artist[0]),artist,song);
}

void clear_lib(struct song_node * table[]){
  while(table){
    free_list(*table);
    table++;
  }
}
