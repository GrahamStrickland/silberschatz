package ch04;

public class TestThreadLambda {
    public static void main(String[] args) {
        Runnable task = () -> {
            System.out.println("I am a thread.");
        };

        Thread worker = new Thread(task);
        worker.start();
    }
}
