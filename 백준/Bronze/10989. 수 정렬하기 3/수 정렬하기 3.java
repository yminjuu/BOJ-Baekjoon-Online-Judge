import java.util.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N= Integer.valueOf(bf.readLine()); /*자동언박싱 */
        int [] arr= new int[N]; int [] counting= new int[10001];
        int [] result= new int[N];
        Arrays.fill(counting, 0);

        for (int i=0; i<N; i++){
            arr[i]=Integer.valueOf(bf.readLine());
            counting[arr[i]]++;}
        
        for (int i=1; i<10001; i++)
            counting[i]+=counting[i-1];

        for (int i=0; i<N; i++){
            result[--counting[arr[i]]]=arr[i];
        }

        BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i=0; i<N; i++){
            bw.write(result[i]+"\n");
        }
        bw.flush();
        bw.close();
    }
}