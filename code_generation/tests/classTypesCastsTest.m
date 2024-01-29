@implementation MyClass1 : NSObject
@end

@implementation MyClass2 : MyClass1
@end

int main ()
{
    MyClass1 *obj1 = [MyClass1 new];
    MyClass2 *obj2 = obj1;
    
    MyClass2 *obj3 = [MyClass2 new];
    MyClass2 *obj4 = obj3;
}
