package lab.n2;

public class Queue {
    private Integer[] values = new Integer[1];
    private Integer count = 0;

    public Queue() {
    }

    public Queue(Integer[] values) {
        this.values = values;
        count = values.length;
    }

    public void enqueue(Integer value){
        if (count >= values.length)
            values = copy(values, new Integer[values.length * 2]);
        values[count++] = value;
    }

    public Integer dequeue() throws Exception {
        if (count == 0){
            throw new Exception("Queue is empty");
        }
        Integer value = values[0];
        values = copy(values, new Integer[values.length - 1], 1, 0, --count);
        return value;
    }

    private Integer[] copy(Integer[] from, Integer[] to) {
        return copy(from, to, 0, 0, from.length);
    }

    private Integer[] copy(Integer[] from, Integer[] to, Integer startFrom, Integer startTo, Integer count){
        for (int i = 0; i < count; i++) {
            to[startTo + i] = from[startFrom + i];
        }
        return to;
    }

    public Queue clone(){
        return new Queue(values);
    }
}
