package com.company;
import java.util.Scanner;

/**
 * Created by rizza15 on 11/12/2015.
 */
public class ConnectFour {

    public ConnectFour(String name1, String name2)
    {
        player1Name = name1;
        player2Name = name2;
    }
//plays game, clearing board, allowing players to insert coins, then checking for win, returning a 1 or 2 depending on win.  0 for ties.
       public int playGame()
    {
        Board board = new Board();
        int[][] slot = board.resetBoard();
        board.displayBoard(slot);
        Scanner scnr = new Scanner(System.in);

        while(keepInserting) {
            board.insertChip(slot, player1Name, 1);
            if (board.checkAll(slot) == 1)
            {
                System.out.println("Congratulations " + player1Name + " you have won this round");
                return 1;
            }

            board.insertChip(slot, player2Name, 2);
            if (board.checkAll(slot) == 2)
            {
                System.out.println("Congratulations " + player2Name + " you have won this round");
                return 2;
            }


        }
        return 0;
    }




private String player1Name;
private String player2Name;
private int player1Wins = 0;
private int player2Wins = 0;
private Board b;
private boolean keepInserting = true;


}
