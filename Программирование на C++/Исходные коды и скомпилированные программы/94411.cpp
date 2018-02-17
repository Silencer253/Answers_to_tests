#include <iostream>
#include <typeinfo>

int main()
{
    typedef int function_type() ;
    typedef function_type* pointer_type ;
    typedef pointer_type array_type[5] ;

    array_type a ;

    int (*p[5])() ;

    std::cout << "both a and b are of the same type: " << std::boolalpha
              << ( typeid(a) == typeid(p) ) << '\n' ;
}