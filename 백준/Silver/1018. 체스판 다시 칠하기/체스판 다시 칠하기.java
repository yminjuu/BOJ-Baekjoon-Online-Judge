import java.util.*;

import javax.sound.midi.Soundbank;
class Main {
	public static void main (String[] args) {
        Scanner scanner= new Scanner(System.in);
        String [] str = new String[2];
        str[0]="WBWBWBWB";
        str[1]="BWBWBWBW";  
        int minDiff=100; int count=0;   
        int N= scanner.nextInt(); int M= scanner.nextInt(); scanner.nextLine();
        String [] inputArr= new String[N];
        for (int i=0; i<N; i++)
            inputArr[i]=scanner.nextLine();

        for (int i=0; i<2; i++){ 
            for (int j=0; j<=N-8; j++){ 
                for (int k=0; k<=M-8; k++){ 
                    for (int b=j; b<j+8; b++){ 
                        for (int a=k; a<k+8; a++){ 
                            if (str[(b%2+i)%2].charAt(a-k)!=inputArr[b].charAt(a)){
                                count++;
                            }
                        }
                    }
                    if (count<minDiff) minDiff=count;
                    count=0;
                }
            }
        }
         System.out.println(minDiff);
    }
}