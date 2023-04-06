package ch04.java_threads.src;

public class TestThread {
    public static void main(String[] args) {
        Thread worker = new Thread(new Task());

        try {
            worker.join();
        } catch (InterruptedException ie) { }
    }
    
}
