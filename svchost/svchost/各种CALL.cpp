#pragma once
#include "pch.h"
#include "模块.h"
#include "全局变量.h"
#include "基址.h"
#include "各种CALL.h"
#include <iostream>   // std::wcout
#include <string> 


void 内存汇编x64(vector<byte>asm_code)
{
	static bool 异步;
	vector<byte> Hook数据, HOOK原数据, asm_as;
	INT64 汇编中转, 空白地址, Hook汇编, 判断地址, Hook跳回;
	if (异步 == true)
	{
		return;
	}
	异步 = true;

	汇编中转 = (INT64)申请内存x64(4096);
	判断地址 = 汇编中转 + 100;
	空白地址 = 汇编中转 + 200;	
	//汇编中转 = 0;	
	size_t 长 = asm_code.size();	
	asm_as = { 0xFF,0x25,0x00,0x00,0x00,0x00 };
	//if (汇编中转 == 0)
	//{
	//	汇编中转 = (INT64)申请内存x64(1024);
	//	//printf("申请的地址：%p\n", 汇编中转);
	//}
	//空白地址 = 汇编地址 + 100;
	//判断地址 = 汇编地址;
	Hook汇编 = 汇编CALL;//0x1456C9C4D
	Hook汇编 = Hook汇编 + 144;
	Hook跳回 = Hook汇编 + 19;

	//if (Hook数据.empty() == true)
	//{ 
		Hook数据 = 读内存字节集(进程ID,Hook汇编, 19);
		HOOK原数据 = Hook数据;
		Hook数据.push_back(0x48);
		Hook数据.push_back(0xB8);
		Hook数据.push_back(整数到字节集(判断地址)[0]);
		Hook数据.push_back(整数到字节集(判断地址)[1]);
		Hook数据.push_back(整数到字节集(判断地址)[2]);
		Hook数据.push_back(整数到字节集(判断地址)[3]);
		Hook数据.push_back(整数到字节集(判断地址)[4]);
		Hook数据.push_back(整数到字节集(判断地址)[5]);
		Hook数据.push_back(整数到字节集(判断地址)[6]);
		Hook数据.push_back(整数到字节集(判断地址)[7]);
		Hook数据.push_back(0x83);
		Hook数据.push_back(0x38);
		Hook数据.push_back(0x01);
		Hook数据.push_back(0x75);
		Hook数据.push_back(0x2A);
		Hook数据.push_back(0x48);
		Hook数据.push_back(0x81);
		Hook数据.push_back(0xEC);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x03);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x48);
		Hook数据.push_back(0xBB);
		Hook数据.push_back(整数到字节集(空白地址)[0]);
		Hook数据.push_back(整数到字节集(空白地址)[1]);
		Hook数据.push_back(整数到字节集(空白地址)[2]);
		Hook数据.push_back(整数到字节集(空白地址)[3]);
		Hook数据.push_back(整数到字节集(空白地址)[4]);
		Hook数据.push_back(整数到字节集(空白地址)[5]);
		Hook数据.push_back(整数到字节集(空白地址)[6]);
		Hook数据.push_back(整数到字节集(空白地址)[7]);
		Hook数据.push_back(0xFF);
		Hook数据.push_back(0xD3);
		Hook数据.push_back(0x48);
		Hook数据.push_back(0xB8);
		Hook数据.push_back(整数到字节集(判断地址)[0]);
		Hook数据.push_back(整数到字节集(判断地址)[1]);
		Hook数据.push_back(整数到字节集(判断地址)[2]);
		Hook数据.push_back(整数到字节集(判断地址)[3]);
		Hook数据.push_back(整数到字节集(判断地址)[4]);
		Hook数据.push_back(整数到字节集(判断地址)[5]);
		Hook数据.push_back(整数到字节集(判断地址)[6]);
		Hook数据.push_back(整数到字节集(判断地址)[7]);
		Hook数据.push_back(0xC7);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x03);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x48);
		Hook数据.push_back(0x81);
		Hook数据.push_back(0xC4);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x03);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0xFF);
		Hook数据.push_back(0x25);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x00);
		Hook数据.push_back(0x00);
		Hook数据.push_back(整数到字节集(Hook跳回)[0]);
		Hook数据.push_back(整数到字节集(Hook跳回)[1]);
		Hook数据.push_back(整数到字节集(Hook跳回)[2]);
		Hook数据.push_back(整数到字节集(Hook跳回)[3]);
		Hook数据.push_back(整数到字节集(Hook跳回)[4]);
		Hook数据.push_back(整数到字节集(Hook跳回)[5]);
		Hook数据.push_back(整数到字节集(Hook跳回)[6]);
		Hook数据.push_back(整数到字节集(Hook跳回)[7]);
		//神话公告("HOOK数据", 0);
		//写内存字节集(进程ID,判断地址, { 0x01 });
		if (读内存整数型(进程ID, 汇编中转)==0)
		{
			写内存字节集(进程ID, 汇编中转, Hook数据);
		}		
		asm_code.push_back(195);
		写内存字节集(进程ID,空白地址, asm_code);
		//神话公告("asm_code", 0);
		asm_as.push_back(整数到字节集(汇编中转)[0]);
		asm_as.push_back(整数到字节集(汇编中转)[1]);
		asm_as.push_back(整数到字节集(汇编中转)[2]);
		asm_as.push_back(整数到字节集(汇编中转)[3]);
		asm_as.push_back(整数到字节集(汇编中转)[4]);
		asm_as.push_back(整数到字节集(汇编中转)[5]);
		asm_as.push_back(整数到字节集(汇编中转)[6]);
		asm_as.push_back(整数到字节集(汇编中转)[7]);
		asm_as.push_back(144);
		asm_as.push_back(144);
		asm_as.push_back(144);
		asm_as.push_back(144);
		asm_as.push_back(144);
		写内存字节集(进程ID,Hook汇编, asm_as);
		写内存整数型(进程ID, 判断地址, 1);
		while (读内存整数型(进程ID,判断地址) == 1)
		{
			超级延时(5);
			处理事件();
		}
		//神话公告("判断地址!=1", 0);
		写内存字节集(进程ID,Hook汇编, HOOK原数据);
		//写内存字节集(进程ID,汇编中转, Hook数据); 
		写内存字节集(进程ID,空白地址, 内存填充(asm_code.size() + 16));
		//Hook数据.clear();
		//asm_as.clear();
		//超级延时(5);
		//神话公告("延时后清空汇编代码", 0);
		vector<byte>().swap(Hook数据);
		vector<byte>().swap(asm_as);
		vector<byte>().swap(HOOK原数据);
	//}
		超级延时(10);
		释放内存((LPVOID)汇编中转);
		超级延时(10);

	异步 = false;
}




void 缓冲Call(int 缓冲参数)
{
	vector<byte>缓冲首 = { 72, 131, 236,96 };
	vector<byte>缓冲尾 = { 255, 208 };
	组包数据.insert(组包数据.end(), 缓冲首.begin(), 缓冲首.end());
	组包数据.push_back(0xBA);
	组包数据.push_back(整数到字节集(缓冲参数)[0]);
	组包数据.push_back(整数到字节集(缓冲参数)[1]);
	组包数据.push_back(整数到字节集(缓冲参数)[2]);
	组包数据.push_back(整数到字节集(缓冲参数)[3]);
	组包数据.push_back(整数到字节集(缓冲参数)[4]);
	组包数据.push_back(整数到字节集(缓冲参数)[5]);
	组包数据.push_back(整数到字节集(缓冲参数)[6]);
	组包数据.push_back(整数到字节集(缓冲参数)[7]);
	组包数据.push_back(0x48);
	组包数据.push_back(0xB9);
	组包数据.push_back(整数到字节集(发包基址)[0]);
	组包数据.push_back(整数到字节集(发包基址)[1]);
	组包数据.push_back(整数到字节集(发包基址)[2]);
	组包数据.push_back(整数到字节集(发包基址)[3]);
	组包数据.push_back(整数到字节集(发包基址)[4]);
	组包数据.push_back(整数到字节集(发包基址)[5]);
	组包数据.push_back(整数到字节集(发包基址)[6]);
	组包数据.push_back(整数到字节集(发包基址)[7]);
	组包数据.push_back(0x48);
	组包数据.push_back(139);
	组包数据.push_back(9);
	组包数据.push_back(0x48);
	组包数据.push_back(0xB8);
	组包数据.push_back(整数到字节集(缓冲CALL)[0]);
	组包数据.push_back(整数到字节集(缓冲CALL)[1]);
	组包数据.push_back(整数到字节集(缓冲CALL)[2]);
	组包数据.push_back(整数到字节集(缓冲CALL)[3]);
	组包数据.push_back(整数到字节集(缓冲CALL)[4]);
	组包数据.push_back(整数到字节集(缓冲CALL)[5]);
	组包数据.push_back(整数到字节集(缓冲CALL)[6]);
	组包数据.push_back(整数到字节集(缓冲CALL)[7]);
	组包数据.insert(组包数据.end(), 缓冲尾.begin(), 缓冲尾.end());

}
void 加密Call(INT64 加密参数,int 加密长度)
{
	vector<byte>汇编首 = { 73, 199, 192};
	vector<byte>汇编尾 = { 255,208 };
	组包数据.insert(组包数据.end(), 汇编首.begin(), 汇编首.end());
	组包数据.push_back(整数到字节集(加密长度)[0]);
	组包数据.push_back(整数到字节集(加密长度)[1]);
	组包数据.push_back(整数到字节集(加密长度)[2]);
	组包数据.push_back(整数到字节集(加密长度)[3]);
	组包数据.push_back(整数到字节集(加密长度)[4]);
	组包数据.push_back(整数到字节集(加密长度)[5]);
	组包数据.push_back(整数到字节集(加密长度)[6]);
	组包数据.push_back(整数到字节集(加密长度)[7]);
	组包数据.push_back(0x48);
	组包数据.push_back(0xB8);
	组包数据.push_back(整数到字节集(加密参数)[0]);
	组包数据.push_back(整数到字节集(加密参数)[1]);
	组包数据.push_back(整数到字节集(加密参数)[2]);
	组包数据.push_back(整数到字节集(加密参数)[3]);
	组包数据.push_back(整数到字节集(加密参数)[4]);
	组包数据.push_back(整数到字节集(加密参数)[5]);
	组包数据.push_back(整数到字节集(加密参数)[6]);
	组包数据.push_back(整数到字节集(加密参数)[7]);
	组包数据.push_back(0x48);
	组包数据.push_back(137);
	组包数据.push_back(68);
	组包数据.push_back(36);
	组包数据.push_back(32);
	组包数据.push_back(0x48);
	组包数据.push_back(141);
	组包数据.push_back(84);
	组包数据.push_back(36);
	组包数据.push_back(32);
	组包数据.push_back(0x48);
	组包数据.push_back(0xB9);
	组包数据.push_back(整数到字节集(发包基址)[0]);
	组包数据.push_back(整数到字节集(发包基址)[1]);
	组包数据.push_back(整数到字节集(发包基址)[2]);
	组包数据.push_back(整数到字节集(发包基址)[3]);
	组包数据.push_back(整数到字节集(发包基址)[4]);
	组包数据.push_back(整数到字节集(发包基址)[5]);
	组包数据.push_back(整数到字节集(发包基址)[6]);
	组包数据.push_back(整数到字节集(发包基址)[7]);
	组包数据.push_back(0x48);
	组包数据.push_back(139);
	组包数据.push_back(9);
	组包数据.push_back(0x48);
	组包数据.push_back(0xB8);
	组包数据.push_back(整数到字节集(加密CALL)[0]);
	组包数据.push_back(整数到字节集(加密CALL)[1]);
	组包数据.push_back(整数到字节集(加密CALL)[2]);
	组包数据.push_back(整数到字节集(加密CALL)[3]);
	组包数据.push_back(整数到字节集(加密CALL)[4]);
	组包数据.push_back(整数到字节集(加密CALL)[5]);
	组包数据.push_back(整数到字节集(加密CALL)[6]);
	组包数据.push_back(整数到字节集(加密CALL)[7]);
	组包数据.insert(组包数据.end(), 汇编尾.begin(), 汇编尾.end());
}
void 发包Call()
{
	vector<byte>汇编尾 = { 72, 131, 196, 96};
	组包数据.push_back(0x48);
	组包数据.push_back(0xB8);
	组包数据.push_back(整数到字节集(发包CALL)[0]);
	组包数据.push_back(整数到字节集(发包CALL)[1]);
	组包数据.push_back(整数到字节集(发包CALL)[2]);
	组包数据.push_back(整数到字节集(发包CALL)[3]);
	组包数据.push_back(整数到字节集(发包CALL)[4]);
	组包数据.push_back(整数到字节集(发包CALL)[5]);
	组包数据.push_back(整数到字节集(发包CALL)[6]);
	组包数据.push_back(整数到字节集(发包CALL)[7]);
	组包数据.push_back(0xFF);
	组包数据.push_back(0xD0);
	组包数据.insert(组包数据.end(), 汇编尾.begin(), 汇编尾.end());
	内存汇编x64(组包数据);
	//组包数据.clear();
	vector<byte>().swap(组包数据);
}



