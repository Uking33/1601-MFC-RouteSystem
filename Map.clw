; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWayDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Map.h"

ClassCount=12
Class1=CMapApp
Class2=CMapDlg
Class3=CAboutDlg

ResourceCount=12
Resource1=IDD_FIND_CAR_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Resource4=IDD_MAP_DIALOG1
Class4=FindSheet
Class5=CCarDlg
Resource5=IDD_EDIT_ONE_DIALOG
Class6=CStateDlg
Resource6=IDD_EDIT_PASSWORD
Class7=CWayDlg
Class8=CLoadingDlg
Resource7=IDD_EDIT_CAR_DIALOG
Resource8=IDD_FIND_STATE_DIALOG
Class9=CEditDlg
Resource9=IDD_MAP_DIALOG
Class10=CEditOneDlg
Resource10=IDD_ABOUTBOX
Class11=CEditStateDlg
Resource11=IDD_FIND_WAY_DIALOG
Class12=CPasswordDlg
Resource12=IDD_EDIT_STATE_DIALOG

[CLS:CMapApp]
Type=0
HeaderFile=Map.h
ImplementationFile=Map.cpp
Filter=N
LastObject=CMapApp

[CLS:CMapDlg]
Type=0
HeaderFile=MapDlg.h
ImplementationFile=MapDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BTN_EDIT

[CLS:CAboutDlg]
Type=0
HeaderFile=MapDlg.h
ImplementationFile=MapDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG1]
Type=1
Class=CEditStateDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:FindSheet]
Type=0
HeaderFile=FindSheet.h
ImplementationFile=FindSheet.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=FindSheet

[DLG:IDD_FIND_CAR_DIALOG]
Type=1
Class=CCarDlg
ControlCount=4
Control1=IDC_LIST1,SysListView32,1350631433
Control2=IDC_BTN_LAST,button,1342275585
Control3=IDC_BTN_NEXT,button,1342275585
Control4=IDCANCEL,button,1342275585

[CLS:CCarDlg]
Type=0
HeaderFile=CarDlg.h
ImplementationFile=CarDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CStateDlg]
Type=0
HeaderFile=StateDlg.h
ImplementationFile=StateDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST1

[DLG:IDD_FIND_STATE_DIALOG]
Type=1
Class=CStateDlg
ControlCount=4
Control1=IDC_LIST1,SysListView32,1350631433
Control2=IDC_BTN_LAST,button,1342275585
Control3=IDC_BTN_NEXT,button,1342275585
Control4=IDCANCEL,button,1342275585

[DLG:IDD_FIND_WAY_DIALOG]
Type=1
Class=CWayDlg
ControlCount=16
Control1=IDC_RADIO1,button,1342341129
Control2=IDC_RADIO2,button,1342210057
Control3=IDC_RADIO3,button,1342210057
Control4=IDC_RADIO4,button,1342341129
Control5=IDC_RADIO5,button,1342210057
Control6=IDC_RADIO6,button,1342210057
Control7=IDC_LIST1,SysListView32,1342243341
Control8=IDC_BTN_LAST,button,1342275585
Control9=IDCANCEL,button,1342275585
Control10=IDC_BTN_NEXT,button,1342275585
Control11=IDC_BTN_FIND,button,1342275585
Control12=IDC_COMBO_START,combobox,1344339969
Control13=IDC_STATIC,static,1342312961
Control14=IDC_COMBO_END,combobox,1344339969
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,button,1342177287

[CLS:CWayDlg]
Type=0
HeaderFile=WayDlg.h
ImplementationFile=WayDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO4
VirtualFilter=dWC

[CLS:CLoadingDlg]
Type=0
HeaderFile=LoadingDlg.h
ImplementationFile=LoadingDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoadingDlg

