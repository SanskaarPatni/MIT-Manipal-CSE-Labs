  public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    int a[]=new int[N] ;
    for(int i=0;i<N;i++){
        a[i]=sc.nextInt();
    }
    HashMap<Integer,Integer>map= new HashMap<Integer,Integer>();
    for(int i : a){
        if(map.containsKey(i)){
           map.put(i,map.get(i)+1);
            }
    else{
            map.put(i,1);
        }
    }
    for(int i:map.keySet()){
        if(map.get(i)%2!=0){
            System.out.println(i);
        }
    }
        
    }