void 技能Call(INT64 触发指针, int 代码, INT64 伤害, int x, int y, int z, int 大小)
{
	INT64 局空白;
	vector<byte>汇编数据;
	vector<byte>汇编首 = { 0x48, 0x81, 0xEC, 0, 0x2, 0, 0 };
	vector<byte>汇编尾 = { 0x48, 0x81, 0xC4, 0, 0x2, 0, 0 };
	//申请内存x64(4096);
	局空白 = (INT64)申请内存x64(1024);
	写内存长整数型(进程ID, 局空白 , 触发指针);
	写内存整数型(进程ID, 局空白 + 16, 代码) ;
	写内存整数型(进程ID, 局空白 + 20, 伤害);
	写内存整数型(进程ID, 局空白 + 32, x) ;
	写内存整数型(进程ID, 局空白 + 36, y)  ;
	写内存整数型(进程ID, 局空白 + 40, z)  ;
	写内存小数型(进程ID, 局空白 + 140, (float)大小);
	写内存整数型(进程ID, 局空白 + 144, 65535);
	写内存整数型(进程ID, 局空白 + 148, 65535);
	汇编数据.insert(汇编数据.end(), 汇编首.begin(), 汇编首.end());
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xB9);
	汇编数据.push_back(整数到字节集(局空白)[0]);
	汇编数据.push_back(整数到字节集(局空白)[1]);
	汇编数据.push_back(整数到字节集(局空白)[2]);
	汇编数据.push_back(整数到字节集(局空白)[3]);
	汇编数据.push_back(整数到字节集(局空白)[4]);
	汇编数据.push_back(整数到字节集(局空白)[5]);
	汇编数据.push_back(整数到字节集(局空白)[6]);
	汇编数据.push_back(整数到字节集(局空白)[7]);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xb8);
	汇编数据.push_back(整数到字节集(技能CALL)[0]);
	汇编数据.push_back(整数到字节集(技能CALL)[1]);
	汇编数据.push_back(整数到字节集(技能CALL)[2]);
	汇编数据.push_back(整数到字节集(技能CALL)[3]);
	汇编数据.push_back(整数到字节集(技能CALL)[4]);
	汇编数据.push_back(整数到字节集(技能CALL)[5]);
	汇编数据.push_back(整数到字节集(技能CALL)[6]);
	汇编数据.push_back(整数到字节集(技能CALL)[7]);
	汇编数据.push_back(0xFF);
	汇编数据.push_back(0XD0);
	汇编数据.insert(汇编数据.end(), 汇编尾.begin(), 汇编尾.end());
	内存汇编x64(汇编数据);
	//汇编数据.clear();	
	vector<byte>().swap(组包数据);
}


void 释放call(INT64 触发指针, INT64 代码, INT64 伤害, INT64 X轴, INT64 Y轴, INT64 Z轴)
{
	vector<byte>汇编数据;
	汇编数据.push_back(0x53);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0x83);
	汇编数据.push_back(0xEC);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xC7);
	汇编数据.push_back(0x44);
	汇编数据.push_back(0x24);
	汇编数据.push_back(0x30);
	汇编数据.push_back(0x00);
	汇编数据.push_back(0x00);
	汇编数据.push_back(0x00);
	汇编数据.push_back(0x00);
	汇编数据.push_back(0xC7);
	汇编数据.push_back(0x44);
	汇编数据.push_back(0x24);
	汇编数据.push_back(0x28);
	汇编数据.push_back(整数到字节集(Z轴)[0]);
	汇编数据.push_back(整数到字节集(Z轴)[1]);
	汇编数据.push_back(整数到字节集(Z轴)[2]);
	汇编数据.push_back(整数到字节集(Z轴)[3]);
	汇编数据.push_back(整数到字节集(Z轴)[4]);
	汇编数据.push_back(整数到字节集(Z轴)[5]);
	汇编数据.push_back(整数到字节集(Z轴)[6]);
	汇编数据.push_back(整数到字节集(Z轴)[7]);
	汇编数据.push_back(0xC7);
	汇编数据.push_back(0x44);
	汇编数据.push_back(0x24);
	汇编数据.push_back(0x20);
	汇编数据.push_back(整数到字节集(Y轴)[0]);
	汇编数据.push_back(整数到字节集(Y轴)[1]);
	汇编数据.push_back(整数到字节集(Y轴)[2]);
	汇编数据.push_back(整数到字节集(Y轴)[3]);
	汇编数据.push_back(整数到字节集(Y轴)[4]);
	汇编数据.push_back(整数到字节集(Y轴)[5]);
	汇编数据.push_back(整数到字节集(Y轴)[6]);
	汇编数据.push_back(整数到字节集(Y轴)[7]);
	汇编数据.push_back(0x41);
	汇编数据.push_back(0xB9);
	汇编数据.push_back(整数到字节集(X轴)[0]);
	汇编数据.push_back(整数到字节集(X轴)[1]);
	汇编数据.push_back(整数到字节集(X轴)[2]);
	汇编数据.push_back(整数到字节集(X轴)[3]);
	汇编数据.push_back(整数到字节集(X轴)[4]);
	汇编数据.push_back(整数到字节集(X轴)[5]);
	汇编数据.push_back(整数到字节集(X轴)[6]);
	汇编数据.push_back(整数到字节集(X轴)[7]);
	汇编数据.push_back(0x41);
	汇编数据.push_back(0xB8);
	汇编数据.push_back(整数到字节集(伤害)[0]);
	汇编数据.push_back(整数到字节集(伤害)[1]);
	汇编数据.push_back(整数到字节集(伤害)[2]);
	汇编数据.push_back(整数到字节集(伤害)[3]);
	汇编数据.push_back(整数到字节集(伤害)[4]);
	汇编数据.push_back(整数到字节集(伤害)[5]);
	汇编数据.push_back(整数到字节集(伤害)[6]);
	汇编数据.push_back(整数到字节集(伤害)[7]);
	汇编数据.push_back(0xBA);
	汇编数据.push_back(整数到字节集(代码)[0]);
	汇编数据.push_back(整数到字节集(代码)[1]);
	汇编数据.push_back(整数到字节集(代码)[2]);
	汇编数据.push_back(整数到字节集(代码)[3]);
	汇编数据.push_back(整数到字节集(代码)[4]);
	汇编数据.push_back(整数到字节集(代码)[5]);
	汇编数据.push_back(整数到字节集(代码)[6]);
	汇编数据.push_back(整数到字节集(代码)[7]);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xB9);
	汇编数据.push_back(整数到字节集(触发指针)[0]);
	汇编数据.push_back(整数到字节集(触发指针)[1]);
	汇编数据.push_back(整数到字节集(触发指针)[2]);
	汇编数据.push_back(整数到字节集(触发指针)[3]);
	汇编数据.push_back(整数到字节集(触发指针)[4]);
	汇编数据.push_back(整数到字节集(触发指针)[5]);
	汇编数据.push_back(整数到字节集(触发指针)[6]);
	汇编数据.push_back(整数到字节集(触发指针)[7]);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xB8);
	汇编数据.push_back(整数到字节集(释放CALL)[0]);
	汇编数据.push_back(整数到字节集(释放CALL)[1]);
	汇编数据.push_back(整数到字节集(释放CALL)[2]);
	汇编数据.push_back(整数到字节集(释放CALL)[3]);
	汇编数据.push_back(整数到字节集(释放CALL)[4]);
	汇编数据.push_back(整数到字节集(释放CALL)[5]);
	汇编数据.push_back(整数到字节集(释放CALL)[6]);
	汇编数据.push_back(整数到字节集(释放CALL)[7]);
	汇编数据.push_back(0xFF);
	汇编数据.push_back(0xD0);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0x83);
	汇编数据.push_back(0xC4);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0x5B);
	汇编数据.push_back(0xC3);
	内存汇编x64(汇编数据);
}


