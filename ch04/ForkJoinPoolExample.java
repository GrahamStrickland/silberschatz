package ch04;

import java.util.concurrent.ForkJoinPool;
import java.util.Random;

public class ForkJoinPoolExample {
    private static final int SIZE = 2001;
    private static final int BOUND = 1000;

    public static void main(String[] args) {
        ForkJoinPool pool = new ForkJoinPool();
        Random random = new Random();

        // array contains the integers to be summed
        int[] array = new int[SIZE];
        System.out.println("Array elements: ");
        for (int i = 0; i < SIZE; i++) {
            array[i] = random.nextInt(BOUND); 
            String paddedNum = String.format("%1$3d", array[i]);
            if (i == SIZE - 1)
                System.out.print(paddedNum + "\n\n");
            else
                System.out.print(paddedNum + (i % 10 == 0 ? "\n" : ", "));
        }

        SumTask task = new SumTask(0, SIZE - 1, array);
        int sum = pool.invoke(task);

        System.out.println("Sum: " + sum);
    }
    
}
