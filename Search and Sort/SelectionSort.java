import java.util.*;
public class SelectionSort {
    public static int [] selectionSort(int arr []){
        for(int i = arr.length-1;i>=0;i--){
            int mx = -0x3f3f3f;
            int pt = -1;
            for(int j = 0;j<=i;j++){
                if(arr[j]>mx){
                    mx = arr[j];
                    pt = j;
                }
            }
            for(int j = pt;j<i;j++){
                arr[j]=arr[j+1];
            }
            arr[i]=mx;
        }
        return arr;
    }
    public static void main(String[] args) {

    }
}