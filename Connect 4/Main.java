package com.company;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scnr = new Scanner(System.in);
        String player1Name;
        String player2Name;
        boolean keepPlaying = true;
        int player1Wins = 0;
        int player2Wins = 0;

        //welcomes player, gets names.
        System.out.println("Welcome to Connect Four!\n\nPlayer 1, enter your name: ");
        player1Name = scnr.nextLine();
        System.out.println("Player 2, please enter your name:  ");
        player2Name = scnr.nextLine();

        ConnectFour game = new ConnectFour(player1Name,player2Name);

        // calls the playgame method, and gets a winner from there.
        // then declares who won each round, keeping tally.
        while (keepPlaying)
        {
            int x = game.playGame();
            if (x == 1)
            {
                player1Wins++;
            }
            if (x ==2)
            {
                player2Wins++;
            }
            System.out.println("Would you like to play another round? Type \"yes\" or \"no\":");
            String f = scnr.nextLine();
            if (!(f.equals("yes")));
            {
                keepPlaying = false;
            }
        }
//prints out both players scores and then declares a winner.

        System.out.println("" + player1Name + "\'s score:        " + player2Name+ "\'s score:");
        System.out.println("\n\n    " + player1Wins + "                      " + player2Wins);
        System.out.println("\n\n ");

        if (player1Wins > player2Wins)
        {
            System.out.println("\n" + player1Name + " has won the most rounds, and thus is the champion!");
        }
        else if (player2Wins > player1Wins)
        {
            System.out.println("\n" + player2Name + " has won the most rounds, and thus is the champion!");
        }
        else if (player1Wins == player2Wins)
        {
            System.out.println(player1Name + " and " + player2Name + " have won the same amount of rounds, thus there is no champion");
        }

    }
}
