import java.util.*;
import java.io.*;

class Main {
	public static void main (String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));
        int N= Integer.parseInt(bf.readLine());
        HashMap<String, Integer> map = new HashMap<>();
        StringTokenizer strTok = new StringTokenizer(bf.readLine(), " ");
        for (int i=0; i<N; i++)
            map.put(strTok.nextToken(), 1);
        int M= Integer.parseInt(bf.readLine());
        strTok = new StringTokenizer(bf.readLine(), " ");
        for (int i=0; i<M; i++){
            if (map.containsKey(strTok.nextToken()))
                bw.write(1+" ");
            else
                bw.write(0+" ");
        }
        bw.flush();
        bw.close();
    }
}