void 坐标call( INT64 X, INT64 Y, INT64 Z)
{
	vector<byte>汇编数据;
	vector<byte>汇编首 = { 72, 129, 236, 0, 1, 0, 0 };
	vector<byte>汇编尾 = { 72, 129, 196, 0, 1, 0, 0 };
	INT64 触发指针 = 读内存长整数型(进程ID, 人物基址);
	if (触发指针<1)
	{
		return;
	}
	汇编数据.insert(汇编数据.end(), 汇编首.begin(), 汇编首.end());
	汇编数据.push_back(0x41);
	汇编数据.push_back(0xB9);
	汇编数据.push_back(整数到字节集(Z)[0]);
	汇编数据.push_back(整数到字节集(Z)[1]);
	汇编数据.push_back(整数到字节集(Z)[2]);
	汇编数据.push_back(整数到字节集(Z)[3]);
	汇编数据.push_back(整数到字节集(Z)[4]);
	汇编数据.push_back(整数到字节集(Z)[5]);
	汇编数据.push_back(整数到字节集(Z)[6]);
	汇编数据.push_back(整数到字节集(Z)[7]);
	汇编数据.push_back(0x41);
	汇编数据.push_back(0xB8);
	汇编数据.push_back(整数到字节集(Y)[0]);
	汇编数据.push_back(整数到字节集(Y)[1]);
	汇编数据.push_back(整数到字节集(Y)[2]);
	汇编数据.push_back(整数到字节集(Y)[3]);
	汇编数据.push_back(整数到字节集(Y)[4]);
	汇编数据.push_back(整数到字节集(Y)[5]);
	汇编数据.push_back(整数到字节集(Y)[6]);
	汇编数据.push_back(整数到字节集(Y)[7]);
	汇编数据.push_back(0xBA);
	汇编数据.push_back(整数到字节集(X)[0]);
	汇编数据.push_back(整数到字节集(X)[1]);
	汇编数据.push_back(整数到字节集(X)[2]);
	汇编数据.push_back(整数到字节集(X)[3]);
	汇编数据.push_back(整数到字节集(X)[4]);
	汇编数据.push_back(整数到字节集(X)[5]);
	汇编数据.push_back(整数到字节集(X)[6]);
	汇编数据.push_back(整数到字节集(X)[7]);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xB9);
	汇编数据.push_back(整数到字节集(触发指针)[0]);
	汇编数据.push_back(整数到字节集(触发指针)[1]);
	汇编数据.push_back(整数到字节集(触发指针)[2]);
	汇编数据.push_back(整数到字节集(触发指针)[3]);
	汇编数据.push_back(整数到字节集(触发指针)[4]);
	汇编数据.push_back(整数到字节集(触发指针)[5]);
	汇编数据.push_back(整数到字节集(触发指针)[6]);
	汇编数据.push_back(整数到字节集(触发指针)[7]);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0x8B);
	汇编数据.push_back(0x01);
	汇编数据.push_back(0xFF);
	汇编数据.push_back(0x90);
	汇编数据.push_back(整数到字节集(坐标偏移)[0]);
	汇编数据.push_back(整数到字节集(坐标偏移)[1]);
	汇编数据.push_back(整数到字节集(坐标偏移)[2]);
	汇编数据.push_back(整数到字节集(坐标偏移)[3]);
	汇编数据.push_back(整数到字节集(坐标偏移)[4]);
	汇编数据.push_back(整数到字节集(坐标偏移)[5]);
	汇编数据.push_back(整数到字节集(坐标偏移)[6]);
	汇编数据.push_back(整数到字节集(坐标偏移)[7]);
	汇编数据.insert(汇编数据.end(), 汇编尾.begin(), 汇编尾.end());
	内存汇编x64(汇编数据);
}


void 任务接受Call(int 任务ID)
{
	vector<byte>汇编字节;
	汇编字节 = { 72, 131, 236, 40 };
	汇编字节.push_back(186);
	汇编字节.push_back(整数到字节集(任务ID)[0]);
	汇编字节.push_back(整数到字节集(任务ID)[1]);
	汇编字节.push_back(整数到字节集(任务ID)[2]);
	汇编字节.push_back(整数到字节集(任务ID)[3]);
	汇编字节.push_back(整数到字节集(任务ID)[4]);
	汇编字节.push_back(整数到字节集(任务ID)[5]);
	汇编字节.push_back(整数到字节集(任务ID)[6]);
	汇编字节.push_back(整数到字节集(任务ID)[7]);
	汇编字节.push_back(255);
	汇编字节.push_back(21);
	汇编字节.push_back(2);
	汇编字节.push_back(0);
	汇编字节.push_back(0);
	汇编字节.push_back(0);
	汇编字节.push_back(235);
	汇编字节.push_back(8);
	汇编字节.push_back(整数到字节集(接受CALL)[0]);
	汇编字节.push_back(整数到字节集(接受CALL)[1]);
	汇编字节.push_back(整数到字节集(接受CALL)[2]);
	汇编字节.push_back(整数到字节集(接受CALL)[3]);
	汇编字节.push_back(整数到字节集(接受CALL)[4]);
	汇编字节.push_back(整数到字节集(接受CALL)[5]);
	汇编字节.push_back(整数到字节集(接受CALL)[6]);
	汇编字节.push_back(整数到字节集(接受CALL)[7]);
	汇编字节.push_back(72);
	汇编字节.push_back(131);
	汇编字节.push_back(196);
	汇编字节.push_back(40);
	内存汇编x64(汇编字节);
}

void 任务完成Call(int 任务ID)
{
	vector<byte>汇编字节;
	汇编字节 = { 72, 131, 236, 40 };
	汇编字节.push_back(179);
	汇编字节.push_back(68);
	汇编字节.push_back(15);
	汇编字节.push_back(182);
	汇编字节.push_back(203);
	汇编字节.push_back(65);
	汇编字节.push_back(176);
	汇编字节.push_back(255);
	汇编字节.push_back(186);
	汇编字节.push_back(整数到字节集(任务ID)[0]);
	汇编字节.push_back(整数到字节集(任务ID)[1]);
	汇编字节.push_back(整数到字节集(任务ID)[2]);
	汇编字节.push_back(整数到字节集(任务ID)[3]);
	汇编字节.push_back(整数到字节集(任务ID)[4]);
	汇编字节.push_back(整数到字节集(任务ID)[5]);
	汇编字节.push_back(整数到字节集(任务ID)[6]);
	汇编字节.push_back(整数到字节集(任务ID)[7]);
	汇编字节.push_back(255);
	汇编字节.push_back(21);
	汇编字节.push_back(2);
	汇编字节.push_back(0);
	汇编字节.push_back(0);
	汇编字节.push_back(0);
	汇编字节.push_back(235);
	汇编字节.push_back(8);
	汇编字节.push_back(整数到字节集(完成CALL)[0]);
	汇编字节.push_back(整数到字节集(完成CALL)[1]);
	汇编字节.push_back(整数到字节集(完成CALL)[2]);
	汇编字节.push_back(整数到字节集(完成CALL)[3]);
	汇编字节.push_back(整数到字节集(完成CALL)[4]);
	汇编字节.push_back(整数到字节集(完成CALL)[5]);
	汇编字节.push_back(整数到字节集(完成CALL)[6]);
	汇编字节.push_back(整数到字节集(完成CALL)[7]);
	汇编字节.push_back(72);
	汇编字节.push_back(131);
	汇编字节.push_back(196);
	汇编字节.push_back(40);
	内存汇编x64(汇编字节);
}

void 任务提交Call(int 任务ID)
{
	vector<byte>汇编字节;
	汇编字节 = { 72, 131, 236, 40 };
	汇编字节.push_back(65);
	汇编字节.push_back(189);
	汇编字节.push_back(1);
	汇编字节.push_back(0);
	汇编字节.push_back(0);
	汇编字节.push_back(0);
	汇编字节.push_back(65);
	汇编字节.push_back(190);
	汇编字节.push_back(255);
	汇编字节.push_back(255);
	汇编字节.push_back(255);
	汇编字节.push_back(255);
	汇编字节.push_back(69);
	汇编字节.push_back(139);
	汇编字节.push_back(205);
	汇编字节.push_back(69);
	汇编字节.push_back(139);
	汇编字节.push_back(198);
	汇编字节.push_back(72);
	汇编字节.push_back(185);
	汇编字节.push_back(整数到字节集(任务基址)[0]);
	汇编字节.push_back(整数到字节集(任务基址)[1]);
	汇编字节.push_back(整数到字节集(任务基址)[2]);
	汇编字节.push_back(整数到字节集(任务基址)[3]);
	汇编字节.push_back(整数到字节集(任务基址)[4]);
	汇编字节.push_back(整数到字节集(任务基址)[5]);
	汇编字节.push_back(整数到字节集(任务基址)[6]);
	汇编字节.push_back(整数到字节集(任务基址)[7]);
	汇编字节.push_back(72);
	汇编字节.push_back(139);
	汇编字节.push_back(9);
	汇编字节.push_back(186);
	汇编字节.push_back(整数到字节集(任务ID)[0]);
	汇编字节.push_back(整数到字节集(任务ID)[1]);
	汇编字节.push_back(整数到字节集(任务ID)[2]);
	汇编字节.push_back(整数到字节集(任务ID)[3]);
	汇编字节.push_back(整数到字节集(任务ID)[4]);
	汇编字节.push_back(整数到字节集(任务ID)[5]);
	汇编字节.push_back(整数到字节集(任务ID)[6]);
	汇编字节.push_back(整数到字节集(任务ID)[7]);
	汇编字节.push_back(255);
	汇编字节.push_back(21);
	汇编字节.push_back(2);
	汇编字节.push_back(0);
	汇编字节.push_back(0);
	汇编字节.push_back(0);
	汇编字节.push_back(235);
	汇编字节.push_back(8);
	汇编字节.push_back(整数到字节集(提交CALL)[0]);
	汇编字节.push_back(整数到字节集(提交CALL)[1]);
	汇编字节.push_back(整数到字节集(提交CALL)[2]);
	汇编字节.push_back(整数到字节集(提交CALL)[3]);
	汇编字节.push_back(整数到字节集(提交CALL)[4]);
	汇编字节.push_back(整数到字节集(提交CALL)[5]);
	汇编字节.push_back(整数到字节集(提交CALL)[6]);
	汇编字节.push_back(整数到字节集(提交CALL)[7]);
	汇编字节.push_back(72);
	汇编字节.push_back(131);
	汇编字节.push_back(196);
	汇编字节.push_back(40);
	内存汇编x64(汇编字节);
}

void 物品Call(int 物品代码)
{
	vector<byte>汇编代码;
	汇编代码 = { 0x53,0x48,0x83,0xEC,0X28,0X48,0XB8 };
	汇编代码.push_back(整数到字节集(人物基址)[0]);
	汇编代码.push_back(整数到字节集(人物基址)[1]);
	汇编代码.push_back(整数到字节集(人物基址)[2]);
	汇编代码.push_back(整数到字节集(人物基址)[3]);
	汇编代码.push_back(整数到字节集(人物基址)[4]);
	汇编代码.push_back(整数到字节集(人物基址)[5]);
	汇编代码.push_back(整数到字节集(人物基址)[6]);
	汇编代码.push_back(整数到字节集(人物基址)[7]);
	汇编代码.push_back(0X48);
	汇编代码.push_back(0X8B);
	汇编代码.push_back(0);
	汇编代码.push_back(0X4C);
	汇编代码.push_back(0X8B);
	汇编代码.push_back(0);
	汇编代码.push_back(0XBA);
	汇编代码.push_back(整数到字节集(物品代码)[0]);
	汇编代码.push_back(整数到字节集(物品代码)[1]);
	汇编代码.push_back(整数到字节集(物品代码)[2]);
	汇编代码.push_back(整数到字节集(物品代码)[3]);
	汇编代码.push_back(整数到字节集(物品代码)[4]);
	汇编代码.push_back(整数到字节集(物品代码)[5]);
	汇编代码.push_back(整数到字节集(物品代码)[6]);
	汇编代码.push_back(整数到字节集(物品代码)[7]);
	汇编代码.push_back(0X48);
	汇编代码.push_back(0X8B);
	汇编代码.push_back(0XC8);
	汇编代码.push_back(0X41);
	汇编代码.push_back(0XFF);
	汇编代码.push_back(0X90);
	汇编代码.push_back(整数到字节集(物品CALL)[0]);
	汇编代码.push_back(整数到字节集(物品CALL)[1]);
	汇编代码.push_back(整数到字节集(物品CALL)[2]);
	汇编代码.push_back(整数到字节集(物品CALL)[3]);
	汇编代码.push_back(整数到字节集(物品CALL)[4]);
	汇编代码.push_back(整数到字节集(物品CALL)[5]);
	汇编代码.push_back(整数到字节集(物品CALL)[6]);
	汇编代码.push_back(整数到字节集(物品CALL)[7]);
	汇编代码.push_back(0X48);
	汇编代码.push_back(0X83);
	汇编代码.push_back(0XC4);
	汇编代码.push_back(0X28);
	汇编代码.push_back(0X5B);
	汇编代码.push_back(0XC3);
	内存汇编x64(汇编代码);
}


