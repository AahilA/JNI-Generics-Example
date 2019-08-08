public class Hello {
    private native void jniSayHello();
    private native void jniSayHello(int a);
    private native <T> void jniSayClass(T t); 
    private native <T> void jniLoadObject(T t);

    static {
	try{
            System.loadLibrary("Hello");
	} catch (UnsatisfiedLinkError e){
	    System.out.println(e.getMessage());	
	}
    }

    static public void main(String[] args) {
        System.out.println("Hello from main.");
        Hello o = new Hello();
	Test peter = new Test();
        o.jniSayHello();
	o.jniSayHello(5);
        o.jniSayClass(peter);
	o.jniLoadObject(peter);
    }
}

class Test{
    String p;
    Test(){
        p="Peter";
    }
    void Peter(){
        System.out.println("Hello From Test");
    }
    void Aahil(){
	System.out.println("Hello from Aahil");
    }
}

