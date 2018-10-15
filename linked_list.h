#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node * x, char artist[], char song[]);

struct song_node * insert_order(struct song_node * x, char artist[], char song[]);

void print_list(struct song_node * start);

struct song_node * find_song(char artist[], char song[]);

struct song_node * find_first(char artist[]);

struct song_node * get_random(struct song_node * start);

void remove_song(struct song_node * x);

void free_list(struct song_node * first);
