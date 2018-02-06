#include "stdafx.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

Parser::Parser(string filename)
{
    ifstream inputStream(filename);
    string fileContent{istreambuf_iterator<char>(inputStream), istreambuf_iterator<char>()};
    //cout << fileContent << endl;
    inputCode = fileContent;
    totalCodeLength = inputCode.length();
    cursorPosition = 0;
    tokenPosition = 0;
    currentChar = inputCode[cursorPosition];
    nextChar = inputCode[cursorPosition + 1];

}

void Parser::parse()
{   
    tokenise();
    parseProcedure();
}

void Parser::tokenise()
{   
    if (tokenPosition == 0)
    {
        constructToken();
        readNextChar();
    }

    while (currentToken[tokenPosition] != END_OF_STRING)
    {
        if (constructToken())
        {
            readNextChar();
        }
        else
        {
            cout << "error when constructing token" << endl;
        }
    }
    cout << currentToken << endl;
}

bool Parser::constructToken()
{
    if (currentChar == SPACE || currentChar == TAB || currentChar == END_OF_LINE)
    {
        return true;
    }
    if (nextChar == SPACE || nextChar == TAB || nextChar == END_OF_LINE)
    {
        currentToken[tokenPosition] = currentChar;
        tokenPosition++;
        currentToken[tokenPosition] = END_OF_STRING;
        return true;
    }
    else
    {
        currentToken[tokenPosition] = currentChar;
        tokenPosition++;
        return true;
    }
    return false;
}

void Parser::parseProcedure()
{
    int i = 5;
    while (i > 0)
    {
        clearTokenArray();
        tokenise();
        i--;
    }
    
}

void Parser::readNextChar()
{
    cursorPosition++;
    if (cursorPosition > totalCodeLength - 1)
    {
        currentChar = END_OF_STRING;
    }
    else
    {
        currentChar = inputCode[cursorPosition];
        nextChar = inputCode[cursorPosition + 1];
    }
}

void Parser::clearTokenArray()
{
    memset(currentToken, '~', sizeof(currentToken));
    tokenPosition = 0;

}

bool isBracket(char input)
{
    return (input == '{' || input == '}' || input == '(' || input == ')');
} 