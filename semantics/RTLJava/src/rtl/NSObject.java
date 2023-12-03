package rtl;

public class NSObject {

    /**
     * Метод выделения памяти. <br/>
     * + (id)alloc
     * */
    public static <T extends NSObject> T allocStatic() {
        return (T) new NSObject();
    }

    /**
     * Метод инициализации. <br/>
     * - (id)init
     * */
    public <T extends NSObject> T init() {
        return (T) this;
    }

    /**
     * Создание нового объекта. Объединяет alloc и init.
     * В objective-c это new. <br/>
     * + (id)new
     * */
    public static <T extends NSObject> T newObject() {
        return T.allocStatic().init();
    }

    /**
     * Возвращает класс. <br/>
     * - (Class)class
     * */
    public Class<? extends NSObject> getclass() {
        return this.getClass();
    }

    /**
     * Возвращает класс. <br/>
     * + (Class)class
     * */
    public static Class<? extends NSObject> getclassStatic() {
        return NSObject.class;
    }

    /**
     * Проверяет является ли класс самим классом или его подклассом
     * @param aClass Класс
     * @return Является ли класс самим классом или его подклассом
     */
    public static  boolean isSubclassOfClassStatic(Class<? extends NSObject> aClass) {
        return getclassStatic().isAssignableFrom(aClass);
    }

    /**
     * Возвращает имя класса
     * @return Имя класса
     * //TODO заменить на NSString
     */
    public String className() {
        return getclass().getName();
    }

    /**
     * Возвращает суперкласс
     * @return суперкласс
     */
    public Class<?> superclass() {
        return getclass().getSuperclass();
    }
}

