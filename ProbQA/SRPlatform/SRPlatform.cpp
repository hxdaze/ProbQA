// SRPlatform.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "../SRPlatform/Interface/SRPlatform.h"

// This is an example of an exported variable
SRPLATFORM_API int nSRPlatform=0;

// This is an example of an exported function.
SRPLATFORM_API int fnSRPlatform(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see SRPlatform.h for the class definition
CSRPlatform::CSRPlatform()
{
    return;
}
