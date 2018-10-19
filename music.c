#include "music.h"

int find_index(char c){
  if (isalpha(c)){
    return tolower(c)-'a';
  }else{
    return 26;
  } 
}

void create_lib(struct song_node * table[27]){
    for (int i = 0; i < 27; i++){
        table[i] = NULL;
    } 
}

void add_song(struct song_node * table[], char artist[], char song[]){ 
  printf("Adding: %s | %s:\n",artist,song);
  table[find_index(tolower(artist[0]))] = insert_order(table[find_index(tolower(artist[0]))],artist,song);
  printf("okay %s | %s added!\n\n",artist,song);
}

struct song_node * search_song(struct song_node * table[], char artist[], char song[]){
  printf("Searching for: %s | %s:\n",artist,song);
  struct song_node * position = find_song(table[find_index(tolower(artist[0]))],artist,song);
  if (position){
    print_list(position);
  }
  return position;
}

struct song_node * search_artist(struct song_node * table[], char artist[]){
  printf("Searching for Artist: %s\n",artist);
  struct song_node * position = find_first(table[find_index(tolower(artist[0]))],artist);
  if (position){
    print_list(position);
  }
  return position;
}

void print_letter(struct song_node * table[], char letter){
  printf("%c List:\n",letter);
  print_list(table[find_index(tolower(letter))]);
}

void print_artist(struct song_node * table[], char artist[]){
  printf("Looking for all songs by: %s\n",artist);
  struct song_node * alpha = table[find_index(tolower(artist[0]))];
  if(alpha == NULL) printf("No such artist\n");
  while(alpha){
    if (strcmp(alpha->artist,artist) == 0){
      printf("Artist: %s | Name: %s \n",alpha->artist,alpha->name);
      alpha = alpha->next;
    }
  }
}

void print_lib(struct song_node * table[]){
  printf("Printing lib:\n");
  for (int i = 0; i < 27; i++){
      if (i == 26) {
          printf("Artist starting with: others\n");
      }else{
          printf("Artists starting with letter: %c\n", i + 'a');
      }
      if (!table){
          printf("No Music\n");
          continue;
      }else{
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
    if (*table){
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
  printf("Deleting %s | %s\n",artist,song);
  table[find_index(artist[0])]= remove_node(table[find_index(artist[0])],artist,song);
}

void clear_lib(struct song_node * table[]){
  for (int i = 0; i < 27; i++){
        table[i] = free_list(table[i]);
    } 
}
