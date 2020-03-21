import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class EulerProblems {

    // Problem One - Multiples of 3 and 5
    static int problemOneRecursive(int n, int limit, int sum) {
        if (n < limit) {
            if ((n % 3) == 0 || (n % 5) == 0) {
                sum += n;
            }
            sum = problemOneRecursive(++n, limit, sum);
        }
        return sum;
    }

    @Test
    @DisplayName("1.1 (loop)")
    void problemOne() {
        int previous = 0;
        int current = 1;
        int limit = 4000000;

        int sum;
        int tmp;
        for(sum = 0; current <= limit; previous = tmp) {
            tmp = current;
            current += previous;
            if (current > limit) {
                break;
            }

            if (current % 2 == 0) {
                sum += current;
            }
        }

        final int result = sum; // Final required for Lambda.
        //assertThat(result).equ
        assertEquals(4613732, result);
    }

    @Test
    @DisplayName("1.2 (recursive)")
    void recursive() {
        assertEquals(233168, problemOneRecursive(0, 1000, 0), "Output doesn't match known result");
    }

static int recursive(int limit, int previous, int current, int sum) {
        int next = previous + current;
        if (next <= limit) {
            if (next % 2 == 0) {
                sum += next;
            }

            sum = recursive(limit, current, next, sum);
        }

        return sum;
    }

    /**
     * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
     * Find the sum of all the multiples of 3 or 5 below 1000.
     */
    @Test
    @DisplayName("2.1 (loop)")
    void problemTwo() {
        int sum = 0;
        final int limit = 1000;
        for (int n = 0; n < limit; ++n) {
            if ((n % 3) == 0 || (n % 5) == 0) { // If divisible by 3 or 5.
                sum += n;
            }
        }
        assertEquals(233168, sum);
    }

    @Test
    @DisplayName("2.2 (recursive)")
    void problemTwoRecursive() {
        assertEquals(
                4613732,
                ProblemTwo.recursive(
                        4000000,
                        0,
                        1,
                        0
                )
        );
    }

}
