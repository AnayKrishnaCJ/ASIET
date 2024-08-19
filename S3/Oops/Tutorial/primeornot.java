import java.util.*;
public class primeornot 
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        int count=0;
        System.out.println("Enter the number");
         int n=s.nextInt();
         for(int i=1;i<=n;i++)
         {
            if(n%i==0)
            {
                count++;

            
            }
            }
                if(count==2)
                {
                    System.out.println(n+" is a prime number.");
                }
            	else
		
		{
			System.out.println(n+" is not a prime number.");
		}
                count=0;
        
            
         
         s.close();


    }

}
   
