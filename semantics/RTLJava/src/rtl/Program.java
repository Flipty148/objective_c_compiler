package rtl;

public class Program {

    //---------- Print Methods ----------
    public static void printInt(int i) {
        System.out.print(i);
    }

    public static void printChar(char c) {
        System.out.print(c);
    }

    public static void printString(String s) {
        System.out.print(s);
    } //TODO Возможно стоит заменить на NSString

    public static void printCharArray(char[] s) {
        System.out.print(s);
    }

    public static void printObject(Object o) {
        System.out.print(o);
    } //TODO Возможно стоит заменить на NSObject

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
