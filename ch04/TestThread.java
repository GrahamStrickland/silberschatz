package ch04;

public class TestThread {
    public static void main(String[] args) {
        Thread worker = new Thread(new Task());
        worker.start();
    }
}
