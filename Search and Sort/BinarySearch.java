import java.util.*;
import java.io.*;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int arr [] = new int [N];
        for(int i = 0;i<N;i++)arr[i]=in.nextInt();
        int target = in.nextInt();
        Arrays.sort(arr);
        int l = 0, r = N-1;
        while(l<r){
            int mid = (l+r)/2;
            if(arr[mid] < target)l = mid+1;
            else r = mid;
            System.out.println(l + " " + r);
        }
        if(arr[l]==target)System.out.println("FOUND");
        else System.out.println("NOT FOUND");
    }
}