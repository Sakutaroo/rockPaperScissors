#ifndef ROCKPAPERSCISSORS_H_
    #define ROCKPAPERSCISSORS_H_
    #define ROCK 0
    #define PAPER 1
    #define SCISSORS 2

typedef struct weapon_s {
    int index;
    char *name;
} weapon_t;

char *search_weapon_name(int opt);
int search_weapon_index(char *buffer);
int check_usage(const char *arg);

#endif
