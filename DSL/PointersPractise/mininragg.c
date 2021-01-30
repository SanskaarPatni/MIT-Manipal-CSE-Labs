#include<stdio.h>
#include<stdlib.h>
int main(){
int rowNum, colNum, i, j;
int **table;
printf("\n enter the number of rows \n");
scanf("%d", &rowNum);
table = (int **) calloc(rowNum+1, sizeof(int *));
for (i = 0; i < rowNum; i++) /* this will tell which row we are in */
{
printf("enter size of %d row", i+1);
scanf("%d", &colNum);
table[i] = (int *) calloc(colNum+1, sizeof(int));
printf("\n enter %d row elements ", i+1);
for (j = 1; j <= colNum; j++)
{
scanf("%d", &table[i][j]);
}
table[i][0] = colNum;
printf("size of row number [%d] = %d", i+1, table[i][0]);
}
table[i] = NULL;
int min=(*(*table)+1);
for (i = 0; i < rowNum; i++) /* this will tell which row we are in */
{
printf("displaying %d row elements\n", i+1);
for (j = 1; j <= *table[i]; j++)
{
	if (table[i][j]<min){
		min=table[i][j];
	}
printf("%5d", table[i][j]);
}
printf("\n");
}
printf("Minimum value in the ragged array  is %d",min);

printf("Minimum value in row :\n");
int f;
scanf("%d",&f);
int new=*(*(table+f-1)+1);
for(j=1;j<=*table[f-1];j++){
	if(table[f-1][j]<min){
		min=table[f-1][j];
	}
}
printf("%d\n",min );
//freeup the memory
for (i = 0; i < rowNum; i++) {
free(table[i]);
}
free(table);
return 0;
}