void 组包_城镇移动(int 大区域, int 小区域, int x, int y)
{
	//缓冲Call(36);
	//加密Call(城镇区域, 4);
	//加密Call(城镇编号, 1);
	//加密Call(城镇横轴, 2);
	//加密Call(城镇纵轴, 2);
	//加密Call(5, 1);
	//加密Call(38, 4);
	//加密Call(2, 2);
	//加密Call(0, 4);
	//加密Call(0, 1);
	//发包Call();
	INT64 触发指针, 储存地址;
	vector<byte> code;
	触发指针 = 读内存长整数型(进程ID, 角色指针);
	储存地址 = 城镇基址;
	写内存整数型(进程ID, 储存地址, 大区域);
	写内存整数型(进程ID, 储存地址 + 4, 小区域);
	写内存整数型(进程ID, 储存地址 + 8, x);
	写内存整数型(进程ID, 储存地址 + 12, y);
	code = Sub_Rsp(256);
	code.push_back(0x48);
	code.push_back(0xBA);
	code.push_back(整数到字节集(储存地址)[0]);
	code.push_back(整数到字节集(储存地址)[1]);
	code.push_back(整数到字节集(储存地址)[2]);
	code.push_back(整数到字节集(储存地址)[3]);
	code.push_back(整数到字节集(储存地址)[4]);
	code.push_back(整数到字节集(储存地址)[5]);
	code.push_back(整数到字节集(储存地址)[6]);
	code.push_back(整数到字节集(储存地址)[7]);
	code.push_back(0x48);
	code.push_back(0xB9);
	code.push_back(整数到字节集(触发指针)[0]);
	code.push_back(整数到字节集(触发指针)[1]);
	code.push_back(整数到字节集(触发指针)[2]);
	code.push_back(整数到字节集(触发指针)[3]);
	code.push_back(整数到字节集(触发指针)[4]);
	code.push_back(整数到字节集(触发指针)[5]);
	code.push_back(整数到字节集(触发指针)[6]);
	code.push_back(整数到字节集(触发指针)[7]);
	code.insert(code.end(), Call(城镇CALL).begin(), Call(城镇CALL).end());
	code.insert(code.end(), Add_Rsp(256).begin(), Add_Rsp(256).end());
	内存汇编x64(code);
}
vector<byte> Sub_Rsp(int i) 
{
	vector<byte> SR;
	if (i>127)
	{
		SR = { 72, 129, 236 };
		SR.push_back(整数到字节集(i)[0]);
		SR.push_back(整数到字节集(i)[1]);
		SR.push_back(整数到字节集(i)[2]);
		SR.push_back(整数到字节集(i)[3]);
		SR.push_back(整数到字节集(i)[4]);
		SR.push_back(整数到字节集(i)[5]);
		SR.push_back(整数到字节集(i)[6]);
		SR.push_back(整数到字节集(i)[7]);
		return SR;
	}
	else
	{
		SR = { 72, 131, 236 };
		SR.push_back(整数到字节集(i)[0]);
		SR.push_back(整数到字节集(i)[1]);
		SR.push_back(整数到字节集(i)[2]);
		SR.push_back(整数到字节集(i)[3]);
		SR.push_back(整数到字节集(i)[4]);
		SR.push_back(整数到字节集(i)[5]);
		SR.push_back(整数到字节集(i)[6]);
		SR.push_back(整数到字节集(i)[7]);
		return SR;
	}
}

vector<byte> Call(INT64 地址)
{
	vector<byte> CA = { 255, 21, 2, 0, 0, 0, 235, 8 };
	CA.push_back(整数到字节集(地址)[0]);
	CA.push_back(整数到字节集(地址)[1]);
	CA.push_back(整数到字节集(地址)[2]);
	CA.push_back(整数到字节集(地址)[3]);
	CA.push_back(整数到字节集(地址)[4]);
	CA.push_back(整数到字节集(地址)[5]);
	CA.push_back(整数到字节集(地址)[6]);
	CA.push_back(整数到字节集(地址)[7]);
	return CA;
}

vector<byte> Add_Rsp(int i)
{
	vector<byte> AR;
	if (i > 127)
	{
		AR = { 72, 129, 196 };
		AR.push_back(整数到字节集(i)[0]);
		AR.push_back(整数到字节集(i)[1]);
		AR.push_back(整数到字节集(i)[2]);
		AR.push_back(整数到字节集(i)[3]);
		AR.push_back(整数到字节集(i)[4]);
		AR.push_back(整数到字节集(i)[5]);
		AR.push_back(整数到字节集(i)[6]);
		AR.push_back(整数到字节集(i)[7]);
		return AR;
	}
	else
	{
		AR = { 72, 131, 196 };
		AR.push_back(整数到字节集(i)[0]);
		AR.push_back(整数到字节集(i)[1]);
		AR.push_back(整数到字节集(i)[2]);
		AR.push_back(整数到字节集(i)[3]);
		AR.push_back(整数到字节集(i)[4]);
		AR.push_back(整数到字节集(i)[5]);
		AR.push_back(整数到字节集(i)[6]);
		AR.push_back(整数到字节集(i)[7]);
		return AR;
	}
}


void 组包_拾取(int 对象编号)
{
	缓冲Call(43);
	加密Call(对象编号, 4);
	加密Call(0, 1);
	加密Call(1, 1);
	加密Call(566, 2);
	加密Call(291, 2);
	加密Call(9961, 2);
	加密Call(553, 2);
	加密Call(285, 2);
	加密Call(18802, 2);
	加密Call(24743, 2);
	发包Call();
}

void 组包_通关翻牌()
{
	缓冲Call(69);
	发包Call();
	缓冲Call(70);
	发包Call();
	缓冲Call(71);
	加密Call(0, 1);
	加密Call(0, 1);
	发包Call();
}

void 组包_领取翻牌()
{

	缓冲Call(1434);
	发包Call();
}

//
//void 组包特殊()
//{
//	int 初始编号, 当前编号, 初始ID, 当前ID, I;
//	初始编号 = 100000003;
//	当前编号 = 全局_收包数据.参_地图编号;
//	初始ID = 0x2325;
//	当前ID = 当前编号 - 初始编号;
//	I = 初始ID + 当前ID;
//	if (读文本(读偏移型(商店基址 - 16, { 时间基址, 门型偏移, 地图名称, 0 }), 64) == L"智慧的引导")
//	{
//		缓冲Call(34);
//		加密Call(34, 2);
//		加密Call(9000, 2);
//		加密Call(65535, 2);
//		加密Call(1, 2);
//		加密Call(65535, 2);
//		发包Call();
//	}
//	if (读文本(读偏移型(商店基址 - 16, { 时间基址, 门型偏移, 地图名称, 0 }), 64) == L"风暴航路")
//	{
//		缓冲Call(34);
//		加密Call(34, 2);
//		加密Call(I, 2);
//		加密Call(65535, 2);
//		加密Call(1, 2);
//		加密Call(65535, 2);
//		发包Call();
//	}
//}

void 组包_强制回城()
{
	缓冲Call(42);
	发包Call();
}

void 组包_过图(int x, int y)
{
	缓冲Call(45);
	加密Call(x, 1);
	加密Call(y, 1);
	加密Call(0, 4);
	加密Call(0, 4);
	加密Call(0, 1);

	for (int i = 0; i < 9; i++)
	{
		加密Call(0, 2);
	}

	for (int i = 0; i < 8; i++)
	{
		加密Call(0, 4);
	}

	for (int i = 0; i < 7; i++)
	{
		加密Call(0, 2);
	}

	加密Call(0, 4);
	加密Call(0, 2);
	加密Call(0, 2);
	加密Call(0, 2);
	加密Call(0, 2);
	加密Call(0, 2);
	加密Call(0, 2);

	for (int i = 0; i < 16; i++)
	{
		加密Call(0, 4);
	}
	发包Call();

}


void 组包_分解(int 装备位置)
{
	缓冲Call(26);
	加密Call(0, 1);
	加密Call(65535, 2);
	加密Call(317, 4);
	加密Call(1, 1);
	加密Call(装备位置, 2);
	发包Call();
}

void 组包_卖物(int 位置, int 数量)
{

	缓冲Call(22);
	加密Call(0, 1);
	加密Call(位置, 2);
	加密Call(数量, 4);
	加密Call(29, 4);
	加密Call(49, 4);
	加密Call(位置 * 2 + 数量 * 2 + 1, 4);
	发包Call();



}

//void 组包_丢弃(int 装备指针)
//{
//	缓冲Call(18);
//	加密Call(装备指针, 4);
//	加密Call(装备指针, 18);
//	加密Call(0, 1);
//	发包Call();
//}

void 组包秒杀(unsigned short 服务器ID)
{
	缓冲Call(39);
	加密Call(服务器ID, 2);
	加密Call(0, 2);
	for (int i = 0; i < 4; i++)
	{
		加密Call(0, 4);
	}
	加密Call(1, 1);
	加密Call(273, 2);
	加密Call(0, 2);
	加密Call(0, 4);
	加密Call(0, 2);
	加密Call(0, 2);
	加密Call(0, 2);
	for (int a = 0; a < 4; a++)
	{
		加密Call(0, 1);
	}
	加密Call(0, 2);
	加密Call(0, 1);
	加密Call(0, 4);
	加密Call(0, 4);
	for (int b = 0; b < 7; b++)
	{
		加密Call(0, 2);
	}
	加密Call(0, 1);
	for (int c = 0; c < 16; c++)
	{
		加密Call(0, 4);
	}
	发包Call();
}

void 组包_选图()
{
	缓冲Call(15);
	加密Call(0, 4);
	发包Call();
}

void 组包_进图(int 地图代码, int 地图难度, int 深渊投递, int 任务编号, int 星空深渊)
{
	缓冲Call(16);
	加密Call(地图代码, 4);
	加密Call(地图难度, 1);
	加密Call(0, 2);
	加密Call(深渊投递, 1);
	加密Call(0, 1);
	加密Call(65535, 2);
	加密Call(0, 4);
	加密Call(0, 1);
	加密Call(任务编号, 4);
	加密Call(星空深渊, 1);
	加密Call(-1, 4);
	发包Call();

}


void 组包_退出角色()
{
	缓冲Call(7);
	发包Call();
}

void 组包_选择角色(int 角色位置)
{
	缓冲Call(4);
	加密Call(角色位置, 2);
	发包Call();
}

void 组包_整理背包()
{
	缓冲Call(20);
	加密Call(6, 4);
	加密Call(16, 1);
	加密Call(0, 1);
	加密Call(24, 1);
	加密Call(1, 1);
	加密Call(32, 1);
	加密Call(0, 1);
	发包Call();

}

