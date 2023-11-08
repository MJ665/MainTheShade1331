public class queue {
    private int maxSize;
    private int front;
    private int rear;
    private int currentSize;
    private int array[];

    public queue(int size) {
        this.maxSize = size;
        front = 0;
        rear = -1;
        currentSize = 0;
        array = new int[maxSize];
    }

    public boolean isFull() {
        return (currentSize == maxSize);
    }

    public boolean isEmpty() {
        return (currentSize == 0);
    }

    public void enqueue(int item) {
        if (isFull()) {
            System.out.println("Queue is full!");
            return;
        }
        rear = (rear + 1) % maxSize;
        array[rear] = item;
        currentSize++;
        System.out.println("Added to queue" + item);
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return -1;
        }
        int temp = front;
        front = (front + 1) % maxSize;
        currentSize--;
        System.out.println("Removed from queue" + array[temp]);
        return array[temp];
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return;
        }
        int temp = front;
        while (temp != rear) {
            System.out.println(array[temp]);
            temp = (temp + 1) % maxSize;
        }
        System.out.println(array[rear]);
    }

    public static void main(String[] args) {
        queue queue = new queue(5);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.dequeue();
        queue.enqueue(5);
        queue.display();
    }
}