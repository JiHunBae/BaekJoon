import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();

        for (int i = 0; i < number; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int result = 0;
            switch(a % 10) {
                case 0 : // 밑의 일의자리가 0인경우 (10의 배수)
                    result = 10;
                    break;
                case 2 : // 밑의 일의자리가 2인 경우
                    if(b % 4 == 0) // 지수가 4의 배수인 경우
                        result = 6;
                    else if(b % 4 == 1) // 지수를 4로 나누었을 때 나머지가 1인 경우
                        result = 2;
                    else if(b % 4 == 2) // 지수를 4로 나누었을때 나머지가 2인 경우
                        result = 4;
                    else // 지수를 4로 나누었을 때 나머지가 3인 경우
                        result = 8;
                    break;
                case 3: // 밑의 일의자리가 3인 경우
                    if(b % 4 == 0) // 이하 %4 연산은 위의 주석(Comment)내용과 동일
                        result = 1;
                    else if(b % 4 == 1)
                        result = 3;
                    else if(b % 4 == 2)
                        result = 9;
                    else
                        result = 7;
                    break;
                case 4 :
                    if(b % 2 == 0) // 지수가 2의 배수인 경우
                        result = 6;
                    else // 자수를 2로 나누었을 때 나머지가 1인 경우
                        result = 4;
                    break;
                case 7 :
                    if(b % 4 == 0)
                        result = 1;
                    else if(b % 4 == 1)
                        result = 7;
                    else if(b % 4 == 2)
                        result = 9;
                    else
                        result = 3;
                    break;
                case 8 :
                    if(b % 4 == 0)
                        result = 6;
                    else if(b % 4 == 1)
                        result = 8;
                    else if(b % 4 == 2)
                        result = 4;
                    else
                        result = 2;
                    break;
                case 9 :
                    if(b % 2 == 0) // % 2 연산은 위에 있는 주석(Comment)내용과 동일함
                        result = 1;
                    else
                        result = 9;
                    break;
                default :
                    // 밑의 일의 자리가 (1, 5, 6)인 경우 어떤 지수가 와도 일의 자리가 변하지 않는 점을 이용
                    result = a % 10;
                    break;
            }
            System.out.println(result);
        }
    }
}