void 组包_修仙死亡(unsigned short 服务器ID)
{

	缓冲Call(39);
	加密Call(服务器ID, 4);
	加密Call(1164, 2);
	加密Call(0, 8);
	加密Call(0, 4);
	加密Call(0, 8);
	加密Call(5, 4);
	加密Call(1, 1);
	加密Call(273, 2);
	加密Call(1164, 2);
	加密Call(0, 8);
	加密Call(5, 2);
	加密Call(1253, 2);
	加密Call(321, 2);
	加密Call(0, 1);
	加密Call(0, 1);
	加密Call(0, 1);
	加密Call(0, 1);
	加密Call(22908, 2);
	加密Call(0, 1);
	加密Call(91, 4);
	加密Call(0, 8);
	加密Call(900, 2);
	加密Call(418, 2);
	加密Call(1174, 2);
	加密Call(332, 2);
	加密Call(12, 2);
	加密Call(25, 2);
	加密Call(35, 2);
	加密Call(0, 1);
	加密Call(0, 1);
	发包Call();
}


void 组包_存金币(int 数量)
{

	缓冲Call(307);
	加密Call(数量, 4);
	发包Call();

}


void 组包_存金库(int 材料位置, int 物品代码, int 材料数量, int 金库位置)
{
	缓冲Call(19);
	加密Call(0, 1);
	加密Call(材料位置, 2);
	加密Call(物品代码, 4);
	加密Call(材料数量, 4);
	加密Call(12, 1);
	加密Call(金库位置, 2);
	加密Call(0, 4);
	加密Call(0, 4);
	加密Call(-1, 4);
	加密Call(0, 1);
	加密Call(0, 1);
	发包Call();
}

//
//void 组包_丢弃(int 坐标x, int 坐标y, int 背包位置, int 数量)
//{
//	缓冲Call(47);
//	加密Call(坐标x, 2);
//	加密Call(坐标y, 2);
//	加密Call(0, 1);
//	加密Call(背包位置, 2);
//	加密Call(数量, 4);
//	加密Call(0, 1);
//	发包Call();
//}


void 换装call(INT64 穿戴指针, INT64 装备代码,int 装备部位)
{
	装备数据.push_back(0x45);
	装备数据.push_back(0x31);
	装备数据.push_back(0xC9);
	装备数据.push_back(0x45);
	装备数据.push_back(0x31);
	装备数据.push_back(0xC0);
	装备数据.push_back(0x48);
	装备数据.push_back(0xBA);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0x00);
	装备数据.push_back(0xB9);
	装备数据.push_back(整数到字节集(装备代码)[0]);
	装备数据.push_back(整数到字节集(装备代码)[1]);
	装备数据.push_back(整数到字节集(装备代码)[2]);
	装备数据.push_back(整数到字节集(装备代码)[3]);
	装备数据.push_back(整数到字节集(装备代码)[4]);
	装备数据.push_back(整数到字节集(装备代码)[5]);
	装备数据.push_back(整数到字节集(装备代码)[6]);
	装备数据.push_back(整数到字节集(装备代码)[7]);
	装备数据.push_back(0x48);
	装备数据.push_back(0xB8);
	装备数据.push_back(整数到字节集(创建CALL)[0]);
	装备数据.push_back(整数到字节集(创建CALL)[1]);
	装备数据.push_back(整数到字节集(创建CALL)[2]);
	装备数据.push_back(整数到字节集(创建CALL)[3]);
	装备数据.push_back(整数到字节集(创建CALL)[4]);
	装备数据.push_back(整数到字节集(创建CALL)[5]);
	装备数据.push_back(整数到字节集(创建CALL)[6]);
	装备数据.push_back(整数到字节集(创建CALL)[7]);
	装备数据.push_back(0xFF);
	装备数据.push_back(0xD0);
	装备数据.push_back(0x48);
	装备数据.push_back(0x8B);
	装备数据.push_back(0xD0);
	装备数据.push_back(0x48);
	装备数据.push_back(0xB9);
	装备数据.push_back(整数到字节集(穿戴指针)[0]);
	装备数据.push_back(整数到字节集(穿戴指针)[1]);
	装备数据.push_back(整数到字节集(穿戴指针)[2]);
	装备数据.push_back(整数到字节集(穿戴指针)[3]);
	装备数据.push_back(整数到字节集(穿戴指针)[4]);
	装备数据.push_back(整数到字节集(穿戴指针)[5]);
	装备数据.push_back(整数到字节集(穿戴指针)[6]);
	装备数据.push_back(整数到字节集(穿戴指针)[7]);
	装备数据.push_back(0x48);
	装备数据.push_back(0x8B);
	装备数据.push_back(0x09);
	装备数据.push_back(0x41);
	装备数据.push_back(0xB8);
	装备数据.push_back(0xFF);
	装备数据.push_back(0xFF);
	装备数据.push_back(0xFF);
	装备数据.push_back(0xFF);
	装备数据.push_back(0x41);
	装备数据.push_back(0xB9);
	装备数据.push_back(1);
	装备数据.push_back(0);
	装备数据.push_back(0);
	装备数据.push_back(0);
	装备数据.push_back(0XC7);
	装备数据.push_back(0X44);
	装备数据.push_back(0X24);
	装备数据.push_back(0X20);
	装备数据.push_back(整数到字节集(装备部位)[0]);
	装备数据.push_back(整数到字节集(装备部位)[1]);
	装备数据.push_back(整数到字节集(装备部位)[2]);
	装备数据.push_back(整数到字节集(装备部位)[3]);
	装备数据.push_back(整数到字节集(装备部位)[4]);
	装备数据.push_back(整数到字节集(装备部位)[5]);
	装备数据.push_back(整数到字节集(装备部位)[6]);
	装备数据.push_back(整数到字节集(装备部位)[7]);
	装备数据.push_back(0x48);
	装备数据.push_back(0xBE);
	装备数据.push_back(整数到字节集(换装CALL)[0]);
	装备数据.push_back(整数到字节集(换装CALL)[1]);
	装备数据.push_back(整数到字节集(换装CALL)[2]);
	装备数据.push_back(整数到字节集(换装CALL)[3]);
	装备数据.push_back(整数到字节集(换装CALL)[4]);
	装备数据.push_back(整数到字节集(换装CALL)[5]);
	装备数据.push_back(整数到字节集(换装CALL)[6]);
	装备数据.push_back(整数到字节集(换装CALL)[7]);
	装备数据.push_back(0xFF);
	装备数据.push_back(0xD6);
}

void 加密(INT64 地址1, INT32 数值)
{
	INT32 加密ID = 0;
	INT64 偏移参数 = 0;
	INT64 偏移地址 = 0;
	INT64 data = 0;
	INT64 地址尾 = 0;
	INT16 ax = 0;
	INT16 si = 0;
	CString 公告值;
	加密ID = 读内存整数型(进程ID, 地址1);
	偏移参数 = 读内存长整数型(进程ID, 读内存长整数型(进程ID, 解密基址) + (加密ID >> 0x10) * 8 + 56);//解密基址
	偏移地址 = 偏移参数 + ((加密ID & 65535) * 4 + 8476);
	偏移参数 = 读内存长整数型(进程ID, 偏移地址);
	data = 偏移参数 & 0xFFFF;
	data += (data << 0x10) ;
	ax = (偏移参数 & 0xFFFF);
	地址尾 = (地址1 & 0xF);
	if (地址尾 == 0)
	{
		si = (数值 >> 0x10);
		si -= ax;
		si += 数值;
	}
	else if (地址尾 == 4)
	{
		si = (数值 & 0xFFFF) - (数值 >> 0x10);
	}
	else if (地址尾 == 8)
	{
		si = (数值 >> 0x10);
		si *= 数值;
	}
	else if (地址尾 == 0xC)
	{
		si = (数值 >> 0x10);
		si += 数值;
		si += ax;
	}
	else
	{
		return;
	}
	ax = si  ^ ax;
	写内存短整数型(进程ID, 偏移地址 + 2, ax);
	写内存整数型(进程ID, 地址1 + 4, (data ^ 数值));
}
int 解密(INT64 address)
{
	INT64 r1,r3, r4, r5, r6, r7;
	INT32 r2, r8, r10, r11;	
	
	r1 = (INT64)读内存短整数型(进程ID, address) & (INT64)65535;
	r2 = 读内存整数型(进程ID,address) >> 16;
	r3 = 读内存长整数型(进程ID,解密基址);
	r4 = r3 + (8 * (INT64)r2 + 56);
	r5 = 读内存长整数型(进程ID,r4);
	r6 = r5 + 4 * r1;
	r7 = r6 + (INT64)8476;
	r8 = 读内存整数型(进程ID,r7);
	r10 = r8 & 65535;
	r11 = r10;
	r10 = r10 << 16;
	r11= r11 | r10;
	r8 = 读内存整数型(进程ID, address + 4) ^ r11;
	return r8;
}


void 满血满蓝() 
{

	写内存整数型(进程ID, 读内存长整数型(进程ID, 人物基址) + 满血偏移, 256);
	写内存整数型(进程ID, 读内存长整数型(进程ID, 人物基址) + 满蓝偏移, 256);

}

void 卖修() 
{
	INT64 pd = 读内存长整数型(进程ID, 卖修基址);
	CString str;
	str.Format("%ld", pd);
	MessageBoxA(自窗口句柄, str, "DNF",  NULL);
	if (pd != 5) 
	{
		
		写内存整数型(进程ID, 读内存长整数型(进程ID, 卖修基址), 5);
	}
	else
	{
		写内存整数型(进程ID, 读内存长整数型(进程ID, 卖修基址), 6);
	}
}

void 透明call(INT64 对象指针) 
{
	vector<byte>汇编数据;
	汇编数据 = { 0x48,0x81,0xEC,0x00,0x02,0,0,0x41,0xBF ,0xFF ,0xFF ,0xFF ,0xFF ,0xC7 ,0x44 ,0x24 ,0x20 ,0xFF ,0xFF ,0x00 ,0x00 ,0x41 ,0xB9 ,0x01 ,0x00 ,0x00 ,0x00 ,0x49 ,0xB8 ,0x01 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0xBA ,0x01 ,0x00 ,0x00 ,0x00 ,0x48 ,0xB9 };
	汇编数据.push_back(整数到字节集(对象指针)[0]);
	汇编数据.push_back(整数到字节集(对象指针)[1]);
	汇编数据.push_back(整数到字节集(对象指针)[2]);
	汇编数据.push_back(整数到字节集(对象指针)[3]);
	汇编数据.push_back(整数到字节集(对象指针)[4]);
	汇编数据.push_back(整数到字节集(对象指针)[5]);
	汇编数据.push_back(整数到字节集(对象指针)[6]);
	汇编数据.push_back(整数到字节集(对象指针)[7]);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xB8);
	汇编数据.push_back(整数到字节集(透明CALL)[0]);
	汇编数据.push_back(整数到字节集(透明CALL)[1]);
	汇编数据.push_back(整数到字节集(透明CALL)[2]);
	汇编数据.push_back(整数到字节集(透明CALL)[3]);
	汇编数据.push_back(整数到字节集(透明CALL)[4]);
	汇编数据.push_back(整数到字节集(透明CALL)[5]);
	汇编数据.push_back(整数到字节集(透明CALL)[6]);
	汇编数据.push_back(整数到字节集(透明CALL)[7]);
	汇编数据.push_back(0xFF);
	汇编数据.push_back(0xD0);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0x81);
	汇编数据.push_back(0xC4);
	汇编数据.push_back(0x00);
	汇编数据.push_back(0x02);
	汇编数据.push_back(0x00);
	汇编数据.push_back(0x00);
	内存汇编x64(汇编数据);
}

