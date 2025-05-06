//AUTORIA DE BRIAN
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D_1{
    public static void main(String [] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(tk.nextToken());

        long [] A = new long[K];

        tk = new StringTokenizer(br.readLine());
        for(int i = 0; i<K; i++){
            A[i] = Long.parseLong(tk.nextToken());
        }

        int N = Integer.parseInt(br.readLine());

        long [][] B = new long[N][K];

        for(int i = 0 ; i<N; i++){
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j<K; j++){
                B[i][j] = Long.parseLong(tk.nextToken());
            }
        }

        solve(B, A, N, K);
    }

    private static void solve(long[][] B, long[] A, int N, int K) {
        
        long [] orderSum = new long[K];

        for(int i = 0; i<K; i++){
            for(int j = 0; j<N; j++){
                orderSum[i] += B[j][i];
            }
        }

        long minDay = Long.MAX_VALUE;
        for(int i = 0 ; i<K ; i++){
            if(orderSum[i] != 0){
                long day = A[i] / orderSum[i];
                if(day<minDay){
                    minDay = day;
                }
            }
        }

        System.out.print((minDay+1) + " ");

        for(int i = 0 ; i<K; i++){
            A[i] = A[i] - minDay*orderSum[i];
        }

        for(int i = 0; i<N; i++){
            for(int j = 0; j<K; j++){
                if(A[j]>=B[i][j]){
                    A[j] -= B[i][j];
                }
                else{
                    System.out.print(i+1);
                    return;
                }
            }
        }
    }   
}