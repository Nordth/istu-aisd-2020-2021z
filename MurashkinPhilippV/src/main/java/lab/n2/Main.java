package lab.n2;

public class Main {
    public static void main(String[] args) {
        Queue queue = new Queue();
        queue.enqueue(2);
        queue.enqueue(5);
        queue.enqueue(7);
        queue.enqueue(9);
        Queue queue2 = queue.clone();
        try {
            System.out.println(queue.dequeue());
            System.out.println(queue.dequeue());
            System.out.println(queue.dequeue());
            System.out.println(queue.dequeue());
            System.out.println(queue.dequeue());
        } catch (Exception e){
            System.out.println(e.getMessage());
        }

        try {
            System.out.println(queue2.dequeue());
            queue2.enqueue(15);
            System.out.println(queue2.dequeue());
            System.out.println(queue2.dequeue());
            System.out.println(queue2.dequeue());
            System.out.println(queue2.dequeue());
        } catch (Exception e) {
            e.getMessage();
        }

    }
}
