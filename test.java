import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class test {
    public static long getMinimumOperations(List<Long> source, List<Long> target) {
        int n = source.size();
        long[] delta = new long[n];
        
        // Compute the delta array and check for negative values
        for (int i = 0; i < n; i++) {
            delta[i] = target.get(i) - source.get(i);
            if (delta[i] < 0) {
                return -1;
            }
        }
        System.out.println("Delta: "+Arrays.toString(delta));
        // Precompute maximum allowable increments for prefixes
        long[] maxPrefixIncrease = new long[n];
        maxPrefixIncrease[0] = delta[0];
        for (int i = 1; i < n; i++) {
            maxPrefixIncrease[i] = Math.min(maxPrefixIncrease[i - 1], delta[i]);
        }

        // Precompute maximum allowable increments for suffixes
        long[] maxSuffixIncrease = new long[n];
        maxSuffixIncrease[n - 1] = delta[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxSuffixIncrease[i] = Math.min(maxSuffixIncrease[i + 1], delta[i]);
        }
        System.out.println("Pre: "+Arrays.toString(maxPrefixIncrease));
        System.out.println("Suf: "+Arrays.toString(maxSuffixIncrease));

        long totalOperations = 0;
        long currentIncrement = 0;

        for (int i = 0; i < n; i++) {
            long requiredIncrement = delta[i] - currentIncrement;
            if (requiredIncrement > 0) {
                // Feasibility check for prefix operation
                if (maxPrefixIncrease[i] >= requiredIncrement) {
                    currentIncrement += requiredIncrement;
                    totalOperations += requiredIncrement;
                }
                // Feasibility check for suffix operation
                else if (maxSuffixIncrease[i] >= requiredIncrement) {
                    currentIncrement += requiredIncrement;
                    totalOperations += requiredIncrement;
                } else {
                    // Neither operation is feasible
                    return -1;
                }
            } else {
                currentIncrement = delta[i];
            }
        }

        return totalOperations;
    }

    public static void main(String[] args) {
        List<Long> source = Arrays.asList(1L, 2L, 4L, 3L);
        List<Long> target = Arrays.asList(2L, 3L, 6L, 3L);
        // List<Long> source = Arrays.asList(1L, 2L, 3L, 0L);
        // List<Long> target = Arrays.asList(1L, 3L, 3L, 0L);
        long res=getMinimumOperations(source, target);
        System.out.println("Operations: "+res);

    }
}