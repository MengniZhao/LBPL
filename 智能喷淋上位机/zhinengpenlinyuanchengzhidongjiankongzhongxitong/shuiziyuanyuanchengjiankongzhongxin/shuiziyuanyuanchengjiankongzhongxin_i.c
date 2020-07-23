

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jul 06 10:44:28 2018
 */
/* Compiler settings for shuiziyuanyuanchengjiankongzhongxin.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_shuiziyuanyuanchengjiankongzhongxin,0x88E04A28,0xA154,0x42D7,0xA6,0x32,0x24,0xBE,0x46,0xC7,0xDA,0x35);


MIDL_DEFINE_GUID(IID, DIID_Ishuiziyuanyuanchengjiankongzhongxin,0x967D4C29,0x34A0,0x421C,0xA9,0x97,0x11,0x1C,0xDD,0xFB,0x08,0x6E);


MIDL_DEFINE_GUID(CLSID, CLSID_shuiziyuanyuanchengjiankongzhongxin,0x83317560,0xB27B,0x4498,0x84,0xFD,0xF4,0x56,0x42,0x1D,0xC2,0x41);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



