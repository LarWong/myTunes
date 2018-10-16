#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node * x, char artist[], char song[]);

struct song_node * insert_order(struct song_node * x, char artist[], char song[]);

void print_list(struct song_node * start);

struct song_node * find_song(struct song_node * x, char artist[], char song[]);

struct song_node * find_first(struct song_node * x, char artist[]);

struct song_node * get_random(struct song_node * start);

void remove_node(struct song_node * x, char artist[], char song[]);

void free_list(struct song_node * first);

#endif
