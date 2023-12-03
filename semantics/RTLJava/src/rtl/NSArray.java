package rtl;

import java.lang.reflect.Array;

public class NSArray extends NSObject {

    private NSObject[] array;
    private NSArray() {
        array = new NSObject[0];
    }

    private NSArray(NSArray array) {
        this.array = array.array;
    }

    private NSArray(NSObject[] array) {
        this.array = array;
    }

    /**
     * Возвращает пустой массив. <br/>
     * + (id)array
     * */
    public static NSArray arrayStatic() {
        return new NSArray();
    }

    /**
     * Создает новый массив на основе другого массива. <br/>
     * + (id)arrayWithArray: (NSArray *)array
     * */
    public static NSArray arrayWithArrayStatic(NSArray array) {
        return new NSArray(array);
    }

    /**
     * Создает новый массив на основе объектов. <br/>
     * + (id)arrayWithObjects: (id)firstObject,...
     * */
    public static NSArray arrayWithObjectsStatic(NSObject... objects) {
        return new NSArray(objects);
    }

    /**
     * Создает новый массив на основе объекта. <br/>
     * + (id)arrayWithObjects: (id)anObject
     * */
    public static NSArray arrayWithObjectStatic(NSObject object) {
        return new NSArray(new NSObject[] {object});
    }

    /**
     * Возвращает массив с добавленным элементом. <br/>
     * - (NSArray *)arrayByAddingObject: (id)anObject
     * */
    public NSArray arrayByAddingObject(NSObject object) {
        NSObject[] res = new NSObject[array.length+1];
        for (int i = 0; i < array.length; i++) {
            res[i] = array[i];
        }
        res[array.length] = object;
        return new NSArray(res);
    }

    /**
     * Возвращает новый массив конкатенацией другого массива. <br/>
     * - (NSArray *)arrayByAddingObjectsFromArray: (NSArray *)anotherArray
     * */
    public NSArray arrayByAddingObjectsFromArray(NSArray anotherArray) {
        NSObject[] res = new NSObject[array.length+anotherArray.array.length];
        for (int i = 0; i < array.length; i++) {
            res[i] = array[i];
        }
        for (int i = 0; i < anotherArray.array.length; i++) {
            res[array.length+i] = anotherArray.array[i];
        }
        return new NSArray(res);
    }

    /**
     * Возвращает строку, состоящую из элементов массива. <br/>
     * - (NSString *)componentsJoinedByString: (NSString *)separator
     * */
    public NSString componentsJoinedByString(NSString separator) {
        String res = "";
        String sep = new String(separator.cString());
        for (int i = 0; i < array.length; i++) {
            res += array[i].description() + sep;
        }
        return NSString.stringWithCStringStatic(res.toCharArray());
    }

    /**
     * Проверяет содержится ли объект в массиве. <br/>
     * - (BOOL)containsObject: (id)anObject
     * */
    public boolean containsObject(NSObject object) {
        for (NSObject o : array) {
            if (o == object) {
                return true;
            }
        }
        return false;
    }

    /**
     * Возвращает количество элементов в массиве. <br/>
     * - (NSUInteger)count
     * */
    public int count() {
        return array.length;
    }


    public NSString description() {
        return NSString.stringWithCStringStatic("nsarray implementation".toCharArray());
    }

    //TODO МБ добавить enumeration

    /**
     * Возвращает первый элемент массива. <br/>
     * - (id)firstObject
     * */
    public NSObject firstObject() {
        if (array.length == 0) {
            return null;
        }
        return array[0];
    }

    /**
     * Возвращает первый элемент массива, содержащийся в другом массиве. <br/>
     * - (id)firstObjectCommonWithArray: (NSArray *)otherArray
     * */
    public NSObject firstObjectCommonWithArray(NSArray array) {
        for (NSObject o : array.array) {
            if (this.containsObject(o)) {
                return o;
            }
        }
        return null;
    }

    /**
     * Копирует объекты в buffer. <br/>
     * - (void)getObjects: (id [])buffer
     * */
    public void getObjects(NSObject[] buffer) {
        System.arraycopy(array, 0, buffer, 0, array.length);
    }

    /**
     * Возвращает индекс объекта в массиве. <br/>
     * - (NSUInteger)indexOfObject: (id)anObject
     * */
    public int indexOfObject(NSObject object) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == object) {
                return i;
            }
        }
        return -1; //TODO В оригинале NSNotFound
    }

    public NSArray init() {
        super.init();
        return this;
    }

    /**
     * Проверяет равен ли массив другому. <br/>
     * - (BOOL)isEqualToArray: (NSArray *)otherArray
     * */
    public boolean isEqualToArray(NSArray otherArray) {
        if (array.length != otherArray.array.length) {
            return false;
        }
        for (int i = 0; i < array.length; i++) {
            if (!array[i].isEqual(otherArray.array[i])) {
                return false;
            }
        }
        return true;
    }

    /**
     * Возвращает последний элемент массива. <br/>
     * - (id)lastObject
     * */
    public NSObject lastObject() {
        if (array.length == 0) {
            return null;
        }
        return array[array.length-1];
    }

    /**
     * Возвращает элемент массива по индексу. <br/>
     * - (id)objectAtIndex: (NSUInteger)index
     * //TODO Заменить на NSInteger
     * */
    public NSObject objectAtIndex(int index) {
        return array[index];
    }
}
