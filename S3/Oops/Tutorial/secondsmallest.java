import java.util.*;
class secondsmallest 
{
    public static void main(String args[])
     {
        int a[];
        int i, j, temp, num;
        Scanner S = new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        num =S.nextInt();
        a = new int[50];
        System.out.println("Enter the elements of the array:");
        for (i = 0; i < num; i++) 
        {
            a[i] =S.nextInt();
        }
        for (i = 0; i < num - 1; i++) 
        {
            for (j = 0;j<num-i-1;j++) 
            {
                if (a[j]>a[j+1]) 
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        System.out.println("The Second Smallest Element is : "+a[1]);
        S.close();  
}
}
