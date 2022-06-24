#include <stdio.h>
#include <string.h>
#include "rockpaperscissors.h"

const weapon_t weapon[] = {
        {0, "rock"},
        {1, "paper"},
        {2, "scissors"},
        {3, NULL}
};

int check_usage(const char *arg)
{
    if (arg == NULL)
        return 1;
    if (strcmp(arg, "-h") == 0) {
        printf("USAGE\n\t./rockPaperScissors\n");
        printf("DESCRIPTION\n\tThis program is a rock paper scissors game.\n");
        return 0;
    }
    return 1;
}

int search_weapon_index(char *buffer)
{
    if (buffer == NULL)
        return 3;
    for (int i = 0; weapon[i].name != NULL; i += 1)
        if (strcmp(buffer, weapon[i].name) == 0)
            return weapon[i].index;
    printf("Invalid weapon\n");
    return 3;
}

char *search_weapon_name(int opt)
{
    for (int i = 0; weapon[i].name != NULL; i += 1)
        if (weapon[i].index == opt)
            return weapon[i].name;
    return NULL;
}
