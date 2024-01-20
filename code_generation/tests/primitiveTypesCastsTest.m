@class InOutFuncs, NSString;
int main() {
    int a = 10 + 20;
    int b = 10 + 'a';
    int c = 'a' + 20;
    int d = 'a' + 'b';
    char e = 10 + 20;
    char f = 10 + 'a';
    char g = 'a' + 10;
    char h = 'a' + 'b';
    int a1 = 10 - 20;
    int b1 = 10 - 'a';
    int c1 = 'a' - 20;
    int d1 = 'a' - 'b';
    int a2 = 10 * 20;
    int b2 = 10 * 'a';
    int c2 = 'a' * 20;
    int d2 = 'a' * 'b';
    int a3 = 10 / 20;
    int b3 = 10 / 'a';
    int c3 = 'a' / 20;
    int d3 = 'a' / 'b';
    int a4 = 10 == 20;
    int b4 = 10 == 'a';
    int c4 = 'a' == 20;
    int d4 = 'a' == 'b';
    int a5 = 10 != 20;
    int b5 = 10 != 'a';
    int c5 = 'a' != 20;
    int d5 = 'a' != 'b';
    int a6 = 10 < 20;
    int b6 = 10 < 'a';
    int c6 = 'a' < 20;
    int d6 = 'a' < 'b';
    int a7 = 10 > 20;
    int b7 = 10 > 'a';
    int c7 = 'a' > 20;
    int d7 = 'a' > 'b';
    int a8 = 10 <= 20;
    int b8 = 10 <= 'a';
    int c8 = 'a' <= 20;
    int d8 = 'a' <= 'b';
    int a9 = 10 >= 20;
    int b9 = 10 >= 'a';
    int c9 = 'a' >= 20;
    int d9 = 'a' >= 'b';
    
    [InOutFuncs printCharArray: "Plus"];
    [InOutFuncs printInt: a];
    [InOutFuncs printInt: b];
    [InOutFuncs printInt: c];
    [InOutFuncs printInt: d];
    [InOutFuncs printChar: e];
    [InOutFuncs printChar: f];
    [InOutFuncs printChar: g];
    [InOutFuncs printChar: h];
    
    [InOutFuncs printCharArray: "\nMinus"];
    [InOutFuncs printInt: a1];
    [InOutFuncs printInt: b1];
    [InOutFuncs printInt: c1];
    [InOutFuncs printInt: d1];
    
    [InOutFuncs printCharArray: "\nMul"];
    [InOutFuncs printInt: a2];
    [InOutFuncs printInt: b2];
    [InOutFuncs printInt: c2];
    [InOutFuncs printInt: d2];
    
    [InOutFuncs printCharArray: "\nDiv"];
    [InOutFuncs printInt: a3];
    [InOutFuncs printInt: b3];
    [InOutFuncs printInt: c3];
    [InOutFuncs printInt: d3];
    
    [InOutFuncs printCharArray: "\nEqual"];
    [InOutFuncs printInt: a4];
    [InOutFuncs printInt: b4];
    [InOutFuncs printInt: c4];
    [InOutFuncs printInt: d4];
    
    [InOutFuncs printCharArray: "\nNotEqual"];
    [InOutFuncs printInt: a5];
    [InOutFuncs printInt: b5];
    [InOutFuncs printInt: c5];
    [InOutFuncs printInt: d5];
    
    [InOutFuncs printCharArray: "\nLess"];
    [InOutFuncs printInt: a6];
    [InOutFuncs printInt: b6];
    [InOutFuncs printInt: c6];
    [InOutFuncs printInt: d6];
    
    [InOutFuncs printCharArray: "\nGreater"];
    [InOutFuncs printInt: a7];
    [InOutFuncs printInt: b7];
    [InOutFuncs printInt: c7];
    [InOutFuncs printInt: d7];
    
    [InOutFuncs printCharArray: "\nLessEqual"];
    [InOutFuncs printInt: a8];
    [InOutFuncs printInt: b8];
    [InOutFuncs printInt: c8];
    [InOutFuncs printInt: d8];
    
    [InOutFuncs printCharArray: "\nGreaterEqual"];
    [InOutFuncs printInt: a9];
    [InOutFuncs printInt: b9];
    [InOutFuncs printInt: c9];
    [InOutFuncs printInt: d9];

    // Ошибки
    // int tmp;
    // tmp = 10/0;

    //NSString *str = 1;
}