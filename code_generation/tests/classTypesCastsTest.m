@implementation MyClass1 : NSObject
@end

@implementation MyClass2 : MyClass1
- (void) func {
    return;
}
@end

@implementation MyClass3 : NSObject
@end

int main ()
{
    MyClass1 *obj1 = [MyClass1 new];
    MyClass2 *obj2 = obj1;
    
    MyClass2 *obj3 = [MyClass2 new];
    MyClass2 *obj4 = obj3;
    
    //В оригинальном компиляторе такое возможно. Однако, JVM не разрешает использовать различные типы для создания и инициализации объекта.
    //Поэтому у меня запрещено преобразовывать типы классов, если они не являются родительскими или дочерними.
    // MyClass2 *obj5 = [MyClass3 new];
    // MyClass2 *obj6 = obj5;
    // MyClass2 *obj5;
    // obj5 = [MyClass3 new];

    // //Ошибки
    // [obj5 func];
}
