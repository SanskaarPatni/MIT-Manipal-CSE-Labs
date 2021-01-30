#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void getData(double *a,double *b,double *c){
scanf("%lg",a);
scanf("%lg",b);
scanf("%lg",c);
}
void findRoots(double *x,double *y,double *z){
d=(*b)*(*b)-4*(*a)*(*c);
printf("Value of d is:\n%d",d);
if(d>0){
  *x=-(*b)/(2*(*a));
  *y=-sqrt(-det)/(2*abs(*a));
}
else if(d<0){
   *x=(-(*b))/(2*(*a));
   *y=0;
}


else{
	 *x=(-(*b))/(2*(*a));
	 *y=sqrt(det)/(2*(*a));

}
}
void printRoots(){
	+

}
int main(){
double *a=(double *)malloc(sizeof(double));
double *b=(double *)malloc(sizeof(double));
double *c=(double *)malloc(sizeof(double));
double *x=(double *)malloc(sizeof(double));
double *y=(double *)malloc(sizeof(double));

getData(a,b,c);
findRoots(a,b,c,x,y,z);
printRoots(x,y);
free(a);
free(b);
free(c);
free(x);
free(y);
return 0;
}