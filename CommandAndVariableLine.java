class A
{  
    public static void main(String args[])
    {  
        for(int i=0;i<args.length;i++)  
        System.out.println(args[i]);  
    }  
}  

// compile by > javac A.java  
// run by > java A sonoo jaiswal 1 3 abc  

class VarargsExample2
{  
   
   static void display(String... values)
  {  
      System.out.println("display method invoked ");  
      for(String s:values)
      {  
       System.out.println(s);  
      }  
   }  
  
   public static void main(String args[]){  
    
   display();//zero argument   
   display("hello");//one argument   
   display("my","name","is","varargs");//four arguments  
   }   
} 