void 透明无敌() 
{
	透明call(读内存长整数型(进程ID, 人物基址));
}

void 超级评分() 
{
	写内存长整数型(进程ID, 读内存长整数型(进程ID, 评分基址) + 0xD00, (INT64)rand() + 777777);
}

void 全屏捡物() 
{
	INT64 i, 对象数量, 一级偏移, 二级偏移, 局_首地址, 局_尾地址,对象指针;
	INT32   对象A, 对象B, 物品编号;

	一级偏移 = 读内存长整数型(进程ID, 人物基址);
	二级偏移 = 读内存长整数型(进程ID,一级偏移 + 地图偏移);
	局_首地址 = 读内存长整数型(进程ID, 二级偏移 + 首地址);
	局_尾地址 = 读内存长整数型(进程ID, 二级偏移 + 尾地址);
	对象数量 = (尾地址 - 首地址) / 8;
	for (i = 0; i < 对象数量; i++) 
	{
		对象指针 = 读内存长整数型(进程ID, 首地址 + i * 8);
		对象A = 读内存整数型(进程ID, 对象指针 + 类型偏移);
		对象B = 读内存整数型(进程ID, 对象指针 + 类型偏移+4);
		if (对象A == 289 || 对象B == 289) 
		{
			物品编号 = 解密(对象指针 + 入包偏移);
			组包_拾取(物品编号);
		}
	}
}

坐标型 读坐标(INT64 对象指针)
{
	坐标型 对象坐标;
	INT64 指针;
	指针 = 读内存长整数型(进程ID, 对象指针 + 读取坐标);
	对象坐标.x = (int)读内存小数型(进程ID, 指针);
	对象坐标.y = (int)读内存小数型(进程ID, 指针 + 4);
	对象坐标.z = (int)读内存小数型(进程ID, 指针 + 8);
	return 对象坐标;
}

void 吸怪()
{
	INT64 i, 对象数量, 一级偏移, 二级偏移, 局_首地址, 局_尾地址, 对象指针;
	INT32  怪物数据;
	坐标型 对象坐标;
	一级偏移 = 读内存长整数型(进程ID, 人物基址);
	二级偏移 = 读内存长整数型(进程ID, 一级偏移 + 地图偏移);
	对象坐标 = 读坐标(一级偏移);
	局_首地址 = 读内存长整数型(进程ID, 二级偏移 + 首地址);
	局_尾地址 = 读内存长整数型(进程ID, 二级偏移 + 尾地址);
	对象数量 = (尾地址 - 首地址) / 8;
	for (i = 0; i < 对象数量; i++)
	{
		对象指针 = 读内存长整数型(进程ID, 首地址 + i * 8);
		怪物数据 = 读内存整数型(进程ID, 对象指针 + 类型偏移);
		if (怪物数据 == 529 || 怪物数据 == 273)
		{
			if (一级偏移 != 怪物数据) 
			{
				写内存小数型(进程ID, 读内存长整数型(进程ID, 怪物数据 + 方向偏移 + 16), (float)对象坐标.x);
				写内存小数型(进程ID, 读内存长整数型(进程ID, 怪物数据 + 方向偏移 + 20), (float)对象坐标.y);
			}
		}
		处理事件();
	}
}


INT64 顺图数据(int 顺图方向) 
{
	INT64 空白地址;
	空白地址 = (INT64)申请内存x64(100);
	INT64 房间数据;
	vector<byte>汇编数据;		
	房间数据 = 读内存长整数型(进程ID, 读内存长整数型(进程ID, 读内存长整数型(进程ID, 房间编号) + 时间基址) + 顺图偏移);
	汇编数据 = { 72, 129, 236, 0, 1, 0, 0 };
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xB9);
	汇编数据.push_back(整数到字节集(房间数据)[0]);
	汇编数据.push_back(整数到字节集(房间数据)[1]);
	汇编数据.push_back(整数到字节集(房间数据)[2]);
	汇编数据.push_back(整数到字节集(房间数据)[3]);
	汇编数据.push_back(整数到字节集(房间数据)[4]);
	汇编数据.push_back(整数到字节集(房间数据)[5]);
	汇编数据.push_back(整数到字节集(房间数据)[6]);
	汇编数据.push_back(整数到字节集(房间数据)[7]);
	汇编数据.push_back(0xBA);
	汇编数据.push_back(整数到字节集(顺图方向)[0]);
	汇编数据.push_back(整数到字节集(顺图方向)[1]);
	汇编数据.push_back(整数到字节集(顺图方向)[2]);
	汇编数据.push_back(整数到字节集(顺图方向)[3]);
	汇编数据.push_back(整数到字节集(顺图方向)[4]);
	汇编数据.push_back(整数到字节集(顺图方向)[5]);
	汇编数据.push_back(整数到字节集(顺图方向)[6]);
	汇编数据.push_back(整数到字节集(顺图方向)[7]);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xB8);
	汇编数据.push_back(整数到字节集(顺图CALL)[0]);
	汇编数据.push_back(整数到字节集(顺图CALL)[1]);
	汇编数据.push_back(整数到字节集(顺图CALL)[2]);
	汇编数据.push_back(整数到字节集(顺图CALL)[3]);
	汇编数据.push_back(整数到字节集(顺图CALL)[4]);
	汇编数据.push_back(整数到字节集(顺图CALL)[5]);
	汇编数据.push_back(整数到字节集(顺图CALL)[6]);
	汇编数据.push_back(整数到字节集(顺图CALL)[7]);
	汇编数据.push_back(0xFF);
	汇编数据.push_back(0xD0);
	汇编数据.push_back(0x48);
	汇编数据.push_back(0xA3);
	汇编数据.push_back(整数到字节集(空白地址)[0]);
	汇编数据.push_back(整数到字节集(空白地址)[1]);
	汇编数据.push_back(整数到字节集(空白地址)[2]);
	汇编数据.push_back(整数到字节集(空白地址)[3]);
	汇编数据.push_back(整数到字节集(空白地址)[4]);
	汇编数据.push_back(整数到字节集(空白地址)[5]);
	汇编数据.push_back(整数到字节集(空白地址)[6]);
	汇编数据.push_back(整数到字节集(空白地址)[7]);
	汇编数据.push_back(72);
	汇编数据.push_back(129);
	汇编数据.push_back(196);
	汇编数据.push_back(0);
	汇编数据.push_back(1);
	汇编数据.push_back(0);
	汇编数据.push_back(0);
	内存汇编x64(汇编数据);
	return 读内存长整数型(进程ID, 空白地址);
}
void 坐标过图(int 顺图方向) 
{
	INT64 房间数据;
	int x, y, xF, yF, cx = 0, cy = 0;
	房间数据 = 顺图数据(顺图方向);
	x = 读内存整数型(进程ID,房间数据 + 0);
	y = 读内存整数型(进程ID,房间数据 + 4);
	xF = 读内存整数型(进程ID,房间数据 + 8);
	yF = 读内存整数型(进程ID,房间数据 + 12);
	if (顺图方向 == 0)
	{
		cx = x + xF + 20;
		cy = y + yF / 2;
	}
	else if (顺图方向 == 1)
	{
		cx = x - 20;
		cy = y + yF / 2;
	}
	else if (顺图方向 == 2)
	{
		cx = x + xF / 2;
		cy = y + yF + 20;
	}
	else if (顺图方向 == 3)
	{
		cx = x + xF / 2;
		cy = y - 20;
	}
	坐标call(cx, cy, 0);
	超级延时(10);
	坐标call(x + xF / 2, y, 0);

}

void 顺图_左() 
{
	坐标过图(0);
}
void 顺图_上()
{
	坐标过图(2);
}
void 顺图_右()
{
	坐标过图(1);
}
void 顺图_下()
{
	坐标过图(3);
}



void 漂移call(INT64 指针, INT32 横轴, INT32 纵轴, INT32 竖轴, INT32 速度 ) 
{
	//__asm 
	//{
	//	mov ecx, 0xF4
	//	mov rax, 申请内存
	//	call rax
	//	mov rsi, rax   
	//	mov rcx, rax
	//	mov rax, 漂移CALL
	//	call rax
	//	mov ecx, 横轴
	//	mov[rax], ecx
	//	mov ecx, 纵轴
	//	mov[rax + 4], ecx
	//	mov ecx, 竖轴
	//	mov[rax + 8], ecx  
	//	lea rcx, [rax + 0x18]
	//	mov edx, 速度
	//	mov rax, 漂移CALL2
	//	call rax
	//	lea rdx, [rsp + 0x70] 
	//	xor ebx,ebx  
	//	mov [rsp+0x70],rbx  
	//	mov[rsp+0x78],rbx  
	//	xor edx,edx  
	//	lea rcx,[rsp+0x70]
	//	mov rax, 写入内存
	//	call rax
	//	mov rcx, rsi   
	//	mov rax, [rcx]
	//	mov rdx, 指针
	//	xor rbx, rbx  
	//	mov r13, 0xFFFFFFFFFFFFFFFF
	//	mov[rsp + 0x40], ebx 
	//	mov[rsp + 0x38], rbx 
	//	mov[rsp + 0x30], r13d
	//	mov[rsp + 0x28], 0x2E8
	//	lea rdi, [rsp + 0x70]  
	//	mov[rsp + 0x20], rdi
	//	xor r9d, r9d
	//	mov r8, 指针
	//	call[rax + 0x120]
	//}
}



void 系统公告(wstring 公告内容)
{

	//LPCWSTR tempStr;
	//公告内容 = 公告内容;
	//tempStr = 公告内容.c_str();
	//__asm {
	//	mov rsi, 0
	//	mov rcx, 商店基址
	//	mov rcx, [rcx]
	//	mov rcx, [rcx + 0xA0]
	//	mov rdx, tempStr
	//	mov qword ptr[rsp + 0x40], rsi
	//	mov byte ptr[rsp + 0x38], 00
	//	mov byte ptr[rsp + 0x30], 00
	//	mov qword ptr[rsp + 0x28], rsi
	//	mov qword ptr[rsp + 0x20], rsi
	//	mov r8d, 0xFFFFFFF0
	//	mov r9d, 0x11
	//	call 喇叭公告
	//}
}

void 普通公告(wstring 公告内容)
{

	//LPCWSTR tempStr;
	//tempStr = 公告内容.c_str();
	//__asm {
	//	mov rsi, 0
	//	mov rcx, 商店基址
	//	mov rcx, [rcx]
	//	mov rcx, [rcx + 0xA0]
	//	mov rdx, tempStr
	//	mov qword ptr[rsp + 0x40], rsi
	//	mov byte ptr[rsp + 0x38], 00
	//	mov byte ptr[rsp + 0x30], 00
	//	mov qword ptr[rsp + 0x28], rsi
	//	mov qword ptr[rsp + 0x20], rsi
	//	mov r8d, 0xFF008FFF
	//	mov r9d, 0x25
	//	call 喇叭公告
	//}
}

