#pragma once
#include "windows.h"

void 缓冲Call(int 缓冲参数);
void 加密Call(INT64 加密参数, int 加密长度);
void 发包Call();

void 技能Call(INT64 触发指针, int 代码, INT64 伤害, int x, int y, int z, int 大小);
void 释放call(INT64 触发指针, INT64 代码, INT64 伤害, INT64 X轴, INT64 Y轴, INT64 Z轴);
//ULONG CALL_取坐标CALL(INT64 参_指针, DWORD 参_方向);
void 坐标call(INT64 X, INT64 Y, INT64 Z);
//void 跳过Call();
void 任务接受Call(int 参_任务);
void 任务完成Call(int 参_任务);
void 任务提交Call(int 参_任务);
void 物品Call(int 物品代码);
void 组包_城镇移动(int 大区域, int 小区域, int x, int y);
void 组包_拾取(int 对象编号);
void 组包_通关翻牌();
void 组包_领取翻牌();
void 组包_强制回城();
void 组包_过图(int x, int y);
void 组包_分解(int 装备位置);
void 组包_卖物(int 位置, int 数量);
void 组包秒杀(unsigned short 服务器ID);
void 组包_选图();
void 组包_进图(int 地图代码, int 地图难度, int 深渊投递, int 任务编号, int 星空深渊);
void 组包_退出角色();
void 组包_选择角色(int 角色位置);
void 组包_整理背包();
void 组包_修仙死亡(unsigned short 服务器ID);
void 组包_存金币(int 数量);
void 组包_存金库(int 材料位置, int 物品代码, int 材料数量, int 金库位置);
void 换装call(INT64 穿戴指针, INT64 装备代码, int 装备部位);
void 加密(INT64 地址1, INT32 数值);
int 解密(INT64 address);
void 满血满蓝();
void 卖修();
void 透明call(INT64 对象指针);
void 超级评分();
void 全屏捡物();
void 吸怪();
void 坐标过图(int 顺图方向);
void 漂移call(INT64 指针, INT32 横轴, INT32 纵轴, INT32 竖轴, INT32 速度 );
void 管理权限();
void 系统公告(wstring 公告内容);
void 普通公告(wstring 公告内容);
void 神话公告(CString 内容, int 类型);
void 三速负重耐久();
void 队友消失();
INT32 取角色等级();
坐标型 读坐标(INT64 对象指针);
void 透明无敌();
void 无视等级();
void 顺图_左();
void 顺图_上();
void 顺图_右();
void 顺图_下();
vector<byte> PASS动态(int val, int n);
void 内存汇编x64(vector<byte>asm_code);
void 改药();
INT64 获取物品数据call(INT64 物品代码);
void 测试函数(CString 信息提示);
void 清理DNF();
void 物品buff();
vector<byte> Sub_Rsp(int i);
vector<byte> Call(INT64 地址);
vector<byte> Add_Rsp(int i);