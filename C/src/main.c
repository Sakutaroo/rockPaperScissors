#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rockpaperscissors.h"

static int check_win(int opt_player, int opt_computer)
{
    if ((opt_player == ROCK && opt_computer == SCISSORS) ||
    (opt_player == PAPER && opt_computer == ROCK) ||
    (opt_player == SCISSORS && opt_computer == PAPER)) {
        printf("You win !\n");
        return 1;
    } else if ((opt_computer == ROCK && opt_player == SCISSORS) ||
    (opt_computer == PAPER && opt_player == ROCK) ||
    (opt_computer == SCISSORS && opt_player == PAPER)) {
        printf("You lose !\n");
        return 1;
    } else {
        printf("It's a draw ! Try again.\n");
        return 0;
    }
}

static int launch_game(void)
{
    int opt_player = 3;
    int opt_computer = 3;
    char buffer[80];

    srand(time(NULL));
    while (1) {
        printf("Choose your weapon : rock, paper or scissors\n");
        scanf("%s", buffer);
        opt_player = search_weapon_index(buffer);
        if (opt_player == 3)
            continue;
        opt_computer = rand() % 3;
        printf("You chose %s and the computer chose %s\n",
        buffer, search_weapon_name(opt_computer));
        if (check_win(opt_player, opt_computer) == 1)
            break;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (av == NULL || ac < 1 || ac > 2) {
        printf("Arguments error : retry with -h\n");
        return 1;
    }
    if (ac == 2)
        return check_usage(av[1]);
    else
        return launch_game();
}
