import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {


        System.out.print("Input 1st String: ");
        Scanner reader = new Scanner(System.in);
        String String1 = reader.nextLine();
        System.out.print("Input 2nd String: ");
        String String2 = reader.nextLine();

        int String1Length = String1.length();
        int String2Length = String2.length();

        int[][] matrix = new int[String1Length + 1][String2Length + 1];

        for (int i = 0; i < String1Length + 1; i++) {
            matrix[i][0] = i;
        }
        for (int j = 0; j < String2Length + 1; j++) {
            matrix[0][j] = j;
        }

        for (int i = 1; i < String1Length + 1; i++) {
            for (int j = 1; j < String2Length + 1; j++) {
                if (String1.charAt(i - 1) == String2.charAt(j - 1)) {
                    matrix[i][j] = matrix[i - 1][j - 1];
                } else {
                    int localmin = Math.min(matrix[i - 1][j - 1], Math.min(matrix[i - 1][j], matrix[i][j - 1]));
                    matrix[i][j] = localmin + 1;

                }
            }

        }

        System.out.print(Arrays.deepToString(matrix));

        System.out.print("\n\nEdit distance is: " + matrix[String1Length][String2Length]);

        int i = String1Length;
        int j = String2Length;


        Stack stack = new Stack();


        int count1 = String1Length, count2 = String2Length;
        while (count1 > 0 | count2 > 0) {
            if (count1 > 0 && count2 > 0 && matrix[count1][count2] == matrix[count1 - 1][count2 - 1]) {
                stack.push("RD");
                count1--;
                count2--;
            } else if (count2 > 0 && matrix[count1][count2] == matrix[count1][count2 - 1] + 1) {
                stack.push("R");
                count2--;
            } else if (count1 > 0 && matrix[count1][count2] == matrix[count1 - 1][count2] + 1) {
                stack.push("D");
                count1--;
            } else if (count1 > 0 && count2 > 0 && matrix[count1][count2] == matrix[count1 - 1][count2 - 1] + 1) {
                stack.push("RD");
                count1--;
                count2--;
            }

        }

        count1= 0;
        count2 =0;
        int count0=0;
        char [][] printalignment = new char[2][Math.max(String1Length, String2Length)];
        while (!stack.empty())
        {
        String temp = stack.pop().toString();
        if(temp == "RD")
        {
            printalignment[0][count0] = String1.charAt(count1);
            printalignment[1][count0] = String2.charAt(count2);
            count1++;
            count2++;
            count0++;

        }

        if (temp=="D")
        {
            printalignment[0][count0]= String1.charAt(count1);
            printalignment[1][count0]= '_';
            count1++;
            count0++;


        }

        if (temp == "R")
        {
            printalignment[0][count0]= '_';
            printalignment[1][count0]=String2.charAt(count2);
            count2++;
            count0++;

        }
        }

        System.out.print("\n");
        for(int a = 0; a< count0;a++)
        {
            System.out.print( printalignment[0][a] + " ");

        }

        System.out.print("\n");
        for(int a = 0; a< count0;a++)
        {
            System.out.print(printalignment[1][a] + " ");

        }
    }
}
/*
  String lookback(int matrix[][], int i, int j)
    {


        int Uvalue= matrix[i - 1][j];
        int Lvalue= matrix[i][j-1];
        int ULvalue = matrix[i-1][j-1];

       int localmin= Math.max(ULvalue,Math.max(Uvalue,Lvalue));
       
       
       if (matrix[i][j]== matrix[i-1][j-1])
        {
            return "UL";
        }
        
        else if( matrix[i][j]== matrix[i-1][j] + 1)
       {
           return "U";
       }
       else if (matrix[i][j]==matrix[i][j-1]+1)
       {
           return "L";
       }
       else if (matrix[i][j] ==  matrix[i-1][j-1])
       {
           return "UL";
       }
       
       // if (localmin == ULvalue)
        //{
        // return "UL";
         
         //if (matrix[i][j]==localmin)
        //}

        return 't';
    }




}

*/