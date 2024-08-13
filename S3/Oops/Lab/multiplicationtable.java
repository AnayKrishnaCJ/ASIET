import java.util.*;
class multiplicationtable
{
	public static void main (String args[])
	{
		int i,range=0,num=0;
		Scanner S1=new Scanner(System.in);
		System.out.println("enter the number :" );
		num=S1.nextInt();
		System.out.println("enter the range :" );
		range =S1.nextInt();
		System.out.println("The multiplication table is:" );
		for(i=0;i<range;i++)
	{
	System.out.println(num+"x"+i+"="+num*i);
	}
	S1.close();
	}
}
