#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int *val;
    int count1;
    }node;
void strule(node **sud);
void frule(node **sud);
void srule(node **sud);
int isAv(node **sud,int row,int col,int num);
int isa(node **sud,int row,int col,int num);
int backtrack(node **sud, int row, int col);
int isAvailable(node **sud, int row, int col, int num);
 int count;
 int temp;
 int n;
 int k;
 int main()
 {
  int i,j;
  scanf("%d",&n);
  for(k=2;;k++)
    {if(k*k==n)
     break;
     }
  node **sud;
  sud=(node **)malloc(n*sizeof(node *));
  for(i=0;i<n;i++)
  { sud[i]=(node *)malloc(n*sizeof(node));
   for(j=0;j<n;j++)
  { sud[i][j].val=(int *)malloc(n*sizeof(int));
   scanf("%d",&sud[i][j].val[0]);
   //printf("%d\n",sud[i][j].val[0]);
   if(sud[i][j].val[0]!=0)
   {sud[i][j].count1=1;
    count++;
   }
   else
   sud[i][j].count1=0;
   }
   }
   strule(sud);
   for(i=0;i<n;i++)
   {for(j=0;j<n;j++)
	   {  if(sud[i][j].val[0]<=9)
		   printf(" %d ",sud[i][j].val[0]);
		   else
		   printf("%d ",sud[i][j].val[0]);
	}
	printf("\n");
   }
  }
   
void strule(node **sud)
{ printf("Enter Start Rule\n");
	int i,j,va;
  temp=count;
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++)
 {if(sud[i][j].count1!=1)
  {for(va=1;va<=n;va++)
  {if(isAv(sud,i,j,va))
   {sud[i][j].val[sud[i][j].count1]=va;
    sud[i][j].count1+=1;
   }
   }
   if(sud[i][j].count1==1)
     count++;
  }
  }
  }
   if(count>temp && count!=n*n)
   frule(sud);
  else if(count!=n*n)
   srule(sud);
  }
  
int isAv(node **sud,int row,int col,int num)
{
    int i, j;
    for(i=0;i<n;i++)
       { if(sud[row][i].count1==1 && i!=col)
        {if( (sud[row][i].val[0] == num)  )//chec in row
            return 0;
        }
        if(sud[i][col].count1==1 && i!=row)
        {if( sud[i][col].val[0] == num   )//chec in col
            return 0;
        }
       }
     
     //check in grid
    int rowSt = (row/k) * k;
    int colSt = (col/k) * k;

    for(i=rowSt;i<(rowSt+k);i++)
    {
        for(j=colSt;j<(colSt+k);j++)
        {   if(sud[i][j].count1==1 && (!(i==row && j==col)))
            {if( sud[i][j].val[0] == num )
                return 0;
            }
        }
    }    

    return 1;
}  

void frule(node **sud)
{   printf("Enter First Rule\n");
	int *t,i,j,va,m=0,x;
	t=(int *)malloc(n*sizeof(int));
	temp=count;
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
		{ if(sud[i][j].count1>1)
		  { m=0;
			  for(va=0;va<sud[i][j].count1;va++)
			  {if(isAv(sud,i,j,sud[i][j].val[va]))
				  {t[m]=sud[i][j].val[va];
					  m++;
				   }
			  }
			 for(x=0;x<m;x++)
			    sud[i][j].val[x]=t[x];
			    sud[i][j].count1=m;
			    if(m==1)
			    count++;
		   }
		 }
	}
	free(t);
  if(count>temp && count!=n*n)
   frule(sud );
  else if(count!=n*n)
   srule(sud);
}

void srule(node **sud)
{printf("Enter Second Rule\n");
	int i,j,va;
	temp=count;
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
		{if(sud[i][j].count1>1)
			{for(va=0;va<sud[i][j].count1;va++)
				{if(isa(sud,i,j,sud[i][j].val[va]))
					{sud[i][j].val[0]=sud[i][j].val[va];
						sud[i][j].count1=1;
						break;
					}
				}
				if(sud[i][j].count1==1)
                count++;
              }
           }
      }
  if(count>temp && count!=n*n)
   frule(sud);
  else if(count!=n*n)
   {   for(i=0;i<n;i++)
	   {for(j=0;j<n;j++)
		   {if(sud[i][j].count1>1)
			   sud[i][j].val[0]=0;
			}
	    }
	    printf("Enter Backtrack\n");
	   backtrack(sud,0,0);
	}
}

int isa(node **sud,int row,int col,int num)
{    int i,j,l=1;
    for(i=0;i<n;i++)
       { if( i!=col)
        {   for(j=0;j<sud[row][i].count1;j++)
			{if( (sud[row][i].val[j] == num))//chec in row 
           { l=0;
            break;
		    }
            }
       }
       if(l==0)
         break;
        
       }
       if(l==1)
          return 1;
        l=1;
       for(i=0;i<n;i++)
       {
         if(i!=row)
         {   for(j=0;j<sud[i][col].count1;j++)
			{if( (sud[i][col].val[j] == num))//chec in row 
            {l=0;
             break;
            }
             }
       }
        if(l==0)
         break;
       }
       if(l==1)
          return 1;
       
       
    int rowSt = (row/k) * k;
    int colSt = (col/k) * k;

    for(i=rowSt;i<(rowSt+k);i++)
    {
        for(j=colSt;j<(colSt+k);j++)
        {   if((!(i==row && j==col)))
            { for(l=0;l<sud[i][j].count1;l++)
				{if( sud[i][j].val[l] == num )
                return 0;
            }
        }
        } 
    }
    return 1;
}		
   

int backtrack(node **sud, int row, int col)
{  
  int i;
    if( row<n && col<n )
    {
        if( sud[row][col].val[0] != 0 )//pre filled 
        {
            if( (col+1)<n )
                return backtrack(sud, row, col+1);
            else if( (row+1)<n )
                return backtrack(sud, row+1, 0);
            else
                return 1;
        }
        else
        {
            for(i=0; i<n; i++)
            {
                if( isAvailable(sud, row, col, i+1) )
                {
                    sud[row][col].val[0] = i+1;

                    if( (col+1)<n )
                    {
                       if( backtrack(sud, row, col +1) )
                           return 1;
                        else
                            sud[row][col].val[0]= 0;
                    }
                    else if( (row+1)<n )
                    {
                        if( backtrack(sud, row+1, 0) )    
                            return 1;
                        else
                            sud[row][col].val[0] = 0;
                    }
                    else
                        return 1;
                }
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
} 


int isAvailable(node **sud, int row, int col, int num)
{
    int i, j;
    for(i=0; i<n; ++i)
        if( (sud[row][i].val[0] == num) || ( sud[i][col].val[0]== num )  )//checking in row and col
            return 0;

     //checking in the grid
    int rowStart = (row/k) * k;
    int colStart = (col/k) * k;

    for(i=rowStart; i<(rowStart+k); ++i)
    {
        for(j=colStart; j<(colStart+k); ++j)
        {
            if( sud[i][j].val[0] == num )
                return 0;
        }
    }    

    return 1;
}    










