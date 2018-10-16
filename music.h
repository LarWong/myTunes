#include "linked_list.h"

void add_song(struct song_node * table[], struct song_node * song);

struct song_node * search_song(struct song_node * table[], char song[], char artist[]);

struct song_node * search_artist(struct song_node * table[], char artist[]);

void print_letter(struct song_node * table[], char letter);

void print_artist(struct song_node * table[], char artist[]);

void print_lib(struct song_node * table[]);

void print_shuffle(struct song_node * table[]);

void delete_song(struct song_node * table, char song[]);

void clear_lib(struct song_node * table[]);
