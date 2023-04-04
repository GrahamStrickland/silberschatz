package ch04.java_threads.src;

class Task implements Runnable
{
    public void run() {
        System.out.println("I am a thread.");
    }
}