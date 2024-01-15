package rtl;

public class InOutFuncs {

    //---------- Print Methods ----------
    public static void printIntStatic(int i) {
        System.out.println(i);
    }

    public static void printCharStatic(char c) {
        System.out.println(c);
    }

    public static void printStringStatic(String s) {
        System.out.println(s);
    } //TODO Возможно стоит заменить на NSString

    public static void printCharArrayStatic(char[] s) {
        System.out.println(s);
    }

    public static void printObjectStatic(Object o) {
        System.out.println(o);
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
