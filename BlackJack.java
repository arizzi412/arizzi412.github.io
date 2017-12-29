package com.company;
import java.util.Scanner;
import java.util.Random;

public class Main {


    public static int playGame(String playerName, String [] cardName, int [] cardValue)
    {
        int i;
        boolean keepDrawing = true;
        int playerNum = 0;
        int dealerNum = 5;

            int dealerScore = 0;
            int playerScore = 0;

            // the following 2 numbers are used as indexes of cardValue/cardName.
            // indexes from 0 to 4 are the players cards. from 5 to 9 are dealer cards

            playerNum = 0;
            dealerNum = 5;

            //deck is shuffled
            shuffleDeck(cardValue, cardName);

            playerNum++;

            dealerNum++;

            System.out.println(playerName + ", your cards are: \n" + cardName[0] + " \n" + cardName[1] + "\n");
            System.out.println("Dealers cards:\n * \n " + cardName[6] + "\n");

            dealerScore = cardValue[5] +cardValue[6];
            playerScore = cardValue[0] + cardValue[1];

            System.out.println("Your total score is : " + playerScore);


            //prompts the player to get a card or not.  If the player's score goes over 21 then they have lost the round.
            Scanner scnr = new Scanner(System.in);
            while ((keepDrawing)&&(playerNum <=4))
            {
                System.out.println("Aces will be evaluated after you stop drawing additional cards.\n");
                System.out.println("Would you like to draw another card?");
                String yes = scnr.nextLine();
                if (yes.equals("yes")) {
                    playerNum++;
                    System.out.println("You have drawn:  \n" + cardName[playerNum] + "\n");
                    System.out.println("Your current cards are: ");
                    for (i=0; i<=playerNum; ++i)
                    {
                        System.out.println(cardName[i] + " ");
                        continue;
                    }
                    playerScore = playerScore + cardValue[playerNum];
                    System.out.println("\nYour total score is " + playerScore);
                    if (playerScore > 21) {
                        System.out.println("\nYou have gone over 21, therefore you have lost.");
                        break;
                    }
                }
                else {
                    break;
                }
            }
            //this for loop checks for aces and essentially gives them a value of 1 or 11
            for (i=0; i < 5; ++i)
            {
                if (cardValue[i] == 1)
                {
                    if (playerScore <= 11)
                    {
                        playerScore = playerScore + 10;
                        System.out.println("The final score of the player (accounting for aces) is: " + playerScore);
                    }
                }
            }

            // this loop keeps giving the dealer cards while the score is less than 17.

            while ((dealerScore < 17) && !(playerScore > 21)&& (dealerNum<=9))
            {
                dealerNum++;
                System.out.println("Dealer draws: \n" + cardName[dealerNum] + "\n");
                System.out.println("The Dealer's current cards are: ");
                for (i=5; i<=dealerNum; ++i)
                {
                    System.out.println(cardName[i] + " ");
                }
                dealerScore = dealerScore + cardValue[dealerNum];
                System.out.println("\nThe Dealer's current score: " + dealerScore + "\n");
            }
            //same as before.  checks for aces and assigns proper value to them.
            for (i=5; i < 10; ++i)
            {
                if (cardValue[i] == 1)
                {
                    if (dealerScore <= 11)
                    {
                        dealerScore = dealerScore + 10;
                        System.out.println("The final score of the player (accounting for aces) is: " + dealerScore);
                    }
                }
            }
            //the following are victory conditions for the round. Player can win, lose, or tie a round
            if ((dealerScore >= playerScore) && !(dealerScore > 21)|| (playerScore > 21))
            {
                System.out.println("The Dealer's current cards are: ");
                for (i=5; i<=dealerNum; ++i)
                {
                    System.out.println(cardName[i] + " ");
                }
                System.out.println("\nThe dealer's score is: "+ dealerScore);
                System.out.println("\nThe dealer has won this round");
                return 0;
            }

            else if (((playerScore > dealerScore) && !(playerScore > 21)) || (dealerScore > 21))
            {
                System.out.println("The Dealer's current cards are: ");
                for (i=5; i<=dealerNum; ++i)
                {
                    System.out.println(cardName[i] + " ");
                }
                System.out.println("\nThe dealer's score is: "+ dealerScore);
                System.out.println("\n" + playerName + " has won this round!");
                return 1;
            }
        //this last return statement should never actually be reached, so it is set to 100000
        // so I know if something goes wrong
        return 100000;
    }

