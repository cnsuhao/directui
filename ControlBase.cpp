#include "StdAfx.h"
#include <mmsystem.h> 
#include "ControlBase.h"

#pragma comment(lib,"Winmm.lib")  

CControlBase::CControlBase(HWND hWnd, UINT uControlID, CRect rc, CString strTitle, BOOL bIsVisible, BOOL bIsDisable,
						   BOOL bRresponse)
{
	m_hWnd = hWnd;
	m_uID = uControlID;
	m_rc = rc;
	m_bIsVisible = bIsVisible;
	m_bIsDisable = bIsDisable;
	m_bRresponse = bRresponse;
	m_strTitle = strTitle;

	VERIFY(m_font.CreateFont(
		12,							// ����ĸ߶�  
		0,							// ����Ŀ��  
		0,							// ������ʾ�ĽǶ�
		0,							// ����ĽǶ�
		FW_DONTCARE,				// ����İ���
		FALSE,						// б������
		FALSE,						// ���»��ߵ�����
		0,							// ��ɾ���ߵ�����
		GB2312_CHARSET,				// ������ַ���
		OUT_DEFAULT_PRECIS,			// ����ľ���
		CLIP_DEFAULT_PRECIS,		// �ü��ľ���
		DEFAULT_QUALITY,			// �߼�����������豸��ʵ��
		DEFAULT_PITCH | FF_SWISS,	// ����������弯
		"����"));					// ��������

}


CControlBase::~CControlBase(void)
{
	if (m_font.m_hObject)
	{
		m_font.DeleteObject();
	}
}

void CControlBase::SetTitle(CString strTitle) 
{
	if(strTitle != m_strTitle)
	{
		m_strTitle = strTitle;
		::InvalidateRect(m_hWnd, &m_rc, true);
	}
};

// ����֪ͨ��Ϣ
bool  CControlBase::SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return ::SendMessage(m_hWnd, Msg, wParam, lParam);
}