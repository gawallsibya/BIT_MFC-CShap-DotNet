//interface.h ÆÄÀÏ
interface ICalcu : IUnknown
{
	virtual	int	__stdcall Sum(int x, int y) = 0;
	virtual 	int	__stdcall Sub(int x, int y) = 0;
	virtual 	int	__stdcall Mul(int x, int y) = 0;
	virtual 	double  	__stdcall Div(int x, int y) = 0;
};
