import java.util.Scanner;

public class Change {
    private static int getChange(int m) {
        // Create Array of denominations, that is, 1, 5, and 10.
        int[] deno = {1, 5, 10};
        int n = deno.length;

        // Initialize result
        int size = 0;

        // Traverse through all denomination
        for (int i=n-1; i>=0; i--){
          // Find denominations
          while (m >= deno[i]){
            m -= deno[i];
            size++;
          }
        }

        return size;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        System.out.println(getChange(m));

    }
}
