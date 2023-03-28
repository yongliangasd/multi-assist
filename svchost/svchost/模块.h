#pragma once
#include "pch.h"
#include "全局变量.h"


using namespace std;

void 处理事件();

DWORD 取进程ID(const char* pName);//通过进程名获取进程ID

HANDLE 打开进程(DWORD nID);//通过进程ID获取进程ID

float 读内存小数型(DWORD 进程ID, INT64 内存地址);

INT16 读内存短整数型(DWORD 进程ID, INT64 内存地址);

INT32 读内存整数型(DWORD 进程ID, INT64 内存地址);

INT64 读内存长整数型(DWORD 进程ID, INT64 内存地址);

INT64 取偏移地址( INT64 基址, vector<int> 偏移地址);

vector<byte>  读内存字节集(DWORD 进程ID, INT64 内存地址, INT64 length);

void 写内存小数型(DWORD 进程ID, INT64 内存地址, float 要写入的数据);

void 写内存短整数型(DWORD 进程ID, INT64 内存地址, INT16 要写入的数据);

void 写内存整数型(DWORD 进程ID, INT64 内存地址, INT32 要写入的数据);

void 写内存长整数型(DWORD 进程ID, INT64 内存地址, INT64 要写入的数据);

void 写内存字节集(DWORD 进程ID, INT64 内存地址, vector<BYTE> 要写入的数据);


/*
*延时间隔	1000微秒 = 1毫秒 ； 1000毫秒 = 1秒
延时单位	可空:毫秒  0 毫秒  1 微秒  2 秒  3 分  4 小时  5 天
*/
void 超级延迟(INT64 延时间隔, INT64 延时单位 );

/*
*延时间隔	1毫秒 ； 1000毫秒 = 1秒
*/
void 超级延时(INT64 延时间隔);

CString 转换Unicode转Ansi(vector<BYTE> 参_字节集);

WCHAR* 转换Ansi转Unicode(CHAR* str);

vector<byte> Ansi转Unicode(CString str);

vector<byte> 整数到字节集(INT64   i);

CString 到文本(LONG64 a);

CString 十到十六(LONG64 a);

BOOL 置剪辑板文本(CString 文本);

wstring string转wstring(string str);

string wstring转string(wstring wstr);

void 进程结束(DWORD 进程PID);

void 提升进程权限();

LPVOID 申请内存x64(int DwSize);

bool 释放内存(LPVOID 释放地址);

vector<byte>内存填充(INT64 填充大小);

vector<byte>HOOK_JMP(INT64 Hook地址, INT64 跳转地址, vector<byte>	附加字节集);

void 写到文件(LPCTSTR 文件路径, int 资源ID,const char* 资源类型);

void 提升读写权限();

void 指定父进程获得system权限(DWORD 参数1, CString 参数2);

bool 文件是否存在(const char* name);

//byte intToByte(int i);

DWORD 进程是否存在(LPCTSTR name);

void 终止进程(CString 进程名);

CString 寻找一个文件(CString 文件名);

CString 取特殊目录(int 目录ID);

INT64 取启动时间();

void 强制删除文件(CString 文件名);

CString 取执行文件名();

void 运行(CString strCmd);






