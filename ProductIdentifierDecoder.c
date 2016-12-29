#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProductIdentifierDecoder.h"
#include "DecodeHexString.h"
#include "Base64.h"

static char Seperator[] = "<#>";

char* DecodeIdentifierString(const char *identifierString)
{
    char *hex;
    char *plain = NULL;
    int plainLen;
    
    hex = DecodeHexString(identifierString);
    
    if (hex)
    {
        plainLen = Base64decode_len(hex);
        plain = malloc(plainLen + 1);
        Base64decode(plain, hex);
        
        free(hex);
    }
    
    return plain;
}

char* DuplicateSubstring(const char *str, int duplicateLength)
{
    char *buffer;
    
    if (duplicateLength <= 0)
        duplicateLength = (int)strlen(str);
    
    buffer = malloc(duplicateLength + 1);
    if (buffer)
    {
        memcpy(buffer, str, duplicateLength);
        buffer[duplicateLength] = '\0';
    }
    
    return buffer;
}

int NextSeperator(const char *str)
{
    char *p = strstr(str, Seperator);
    return p ? (int)(p - str) : -1;
}

typedef enum
{
    IdentifierValidateResultValid,
    IdentifierValidateResultInvalid,
} IdentifierValidateResult;

IdentifierValidateResult ValidatePlainIdentifier(const char *plainIdentifier)
{
    int pos;
    int i;
    
    for (i = 0; i < 2; i++)
    {
        pos = NextSeperator(plainIdentifier);
        if (pos < 0)
            return IdentifierValidateResultInvalid;
        
        plainIdentifier += pos + strlen(Seperator);
    }
    
    return IdentifierValidateResultValid;
}

ProductIdentifierDecodeResult DecodeProductIdentifier(ProductIdentifier *identifier, const char *identifierString)
{
    char *decoded;
    ProductIdentifierDecodeResult result = ProductIdentifierDecodeFailed;
    
    decoded = DecodeIdentifierString(identifierString);
    if (decoded)
    {
        if (ValidatePlainIdentifier(decoded) == IdentifierValidateResultValid)
        {
            char *p = decoded;
            int pos;
            
            pos = NextSeperator(p);
            identifier->productSystemId = DuplicateSubstring(p, pos);
            p += pos + strlen(Seperator);
            
            pos = NextSeperator(p);
            identifier->productSystemCustomerId = DuplicateSubstring(p, pos);
            p += pos + strlen(Seperator);
            
            identifier->productNumber = DuplicateSubstring(p, -1);
            
            result = ProductIdentifierDecodeSuccess;
        }
        
        free(decoded);
    }
    
    return result;
}
