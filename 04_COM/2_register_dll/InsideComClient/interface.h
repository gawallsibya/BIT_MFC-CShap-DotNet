//interface.h
interface ISetVal : IUnknown
{
	virtual void __stdcall SetValue(int , int) = 0;
};

interface ICalcu : IUnknown
{	
	virtual int __stdcall Sum() = 0;
	virtual int __stdcall Sub() = 0;
};

