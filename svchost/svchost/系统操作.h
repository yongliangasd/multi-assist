#pragma once
#include "pch.h"
#include "framework.h"
#include "svchost.h"
#include "svchostDlg.h"
#include "afxdialogex.h"
#include "全局变量.h"


void 折叠(HTREEITEM hTreeItem);
void ExpandTree(HTREEITEM hTreeItem);
void 展开(HTREEITEM hTreeItem);
void 改变窗口位置(int 左边, int 顶边);
void 改变窗口大小(int 宽度, int 高度);
