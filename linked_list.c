#include "linked_list.h"

char* to_lower(char* original){
  char * holder = (char *)malloc(100);
  strcpy(holder, original);
  for(int i = 0; holder[i]; i++){
    holder[i] = tolower(holder[i]);
  }
  return holder;
}

int songcmp(struct song_node * first, struct song_node * second){
    if (!second){
        return 1;
    }
    if (strcmp(first->artist,second->artist) == 0){
        return strcmp(first->name,second->name);
    }
    return strcmp(first->artist,second->artist);
}

struct song_node * insert_front(struct song_node * x, char artist[], char song[]){
    struct song_node * new_front = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(new_front->artist, to_lower(artist));
    strcpy(new_front->name, to_lower(song));
    new_front->next = x;
    return new_front;
}

struct song_node * insert_order(struct song_node * x, char artist[], char song[]){
    struct song_node * new_node = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(new_node->artist, to_lower(artist));
    strcpy(new_node->name, to_lower(song));

    if (x == NULL || songcmp(new_node,x) < 0){
        return insert_front(x,artist,song);
    }

    struct song_node * holder = x;
    while(x){
        if (!holder->next){
            holder->next = new_node;
            break;
        }
        if (songcmp(new_node,holder->next) < 0){
            new_node->next = holder->next;
            holder->next = new_node;
            break;
        }
        holder = holder->next;
    }
    return x;
}

void print_list(struct song_node * start){
    if (!start){
        printf("No Music Available...\n\n");
        return;
    }
    while(start){
        printf("Artist: %s | Song: %s\n\n",start->artist,start->name);
        start = start->next;
    }
}

struct song_node * find_song(struct song_node * x, char artist[], char song[]){
    while(x){
        if(strcmp(to_lower(artist),x->artist) == 0 && strcmp(to_lower(song),x->name) == 0){
            printf("Found song.\n");
            return x;
        }
        x = x->next;
    }
    printf("No such Song.\n");
    return x;
}

struct song_node * find_first(struct song_node * x, char artist[]){
    while(x && strcmp(x->artist,to_lower(artist)) != 0){
        x = x->next;
    }
    if (!x){
        printf("No such artist.\n");
    }else{
        printf("Found.\n");
    }
    return x;
}

struct song_node * get_random(struct song_node * start){
    int length = 0;
    struct song_node * original = start;
    while(start){
        length++;
        start = start->next;
    } 
    int random_index = rand()%length;
    while(original && random_index > 0){
        random_index--;
        original = original->next;
    }
    return original;
}

struct song_node * remove_node(struct song_node * x, char artist[], char song[]){
    struct song_node * target = (struct song_node *)malloc(sizeof(struct song_node));
    strcpy(target->artist, to_lower(artist));
    strcpy(target->name, to_lower(song));

    struct song_node *holder = x;

    if (songcmp(target,x) == 0){
        x = x->next;
        free(holder);
        free(target);
        return x;
    }

    struct song_node *another_holder = x;

    while(another_holder->next){
        if (songcmp(target,another_holder->next) == 0){
            holder = another_holder->next;
            another_holder->next = another_holder->next->next;
            printf("Found and Removed.\n\n");
            return x;
        }
        another_holder = another_holder->next;
    }
    printf("Not found.\n\n");
    return x;
}

struct song_node * free_list(struct song_node * first){
    while(first != NULL){
        first = remove_node(first,first->artist,first->name);
    }
    return first;
}





