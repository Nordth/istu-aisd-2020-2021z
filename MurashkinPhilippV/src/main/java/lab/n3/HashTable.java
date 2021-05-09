package lab.n3;

public class HashTable {
    private Item[] items = new Item[]{new Item()};
    private int length = 1;
    private int size = 0;

    private Integer hash(Integer key){
        return key % length;
    }

    public void put(Integer key, String value) {
        if (items[hash(key)].put(key, value)) {
            size++;
        };
        if (size > length/2){
            resize(length > 0 ? length * 2 : 2);
        }
    }

    private void resize(Integer length) {
        this.length = length;
        Item[] values = getItems();
        items = new Item[length];
        for (int i = 0; i < length; i++) {
            items[i] = new Item();
        }
        for (Item item: values) {
            if (item.getKey() == null) continue;
            items[hash(item.getKey())].put(item.getKey(), item.getValue());
        }
    }

    private Item[] getItems(){
        Item[] values = new Item[size];
        Integer k = 0;
        for (Item item: items) {
            while (item != null && item.getKey() != null){
                values[k++] = new Item(item.getKey(), item.getValue());
                item = item.getNext();
            }
        }
        return values;
    }

    public String get(Integer key) {
        return items[hash(key)].get(key);
    }

    public void remove(Integer key) {
        Integer hash = hash(key);
        if (items[hash] != null){
            if ((items[hash].getNext() != null && !items[hash].remove(key)) || items[hash].getKey() != key){
                return;
            } else {
                items[hash] = new Item();
            }
            size--;
        }
    }

    public void clear() {
        items = null;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for (Item item: getItems()) {
            stringBuilder.append("(");
            stringBuilder.append(item.getKey());
            stringBuilder.append(",");
            stringBuilder.append(item.getValue());
            stringBuilder.append(")");
        }
        return stringBuilder.toString();
    }
}
