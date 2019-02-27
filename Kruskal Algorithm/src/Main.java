import java.io.File;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {

        String filename;
        int numvertices;

        // gets user info
        System.out.print("Input name of file with extension: \n");
        Scanner reader = new Scanner(System.in);
        filename = reader.nextLine();
        System.out.print("input number of vertices :  \n");
        numvertices = reader.nextInt();

        vertex[] vertices = new vertex[numvertices];

        // array of edges that belong to the final solution MST
        edge[] X = new edge[numvertices - 1];

        //array of vertices to keep track of
        for(int a =0; a < numvertices; ++a)
        {
            vertices[a] = new vertex(a);
        }

        // basically does what the makeset function does from the book.  Each vertex is part of a singleton set
        set sets[] = new set[numvertices];


        //initializes sets
        for(int a=0; a < numvertices; ++a) {
            sets[a] = new set();
            sets[a].root = a;
            sets[a].rank = 0;
        }


        Scanner scanner = new Scanner(new File(filename));

        //adjacency matrix representation
        edge[][] Matrix = new edge[numvertices][numvertices];

        int i = 0, j = 0;

            while (i < numvertices) {
                while (j < numvertices) {
                   int temp= scanner.nextInt();

                   // skips diagonals, 0s and the flip side of diagonal, which is redundant for undirected graphs
                    if (temp==0 || j<i || i==j)
                    {

                    }

                    else {
                        Matrix[i][j] = new edge(temp, vertices[i], vertices[j]);
                    }
                    ++j;
                }
                j=0;
                ++i;
            }


        //GFG.print2D(Matrix);

        //priority queue
        edgeComparator compare = new edgeComparator();
        PriorityQueue<edge> pq = new PriorityQueue<>(compare);


        //queues the edges we want to consider
        for(int a=0;a< numvertices;++a)
        {
            for(int b=0;b< numvertices;++b)
            {
                if(Matrix[a][b]==null)
                {

                }
                else
                    {
                        pq.add(Matrix[a][b]);
                    }

            }

        }

        int numedges= 0;
        while ( numedges < numvertices - 2)
        {
            //automatically adds smallest edge
            edge currentE =  pq.poll();
            if(numedges == 0)
            {
                X[0]= currentE;
            }

            edge nextE= pq.poll();

            // this is exactly the algorithm from  the textbook
            int x = find(sets, currentE.vertex1.vertexnum);
            int y = find(sets, nextE.vertex2.vertexnum);


            if (x != y)
            {
                X[++numedges] = nextE;
                Union(sets, x, y);
            }

        }

        //while(!pq.isEmpty()) {
          //  System.out.println(pq.poll().value);
        //}

        //prints out solution
        int a =0 ;
        System.out.print("Edges in MST (Vertex numbers start at index 0):\n\n");
        while( a < X.length)
        {
            System.out.print("Edge " + (a+1) + "  \n Value: " + X[a].value + "\nConnects Vertex " + (X[a].vertex1.vertexnum) + " to Vertex " + (X[a].vertex2.vertexnum)  + "\n\n");
            ++a;
        }
    }

    static int  find(set sets[], int a)
    {
        //again almost exactly from the textbook

        if (sets[a].root != a)
            sets[a].root = find(sets, sets[a].root);

        return sets[a].root;
    }

    static void Union(set sets[], int a, int b)
    {
        //textbook
        int roota = find(sets, a);
        int rootb = find(sets, b);

        
        if (sets[roota].rank < sets[rootb].rank)
            sets[roota].root = rootb;
        else if (sets[roota].rank > sets[rootb].rank)
            sets[rootb].root = roota;

        else
        {
            sets[rootb].root = roota;
            sets[roota].rank++;
        }
    }

}



class edge {
   public vertex vertex1;
   public vertex vertex2;
   public int value;

    edge(int value, vertex vertex1, vertex vertex2) {
        this.value = value;
         this.vertex1 = vertex1;
         this.vertex2 = vertex2;
    }


}

  class vertex
{
   public int vertexnum;

    vertex(int vertexnum)
    {
        this.vertexnum=vertexnum;
    }


}

class set
{
 int root;
 int rank;

}


/*
class GFG {

    public static void print2D(edge mat[][])
    {
        // Loop through all rows
        for (int i = 0; i < mat.length; i++) {

            // Loop through all elements of current row
            for (int j = 0; j < mat[i].length; j++) {
                if (!(i==j || j<i)) {
                    System.out.print(mat[i][j].value + " ");
                }

            }
            System.out.print("\n");
        }
    }
}
*/
