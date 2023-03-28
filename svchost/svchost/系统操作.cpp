#include "系统操作.h"




void 改变窗口大小(int 宽度, int 高度)
{
	SetWindowPos(自窗口句柄, HWND_TOPMOST, 0, 0, 宽度, 高度, SWP_NOZORDER | SWP_NOMOVE);
}
void 改变窗口位置(int 左边, int 顶边)
{
	SetWindowPos(自窗口句柄, HWND_TOPMOST, 左边, 顶边, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
}

void 展开(HTREEITEM hTreeItem)
{
	if (!m_Dia1.m_tree.ItemHasChildren(hTreeItem))
	{
		return;
	}
	HTREEITEM hNextItem = m_Dia1.m_tree.GetChildItem(hTreeItem);
	while (hNextItem != NULL)
	{
		展开(hNextItem);
		hNextItem = m_Dia1.m_tree.GetNextItem(hNextItem, TVGN_NEXT);
	}
	m_Dia1.m_tree.Expand(hTreeItem, TVE_EXPAND);
}

void ExpandTree(HTREEITEM hTreeItem)
{
	if (!m_Dia1.m_tree.ItemHasChildren(hTreeItem))
	{
		return;
	}
	HTREEITEM hNextItem = m_Dia1.m_tree.GetChildItem(hTreeItem);
	while (hNextItem != NULL)
	{
		ExpandTree(hNextItem);
		hNextItem = m_Dia1.m_tree.GetNextItem(hNextItem, TVGN_NEXT);
	}
	HTREEITEM hchild = m_Dia1.m_tree.GetChildItem(hTreeItem);
	CString NodeData, NodeName;
	NodeName = m_Dia1.m_tree.GetItemText(hchild);
	if (NodeData.Compare(_T("2")) == 0)
	{
		return;
	}
	m_Dia1.m_tree.Expand(hTreeItem, TVE_EXPAND);
}

//折叠所有的树节点
void 折叠(HTREEITEM hTreeItem)
{
	if (!m_Dia1.m_tree.ItemHasChildren(hTreeItem))
	{
		return;
	}
	HTREEITEM hNextItem = m_Dia1.m_tree.GetChildItem(hTreeItem);
	while (hNextItem != NULL)
	{
		ExpandTree(hNextItem);
		hNextItem = m_Dia1.m_tree.GetNextItem(hNextItem, TVGN_NEXT);
	}
	m_Dia1.m_tree.Expand(hTreeItem, TVE_COLLAPSE);
}






//BOOL RunAsSystem(HANDLE hProc, TCHAR *pszPath)
//{
//    BOOL bRet;
//    HANDLE hProcToken = NULL;
//    HANDLE hDupToken = NULL;
//    DWORD dwFlag;
//    STARTUPINFO si;
//    PROCESS_INFORMATION pi;
//
//    // Open the process access token.
//    bRet = OpenProcessToken(hProc, TOKEN_DUPLICATE, &hProcToken);
//    if (!bRet)
//        goto end;
//
//    // Create a new access token that duplicates an existing token.
//    bRet = DuplicateTokenEx(hProcToken, MAXIMUM_ALLOWED, NULL,
//        SecurityImpersonation, TokenPrimary, &hDupToken);
//    if (!bRet)
//        goto end;
//
//    dwFlag = NORMAL_PRIORITY_CLASS | CREATE_NEW_CONSOLE | CREATE_UNICODE_ENVIRONMENT;
//    ZeroMemory(&si, sizeof(STARTUPINFO));
//    si.cb = sizeof(STARTUPINFO);
//    si.lpDesktop = TEXT("winsta0\\default");
//
//#ifdef _WINXP_
//    // For Windows XP.
//    bRet = ImpersonateLoggedOnUser(hDupToken);
//    if (!bRet)
//        goto end;
//
//    bRet = CreateProcessAsUser(hDupToken, pszPath, NULL, NULL, NULL, FALSE,
//        dwFlag, NULL, NULL, &si, &pi);
//
//    RevertToSelf();
//#else
//    // For Windows 7 and above.
//    bRet = CreateProcessWithTokenW(hDupToken, LOGON_NETCREDENTIALS_ONLY, NULL, (LPWSTR)pszPath,dwFlag, NULL, NULL, (LPSTARTUPINFOW)&si, &pi);
//#endif
//
//end:
//    if (bRet)
//    {
//        printf("Success!\n");
//        if (pi.hThread)
//        {
//            printf("Wait for thread exit...\n");
//            WaitForSingleObject(pi.hThread, INFINITE);
//            CloseHandle(pi.hThread);
//        }
//        if (pi.hProcess)
//        {
//            printf("Wait for process exit...\n");
//            WaitForSingleObject(pi.hProcess, INFINITE);
//            CloseHandle(pi.hProcess);
//        }
//        printf("Exit: %d\n", GetLastError());
//    }
//    else
//    {
//        printf("Error: %d\n", GetLastError());
//    }
//
//    if (hDupToken)
//        CloseHandle(hDupToken);
//    if (hProcToken)
//        CloseHandle(hProcToken);
//
//    return bRet;
//}
//
//BOOL SetOwnerAndPermissions(SE_OBJECT_TYPE objtype, HANDLE hProc, HKEY hPreKey, TCHAR *pszPath)
//{
//    BOOL bRet;
//    DWORD dwRet;
//    DWORD cbSize;
//    HANDLE hToken = NULL;
//    PTOKEN_PRIVILEGES ptp;
//    BYTE tpbyte[sizeof(TOKEN_PRIVILEGES) + sizeof(LUID_AND_ATTRIBUTES)];
//    PACL paclOld;
//    PACL paclNew = NULL;
//    PSID psidOld;
//    PSID psidNew;
//    BYTE sidbyte[SECURITY_MAX_SID_SIZE];
//    PSECURITY_DESCRIPTOR psd = NULL;
//    EXPLICIT_ACCESS ea;
//    LSTATUS ls;
//    HKEY hKey = NULL;
//    HANDLE hFile = INVALID_HANDLE_VALUE;
//    HANDLE hProcToken = NULL;
//    HANDLE hHandle;
//
//    // Open a handle to the access token for the calling process.
//    bRet = OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
//    if (!bRet)
//        goto end;
//    
//    // Enable the SeTakeOwnershipPrivilege.
//    ptp = (PTOKEN_PRIVILEGES)tpbyte;
//    bRet = LookupPrivilegeValue(NULL, SE_TAKE_OWNERSHIP_NAME, &ptp->Privileges[0].Luid);
//    if (!bRet)
//        goto end;
//
//    // Enable the SeRestorePrivilege.
//    bRet = LookupPrivilegeValue(NULL, SE_RESTORE_NAME, &ptp->Privileges[1].Luid);
//    if (!bRet)
//        goto end;
//
//    // Enable the privileges.
//    cbSize = sizeof(tpbyte);
//    ptp->PrivilegeCount = 2;
//    ptp->Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
//    ptp->Privileges[1].Attributes = SE_PRIVILEGE_ENABLED;
//    bRet = AdjustTokenPrivileges(hToken, FALSE, ptp, cbSize, NULL, NULL);
//    if (bRet)
//    {
//        if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
//        {
//            bRet = FALSE;
//            goto end;
//        }
//    }
//
//    // Create a SID for the Administrators or Users group.
//    cbSize = sizeof(sidbyte);
//    psidNew = (PSID)sidbyte;
//    bRet = CreateWellKnownSid(WinBuiltinAdministratorsSid, NULL, psidNew, &dwRet);
//    //bRet = CreateWellKnownSid(WinBuiltinUsersSid, NULL, psidNew, &cbSize);
//    if (!bRet)
//        goto end;
//    bRet = FALSE;
//
//    // Open the object with READ_CONTROL|WRITE_OWNER access.
//    if (objtype == SE_REGISTRY_KEY)
//    {
//        ls = RegOpenKeyEx(hPreKey, pszPath, 0, READ_CONTROL | WRITE_OWNER, &hKey);
//        if (ls != ERROR_SUCCESS)
//            goto end;
//        hHandle = hKey;
//    }
//    else if (objtype == SE_FILE_OBJECT)
//    {
//        hFile = CreateFile(pszPath, READ_CONTROL | WRITE_OWNER,
//            FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
//        if (hFile == INVALID_HANDLE_VALUE)
//            goto end;
//        hHandle = hFile;
//    }
//    else if (objtype == SE_KERNEL_OBJECT)
//    {
//        bRet = OpenProcessToken(hProc, READ_CONTROL | WRITE_OWNER, &hProcToken);
//        if (!bRet)
//            goto end;
//        bRet = FALSE;
//        hHandle = hProcToken;
//    }
//
//    // Get the object's original owner and permissions.
//    dwRet = GetSecurityInfo(hHandle, objtype, OWNER_SECURITY_INFORMATION |
//        DACL_SECURITY_INFORMATION, &psidOld, NULL, &paclOld, NULL, &psd);
//    if (dwRet != ERROR_SUCCESS)
//        goto end;
//
//    // Set full control for Administrators or Users group.
//    ea.grfAccessMode = SET_ACCESS;
//    ea.grfAccessPermissions = GENERIC_ALL;
//    ea.grfInheritance = NO_INHERITANCE;
//    ea.Trustee.TrusteeForm = TRUSTEE_IS_SID;
//    ea.Trustee.TrusteeType = TRUSTEE_IS_GROUP;
//    ea.Trustee.ptstrName = (LPTSTR)psidNew;
//    ea.Trustee.MultipleTrusteeOperation = NO_MULTIPLE_TRUSTEE;
//    ea.Trustee.pMultipleTrustee = NULL;
//    dwRet = SetEntriesInAcl(1, &ea, paclOld, &paclNew);
//    if (dwRet != ERROR_SUCCESS)
//        goto end;
//
//    // Set the object's owner first.
//    dwRet = SetSecurityInfo(hHandle, objtype, OWNER_SECURITY_INFORMATION,
//        psidNew, NULL, NULL, NULL);
//    if (dwRet != ERROR_SUCCESS)
//        goto end;
//
//    // Now the object have WRITE_DAC permission, reopen it.
//    if (objtype == SE_REGISTRY_KEY)
//    {
//        RegCloseKey(hKey);
//        hKey = NULL;
//        ls = RegOpenKeyEx(hPreKey, pszPath, 0,READ_CONTROL | WRITE_OWNER | WRITE_DAC, &hKey);
//        if (ls != ERROR_SUCCESS)
//            goto end;
//        hHandle = hKey;
//    }
//    else if (objtype == SE_FILE_OBJECT)
//    {
//        CloseHandle(hFile);
//        hFile = INVALID_HANDLE_VALUE;
//        hFile = CreateFile(pszPath, READ_CONTROL | WRITE_OWNER | WRITE_DAC,
//            FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
//        if (hFile == INVALID_HANDLE_VALUE)
//            goto end;
//        hHandle = hFile;
//    }
//    else if (objtype == SE_KERNEL_OBJECT)
//    {
//        CloseHandle(hProcToken);
//        hProcToken = NULL;
//        bRet = OpenProcessToken(hProc, READ_CONTROL | WRITE_OWNER | WRITE_DAC, &hProcToken);
//        if (!bRet)
//            goto end;
//        bRet = FALSE;
//        hHandle = hProcToken;
//    }
//
//    // Then set the object's permissions.
//    dwRet = SetSecurityInfo(hHandle, objtype, DACL_SECURITY_INFORMATION,
//        NULL, NULL, paclNew, NULL);
//    if (dwRet != ERROR_SUCCESS)
//        goto end;
//
//    // Now you can modify the object.
//    //printf("%ws Success!\n", pszPath);
//    //system("pause");///////////////////////////////////////////////////////////
//    RunAsSystem(hProc, pszPath);
//    
//    // Restore the object's permissions first.
//    dwRet = SetSecurityInfo(hHandle, objtype, DACL_SECURITY_INFORMATION,
//        NULL, NULL, paclOld, NULL);
//    if (dwRet != ERROR_SUCCESS)
//        goto end;
//
//    // Then restore the object's owner.
//    dwRet = SetSecurityInfo(hHandle, objtype, OWNER_SECURITY_INFORMATION,
//        psidOld, NULL, NULL, NULL);
//    if (dwRet != ERROR_SUCCESS)
//        goto end;
//
//    // Disable the privileges.
//    cbSize = sizeof(tpbyte);
//    ptp->Privileges[0].Attributes = 0;
//    ptp->Privileges[1].Attributes = 0;
//    bRet = AdjustTokenPrivileges(hToken, FALSE, ptp, cbSize, NULL, NULL);
//    if (bRet)
//    {
//        if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
//            bRet = FALSE;
//    }
//
//end:
//    if (hKey)
//        RegCloseKey(hKey);
//    if (hFile != INVALID_HANDLE_VALUE)
//        CloseHandle(hFile);
//    if (hProcToken)
//        CloseHandle(hProcToken);
//    if (paclNew)
//        LocalFree(paclNew);
//    if (psd)
//        LocalFree(psd);
//    if (hToken)
//        CloseHandle(hToken);
//    
//    printf("%ws End: %d, %d\n", pszPath, bRet, GetLastError());
//    //system("pause");
//
//    return bRet;
//}
//
//int main()
//{
//    BOOL bRet;
//    HANDLE hSnapshot = NULL;
//    PROCESSENTRY32 pe;
//    HANDLE hProc = NULL;
//
//    // Take a snapshot of all processes int the system.
//    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//    if (hSnapshot == INVALID_HANDLE_VALUE)
//        goto end;
//
//    // Get the first process and walk the snapshot of processes.
//    ZeroMemory(&pe, sizeof(PROCESSENTRY32));
//    pe.dwSize = sizeof(PROCESSENTRY32);
//    bRet = Process32First(hSnapshot, &pe);
//    while (bRet)
//    {
//        if (!lstrcmp(pe.szExeFile, TEXT("winlogon.exe")))
//            break;
//
//        bRet = Process32Next(hSnapshot, &pe);
//    }
//    if (!bRet)
//        goto end;
//
//    // Open the process with process id.
//    hProc = OpenProcess(MAXIMUM_ALLOWED, FALSE, pe.th32ProcessID);
//    if (!hProc)
//        goto end;
//
//#ifdef _WINXP_
//    // For Windows XP.
//    bRet = SetOwnerAndPermissions(SE_KERNEL_OBJECT, hProc, NULL,
//        TEXT("c:\\windows\\system32\\cmd.exe"));
//#else
//    // For Windows 7 and above.
//    bRet = RunAsSystem(hProc, TEXT("c:\\windows\\system32\\cmd.exe"));
//#endif
//
//end:
//    if (hProc)
//        CloseHandle(hProc);
//    if (hSnapshot)
//        CloseHandle(hSnapshot);
//
//    system("pause");
//
//    return 0;
//}






