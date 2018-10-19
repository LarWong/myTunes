#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "linked_list.h"
#include "music.h"

int main(){
   printf("Testing linked_list:\n");
   struct song_node * head = NULL;
   printf("Adding to the Front:\n");
   head = insert_front(head,"cool","cat");
   head = insert_front(head,"bool","bat");
   head = insert_front(head,"aool","aat");
   print_list(head);

   printf("Adding in order:\n");
   head = insert_order(head,"zool","zat");
   head = insert_order(head,"fool","fat");
   head = insert_order(head,"xool","xat");

   head = insert_order(head,"cool","zat");
   head = insert_order(head,"Cool","Rat");
   head = insert_order(head,"Cool","Cezz");

   head = insert_order(head,"xool","asa");
   head = insert_order(head,"xool","treww");
   print_list(head);

   printf("(Helper)Comparing %s | %s with %s | %s:\n",head->artist,head->name,head->artist,head->name);
   printf("%d\n",songcmp(head,head));
    
   printf("(Helper)Comparing %s | %s with %s | %s:\n",head->next->artist,head->next->name,head->artist,head->name);
   printf("%d\n",songcmp(head->next,head));
    
   printf("(Helper)Comparing %s | %s with %s | %s:\n",head->artist,head->name,head->next->artist,head->next->name);
   printf("%d\n",songcmp(head,head->next));   
    
   printf("Looking for cool | rat:\n");
   struct song_node * my_song = find_song(head,"cool","rat");
   printf("%s | %s\n",my_song->artist,my_song->name);
    
   printf("Looking for pool | pat:\n");
   my_song = find_song(head,"pool","pat");
    
   printf("Looking for artist: cool:\n");
   struct song_node * my_artist = find_first(head,"cool");
   print_list(my_artist);
   
   printf("Looking for artizt zoom:\n");
   my_artist = find_first(head,"zoom");
   print_list(my_artist);

   printf("Getting Random Song:\n");
   struct song_node *rando = get_random(head);
   printf("%s | %s\n",rando->artist,rando->name);

   printf("Getting Random Song:\n");
   rando = get_random(head);
   printf("%s | %s\n",rando->artist,rando->name);

   printf("Removing Cool | Cat:\n");
   head = remove_node(head,"Cool","Cat");
   print_list(head);
    
   printf("Removing cool | rat:\n");
   head = remove_node(head,"cool","rat");
   print_list(head);

   printf("Removing zzz | z:\n");
   head = remove_node(head,"zzz","z");
   print_list(head);

   printf("Freeing List:\n");
   head = free_list(head);
   print_list(head);

   printf("\n\n\n\n");
   srand(time(NULL));
   printf("testing for music.c\n");
   printf("Creating music library:\n");
   create_lib(table); 

   printf("\n(Helper)Finding index to: c \n Index: %d\n",find_index('c'));
   printf("(Helper)Finding index to e \n Index: %d\n",find_index('e'));
   printf("(Helper)Finding index to: x \n Index: %d\n",find_index('x'));

   printf("Adding songs:\n");
   add_song(table, "cog", "the jo");
   add_song(table, "alan", "a song");
   add_song(table, "zlan", "ong");
   add_song(table, "zlan", "aoong");
   add_song(table, "zlan", "sfa sssss jon song");
   add_song(table, "al", "on song");
   add_song(table, "xan", "sog");
   add_song(table, "need", "ssssosng");
   add_song(table, "alan", "jon");
   add_song(table, "az", "jazz");
   add_song(table, "az", "pop");
   add_song(table, "xlan", "pop");
   add_song(table, "zlan", "fic");
   add_song(table, "slan", "ssfa");
   add_song(table, "alan", "sssss jon");
   add_song(table, "boo", "also jon the song");
   add_song(table, "bwser", "maybe jon da song");
   add_song(table, "dog", "the jo");
   add_song(table, "dog", "rock");
   add_song(table, "dog", "dj");
   add_song(table, "dog", "cat");

   print_lib(table);
   
   printf("Printing all songs by letter:\n");
   print_letter(table,'a');
   print_letter(table,'y');


   printf("Find and print out list:\n");
   search_song(table,"alan","a jon song");
   
   search_song(table,"fresh","beats");
   
   printf("\n\nSearching for First occurance of an artist:\n");
   search_artist(table,"dog");
   search_artist(table,"cat");
   
   printf("\n\nSearching for all songs by an artist:\n");
   print_artist(table,"zlan");
   print_artist(table,"karp");
   
   printf("\n\nPrinting out Shuffled List:\n");
   print_shuffle(table);

   printf("\n\nPrinting out another Shuffled List:\n");
   print_shuffle(table);

   printf("Deleting Songs:\n");
   printf("\nBefore:\n");
   print_letter(table,'a');
   delete_song(table, "alan", "a song");
   printf("After:\n");
   print_letter(table,'z');

   printf("\nBefore:\n");
   print_letter(table,'z');
   delete_song(table, "zoom", "z zong");
   printf("After:\n");
   print_letter(table,'z');

   printf("\nClearing Library...\n\n\n");
   clear_lib(table);
   printf("Now Printing Library:\n");
   print_lib(table);


   return 0;
}

