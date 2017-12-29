package com.company;
import java.util.Scanner;
/**
 * Created by rizza15 on 11/12/2015.
 */
public class Board {

//  resets the board to zero
    public static int[][] resetBoard()
    {
        int numRows = 6;
        int numColumns = 7;
        int i;
        int j;
        int[][] slot = new int[6][7];
        for (i =0; i < numRows; ++i)
        {
            for (j = 0; j < numColumns; ++j)
            {
                slot[i][j] = 0;
            }
        }
        return slot;
    }

    // player chooses row, and the respective coin is place into the board/array.
    public static void insertChip(int[][] slot,String playername, int team) {
        Scanner scnr = new Scanner(System.in);
        int tempCol;
        int tempRow = 0;
            System.out.println(playername + " Type the number of the column would you like to drop your chip in: ");
            tempCol = scnr.nextInt();
            while ((tempRow <= 5)&&(slot[tempRow][tempCol] != 0)) {
                ++tempRow;
            }
            if (team == 1) {
                slot[tempRow][tempCol] = 1;
            }
            else
            {
                slot[tempRow][tempCol] = 2;
            }
            System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            displayBoard(slot);
            return;

    }
// checks for 4 in a row in the horizontal
    public static int checkForHorizontal (int[][] slot)
    {
        int i;
        int j;

        for (i=0; i < 5; i++)
        {
            //j is shifting horizontal base
            for (j = 0; j < 4; j++) {
                int v = slot[i][j];
                //temp checking for 4 in a row
                int sames = 0;
                for (int k = 0; (k <= 3);k++)
                {
                    if ((slot[i][j + k] != 0) && (slot[i][j + k] == v)) {
                        sames++;
                        if (sames == 4) {
                            System.out.println("Player wins");
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
// checks for 4 in a row in the vertical

    public static int checkForVertical(int[][] slot)
    {
        int i;
        int j;

        // diagonally left to right rows from row 2 to 0
        for (j=0; j < 6; j++)
        {
            for (i = 0; i < 3; i++) {
                int v = slot[i][j];
                //temp checking for 4 in a row
                int sames = 0;
                for (int k = 0; (k <= 3);k++)
                {
                    if ((slot[i + k][j] != 0) && (slot[i + k][j] == v)) {
                        sames++;
                        if (sames == 4) {
                            System.out.println("Player wins");
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }

// diagonally from right to left from row 2 to 0
    public static int checkForDiagonal(int[][]slot)
    {
    int i;
    int j;

    for (i=2; i >= 0; i--)
    {
        for (j = 0; j <= 2 - i  ; j++) {
            int v = slot[i + (j)][j];
            int sames = 0;
            for (int k = 0; (k <= 3);k++)
            {
                if ((slot[i + k][j + k] != 0) && (slot[i + k][j + k] == v)) {
                    sames++;
                    if (sames == 4) {
                        System.out.println("Player wins");
                        return 1;
                    }
                }
            }
        }
    }

// diagonally from left to right column from 1 - 3
        for (j = 1; j <= 3 ; j++)
        {
            for (i = 0; i <=  2 - i  ; i++) {
                int v = slot[i + (2 - i)][j + i];
                int sames = 0;
                for (int k = 0; (k <= 3);k++)
                {
                    if ((slot[i + k][j + k] != 0) && (slot[i + k][j + k] == v)) {
                        sames++;
                        if (sames == 4) {
                            System.out.println("Player wins");
                            return 1;
                        }
                    }
                }
            }
        }

        // diagonally from right to left from row 2 to 0
        for (i=2; i >= 0; i--)
        {
            for (j = 6; j >= i + 4 ; j--) {
                int x = 0;
                int v = slot[i + x][j - (2 - i)];
                int sames = 0;
                for (int k = 0; (k <= 3);k++)
                {
                    if ((slot[i + k][j - k] != 0) && (slot[i + k][j - k] == v)) {
                        sames++;
                        if (sames == 4) {
                            System.out.println("Player wins");
                            return 1;

                        }
                    }
                    x++;
                }
            }
        }


        // diagonally from right to left column from 0 - 3
        for (j = 5; j >= 3 ; j--)
        {
            for (i = 0; i >=  j - 3 ; i--) {
                int x = 2;
                int v = slot[i + ( j -3)][j];
                int sames = 0;
                for (int k = 0; (k <= 3);k++)
                {
                    if ((slot[i + k][j - k] != 0) && (slot[i + k][j - k] == v)) {
                        sames++;
                        if (sames == 4) {
                            System.out.println("Player wins");
                            return 1;
                        }
                    }
                }
                x--;
            }
        }

        return 0;

    }
// calls all checking methods
    public static int checkAll(int[][]slot)
    {
       if (checkForHorizontal(slot) == 1 )
       {
           return 1;
       }
        else if (checkForVertical(slot) == 1)
       {
           return 1;
       }
        else if (checkForDiagonal(slot) == 1)
        {
        return 1;
        }
        else {
           return 0;
       }
    }



// prints the board/apparatus
    public static void displayBoard(int[][] slot)
    {
        System.out.println("Row:-----------------------------------------------------------------------");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("5   |    " + slot[5][0] +"    |    " + slot[5][1] +"    |    " + slot[5][2] +"    |" +
                "    " + slot[5][3] +"    |    " + slot[5][4] +"    |    " + slot[5][5] +"    |    " + slot[5][6] + "    |");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("    -----------------------------------------------------------------------");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("4   |    " + slot[4][0] +"    |    " + slot[4][1] +"    |    " + slot[4][2] +"    |" +
                "    " + slot[4][3] +"    |    " + slot[4][4] +"    |    " + slot[4][5] +"    |    " + slot[4][6] + "    |");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("    -----------------------------------------------------------------------");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("3   |    " + slot[3][0] +"    |    " + slot[3][1] +"    |    " + slot[3][2] +"    |" +
                "    " + slot[3][3] +"    |    " + slot[3][4] +"    |    " + slot[3][5] +"    |    " + slot[3][6] + "    |");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("    -----------------------------------------------------------------------");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("2   |    " + slot[2][0] +"    |    " + slot[2][1] +"    |    " + slot[2][2] +"    |" +
                "    " + slot[2][3] +"    |    " + slot[2][4] +"    |    " + slot[2][5] +"    |    " + slot[2][6] + "    |");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("    -----------------------------------------------------------------------");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("1   |    " + slot[1][0] +"    |    " + slot[1][1] +"    |    " + slot[1][2] +"    |" +
                "    " + slot[1][3] +"    |    " + slot[1][4] +"    |    " + slot[1][5] +"    |    " + slot[1][6] + "    |");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("    -----------------------------------------------------------------------");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("0   |    " + slot[0][0] +"    |    " + slot[0][1] +"    |    " + slot[0][2] +"    |" +
                "    " + slot[0][3] +"    |    " + slot[0][4] +"    |    " + slot[0][5] +"    |    " + slot[0][6] + "    |");
        System.out.println("    |         |         |         |         |         |         |         |");
        System.out.println("    -----------------------------------------------------------------------");
        System.out.println("Column:  0         1         2         3         4         5         6");

        return;
    }
}
