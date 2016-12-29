#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DecodeHexString.h"

static int DigitValue(char hex)
{
    if (hex >= '0' && hex <= '9')
        return hex - '0';
    
    if (hex >= 'a' && hex <= 'f')
        return hex - 'a' + 10;
    
    if (hex >= 'A' && hex <= 'F')
        return hex - 'A' + 10;
    
    return 0;
}

char* DecodeHexString(const char *hexString)
{
    char *hex;
    int hexLen;
    int i;
    
    hexLen = (int)strlen(hexString) / 2;
    hex = malloc(hexLen + 1);
    
    if (hex)
    {
        for (i = 0; i < hexLen; i++)
        {
            int ch = 0;
            
            ch |= DigitValue(hexString[i * 2]) << 4;
            ch |= DigitValue(hexString[i * 2 + 1]);
            
            hex[i] = ch;
        }
    }
    
    hex[hexLen] = '\0';
    return hex;
}
