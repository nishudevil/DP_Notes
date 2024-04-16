import java.util.*;

public class test {

    private static int operationCount(int target, int elem, int x, int y, int z) {
        if (elem == target) return 0;
        if (elem + x == target) return 1;
        if (elem - y == target && elem > y) return 1;
        if (elem * z == target) return 1;
        return Integer.MAX_VALUE; // Impossible to reach target with one operation
    }

    public static int findMaxFrequency(int x, int y, int z, List<Integer> arr) {
        Collections.sort(arr);
        Set<Integer> possibleFreq = new HashSet<>();

        for (int freq : arr) {
            possibleFreq.add(freq);          // Original frequency
            possibleFreq.add(freq + x);      // Increased by x
            if (freq > y) {
                possibleFreq.add(freq - y);  // Decreased by y
            }
            possibleFreq.add(freq * z);      // Multiplied by z
        }

        int maxFreq = 0;

        for (int target : possibleFreq) {
            int left = 0, right = 0, count = 0;
            while (right < arr.size()) {
                if (operationCount(target, arr.get(right), x, y, z) <= 1) {
                    count++;
                    right++;
                } else {
                    if (right == left) {
                        // Move both pointers if they point to the same element
                        right++;
                    }
                    left++;
                }
                maxFreq = Math.max(maxFreq, count);
            }
        }

        return maxFreq;
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(10,5,5,2,11);
        int x = 2;
        int y = 2;
        int z = 1;
        System.out.println("Maximum number of elements with the same frequency: " + findMax(x, y, z, arr));
    }
}
