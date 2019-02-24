import java.util.Scanner;
// 별 찍기 - 7
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number;
        number = sc.nextInt();

        // 5개 줄 위로 뾰족한 삼각형 별 찍기
        for(int a = 0; a < number; ++a) {
            for(int b = 0; b < number + a + 1; ++b) {
                if(b < number - a - 1 || b > number + a -1)
                    System.out.print(" ");
                else
                    System.out.print("*");
            }
            System.out.println("");
        }

        // 4개줄 아래로 뾰족한 삼각형 별 찍기
        for(int i = 0; i < number - 1; ++i) {
            for(int j = 0; j < 2 * number - i - 1; ++j) {
                if(j >= number - (number - i) + 1 && j <= number + (number - i) -3)
                    System.out.print("*");
                else
                    System.out.print(" ");
            }
            if(i != number - 2)
                System.out.println("");
        }
    }
}
