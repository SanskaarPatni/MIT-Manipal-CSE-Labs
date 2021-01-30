package myPackages.p1;
public class Maximum{
 public int max(int a,int b,int c){
		int big=a>b?a>c?a:c:b>c?b:c;
		return big;

	}
    public float max(float a,float b,float c){
		float big=a>b?a>c?a:c:b>c?b:c;
		return big;
	}
	public int max(int a[]){
		int big=a[0];
		for(int i=0;i<a.length;i++){
			if(a[i]>big){
				big=a[i];
			}
		}
		return big;
	}
	public int max(int a[][]){
		int max=a[0][0];
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a[i].length;j++){
				if(a[i][j]>max){
					max=a[i][j];
				}
			}
		}
		return max;
	}

}
