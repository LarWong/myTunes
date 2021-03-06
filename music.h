#ifndef MUSIC_H
#define MUSIC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include "linked_list.h"

struct song_node * table[27];

void create_lib(struct song_node * table[]);

int find_index(char c);

void add_song(struct song_node * table[], char artist[], char song[]);

struct song_node * search_song(struct song_node * table[], char song[], char artist[]);

struct song_node * search_artist(struct song_node * table[], char artist[]);

void print_letter(struct song_node * table[], char letter);

void print_artist(struct song_node * table[], char artist[]);

void print_lib(struct song_node * table[]);

void print_shuffle(struct song_node * table[]);

void delete_song(struct song_node * table[], char artist[], char song[]);

void clear_lib(struct song_node * table[]);

#endif
