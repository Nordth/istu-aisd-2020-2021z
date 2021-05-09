package lab.n3;

public class Item {
    private Integer key = null;
    private String value = null;
    private Item next = null;

    public Item(Integer key, String value) {
        this.key = key;
        this.value = value;
    }

    public Item() {
    }

    public boolean put(Integer key, String value) {
        if (this.key == null) {
            this.key = key;
            this.value = value;
        } else if (this.key == key){
            this.value = value;
            return false;
        } else if (this.next == null){
            this.next = new Item(key, value);
        } else {
            this.next.put(key, value);
        }
        return true;
    }

    public Integer getKey() {
        return key;
    }

    public Item getNext() {
        return next;
    }

    public String getValue() {
        return value;
    }

    public String get(Integer key) {
        if (this.key == key){
            return value;
        } else if (next != null){
            return next.get(key);
        } else {
            return null;
        }
    }

    public boolean remove(Integer key) {
        if (this.key == key){
            if (getNext() != null){
                this.key = next.getKey();
                this.value = next.getValue();
                this.next = next.getNext();
            } else {
                this.key = null;
                this.value = null;
            }
            return true;
        } else if (getNext() != null) {
            return this.next.remove(key);
        }
        return false;
    }
}
