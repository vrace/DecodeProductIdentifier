#ifndef PRODUCT_IDENTIFIER_DECODER_H
#define PRODUCT_IDENTIFIER_DECODER_H

#include "ProductIdentifier.h"

typedef enum
{
    ProductIdentifierDecodeSuccess,
    ProductIdentifierDecodeFailed
} ProductIdentifierDecodeResult;

ProductIdentifierDecodeResult DecodeProductIdentifier(ProductIdentifier *identifier, const char *identifierString);

#endif
