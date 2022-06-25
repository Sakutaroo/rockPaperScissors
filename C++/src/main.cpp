#include <iostream>
#include <cstring>
#include "rockpaperscissors.h"

const weapon_t weapon[] = {
    {0, "rock"},
    {1, "paper"},
    {2, "scissors"},
    {3, NULL}
};

static int search_weapon_index(char *buffer)
{
    if (buffer == NULL)
        return 3;
    for (int i = 0; weapon[i].name != NULL; i += 1)
        if (strcmp(buffer, weapon[i].name) == 0)
            return weapon[i].index;
    std::cout << "Invalid weapon\n";
    return 3;
}

static int check_usage(const char *arg)
{
    if (arg == NULL)
        return 1;
    if (strcmp(arg, "-h") == 0) {
        std::cout << "USAGE\n\t./rockPaperScissors\n";
        std::cout << "DESCRIPTION\n\tThis program is a rock paper scissors game.\n";
        return 0;
    } else {
        std::cout << "Arguments error : retry with -h\n";
        return 1;
    }
}

static int check_win(int opt_player, int opt_computer)
{
    if ((opt_player == ROCK && opt_computer == SCISSORS) ||
    (opt_player == PAPER && opt_computer == ROCK) ||
    (opt_player == SCISSORS && opt_computer == PAPER)) {
        std::cout << "You win !\n";
        return 1;
    } else if ((opt_computer == ROCK && opt_player == SCISSORS) ||
    (opt_computer == PAPER && opt_player == ROCK) ||
    (opt_computer == SCISSORS && opt_player == PAPER)) {
        std::cout << "You lose !\n";
        return 1;
    } else {
        std::cout << "It's a draw ! Try again.\n";
        return 0;
    }
}

static int launch_game(void)
{
    int opt_player = 3;
    int opt_computer = 3;
    char buffer[80];

    srand(time(0));
    while (1) {
        std::cout << "Choose your weapon : rock, paper or scissors\n";
        std::cin >> buffer;
        opt_player = search_weapon_index(buffer);
        if (opt_player == 3)
            continue;
        opt_computer = rand() % 3;
        std::cout << "You chose " << weapon[opt_player].name << " and the computer chose " << weapon[opt_computer].name << "\n";
        if (check_win(opt_player, opt_computer) == 1)
            break;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (av == NULL || ac < 1 || ac > 2) {
        std::cout << "Arguments error : retry with -h\n";
        return 1;
    }
    if (ac == 2)
        return check_usage(av[1]);
    else
        return launch_game();
}
