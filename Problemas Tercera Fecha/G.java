import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class G {
    public static void main(String[] args) throws Exception {
    

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(tk.nextToken());
        StringBuilder sb = new StringBuilder();

        for (int i =0; i<n;i ++){
            tk = new StringTokenizer(br.readLine());
            double h1 = Double.parseDouble(tk.nextToken());
            double h2 = Double.parseDouble(tk.nextToken());
            double b = Double.parseDouble(tk.nextToken());

            sb.append(solve(h1, h2, b) + "\n");
        }
        String ans = sb.toString();
        System.out.println(ans.substring(0, ans.length()-1));
    }

    private static int solve (double h1, double h2, double b){
        double res = Math.log(h2/h1)/Math.log((b-1)/b); 
        double intRes = (int)res;
        double reminder = res - intRes;
        if(reminder>0){
            return (int)intRes+1;
        }
        return (int)intRes;
    }
}