    // this method shuffles the deck.  Essentially swapping each index with another random index.
    public static void shuffleDeck(int[] cardValue, String[] cardName) {
        Random randGen = new Random();
        for (int i = 51; i >= 0; --i) {
            int index = randGen.nextInt(i + 1);

            int temp = cardValue[i];
            cardValue[i] = cardValue[index];
            cardValue[index] = temp;

            String tempstring = cardName[i];
            cardName[i] = cardName[index];
            cardName[index] = tempstring;
        }
    }

    public static void announceOverallWinner(String playerName, int playerWonrounds, int dealerWonrounds)

    {
        //this prints the final number of rounds won for each player at the end of the day and declares an overall winner (or tie).
        System.out.println("\n\nRounds Won: \n \nDealer: " + dealerWonrounds + "\n\n" + playerName+  ": " + playerWonrounds + "\n\n");
        if (dealerWonrounds > playerWonrounds)
        {
            System.out.println("\nThe dealer has won the most rounds, and thus is the champion!");
        }
        else if (playerWonrounds > dealerWonrounds)
        {
            System.out.println("\n" + playerName + " has won the most rounds, and thus is the champion!");
        }
        else if (playerWonrounds == dealerWonrounds)
        {
            System.out.println(playerName + " and the dealer have won the same amount of rounds, thus there is no champion");
        }
    }

    public static void main(String[] args) {
        int playerWonrounds = 0;
        int dealerWonrounds = 0;
        boolean keepPlaying = true;

        Random ranGen = new Random();


        Scanner scnr = new Scanner(System.in);
        //Random ranGen = new Random();

        String playerName = "";
        System.out.println("Player please enter your name: ");
        playerName = scnr.nextLine();

        System.out.println("Welcome to Blackjack " + playerName + "!");

        // the array cardName stores the strings of the cards.  The array cardValue corresponds to the point value of the card at the corresponding string.
        String[] cardName = {"Ace Spades", "2 Spades", "3 Spades", "4 Spades", "5 Spades", "6 Spades", "7 Spades", "8 Spades", "9 Spades", "10 Spades", "Jack Spades", "Queen Spades", "King Spades",
                "Ace Hearts", "2 Hearts", "3 Hearts", "4 Hearts", "5 Hearts", "6 Hearts", "7 Hearts", "8 Hearts", "9 Hearts", "10 Hearts", "Jack Hearts", "Queen Hearts", "King Hearts",
                "Ace Diamonds", "2 Diamonds", "3 Diamonds", "4 Diamonds", "5 Diamonds", "6 Diamonds", "7 Diamonds", "8 Diamonds", "9 Diamonds", "10 Diamonds", "Jack Diamonds", "Queen Diamonds", "King Diamonds",
                "Ace Clubs", "2 Clubs", "3 Clubs", "4 Clubs", "5 Clubs", "6 Clubs", "7 Clubs", "8 Clubs", "9 Clubs", "10 Clubs", "Jack Clubs", "Queen Clubs", "King Clubs"};

        int[] cardValue = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

        while (keepPlaying) {
            int temp = playGame(playerName, cardName, cardValue);

            if (temp == 0)
            {
                dealerWonrounds++;
            }
            if (temp == 1)
            {
                playerWonrounds++;
            }

            //asks if player wants to play another round
            System.out.println("\nWould you like to play another round? (yes or no)");
            String yes = scnr.nextLine();
            if (yes.equals("yes")) {
                keepPlaying = true;
            }
            else
            {
                keepPlaying = false;
            }
        }

        announceOverallWinner(playerName,playerWonrounds,dealerWonrounds);
    }
}