void 神话公告(CString 公告内容, int 类型)
{
	INT64 空白地址 = 0, 空白地址1 = 0, 空白地址2 = 0;
	if (空白地址 == 0)
	{

		空白地址 = (INT64)申请内存x64(1024);
		空白地址1 = 空白地址 + 200;
		空白地址2 = 空白地址1 + 350;
	}
	if (类型 == 0)
		类型 = 38;
	else if (类型 == 1)
		类型 = 17;
	else if (类型 == 2)
		类型 = 54;
	else if (类型 == 3)
		类型 = 56;

	写内存长整数型(进程ID,空白地址 + 8, 空白地址1);
	写内存整数型(进程ID,空白地址 + 24, 解密(读内存长整数型(进程ID, 人物基址) + 入包偏移) );//0
	写内存整数型(进程ID,空白地址 + 28, -1);
	写内存整数型(进程ID, 空白地址 + 32, 65535);//65280  //16777062
	写内存整数型(进程ID,空白地址 + 36, 类型);
	写内存字节集(进程ID,空白地址1, Ansi转Unicode(公告内容));
	写内存字节集(进程ID,空白地址2, Ansi转Unicode("character/common/th_music.img"));
	写内存整数型(进程ID,空白地址 + 40, 16);
	写内存长整数型(进程ID,空白地址 + 44, 空白地址2);
	写内存长整数型(进程ID,空白地址 + 56, 空白地址2);
	写内存整数型(进程ID, 空白地址 + 108, 16751103);//16754943

	组包数据.push_back(0x48);
	组包数据.push_back(0X81);
	组包数据.push_back(0XEC);
	组包数据.push_back(0X00);
	组包数据.push_back(0X01);
	组包数据.push_back(0X00);
	组包数据.push_back(0X00);
	组包数据.push_back(0X48);
	组包数据.push_back(0XBA);
	组包数据.push_back(整数到字节集(空白地址)[0]);
	组包数据.push_back(整数到字节集(空白地址)[1]);
	组包数据.push_back(整数到字节集(空白地址)[2]);
	组包数据.push_back(整数到字节集(空白地址)[3]);
	组包数据.push_back(整数到字节集(空白地址)[4]);
	组包数据.push_back(整数到字节集(空白地址)[5]);
	组包数据.push_back(整数到字节集(空白地址)[6]);
	组包数据.push_back(整数到字节集(空白地址)[7]);
	组包数据.push_back(0X48);
	组包数据.push_back(0XBE);
	组包数据.push_back(整数到字节集(公告参数)[0]);
	组包数据.push_back(整数到字节集(公告参数)[1]);
	组包数据.push_back(整数到字节集(公告参数)[2]);
	组包数据.push_back(整数到字节集(公告参数)[3]);
	组包数据.push_back(整数到字节集(公告参数)[4]);
	组包数据.push_back(整数到字节集(公告参数)[5]);
	组包数据.push_back(整数到字节集(公告参数)[6]);
	组包数据.push_back(整数到字节集(公告参数)[7]);
	组包数据.push_back(0x48);
	组包数据.push_back(0X8B);
	组包数据.push_back(0X36);
	组包数据.push_back(0X48);
	组包数据.push_back(0X89);
	组包数据.push_back(0XF1);
	组包数据.push_back(0XBF);
	组包数据.push_back(0XFF);
	组包数据.push_back(0XFF);
	组包数据.push_back(0XFF);
	组包数据.push_back(0XFF);
	组包数据.push_back(0X48);
	组包数据.push_back(0XB8);
	组包数据.push_back(整数到字节集(公告CALL)[0]);
	组包数据.push_back(整数到字节集(公告CALL)[1]);
	组包数据.push_back(整数到字节集(公告CALL)[2]);
	组包数据.push_back(整数到字节集(公告CALL)[3]);
	组包数据.push_back(整数到字节集(公告CALL)[4]);
	组包数据.push_back(整数到字节集(公告CALL)[5]);
	组包数据.push_back(整数到字节集(公告CALL)[6]);
	组包数据.push_back(整数到字节集(公告CALL)[7]);
	组包数据.push_back(0xFF);
	组包数据.push_back(0XD0);
	组包数据.push_back(0X48);
	组包数据.push_back(0X81);
	组包数据.push_back(0XC4);
	组包数据.push_back(0X00);
	组包数据.push_back(0X01);
	组包数据.push_back(0X00);
	组包数据.push_back(0X00);
	内存汇编x64(组包数据);
	//组包数据.clear();
	vector<byte>().swap(组包数据);
}

void 管理权限() 
{
	//static INT64 相对地址 = 角色基址 - GM权限模式 - 7;
	//vector <byte>  字节集 = 整数到字节集(相对地址);
	//vector <byte> 字节集左 = { 72, 59, 13 };
	//vector <byte> 字节集右 = { 15, 148, 192, 195, 204, 204 };
	//static vector <byte> 权限数据;
	//static bool 权限开关;
	//权限开关 = !权限开关;
	//if (权限开关)
	//{
	//	字节集.insert(字节集.begin(), 字节集左.begin(), 字节集左.end());
	//	字节集.insert(字节集.end(), 字节集右.begin(), 字节集右.end());
	//	权限数据 = 读内存字节集(进程ID, GM权限模式, 16);
	//	写内存字节集(进程ID, GM权限模式, 字节集);
	//	神话公告("管理权限 - 开",1);
	//}
	//else
	//{
	//	写内存字节集(进程ID, GM权限模式, 权限数据);
	//	神话公告("管理权限 - 关", 1);
	//}
}

void 三速负重耐久() 
{
	加密(取偏移地址( 人物基址, { 鞋子偏移, 0 }) + 攻击速度, 300*10);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 鞋子偏移, 0 }) + 施放速度, 300*10);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 鞋子偏移, 0 }) + 移动速度, 300*10);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 鞋子偏移, 0 }) + 负重偏移, 300*1000);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 武器偏移, 最大耐久 }), 0);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 上衣偏移, 最大耐久 }), 0);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 下装偏移, 最大耐久 }), 0);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 头肩偏移, 最大耐久 }), 0);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 腰带偏移, 最大耐久 }), 0);
	超级延时(100);
	加密(取偏移地址( 人物基址, { 鞋子偏移, 最大耐久 }), 0);
}

void 队友消失()
{
	INT64 i, 数量, 一级偏移, 二级偏移, 局_首地址, 局_尾地址,遍历指针;
	INT32  类型,阵营;
	一级偏移 = 读内存长整数型(进程ID, 人物基址);
	二级偏移 = 读内存长整数型(进程ID, 一级偏移 + 地图偏移);
	if (二级偏移 == 0) 
	{
		return;
	}

	局_首地址 = 读内存长整数型(进程ID, 二级偏移 + 首地址);
	局_尾地址 = 读内存长整数型(进程ID, 二级偏移 + 尾地址);
	数量 = (尾地址 - 首地址) / 8;

	for ( i = 0; i < 数量; i++)
	{
		遍历指针 = 读内存长整数型(进程ID, 首地址 + i * 8);
		类型 = 读内存整数型(进程ID, 遍历指针 + 类型偏移);
		阵营 = 读内存整数型(进程ID, 遍历指针 + 阵营偏移);
		if ((阵营 == 50) || (阵营 == 100) || (阵营 == 101) || (阵营 == 0))
		{
			if (类型==273)
			{
				if (遍历指针 != 一级偏移)
				{
					加密(遍历指针 + 792, 0);
				}
			}
		}
	}
	神话公告("无视队友 [开启]",1);
}

INT32 取角色等级() 
{
	return 读内存整数型(进程ID, 角色等级);
}

void 无视等级()
{
	vector<int> 偏移地址;
	int 角色等级 = 取角色等级();
	偏移地址 = { 武器偏移,0 };
	加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);

	if (角色等级<100)
	{
		偏移地址 = { 武器偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 上衣偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 下装偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 头肩偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 腰带偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 鞋子偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 手镯偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 项链偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 戒指偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 辅助装备,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { __魔法石,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);
		偏移地址 = { 耳环偏移,0 };
		加密(取偏移地址(人物基址, 偏移地址) + 装备等级偏移, 1);

	}
	
}



vector<byte> PASS动态(int val, int n) 
{
	CString 基址文本,文本1;
	vector<byte>转换结果;
	INT64 b;
	基址文本 =十到十六(val);
	文本1=基址文本.Right(n);
	for (int i = 0; i < sizeof(文本1)/2; i++) 
	{
		b = strtol(文本1.Mid((int)sizeof(文本1) - (i * 2+2 ), 2),0,16);
		转换结果.push_back(b);
	}
	return 转换结果;
}

void 物品buff() 
{
	物品Call(1025);  // 狂龙吼一声
	物品Call(1072);  // 邪恶药剂50力智
	物品Call(1091);  // 属性药水属性攻击
	物品Call(1298);  // 超速 30三速
	物品Call(7163);  // 蒂米迪亚的蛋糕
	物品Call(2600027);  // 透明药
	物品Call(2600021);  // 精神刺激 20冷却
	物品Call(2600561);  // 顶级175力量药
	物品Call(2600562);  // 顶级175智力药
	物品Call(2600655);  // 小斗神 10伤害
	物品Call(2600656);  // 斗神 12伤害
	物品Call(2600021);  // 精神刺激 20冷却
	物品Call(2600028);  // 血蓝药
	物品Call(2600020);  // 复活药
	物品Call(2600022);  // 霸体药
	物品Call(2680766);  // 死神的瞬间增益胶囊 (力智 +100);
	物品Call(2683266);  // 武者CD药
	物品Call(2682833);  // 三攻10%
	物品Call(2683263);  // 虚祖药
	物品Call(2683264);  // 千体药
	物品Call(10004110);  // 双攻15%
	物品Call(10004505);  // 忍者能量药剂  魔攻10%
	物品Call(10004695);  // 壕罐的攻击药剂
	物品Call(10088698);  // -13CD
	物品Call(10088630);  // 20三攻
	物品Call(10088699);  // 40三攻
	物品Call(10088636);  // 8%暴击
	物品Call(10099409);  // 活力秘药
	物品Call(10007342);  // 亚丝娜的秘制酱汁 (力智+100);
	物品Call(10007483);  // 黄金羊毛
	物品Call(490703676);  // 快乐飞跃药剂
	物品Call(490703930);  // 魔界战力药  150力智
	物品Call(490703931);  // 魔界潜力药  10速度
	物品Call(490705903);  // 春之祝福2000力智
	物品Call(490013664);  // 雪人药 14000力智
	物品Call(490014049);  // 成长药水14000力智
	物品Call(490016659);  // 主播热枕14000力智
	物品Call(490017343);  // 智慧引导14000力智
	物品Call(490010896);  // 潜能爆发药剂
	物品Call(490015961);  // 天才的精神刺激灵药物
	物品Call(490010607);  // 耶姆之息药剂
	
}

