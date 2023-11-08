public class LinearSearch {
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i; // Element found at index 'i'.
            }
        }
        return -1; // Element not found in the list.
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};
        int target = 22;

        int result = linearSearch(arr, target);

        if (result != -1) {
            System.out.println("Element found at index " + result);
        } else {
            System.out.println("Element not found in the list.");
        }
    }
}