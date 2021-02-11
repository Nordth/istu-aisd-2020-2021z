package bubbleSort;

public class Main {
    public static void main(String[] args) {
        int[] arr = {860, 8, 200, 9};

        bubbleSort(arr);
        printArray(arr);

    }

    static void bubbleSort(int[] array) {
        int n = array.length;
        int temp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (n - i); j++) {
                if (array[j - 1] > array[j]) {
                    temp = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = temp;
                }

            }
        }

    }

    static void printArray(int[] array) {

        for (int j : array) {
            System.out.print(j + " ");
        }
        System.out.println();

    }
}