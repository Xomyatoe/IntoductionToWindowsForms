#include<Windows.h>
#include "resource.h"

//��������� ����:
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//hInstance - ��������� ����������� *.exe-����� ����� ���������
	//hPrevInst - �� ������������
	//LPSTR - Long Pointer To String
	//lpCmdLine - CommandLine (��������� ������ � ����������� ������� ����������)
	//nCmdShow  - ����� ����������� ���� (���������� �� ���� �����, c������� �� ������ ����� � �.�.)
	//��������: n..., lp... ��� ���������� �������
	//			n - Number
	//			lp - Long Pointer
	//			h - HINSTANCE

	/*MessageBox
	(
		NULL,
		"Hello Windows!\nThis is MessageBox()",
		"Window title",
		MB_CANCELTRYCONTINUE | MB_HELP | MB_DEFBUTTON3 |
		MB_ICONINFORMATION |
		MB_SERVICE_NOTIFICATION |
		MB_RIGHT
	);*/

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)DlgProc, 0);

	return 0;
}

//��������� ����:
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//hwnd - Handler to Window. ���������� ��� ���������� ���� - ��� �����, ��� ������ �������� ����� ���������� � ����.
	//uMsg - Message. ���������, ������� ������������ ����.
	//wParam, lParam - ��� ��������� ���������, � ������� ��������� ���� ����� ����������.
	//LOWORD - ������� �����;
	//HIWORD - ������� �����;
	//DWORD  - Double Word;

	switch (uMsg)
	{
	case WM_INITDIALOG:	//��� ��������� ������������ 1 ��� ��� ������������� ����
		break;
	case WM_COMMAND:	//������������ ������� ������ � ������ �������� ������������
		//ResourceID
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_COPY:
		{
			//1) ������� �����:
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};	//sz_ - String Zero (NULL Terminated Line - C-string)

			//2) �������� ����������� ��������� �����:
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);

			//3) ��������� ���������� ���� 'Login' � �����:
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);

			//4) ���������� ���������� ����� � ��������� ���� 'Password':
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
		break;
		case IDOK:		MessageBox(hwnd, "���� ������ ������ OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:	EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:		//������������ ��� ������� ������ '�������' X
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}