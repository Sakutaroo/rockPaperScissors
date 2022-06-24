from random import choice

def verify_opt(opt_player):
    if opt_player == "rock" or opt_player == "paper" or opt_player == "scissors":
        return True
    else:
        return False


def check_win(opt_player, opt_computer):
    if (opt_player == "rock" and opt_computer == "scissors") or (opt_player == "paper" and opt_computer == "rock") or (opt_player == "scissors" and opt_computer == "paper"):
        print("You win !")
        return True
    elif (opt_computer == "rock" and opt_player == "scissors") or (opt_computer == "paper" and opt_player == "rock") or (opt_computer == "scissors" and opt_player == "paper"):
        print("You lose !")
        return True
    else:
        print("It's a draw ! Try again.")
        return False


def launch_game():
    while 1:
        opt_player = input("Choose your weapon : rock, paper or scissors\n")
        if not verify_opt(opt_player):
            print("Error : invalid option")
            continue
        opt_computer = choice(["rock", "paper", "scissors"])
        print(f"You chose {opt_player} and the computer chose {opt_computer}")
        if check_win(opt_player, opt_computer):
            break
    return 0
