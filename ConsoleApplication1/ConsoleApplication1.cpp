// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Parser.h"
using namespace std;

int main()
{
    Parser parser = Parser("test.txt");
    parser.parse();
    return 0;
}

