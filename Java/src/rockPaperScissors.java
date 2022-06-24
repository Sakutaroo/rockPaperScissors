import java.util.Scanner;
import java.util.Random;
import java.util.ArrayList;
import java.util.List;

public class rockPaperScissors {
    public static int display_usage(String[] args) {
        if (args[0].equals("-h")) {
            System.out.println("USAGE\n\tjava rockPaperScissors");
            System.out.println("DESCRIPTION\n\tThis program is a rock paper scissors game.");
            return 0;
        }
        else {
            System.out.println("Arguments error : retry with -h");
            return 1;
        }
    }
    public static boolean verify_opt(String opt_player) {
        if (opt_player.equals("rock") == true || opt_player.equals("paper") == true || opt_player.equals("scissors") == true)
            return true;
        else
            return false;
    }
    public static boolean check_win(String opt_player, String opt_computer) {
        if ((opt_player.equals("rock") == true && opt_computer.equals("scissors") == true)
        || (opt_player.equals("paper") == true && opt_computer.equals("rock") == true)
        || (opt_player.equals("scissors") == true && opt_computer.equals("paper") == true)) {
            System.out.println("You win !");
            return true;
        } else if ((opt_computer.equals("rock") == true && opt_player.equals("scissors") == true)
        || (opt_computer.equals("paper") == true && opt_player.equals("rock") == true)
        || (opt_computer.equals("scissors") == true && opt_player.equals("paper") == true)) {
            System.out.println("You lose !");
            return true;
        } else {
            System.out.println("It's a draw ! Try again.");
            return false;
        }
    }
    public static int launch_game() {
        Scanner opt = new Scanner(System.in);
        String opt_player = "";
        String opt_computer = "";
        Random random = new Random();
        List<String> weapon = new ArrayList<String>();
        weapon.add("rock");
        weapon.add("paper");
        weapon.add("scissors");
        while (true) {
            System.out.println("Choose your weapon : rock, paper or scissors");
            opt_player = opt.nextLine();
            if (verify_opt(opt_player) == false) {
                System.out.println("Error : invalid option");
                continue;
            }
            opt_computer = weapon.get(random.nextInt(weapon.size()));
            System.out.println("You chose " + opt_player + " and the computer chose " + opt_computer);
            if (check_win(opt_player, opt_computer) == true)
                break;
        }
        return 0;
    }
    public static void main (String[] args) {
        int count = args.length;
        if (count < 0 || count > 1) {
            System.out.println("Arguments error : retry with -h");
            System.exit(1);
        }
        if (count == 1)
            System.exit(display_usage(args));
        else {
            System.exit(launch_game());
        }
    }
}
