
### 2.5.7

The program below takes in any user input, checks for the correct type by checking for letters or decimal points and outputs the hexadecimal byte representation of the integer if it passes these checks.

```c++

void test_int(string &start, size_t len){
    int i;
    int e=0;
    for (i=0; i < len; i++)
    {
    if(start[i] == 0x2e || start[i] <0x30 || start[i] > 0x39 ) throw e;
    
    }
   
   
}


int main()

{
    string anyNumber;
    cout << "Input any number\n";
    cin >> anyNumber;
    try{
        test_int(anyNumber, anyNumber.length());


    } catch(int notInt)
    {
        cout << "Not an integer, exiting\n";
        exit(0);
    }

    test_show_bytes(stoi(anyNumber));
  

}
```

### 2.5.8

The program checks whether the machine its running on is big or little endian by checking whether the first byte in memory is the least or most significant of a test number consiting of two bytes. Little endians would store the least significant digit at the "top" of the stack/ at the lowest memory address (explored further in chapter 3).
```c++

int is_little_indian(){
    int test_byte = 0xffee;
    byte_pointer start = (byte_pointer) &test_byte;
    if (start[0] == 0xff){
        return 0;

    } else {
        return 1;
    }

}
int main (){
int whatis = is_little_indian();
cout << (( whatis == 0) ? "This machine is Little Endian" : "This machine is Big Endian");


}
```

### 2.6.0

Making use of byte.cpp again, the function replace_byte changes the value of a byte according to its location as given by the variable loc. It is quick and easy in that sense.
```c++


int replace_byte(unsigned &old_hex, int loc, unsigned rep_hex){
    byte_pointer new_hex = (byte_pointer) &old_hex;
    new_hex[loc] = rep_hex;
}
int main (){
    unsigned x = 0x12345678;
cout << "Previously, the old hex was "; 
show_bytes((byte_pointer) &x, sizeof(unsigned)); 
cout << "The new hex is "; replace_byte(x, 2, 0xAB);
show_bytes((byte_pointer) &x, sizeof(unsigned)); 

}
```
### 2.6.1

The program checks whether a 1 or a 0 is in the binary representation of a given number by performing a XOR test with 0 or ~0 in the latter case. This works for any word size. It also checks the least and most significant bytes for any bits equal to 1 or 0 respectively, by shifting (exploiting the fact that any number left shifted by k is multiplied by 2^k), and performing a XOR test with 0x0.
```c++

int main (){
int anyNum;
cout << "Input any number including zero" << endl;
cin >> anyNum;
int bit_test = anyNum ^ 0x0;
bool bits = !!bit_test;
cout << "Number includes a 1 somewhere:" << bits << endl;

bit_test = anyNum ^ ~0x0;
bits = !!bit_test;
cout << "Number includes a 0 somewhere:" <<  bits << endl;

int shift_val = (sizeof(int)-1)<<3;
char msb = (char) (anyNum >> shift_val);
char lsb = (char) anyNum;
char bit_test_new = lsb ^ 0x00;
bits = !!bit_test_new;

cout << "Number includes a 1 in the least signfificant bit:" << bits<< endl;

bit_test_new = msb ^ 0x00;
bits = !!bit_test_new;
cout<< msb;
cout << "Number includes a 1 in the most signfificant bit:" << bits<< endl;

}
```
### 2.6.2

Testing whether a particular machine performs arithmetic or logical shifts, a test number (negative 1 or all ones in binary two's complement) is right shifted to its last bit and tested with yet another XOR operation.
```c++

int int_shifts_are_arithmetic (){
    int testNum= -1;
    int shift_size = ((sizeof(int) -1) << 3) + 7;

    int newNum = testNum >> shift_size;
    cout << newNum << endl;
    bool res;
    res = (newNum ^ testNum);
    return res;

}


int main (){

int endresults = int_shifts_are_arithmetic();
    cout << "This machine performs uses right shifts that are: "<<endl;
    cout << "Arithmetic: " << endresults << endl;
    cout << "Logical: " << !endresults <<endl;


}
```
### 2.6.3

The idea of both these functions is to perform right shifts by firstly shifting with their counter opposites and then filling in missing operations. For example, srl performs logical right shift by first doing an arithmetic right shift (casting as unsigned), and then creating a new variable with all ones where the positions in the x variable were zero extended, and finally combined both with an OR operation sra follows the same logic.
```c++

unsigned srl (unsigned x, int k){
    unsigned xsra = (int) x >> k;
    int size = sizeof(int) * 8;
    return (xsra | ~(0x1 << (size -1)) >> k);
}

signed sra(int x, int k){
    int xsrl = (unsigned) x>>k;
    int size = sizeof(int) * 8;
    return (xsrl | ~(0x1 << (size -1)) >> k);
}
```
### 2.6.4

The code returns a 1 when any odd bit of x equals 1. It does so by making use of the fact that the hex A has 1's in all even positions. x OR 0xAA...AA should equal 0xAA...AA itself if x has 1's in even spots only.
```c++

int any_odd_one(unsigned x){
return ( (x | 0xAAAAAAAA) == 0xAAAAAAAA);
}

int main (){

int anyNum;
cout << "Input any number including zero" << endl;
cin >> anyNum;
int bit_test = any_odd_one(anyNum);
cout << "Number includes an odd 1 bit somewhere:" << bit_test << endl;
}
```

### 2.6.5

