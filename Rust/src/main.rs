use std::env;
use std::io::stdin;
use rand::Rng;

fn verify_usage(args: Vec<String>) {
    let arg = &args[1];
    if arg.eq("help") == true {
        println!("USAGE\n\tcargo run");
        println!("DESCRIPTION\n\tThis program is a rock paper scissors game.");
    } else {
        println!("Arguments error : retry with help");
    }
    return;
}

fn verify_weapon(opt_player: &String) -> i32 {
    if (opt_player == "rock") || (opt_player == "paper") || (opt_player == "scissors") {
        return 1;
    } else {
        return 0;
    }
}

fn check_weapon(nb: u8) -> String {
    match nb {
        0 => return "rock".to_string(),
        1 => return "paper".to_string(),
        2 => return "scissors".to_string(),
        _ => return "error".to_string(),
    }
}

fn check_win(opt_player: String, opt_computer: String) -> i32 {
    if (opt_player == "rock" && opt_computer == "scissors") ||
    (opt_player == "paper" && opt_computer == "rock") ||
    (opt_player == "scissors" && opt_computer == "paper") {
        println!("You win !");
        return 1;
    } else if (opt_computer == "rock" && opt_player == "scissors") ||
    (opt_computer == "paper" && opt_player == "rock") ||
    (opt_computer == "scissors" && opt_player == "paper") {
        println!("You lose !");
        return 1;
    } else {
        println!("It's a draw ! Try again.");
        return 0;
    }
}

fn launch_game() {
    let mut opt_computer;
    let mut rng = rand::thread_rng();
    let mut weapon: u8;
    loop {
        let mut opt_player = String::new();
        println!("Choose your weapon : rock, paper or scissors");
        match stdin().read_line(&mut opt_player) {
            Err(e) => println!("{:?}", e),
            _ => ()
        }
        opt_player.remove(opt_player.len() - 1);
        if verify_weapon(&opt_player) == 0 {
            println!("Error : invalid option");
            continue;
        }
        weapon = rng.gen_range(0..3);
        opt_computer = check_weapon(weapon);
        println!("You chose {} and the computer chose {}", opt_player, opt_computer);
        if check_win(opt_player, opt_computer) == 1 {
            break;
        }
    }
    return;
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 1 || args.len() > 2 {
        println!("Arguments error : retry with help");
        return;
    }
    if args.len() == 2 {
        return verify_usage(args);
    } else {
        return launch_game();
    }
}
