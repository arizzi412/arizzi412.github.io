import java.util.*;

public class edgeComparator implements Comparator<edge> {
    public int compare(edge p1, edge p2) {
        if (p1.value < p2.value) return -1;
        if (p1.value > p2.value) return 1;
        return 0;
    }
}
