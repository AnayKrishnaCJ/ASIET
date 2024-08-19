import java.util.*;
class multitable
{
	public static void main(String[] args)
        {
	int i;
	Scanner s= new Scanner(System.in);
	System.out.println("Enter the number:");
	int n=s.nextInt();
	System.out.println("Enter the range");
	int range=s.nextInt();
	System.out.println("Multiplication table:");
	for(i=1;i<=range;i++)
	{
		System.out.println(n+"x"+i+"="+(n*i));
	}
	s.close();
	}
}	        
