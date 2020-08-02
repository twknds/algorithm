import java.util.ArrayList;
import java.util.Scanner;

public class main {
    static class Line{

        int s;
        int e;

        public Line(){
            this.s = 0;
            this.e = 0;
        }
        public Line(int s, int e){
            this.s = s;
            this.e = e;
        }

        public int getS() {
            return s;
        }

        public void setS(int s) {
            this.s = s;
        }

        public int getE() {
            return e;
        }

        public void setE(int e) {
            this.e = e;
        }

        @Override
        public String toString() {
            return "Line{" +
                    "s=" + s +
                    ", e=" + e +
                    '}';
        }
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int N, L;
        ArrayList<Line> lines = new ArrayList<>();

        N = input.nextInt();
        L = input.nextInt();

        for(int i=0;i<N;i++){
            int s = input.nextInt();
            int e = input.nextInt();
            Line line = new Line(s,e);
            lines.add(line);
        }
        System.out.println(lines);
    }
}
