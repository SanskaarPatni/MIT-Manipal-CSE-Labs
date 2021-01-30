import java.util.*; 
  
class posttopre
{ 
  
// funtion to check if character  
// is operator or not 
static boolean isOperator(char x)  
{ 
    switch (x)  
    { 
        case '+': 
        case '-': 
        case '/': 
        case '*': 
        return true; 
    } 
    return false; 
} 
  
// Convert prefix to Postfix expression 
static String Posttopre(String post) 
{ 
  
    Stack<String> s= new Stack<String>(); 
  
    // length of expression 
    int length = post.length(); 
  
    // reading from right to left 
    for (int i =0;i<length;i++)  
    { 
  
        // check if symbol is operator 
        if (isOperator(post.charAt(i)))  
        { 
  
            // pop two operands from stack 
            String op1 = s.peek(); s.pop(); 
            String op2 = s.peek(); s.pop(); 
  
            // concat the operands and operator 
            String temp = post.charAt(i)+op2+op1; 
  
            // Push String temp back to stack 
            s.push(temp); 
        } 
  
        // if symbol is an operand 
        else
        { 
            // push the operand to the stack 
            s.push( post.charAt(i)+""); 
        } 
    } 
  
    // stack contains only the Postfix expression 
    return s.peek(); 
} 
  
// Driver Code 
public static void main(String args[])  
{ 
    //String pre_exp = "*-A/BC-/AKL"; 
    String post="ABC/-AK/L-*";
    System.out.println("Postfix : " + Posttopre(post)); 
} 
} 