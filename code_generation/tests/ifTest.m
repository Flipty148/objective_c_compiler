@class InOutFuncs;

@implementation MyClass : NSObject
@end

int main() {
    int a;
    int b;
    int c;
    int d;
    
    [InOutFuncs printCharArray: "Input a:"];
    a = [InOutFuncs readInt];
    
    [InOutFuncs printCharArray: "Input b:"];
    b = [InOutFuncs readInt];
    
    [InOutFuncs printCharArray: "Input c:"];
    c = [InOutFuncs readInt];
    
    [InOutFuncs printCharArray: "Input d:"];
    d = [InOutFuncs readInt];
    

    
    if (a == b) {
        [InOutFuncs printCharArray: "a == b"];
    }
    else {
        [InOutFuncs printCharArray: "a != b"];
    }
    
    if (a == b) {
        [InOutFuncs printCharArray: "a == b"];
    }
    
    if (a == b) {
        
    }
    else {
        [InOutFuncs printCharArray: "a != b"];
    }
    
    if (a == b) {
        
    }
    else {
        
    }
    
    if (a == b)
        [InOutFuncs printCharArray: "a == b"];
    else
        [InOutFuncs printCharArray: "a != b"];
        
    if (a == b)
        [InOutFuncs printCharArray: "a == b"];
        
    MyClass *obj;
    // obj = [MyClass new];
    
    if (a == b) {
        if (obj) {
            [InOutFuncs printCharArray: "a == b, true"];
        }
        else {
            [InOutFuncs printCharArray: "a == b, false"];
        }
    }
    else {
        if (obj) {
            [InOutFuncs printCharArray: "a != b, true"];
        }
        else {
            [InOutFuncs printCharArray: "a != b, false"];
        }
    }
    
    if (a == b) {
        [InOutFuncs printCharArray: "a == b"];
    }
    else if (c < d) {
        [InOutFuncs printCharArray: "c < d"];
    }
    else {
        [InOutFuncs printCharArray: "a != b, c >= d"];
    }
}
