//==========================================================================
// Copyright (c) 2000-2008,  Elastos, Inc.  All Rights Reserved.
//==========================================================================

#include <_ElastosCoreuuid.cpp>

_ELASTOS_NAMESPACE_USING

// CAR ClassID
//
EXTERN_C const EMuid EMUID_NULL =
        {0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};

EXTERN_C const EMuid ECLSID_ClassInfo =
    {0x4CDBF5FC,0xD030,0x4583,{0xAE,0xCD,0xA2,0x6E,0x95,0xB3,0x02,0x6F}};

EXTERN_C const EMuid CLSID_CustomMarshal =
    {0xbe99507c,0xe6b8,0x42d9,{0x8d,0x95,0xf8,0xbe,0x0c,0xc6,0x4e,0xbd}};

EXTERN_C const _ELASTOS ClassID ECLSID_CClassObject =
    {{0x0000110A,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}},
    (char *)"elastos.dll"};

// IID
//

EXTERN_C const _ELASTOS InterfaceID EIID_IInterface = \
    {0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_IObject = \
    {0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x68}};

EXTERN_C const _ELASTOS InterfaceID EIID_IAspect = \
    {0x00010002,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_IClassObject = \
    {0x00000001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

EXTERN_C const _ELASTOS InterfaceID EIID_METADATA_INFO = \
    {0x00010001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_CALLBACK_CONNECTOR = \
    {0x00010004,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_IProxy = \
    {0x00010005,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_GENERIC_INFO = \
    {0x00010006,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_MUTEX_INFO = \
    {0x00010007,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_NEXT_ASPECT = \
    {0x00010008,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_PARENT_CONTEXT = \
    {0x00010009,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_CALLBACK_TRIGGER = \
    {0x0001000A,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_SUPER_CALLBACK_CONNECTOR = \
    {0x0001000B,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_SUPER_OBJECT= \
    {0x0001000C,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_IProxyDeathRecipient= \
    {0x0001000D,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_IWeakReference= \
    {0x00010008,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};

EXTERN_C const _ELASTOS InterfaceID EIID_IWeakReferenceSource= \
    {0x0001000A,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x66}};
