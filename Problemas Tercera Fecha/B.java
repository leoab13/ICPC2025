import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B{
    public static void main(String[] args) throws Exception {
    

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(tk.nextToken());

        int [] a = new int[n];

        long sum = 0;
        long current = 0;

        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i<n; i++){
            a[i] = Integer.parseInt(tk.nextToken());
            current += a[i];
        }

        sum += current*2;
        long currAux = current;

        for(int i =0 ; i<n/2; i++){
            int L = a[i];
            int R = a[n-i-1];
            
            currAux = currAux - (L+R);
            current += currAux;
            sum += current*2;
        }

        if(n%2 != 0){
            sum -= current;
        }
        else{
            sum -= current*2;
        }
        System.out.println(sum);
}
}