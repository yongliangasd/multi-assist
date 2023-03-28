/***************************************************************************************
* AUTHOR : ã¶Í·Çà
* DATE   : 2019-11-30
****************************************************************************************/

#pragma once 

//#######################################################################################
// D E F I N E S
//#######################################################################################
#define MyDbg 0
#if MyDbg

#define dprintf DbgPrint
#else

#define dprintf
#endif


#define NT_DEVICE_NAME               L"\\Device\\Ltq"                // Driver Name
#define SYMBOLIC_LINK_NAME           L"\\DosDevices\\LtqDriver"            // Symbolic Link Name

//
// Device IO Control Codes
//
#define IOCTL_BASE          0x800
#define MY_CTL_CODE(i)        \
    CTL_CODE                  \
    (                         \
        FILE_DEVICE_UNKNOWN,  \
        IOCTL_BASE + i,       \
        METHOD_BUFFERED,      \
        FILE_ANY_ACCESS       \
    )

#define IOCTL_LTQ_Read          MY_CTL_CODE(3)
#define IOCTL_LTQ_Write         MY_CTL_CODE(4)
#define IOCTL_LTQ_GetModule     MY_CTL_CODE(5)
#define IOCTL_LTQ_Init_Check    MY_CTL_CODE(6)
#define IOCTL_LTQ_AllocMen    MY_CTL_CODE(7)
