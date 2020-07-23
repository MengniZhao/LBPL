// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类
#include "stdafx.h"
//#import "F:\\三华讲解\\20170215\\mschart图表ocx\\MSCHRT20.OCX" no_namespace
// CVcFill 包装器类

class CVcFill : public COleDispatchDriver
{
public:
	CVcFill(){} // 调用 COleDispatchDriver 默认构造函数
	CVcFill(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcFill(const CVcFill& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IVcFill 方法
public:
	long get_Style()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Style(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Brush()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// IVcFill 属性
public:

};
