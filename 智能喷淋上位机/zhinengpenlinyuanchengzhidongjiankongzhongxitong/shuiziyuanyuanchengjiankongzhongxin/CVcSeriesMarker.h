// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类
#include "stdafx.h"
//#import "F:\\三华讲解\\20170215\\mschart图表ocx\\MSCHRT20.OCX" no_namespace
// CVcSeriesMarker 包装器类

class CVcSeriesMarker : public COleDispatchDriver
{
public:
	CVcSeriesMarker(){} // 调用 COleDispatchDriver 默认构造函数
	CVcSeriesMarker(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcSeriesMarker(const CVcSeriesMarker& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IVcSeriesMarker 方法
public:
	BOOL get_Auto()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Auto(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Show()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Show(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IVcSeriesMarker 属性
public:

};
