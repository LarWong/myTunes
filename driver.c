#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "linked_list.h"
#include "music.h"


char * helper(char * end){
    char src = "abcdefghijklmnopqrstuvwxyz"[rand()%26];
    char * holder = malloc(100);
    holder[0] = src;
    holder[1] = 0;
    strcat(holder, end);
    return holder;
}

int main(){
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
    for (int i = 0; i < 10; i++){
        add_song(table, helper("ool"), helper("song"));
    }
    
    add_song(table, "alan", "the jon song");
    // add_song(table, "alan", "ssfa sssss jon song");
    //add_song(table, "boo", "also jon the song");
    //add_song(table, "bwser", "maybe jon da song");
    //add_song(table, "dog", "the jo");
 
    printf("testing find index\n");
    struct song_node * hello = find_index(table, 'a');
    printf("%p\n", hello->next);
    //print_list(hello);
    print_node(hello);

    printf("\n");
    
    print_lib(table);
    printf("\ndone\n");

    

    return 0;
}