void 改药()
{
	INT64 空白地址;
	INT64 物品代码, 药剂地址;
	物品代码 = 490703930;  //' 魔界战力释放秘药' 2683263  ' 虚祖药
	空白地址 =(INT64)申请内存x64(1024);
	药剂地址 = 获取物品数据call(物品代码);
	写内存长整数型(进程ID, 药剂地址 + 药剂开始, 空白地址);  //' 开始
	写内存长整数型(进程ID, 药剂地址 + 药剂结束A, 空白地址 + 300); // ' 结束
	写内存长整数型(进程ID, 药剂地址 + 药剂结束B, 空白地址 + 300); // ' 结束
	写内存长整数型(进程ID, 药剂地址 + 药剂持续时间, 3000000); // ' 持续时间
	写内存整数型(进程ID, 药剂地址 + 药剂生效2, 1); // ' 生效
		// 攻击速度
	写内存整数型(进程ID, 空白地址 + 0, 10);
	写内存整数型(进程ID, 空白地址 + 4, 3000);
	写内存整数型(进程ID, 空白地址 + 8, 0);
	写内存整数型(进程ID, 空白地址 + 12, 0);
		//移动速度	   句柄			+
	写内存整数型(进程ID, 空白地址 + 16, 11);
	写内存整数型(进程ID, 空白地址 + 20, 200);
	写内存整数型(进程ID, 空白地址 + 24, 0);
	写内存整数型(进程ID, 空白地址 + 28, 0);
		//施放速度	   句柄			+
	写内存整数型(进程ID, 空白地址 + 32, 12);
	写内存整数型(进程ID, 空白地址 + 36, 3000);
	写内存整数型(进程ID, 空白地址 + 40, 0);
	写内存整数型(进程ID, 空白地址 + 44, 0);
		//跳跃力	  句	柄		 +
	写内存整数型(进程ID, 空白地址 + 48, 8);
	写内存整数型(进程ID, 空白地址 + 52, 180);//' 1500%
	写内存整数型(进程ID, 空白地址 + 56, 0);
	写内存整数型(进程ID, 空白地址 + 60, 0);
		//HP恢复	  句	柄		 +				 ;
	写内存整数型(进程ID, 空白地址 + 64, 14);
	写内存整数型(进程ID, 空白地址 + 68, 1000000);
	写内存整数型(进程ID, 空白地址 + 72, 0);
	写内存整数型(进程ID, 空白地址 + 76, 0);
		//物理暴击	  句	柄		 +				 
	写内存整数型(进程ID, 空白地址 + 80, 15);
	写内存整数型(进程ID, 空白地址 + 84, 150);
	写内存整数型(进程ID, 空白地址 + 88, 0);
	写内存整数型(进程ID, 空白地址 + 92, 0);
		//魔法暴击率  句	柄		 +				 
	写内存整数型(进程ID, 空白地址 + 96, 16);
	写内存整数型(进程ID, 空白地址 + 100, 150);
	写内存整数型(进程ID, 空白地址 + 104, 0);
	写内存整数型(进程ID, 空白地址 + 108, 0);
		// 所有抗性
	写内存长整数型(进程ID, 空白地址 + 112, 24);
	写内存长整数型(进程ID, 空白地址 + 116, 10000); 
	写内存长整数型(进程ID, 空白地址 + 120, 0);
	写内存长整数型(进程ID, 空白地址 + 124, 0);


	// 所有异常状态抗性
	写内存长整数型(进程ID, 空白地址 + 128, 43);
	写内存长整数型(进程ID, 空白地址 + 132, 10000);
	写内存长整数型(进程ID, 空白地址 + 136, 0);
	写内存长整数型(进程ID, 空白地址 + 140, 0);
	//  MP回复率		
	写内存长整数型(进程ID, 空白地址 + 144, 46);
	写内存长整数型(进程ID, 空白地址 + 148, 100000);
	写内存长整数型(进程ID, 空白地址 + 152, 0);
	写内存长整数型(进程ID, 空白地址 + 156, 0);
	// 冷却
	写内存整数型(进程ID, 空白地址 + 160, 106);
	写内存整数型(进程ID, 空白地址 + 164, -95);  //' -90
	写内存整数型(进程ID, 空白地址 + 168, 0);
	写内存整数型(进程ID, 空白地址 + 172, 0);
	// 命中率		
	写内存长整数型(进程ID, 空白地址 + 176, 50);
	写内存长整数型(进程ID, 空白地址 + 180, -100);
	写内存长整数型(进程ID, 空白地址 + 184, 0);
	写内存长整数型(进程ID, 空白地址 + 188, 0);
	// 被击时所受物理伤害减少	
	写内存长整数型(进程ID, 空白地址 + 192, 131);
	写内存长整数型(进程ID, 空白地址 + 196, 100000);
	写内存长整数型(进程ID, 空白地址 + 200, 1);
	写内存长整数型(进程ID, 空白地址 + 204, 0);
	//被击时所受魔法伤害减少
	写内存整数型(进程ID, 空白地址 + 208, 132);
	写内存整数型(进程ID, 空白地址 + 212, 100000);  //' -90
	写内存整数型(进程ID, 空白地址 + 216, 1);
	写内存整数型(进程ID, 空白地址 + 220, 0);
	//技能无色消耗量	
	写内存长整数型(进程ID, 空白地址 + 224, 104);
	写内存长整数型(进程ID, 空白地址 + 228, -100);
	写内存长整数型(进程ID, 空白地址 + 232, 1);
	写内存长整数型(进程ID, 空白地址 + 236, 0);
	// 最终伤害	
	写内存长整数型(进程ID, 空白地址 + 240, 110);
	写内存长整数型(进程ID, 空白地址 + 244, 200000);
	写内存长整数型(进程ID, 空白地址 + 248, 1);
	写内存长整数型(进程ID, 空白地址 + 252, 0);
	//却
	//写内存整数型(进程ID, 空白地址 + 256, 110);
	//写内存整数型(进程ID, 空白地址 + 260, 200000);  //' -90
	//写内存整数型(进程ID, 空白地址 + 264, 1);
	//写内存整数型(进程ID, 空白地址 + 268, 0);
	// 力量			
	//写内存长整数型(进程ID, 空白地址 + 144, 0);
	//写内存长整数型(进程ID, 空白地址 + 148, 14000);
	//写内存长整数型(进程ID, 空白地址 + 152, 0);
	//写内存长整数型(进程ID, 空白地址 + 156, 0);
	// 智力			
	//写内存长整数型(进程ID, 空白地址 + 160, 1);
	//写内存长整数型(进程ID, 空白地址 + 164, 14000);
	//写内存长整数型(进程ID, 空白地址 + 168, 0);
	//写内存长整数型(进程ID, 空白地址 + 172, 0);
	////却
	//写内存整数型(进程ID, 空白地址 + 144, 106);
	//写内存整数型(进程ID, 空白地址 + 148, -95);  //' -90
	//写内存整数型(进程ID, 空白地址 + 152, 0);
	//写内存整数型(进程ID, 空白地址 + 156, 0);

	物品Call(物品代码);

	神话公告("药剂buff已附加",0);
}

INT64 获取物品数据call(INT64 物品代码)
{
	vector<byte> 数据;
	INT64 空白地址;
	INT64 物品rcx, call地址;
	物品rcx = 物品RCX;
	call地址 = 物品数据;
	空白地址 = (INT64)申请内存x64(4096);
	//神话公告("申请数据内存", 0);
	数据 = { 0x53,0x48,0x83,0xEC,0x28,49,0xB8,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xB9 };
	//神话公告("数据赋值0", 0);
	数据.push_back(整数到字节集(物品rcx)[0]);
	数据.push_back(整数到字节集(物品rcx)[1]);
	数据.push_back(整数到字节集(物品rcx)[2]);
	数据.push_back(整数到字节集(物品rcx)[3]);
	数据.push_back(整数到字节集(物品rcx)[4]);
	数据.push_back(整数到字节集(物品rcx)[5]);
	数据.push_back(整数到字节集(物品rcx)[6]);
	数据.push_back(整数到字节集(物品rcx)[7]);
	//神话公告("数据赋值1", 0);
	数据.push_back(0x48);
	数据.push_back(0x8B);
	数据.push_back(0x09);
	数据.push_back(0x48);
	数据.push_back(0xBA);
	//神话公告("数据赋值2", 0);
	数据.push_back(整数到字节集(物品代码)[0]);
	数据.push_back(整数到字节集(物品代码)[1]);
	数据.push_back(整数到字节集(物品代码)[2]);
	数据.push_back(整数到字节集(物品代码)[3]);
	数据.push_back(整数到字节集(物品代码)[4]);
	数据.push_back(整数到字节集(物品代码)[5]);
	数据.push_back(整数到字节集(物品代码)[6]);
	数据.push_back(整数到字节集(物品代码)[7]);
	//神话公告("数据赋值3", 0);
	数据.push_back(0x48);
	数据.push_back(0xBE);
	数据.push_back(整数到字节集(call地址)[0]);
	数据.push_back(整数到字节集(call地址)[1]);
	数据.push_back(整数到字节集(call地址)[2]);
	数据.push_back(整数到字节集(call地址)[3]);
	数据.push_back(整数到字节集(call地址)[4]);
	数据.push_back(整数到字节集(call地址)[5]);
	数据.push_back(整数到字节集(call地址)[6]);
	数据.push_back(整数到字节集(call地址)[7]);
	//神话公告("数据赋值4", 0);
	数据.push_back(0xFF);
	数据.push_back(0xD6);
	数据.push_back(0x48);
	数据.push_back(0xA3);
	数据.push_back(整数到字节集(空白地址)[0]);
	数据.push_back(整数到字节集(空白地址)[1]);
	数据.push_back(整数到字节集(空白地址)[2]);
	数据.push_back(整数到字节集(空白地址)[3]);
	数据.push_back(整数到字节集(空白地址)[4]);
	数据.push_back(整数到字节集(空白地址)[5]);
	数据.push_back(整数到字节集(空白地址)[6]);
	数据.push_back(整数到字节集(空白地址)[7]);
	//神话公告("数据赋值5", 0);
	数据.push_back(0x48);
	数据.push_back(0x83);
	数据.push_back(0xC4);
	数据.push_back(0x28);
	数据.push_back(0x5B);
	数据.push_back(0xC3);
	//神话公告("数据汇编完成", 0);
	内存汇编x64(数据);
	神话公告("执行完成数据汇编", 0);
	return 读内存长整数型(进程ID, 空白地址);
}




void 测试函数(CString 信息提示)
{
	//CString str1,str2,测试文本1;
	//for (size_t i = 0; i < 线程个数; i++)
	//{		
	//	str1.Format("%ld", 线程ID[i]);
	//	测试文本1 += str1+",";
	//}

	//
	//str2.Format("%d", 线程个数);
	//MessageBoxA(自窗口句柄, str2, "线程个数", 0);
	//MessageBoxA(自窗口句柄, 测试文本1, 信息提示, 0);
}

void 清理DNF() 
{
	CString DNF;
	终止进程("dnf.exe");
	终止进程("Client.exe");
	终止进程("Tencentdl.exe");
	终止进程("TenSafe.exe");
	终止进程("TenSafe_1.exe");
	终止进程("tgp_browser.exe");
	终止进程("TP3Helper.exe");
	终止进程("TPHelper.exe");
	终止进程("GameLoader.exe");
	终止进程("TenioDL.exe");
	终止进程("tgp_gamead.exe");
	终止进程("TXPlatform.exe");
	终止进程("BackgroundDownloader.exe");
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.zip");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.zip");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.zip");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.zip");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.zip");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.zip");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.zip");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.zip");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.cmp");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
	DNF = 寻找一个文件("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\*.dmp");
	remove("C:\\Users\\Administrator\\AppData\\LocalLow\\DNF\\" + DNF);
}