#include <stdio.h>
#include <stdlib.h>
#include "ProductIdentifier.h"

void InitProductIdentifier(ProductIdentifier *identifier)
{
    identifier->productSystemId = NULL;
    identifier->productSystemCustomerId = NULL;
    identifier->productNumber = NULL;
}

void DeinitProductIdentifier(ProductIdentifier *identifier)
{
    free(identifier->productSystemId);
    free(identifier->productSystemCustomerId);
    free(identifier->productNumber);
}
