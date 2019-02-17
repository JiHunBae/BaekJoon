package newTest;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String copy_String = new String();
        
        while(sc.hasNextLine()) {
            copy_String = sc.next();
            if(!(copy_String.isEmpty() | copy_String.length() > 100))
            	System.out.println(copy_String);
        }
    }
}