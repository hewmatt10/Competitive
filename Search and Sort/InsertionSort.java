import java.util.*;
public class InsertionSort {
    public static int [] insertionSort(int intArray []){
        for (int i = 1,cur; i < intArray.length; i++){
            int ptr = i - 1;
            cur = intArray[i];
            while(ptr >= 0 && intArray[ptr] > cur){
                intArray[ptr+1] = intArray[ptr];
                ptr--;
            }
            intArray[ptr+1] = cur;
            }
        return intArray;
    }   
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}