#include "pch.h"
#include "ȫ�ֱ���.h"




BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		//MessageBoxA(0, "�ٳֳɹ�!", "DNF", 0);
		// save critical data pointers before running the constructors
		AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
		pModuleState->m_pClassInit = pModuleState->m_classList;
		pModuleState->m_pFactoryInit = pModuleState->m_factoryList;
		pModuleState->m_classList.m_pHead = NULL;
		pModuleState->m_factoryList.m_pHead = NULL;
	}
	/*else 
	{
		MessageBoxA(0,"�ٳ�ʧ��!","DNF",0);
	}*/
	return TRUE;  // ok
}






