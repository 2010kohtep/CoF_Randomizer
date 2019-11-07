#pragma once

class CSimpleList
{
protected:
	int m_Size;
	const char *m_List[64];

	bool AddString(const char *item);

public:
	CSimpleList()
	{
		m_Size = 0;
		memset(m_List, 0, sizeof(m_List));
	}

	const char *PickRandomString();
};