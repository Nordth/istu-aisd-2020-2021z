package lab.n1;

public class Main {
    public static void main(String[] args) {

        Integer[] arr = new Integer[]{1,2,6,7,8,3,5,2,5,7,3,2,2,5,1,3,4,5,6};
        System.out.println("Input: " + arrayInt2String(arr));
        arr = sortMerge(arr);
        System.out.println("Output: " + arrayInt2String(arr));
    }

    private static Integer[] sortMerge(Integer[] array){
        if (array.length == 1)
            return array;
        if (array.length == 2){
            if (array[0] > array[1]){
                array = exchange(array, 0, 1);
            }
            return array;
        }
        Integer n = array.length / 2;
        Integer[] arr1 = sortMerge(split(array, 0, n));
        Integer[] arr2 = sortMerge(split(array, n));
        return merge(arr1, arr2);
    }

    private static Integer[] merge(Integer[] arr1, Integer[] arr2) {
        Integer i1 = 0, i2 = 0;
        Integer[] array = new Integer[arr1.length + arr2.length];
        while (i1 < arr1.length || i2 < arr2.length){
            if (i2 >= arr2.length || (i1 < arr1.length && arr1[i1] < arr2[i2])){
                array[i1+i2] = arr1[i1++];
            } else {
                array[i1+i2] = arr2[i2++];
            }
        }
        return array;
    }

    private static Integer[] exchange(Integer[] array, int i1, int i2) {
        Integer h = array[0];
        array[0] = array[1];
        array[1] = h;
        return array;
    }

    private static Integer[] split(Integer[] array, Integer begin) {
        return split(array, begin, array.length - begin);
    }

    private static Integer[] split (Integer[] array, Integer begin, Integer length){
        Integer[] arr = new Integer[length];
        for (int i = 0; i < length; i++) {
            arr[i] = array[begin + i];
        }
        return arr;
    }

    private static String arrayInt2String(Integer[] array){
        if (array.length == 0) return "";
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(array[0]);
        for (int i = 1; i < array.length; i++) {
            stringBuilder.append(",").append(array[i]);
        }
        return stringBuilder.toString();
    }

}
