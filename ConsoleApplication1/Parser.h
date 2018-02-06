#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Parser
{
private:
    const char END_OF_STRING = '\0';
    const char END_OF_LINE = '\n';
    const char TAB = '\t';
    const char SPACE = ' ';

    int totalCodeLength;
    int cursorPosition;
    int tokenPosition;
    char currentChar;
    char nextChar;
    char currentToken[100];
    string inputCode;
    //string currentToken;

    void readNextChar();
    void clearTokenArray();
    void parseProcedure();
    void tokenise();
    bool constructToken();

public:
    Parser(string filename);
    void parse();


};