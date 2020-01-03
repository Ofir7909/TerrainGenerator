#include <iostream>

#include <forge.h>

int main(int argc, char** argv)
{
    std::cout<< "Hello World" <<std::endl;
    int errorCode = forge::Example();

    return errorCode;
}