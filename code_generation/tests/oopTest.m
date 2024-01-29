@class InOutFuncs;
@implementation MyClass1 : NSObject
- (void) print {
    [InOutFuncs printCharArray: "call method print from class 'MyClass1'"];
}
@end

@implementation MyClass2 : MyClass1
- (void) print {
    [InOutFuncs printCharArray: "call method print from class 'MyClass2'"];
}
@end

@implementation MyClass3 : MyClass1
- (void) print {
    [InOutFuncs printCharArray: "call method print from class 'MyClass3'"];
    [super print];
}
@end

 @implementation MyClass4 : MyClass2
@end

int main ()
{
    MyClass1 *obj1 = [MyClass1 new];
    MyClass2 *obj2 = [MyClass2 new];
    MyClass3 *obj3 = [MyClass3 new];
    
    MyClass1 *objects[] = { obj1, obj2, obj3, [MyClass4 new] };
    
    for (int i=0; i<4; i = i + 1) {
        [objects[i] print];
    }
}
