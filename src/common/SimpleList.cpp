#include "precompiled.h"

bool CSimpleList::AddString(const char *item)
{
	if (!item || !*item)
		return false;

	if (m_Size >= _countof(m_List))
		return false;

	m_List[m_Size] = item;
	m_Size++;

	return true;
}

const char *CSimpleList::PickRandomString()
{
	if (m_Size == 0)
		return nullptr;

	int index = rand() % m_Size;
	return m_List[index];
}