import java.util.Scanner;
// 별 찍기 - 5
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number;

        number = sc.nextInt();
        for(int a = 0; a < number; ++a) {
            for(int b = 0; b < number + a + 1; ++b) {
                if(b < number - a - 1 || b > number + a - 1)
                    System.out.print(" ");
                else
                    System.out.print("*");
            }
            if(a != number - 1)
                System.out.println("");
        }
    }

}
