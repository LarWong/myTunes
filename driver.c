#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#include "music.h"

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
    head = insert_order(head,"cool","rat");
    head = insert_order(head,"cool","rezz");

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

    printf("Removing cool | cat:\n");
    head = remove_node(head,"cool","cat");
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




    return 0;
}