[DLG:IDD_MAP_DIALOG1]
Type=1
Class=CMapDlg
ControlCount=5
Control1=IDC_BTN_FINDCAR,button,1342275585
Control2=IDC_BTN_FINDCARSTATE,button,1342275585
Control3=IDC_BTN_FIND_WAY,button,1342275585
Control4=IDCANCEL2,button,1342275585
Control5=IDCANCEL,button,1342275585

[DLG:IDD_MAP_DIALOG]
Type=1
Class=CMapDlg
ControlCount=5
Control1=IDC_BTN_FINDCAR,button,1342275585
Control2=IDC_BTN_FINDCARSTATE,button,1342275585
Control3=IDC_BTN_FIND_WAY,button,1342275585
Control4=IDC_BTN_EDIT,button,1342275585
Control5=IDCANCEL,button,1342275585

[DLG:IDD_EDIT_CAR_DIALOG]
Type=1
Class=CEditDlg
ControlCount=8
Control1=IDC_LIST1,SysListView32,1350631433
Control2=IDC_BTN_LAST,button,1342275585
Control3=IDC_BTN_NEXT,button,1342275585
Control4=IDC_BTN_EDIT,button,1342275585
Control5=IDCANCEL,button,1342275585
Control6=IDC_BTN_PASSWORD,button,1342275585
Control7=IDC_BTN_DEL,button,1342275585
Control8=IDC_BTN_ADD,button,1342275585

[CLS:CEditDlg]
Type=0
HeaderFile=EditDlg.h
ImplementationFile=EditDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CEditOneDlg]
Type=0
HeaderFile=EditOneDlg.h
ImplementationFile=EditOneDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEditOneDlg

[CLS:CEditStateDlg]
Type=0
HeaderFile=EditStateDlg.h
ImplementationFile=EditStateDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_EDIT_ONE_DIALOG]
Type=1
Class=CEditOneDlg
ControlCount=20
Control1=IDC_LIST1,SysListView32,1350631433
Control2=IDC_BTN_EDIT,button,1342275585
Control3=IDCANCEL,button,1342275585
Control4=IDC_BTN_DEL,button,1342275585
Control5=IDC_BTN_ADD,button,1342275585
Control6=IDC_EDIT_NAME,edit,1350631553
Control7=IDC_STATIC,static,1342308865
Control8=IDC_EDIT_COST,edit,1350631553
Control9=IDC_STATIC,static,1342308865
Control10=IDC_STATIC,static,1342308865
Control11=IDC_STATIC,static,1342308865
Control12=IDC_COMBO_TYPE,combobox,1344339970
Control13=IDC_COMBO_TWOWAY,combobox,1344339970
Control14=IDC_STATIC,static,1342308865
Control15=IDC_STATIC,static,1342308865
Control16=IDC_STATIC,static,1342308865
Control17=IDC_STATIC,static,1342308865
Control18=IDC_EDIT_START,edit,1350631553
Control19=IDC_EDIT_END,edit,1350631553
Control20=IDOK,button,1342275585

[DLG:IDD_EDIT_STATE_DIALOG]
Type=1
Class=CPasswordDlg
ControlCount=10
Control1=IDCANCEL,button,1342275585
Control2=IDC_EDIT_NAME,edit,1350631553
Control3=IDC_STATIC,static,1342308865
Control4=IDC_EDIT_DISTANCE,edit,1350631553
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308865
Control8=IDOK,button,1342275585
Control9=IDC_EDIT_TIME,edit,1350631553
Control10=IDC_STATIC,static,1342308865

[DLG:IDD_EDIT_PASSWORD]
Type=1
Class=CEditOneDlg
ControlCount=4
Control1=IDCANCEL,button,1342275585
Control2=IDC_EDIT_PASSWORD,edit,1350631585
Control3=IDOK,button,1342275585
Control4=IDC_TEXT,static,1342308865

[CLS:CPasswordDlg]
Type=0
HeaderFile=PasswordDlg.h
ImplementationFile=PasswordDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPasswordDlg

