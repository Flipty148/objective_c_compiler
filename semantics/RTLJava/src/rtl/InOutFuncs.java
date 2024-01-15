package rtl;

public class InOutFuncs {

    //---------- Print Methods ----------
    public static void printIntStatic(int i) {
        System.out.print(i);
    }

    public static void printCharStatic(char c) {
        System.out.print(c);
    }

    public static void printStringStatic(String s) {
        System.out.print(s);
    } //TODO Возможно стоит заменить на NSString

    public static void printCharArrayStatic(char[] s) {
        System.out.print(s);
    }

    public static void printObjectStatic(Object o) {
        System.out.print(o);
    } //TODO Возможно стоит заменить на NSObject

    //---------- Read Methods ----------
    /**
     * Считывает строку с консоли
     * */
    public static String readStatic() {
        return  System.console().readLine();
    }

    /**
     * Считывает целое число с консоли
     * */
    public static int readIntStatic() {
        return  Integer.parseInt(readStatic());
    }

    /**
     * Считывает символ с консоли
     * */
    public static char readCharStatic() {
        return  readStatic().charAt(0);
    }
}
