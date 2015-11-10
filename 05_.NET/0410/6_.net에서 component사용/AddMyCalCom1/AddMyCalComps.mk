
AddMyCalComps.dll: dlldata.obj AddMyCalCom_p.obj AddMyCalCom_i.obj
	link /dll /out:AddMyCalComps.dll /def:AddMyCalComps.def /entry:DllMain dlldata.obj AddMyCalCom_p.obj AddMyCalCom_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del AddMyCalComps.dll
	@del AddMyCalComps.lib
	@del AddMyCalComps.exp
	@del dlldata.obj
	@del AddMyCalCom_p.obj
	@del AddMyCalCom_i.obj
