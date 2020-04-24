import java.util.*;
public class LinearSearch {
    public static void linearSearch(int arr [], int val){
        for(int i = 0;i<arr.length;i++){
            if(arr[i] == val){
                System.out.println(val + " was found at index " + i);
                return;
            }
        }
        System.out.println(val + " was not found");
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}