package lab.n2;

public class List {
    private Integer[] values = new Integer[0];
    private Integer current = -1;

    public void add(Integer value){
        values = copy(values, new Integer[values.length + 1]);
        values[++current] = value;
    }


    public void insertBefore(Integer index, Integer value){
        Integer[] array = copy(values, new Integer[values.length + 1], 0, 0, index - 1);
        array[index - 1] = value;
        values = copy(values, array, index - 1, index, array.length - index);
        current = values.length - 1;
    }

    public Integer get(Integer index){
        return values[index];
    }

    public Boolean deleteByValue(Integer value){
        for (int i = 0; i < values.length; i++) {
            if (value == values[i]){
                Integer[] array = copy(values, new Integer[values.length - 1], 0, 0, i);
                values = copy(values, array, i + 1, i, values.length - i - 1);
                current = values.length;
                return true;
            }
        }
        return false;
    }

    public void print(){
        System.out.println(this);
    }

    public void clear(){
        values = null;
    }

    public String toString(){
        if (values.length == 0) return "";
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(values[0]);
        for (int i = 1; i < values.length; i++) {
            stringBuilder.append(",");
            stringBuilder.append(values[i]);
        }
        return stringBuilder.toString();
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
}
