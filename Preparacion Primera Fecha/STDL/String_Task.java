import java.util.Scanner;
public class String_Task
{
    public static void main(String ars[])
    {
        Scanner scanner = new Scanner(System.in);
        String cad = scanner.next().toLowerCase();
        scanner.close();
        StringBuilder ans = new StringBuilder();
        String vowels = "aoyeui";
        for(char c : cad.toCharArray())
        {
            if(vowels.indexOf(c) == -1)
            {
                ans.append('.').append(c);
            }
        }
        System.out.println(ans);
    }
}