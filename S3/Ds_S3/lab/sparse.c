//program for addition of sparse matrix
//Devika P Sajith
//roll no:26
#include<stdio.h>	
void printSparseMatrix(int sparse[50][3], int row, int col, int numNonZero) 
{
    int normalMatrix[row][col];
    
    for (int i = 0; i < row ;i++) {
        for (int j = 0; j < col; j++) {
            normalMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < numNonZero; i++) {
        normalMatrix[sparse[i][0]][sparse[i][1]] = sparse[i][2];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", normalMatrix[i][j]);
        }
        printf("\n");
    }
}
void main()
{
         int t1[50][3], t2[50][3], sum[50][3];
         int i = 0, j = 0, k = 0, count = 0;
         int m, n,row,col;
	printf("enter the number of rows and columns");
	scanf("%d%d",&row,&col);
	printf("enter the non zero elements in t1");
	scanf("%d",&m);
	printf("enter the elements of t1:\n");
	for(i=0;i<row;i++)
	{
		scanf("%d%d%d",&t1[i][0],&t1[i][1],&t1[i][2]);
	}
	
	printf("enter the elements of t2\n");
	for(j=0;j<n;j++)
	{
		scanf("%d%d%d",&t2[j][0],&t2[j][1],&t2[j][2]);
		
	}
	printf("\nSparse Matrix t1:\n");
   	printSparseMatrix(t1, row, col, m);

    	printf("\nSparse Matrix t2:\n");
    	printSparseMatrix(t2, row, col, n);
    	i=0;j=0;
    	while(i<m&&j<n)
    	{
	if( t1[i][0]<t2[j][0])
	{
		sum[k][0]=t1[i][0];
		sum[k][1]=t1[i][1];
		sum[k][2]=t1[i][2];
		i++,k++,count++;
	}
	else if( t1[i][0]<t2[j][0])
	{
		sum[k][0]=t1[i][0];
		sum[k][1]=t1[i][1];
		sum[k][2]=t1[i][2];
	}
	else if(t1[i][1]==t2[j][0])
	
	{
		sum[k][0]=t1[i][0];
		sum[k][1]=t1[i][1];
		sum[k][2]=t1[i][2];
		i++,k++,count++;
	}
	else
	{
	sum[k][0]=t2[j][0];
		sum[k][1]=t2[j][1];
		sum[k][2]=t2[j][2];
		j++,k++,count++;
	}
	}
		
	while(i<m)
	{
		sum[k][0]=t1[i][0];
		sum[k][1]=t1[i][1];
		sum[k][2]=t1[i][2];
		i++,k++,count++;
	}
	while(j<n)
	{
		sum[k][0]=t2[j][0];
		sum[k][1]=t2[j][1];
		sum[k][2]=t2[j][2];
		j++,k++,count++;
	}
	printf("the resultant matrix is\n");
	for(int i=0;i<count;k++)
	{
	printf("%d%d%d",sum[k][0],sum[k][1],sum[k][2]);
	}

}	
	
	
	


