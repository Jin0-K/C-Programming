/*
The compiler can't determine which function should be called 
when the function with no parameter, such as SimpleFunc() is called.
*/

int SimpleFunc(int a=10) {
    return a+1;
}

int SimpleFunc(void) {
    return 10;
}

int main(void) {
    SimpleFunc();

    return 0;
}