#ifndef PRODUCT_IDENTIFIER_H
#define PRODUCT_IDENTIFIER_H

typedef struct
{
    char *productSystemId;
    char *productSystemCustomerId;
    char *productNumber;
} ProductIdentifier;

void InitProductIdentifier(ProductIdentifier *identifier);
void DeinitProductIdentifier(ProductIdentifier *identifier);

#endif
