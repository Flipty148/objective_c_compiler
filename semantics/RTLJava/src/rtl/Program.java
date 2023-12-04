package rtl;

public class Program {

    //---------- Print Methods ----------
    public static void print(int i) {
        System.out.print(i);
    }

    public static void print(char c) {
        System.out.print(c);
    }

    public static void print(String s) {
        System.out.print(s);
    }

    public static void print(char[] s) {
        System.out.print(s);
    }

    public static void print(Object o) {
        System.out.print(o);
    }

    //---------- Read Methods ----------
    /**
     * Считывает строку с консоли
     * */
    public static String read() {
        return  System.console().readLine();
    }

    /**
     * Считывает целое число с консоли
     * */
    public static int readInt() {
        return  Integer.parseInt(read());
    }

    /**
     * Считывает символ с консоли
     * */
    public static char readChar() {
        return  read().charAt(0);
    }
}