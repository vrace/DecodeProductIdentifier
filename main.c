#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProductIdentifier.h"
#include "ProductIdentifierDecoder.h"

void PrintProductIdentifier(const ProductIdentifier *identifier)
{
    printf("Product System ID: %s\n", identifier->productSystemId);
    printf("Product System Customer ID: %s\n", identifier->productSystemCustomerId);
    printf("Product Number: %s\n", identifier->productNumber);
}

#ifdef DEBUG

int main(int argc, char *argv[])
{
    char identifierString[] = "546c425350434d2b4d54497a50434d2b4d54497a4e44553d";
    ProductIdentifier identifier;
    
    InitProductIdentifier(&identifier);
    if (DecodeProductIdentifier(&identifier, identifierString) == ProductIdentifierDecodeSuccess)
    {
        PrintProductIdentifier(&identifier);
        DeinitProductIdentifier(&identifier);
    }
    
    return 0;
}

#else

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: DecodeProductIdentifier <Product Identifier>\n");
    }
    else
    {
        ProductIdentifier identifier;
        
        InitProductIdentifier(&identifier);
        
        if (DecodeProductIdentifier(&identifier, argv[1]) == ProductIdentifierDecodeSuccess)
        {
            PrintProductIdentifier(&identifier);
            DeinitProductIdentifier(&identifier);
        }
        else
        {
            fprintf(stderr, "Invalid Product Identifier.\n");
        }
    }
    
    return 0;
}

#endif
