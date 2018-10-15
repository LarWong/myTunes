#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add_song(struct song_node * song);

struct song_node * search_song(char song[], char artist[]);

struct song_node * search_artist(char artist[]);

void print_letter(char letter);

void print_artist(char artist[]);

void print_lib();

void print_shuffle();

void delete_song(char song[]);

void clear_lib(struct song_node * lib[]);
