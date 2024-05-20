import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int[][] arr= new int[3][t];
        for (int i = 0; i < t; i++) {
            String[] s = br.readLine().split(" ");
            for (int j = 0; j < 3; j++) {
                arr[i][j] = Integer.parseInt(s[j]);
            }
        }
        br.close();
        for (int i = 0; i < t; i++) {
            int[] temp;
           temp= arr[i];
           go(temp);
            System.out.println();
        }
    }
    public static void go(int[] arr){
        int add_num = arr[0]-1;
        int n = arr[2];
        int now_value = arr[1];
        for (int i = 0; i < n; i++) {
            now_value+=1;
            String temp = Integer.toString(now_value);
            if (now_value%7==0|| temp.contains("7")){
                System.out.print("p ");
            }else System.out.print(now_value+" ");
            now_value+=add_num;
        }
    }
}