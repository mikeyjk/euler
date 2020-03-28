import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class EulerProblems {

    /**
     * Problem #1
     */

    // Problem One - Multiples of 3 and 5
    private static int problemOneRecursive(int n, int limit, int sum) {
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

        assertEquals(
                233168,
                problemOneRecursive(0, 1000, 0),
                "Output doesn't match known result"
        );
    }

    private static int recursive(int limit, int previous, int current, int sum) {
        int next = previous + current;
        if (next <= limit) {
            if (next % 2 == 0) {
                sum += next;
            }

            sum = recursive(limit, current, next, sum);
        }

        return sum;
    }

    /*
     * Problem #2
     */

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
                recursive(4000000, 0, 1, 0)
        );
    }

    @Test // TODO: do as a one liner
    void problemOne2() { // O(n)
        int maxRange = 999;
        int divisorOne = 3;
        int divisorTwo = 5;
        // int[] matches = new int[maxRange + 1];

        int sum = 0;
        for (int i = maxRange; i > 0; i--) {
            // System.out.println("i " + i);
            // System.out.println("remainder " + i % divisorOne);
            if (i % divisorOne == 0 || i % divisorTwo == 0) {
                // matches[i] = i;
                sum += i;
                // System.out.println("sum " + sum);
            }
            // System.out.println("");
        }
        assertEquals(sum, 233168 );

        /*
        int lastItem = 0;
        int sumOfDif = 0;
        for (int i = 0; i < 1000; i++) {
            if (matches[i] != 0) {
                System.out.print(matches[i] + matches[lastItem] + ", ");
                sumOfDif += matches[i] + matches[lastItem];
                lastItem = i;
            }
        }*/
        // why does finding a pattern between non-zero numbers, then summing
        // them culminate in the maxRange?
        // n-(n-1)
        // 3, 2, 1, 3, 1, 2, 3
        //System.out.print(sumOfDif);
        // n+(n-1)
        // sequence: 3, 8, 11, 15, 19, 22, 27, 33, 38, 41, 45, 49, 52, 57, 63, 68, 71, 75, 79
        // repeating pattern: 5, 3, 4, 4, 3, 5, 6
        // sum: 465337
    }

    @Test
    void problemOneRecursive() { // O(n)?

        assertEquals(
                233168,
                problemOneTailRecursiveImpl(0, 999)
        );
    }

    private int problemOneTailRecursiveImpl(int sum, int i) {
        return (i > 0) ?
                problemOneTailRecursiveImpl(
                        (i % 3 == 0 || i % 5 == 0) ?
                                sum + i :
                                sum,
                        --i
                ) :
                sum;
    }

    void problemOneFormula() {
        // https://math.stackexchange.com/questions/9259/find-the-sum-of-all-the-multiples-of-3-or-5-below-1000
        // https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle
        /*
         * Such a sequence, where the difference between each number is constant, is called a finite arithmetic
         * progression or finite arithmetic sequence and the sum of a finite arithmetic progression is called a
         * finite arithmetic series. The formula for the sum is 1/2 * n * (a_1 + a_n). where n is the number of
         * terms being added, a_1 is the first element in the sequence, and a_n is the last element in the
         * sequence.
         *  - https://adamdrake.com/an-unreasonably-deep-dive-into-project-euler-problem-1.html
         */
        // 1: 3 *  (1/2 * floor(999/3) *  (1 + floor(999/3)))  = 166833
        // 2: 5 *  (1/2 * floor(999/5) *  (1 + floor(999/5)))  = 49750
        // 3: 15 * (1/2 * floor(999/15) * (1 + floor(999/15))) = 33165

        // n * (n + 1) * 0.5 -
        // (1 + 2) - 3
        // 166833 + 99900 - 33466.5
        // 233266.5
        // wrong

        // wtf @ the above
        // https://en.wikipedia.org/wiki/Arithmetic_progression
    } // O(1)

    /**
     * Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
     * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
     * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
     */
    @Test
    void problemTwo2() { // O(n)??
        int sum = 0;
        int priorTerm = 0;
        int currentTerm = 1;
        while (currentTerm < 3000000) {
            int oldTerm = currentTerm;
            currentTerm = priorTerm + currentTerm;
            priorTerm = oldTerm;
            sum += currentTerm;
            System.out.print(currentTerm + ", ");
        }
        System.out.println("\n\nSum of terms: " + sum);

        System.out.println("");
        //

        sum = 0;
        priorTerm = 0;
        currentTerm = 1;
        while (currentTerm < 3000000) {
            int oldTerm = currentTerm;
            currentTerm = priorTerm + currentTerm;
            priorTerm = oldTerm;
            sum = currentTerm % 2 == 0 ?
                    sum + currentTerm :
                    sum;
            System.out.print(currentTerm + ", ");
        }
        System.out.println("\n\nSum of even terms: " + sum);
    }

    @Test
    void problemTwoRecursive2() { // O(n)??
        System.out.println(
                "highest term < 4,000,000: " +
                        fibonnaciRecursive(1, 1)
        );
        System.out.println(
                "sum of terms <  < 4,000,000: " +
                        fibonnaciRecursiveSum(1, 1, 0)
        );
        System.out.println(
                "sum of even terms < 4,000,000: "  +
                        fibonnaciRecursiveEvenSum(1, 1, 0)
        );
    }
    int fibonnaciRecursive(int lastTerm, int currentTerm) {
        return currentTerm <= 4000000 ?
                fibonnaciRecursive(currentTerm, lastTerm + currentTerm) :
                currentTerm;
    }
    int fibonnaciRecursiveSum(int lastTerm, int currentTerm, int sum) {
        return currentTerm <= 4000000 ?
                fibonnaciRecursiveSum(
                        currentTerm,
                        lastTerm + currentTerm,
                        sum + currentTerm
                ) :
                sum;
    }
    int fibonnaciRecursiveEvenSum(int lastTerm, int currentTerm, int sum) {
        return currentTerm <= 4000000 ?
                fibonnaciRecursiveEvenSum(
                        currentTerm,
                        lastTerm + currentTerm,
                        currentTerm % 2 == 0 ?
                                sum + currentTerm :
                                sum
                ) :
                sum;
    }

    /**
     * The prime factors of 13195 are 5, 7, 13 and 29.
     * What is the largest prime factor of the number 600851475143 ?
     *
     * Factor:
     *  - A factor is a whole numbers that can be divided evenly into another number.
     *
     * Prime:
     *  - a whole number greater than 1 that can not be made by multiplying other whole numbers
     *  - A prime number is a whole number greater than 1 whose only factors are 1 and itself
     *
     *  As the set of natural numbers N = {1, 2, 3, ...} proceeds, however, prime numbers generally
     *  become less frequent and are more difficult to find in a reasonable amount of time. As of
     *  this writing, the largest known prime number has more than 23 million digits. It is referred
     *  to as M77232917 and has one million more digits than the previous record holder.
     *  - https://whatis.techtarget.com/definition/prime-number
     */
    @Test
    void problemThree() {
        /**
         int numba = 20;
         int m = Math.round((int) Math.sqrt(numba));
         int a = numba / m;

         int divisor = m;
         while
         int b = numba / (m - 1)
         */
    }
}
