import java.util.*;
public class MergeSort {
    public static int [] mergeSort(int arr []){
        if(arr.length <= 1)return arr;
        int mid = (arr.length)/2;
        int left [] = new int [mid];
        int right [] = new int [arr.length-mid];
        for(int i = 0;i<mid;i++)left[i]=arr[i];
        for(int i = mid;i<arr.length;i++)right[i-mid]=arr[i];
        int sorted [] = new int [arr.length];
        left = mergeSort(left);
        right = mergeSort(right);
        merge(sorted,left, right);
        return sorted;
    }
    private static int [] merge (int res [], int left [], int right []){
        int i = 0,j = 0;
        while(i < left.length || j < right.length){
            if(i < left.length && j < right.length){
                if(left[i]<right[j])
                    res[i+j]=left[i++];
                else
                    res[i+j]=right[j++];
            }
            else if(i < left.length)
                res[i+j]=left[i++];
            else 
                res[i+j]=right[j++];
        }
        return res;
    }
    public static void main(String[] args) {
        
    }
}