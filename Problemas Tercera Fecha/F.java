import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.function.Function;

import javax.print.DocFlavor.INPUT_STREAM;

public class F {

    
    public static void main(String[] args) throws Exception {
    
        Map<String, Function<Point, Point>> movements;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());
    
        movements = Map.of(
            "R", point -> point.moveY(1),
            "L", point -> point.moveY(-1),
            "D", point -> point.moveX(1),
            "U", point -> point.moveX(1));

        int N = Integer.parseInt(tk.nextToken());
        int M = Integer.parseInt(tk.nextToken());

        HashSet<Point> activePoints = new HashSet<>(); 

        int [][] map = new int[N][M];
        int [][] dp = new int [N][M]; 

        for(int i = 0; i<N; i++){
            tk = new StringTokenizer(br.readLine());
            for(int j = 0; j<M; j ++){
                map[i][j] = Integer.parseInt(tk.nextToken());
            }
        }

        tk = new StringTokenizer(br.readLine());
        int xI = Integer.parseInt(tk.nextToken());
        int yI = Integer.parseInt(tk.nextToken());

        Point stPoint = new Point(xI, yI);

        tk = new StringTokenizer(br.readLine());
        int xF = Integer.parseInt(tk.nextToken());
        int yF = Integer.parseInt(tk.nextToken());

        Point endPoint = new Point(xI, yI);

        activePoints.add(stPoint);


        do{
            
        }while(true);




    }

    private static class Point {
        int x;
        int y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }

        public Point moveY(int q){
            this.y += 1;
            return this;
        }
        public Point moveX(int q){
            this.y += 1;
            return this;
        }

    }

}
