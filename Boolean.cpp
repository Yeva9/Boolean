#include "Boolean.h"

Boolean::Boolean(int n)
    : m_size(n)
{
	m_array = new bool[m_size];
	for (int i = 0; i < m_size; ++i)
		m_array[i] = 0;
}

Boolean::Boolean(int n, const bool* B)
	:m_size(n)
{
	m_array = new bool[m_size];
	for (int i = 0; i < m_size; ++i)
		m_array[i] = B[i];
}

Boolean::Boolean(const Boolean& B)
	:m_size(B.m_size)
{
	m_array = new bool[m_size];

	for (int i = 0; i<m_size; ++i)
		m_array[i] = B.m_array[i];
}

Boolean::~Boolean()
{
	delete[] m_array;
}

/*void Boolean::Print() const
{
	for (int i = 0; i<m_size; ++i)
		cout << m_array[i] << ' ';
}*/

Boolean& Boolean::operator=(const Boolean& B)
{
	if (&B != this)
	{
		delete[] m_array;
		m_size = B.m_size;
		m_array = new bool[m_size];
		for (int i = 0; i<m_size; ++i)
			m_array[i] = B.m_array[i];
	}
	return *this;
}

bool Boolean::operator==(const Boolean& B) const
{
	if (m_size != B.m_size) return false;
	for (int i = 0; i< m_size; ++i)
		if (m_array[i] != B.m_array[i]) return false;

	return true;
}

bool operator!=(const Boolean& B1, const Boolean& B2)
{
	return !(B1 == B2);
}

Boolean& Boolean::operator<<=(int j)
{
	if(j <= m_size)
	{
		int i = 0;
		for(; i< m_size - j; ++i)
			m_array[i] = m_array[i + j];
		for(; i < m_size; ++i)
			m_array[i] = false;
	}
	return *this;
}

Boolean& Boolean::operator>>=(int j)
{
    if(j <= m_size)
    { 
        Boolean B =  *this;
        int i = 0;
        for(; i<= m_size-j; ++i)
        m_array[i] = 0;
        
        for(int k = 0; k<j; ++k, ++i)
        m_array[i] = B.m_array[k];
    }
	return *this;
}

Boolean operator<<(Boolean B1, int j)
{
	return B1 <<= j;
}

Boolean operator>>(Boolean B1, int j)
{
	return B1 >>= j;
}

Boolean& Boolean::operator^=(const Boolean& B)
{
	if (m_size == B.m_size)
	{
		for (int i = 0; i< m_size; ++i)
			m_array[i] = (m_array[i] != B.m_array[i]);
	}
	return *this;
}

Boolean& Boolean:: operator|=(const Boolean& B)
{
	if (m_size == B.m_size)
	{
		for (int i = 0; i< m_size; ++i)
			m_array[i] = m_array[i] || B.m_array[i];
	}
	return *this;
}

Boolean& Boolean:: operator&=(const Boolean& B)
{
	if (m_size == B.m_size)
	{
		for (int i = 0; i< m_size; ++i)
			m_array[i] = m_array[i] && B.m_array[i];
	}
	return *this;
}

Boolean operator^(Boolean B1, const Boolean& B2)
{
	return B1 ^= B2;
}

Boolean operator|(Boolean B1, const Boolean& B2)
{
	return B1 |= B2;
}

Boolean operator&(Boolean B1, const Boolean& B2)
{
	return B1 &= B2;
}

Boolean& Boolean::operator~()
{
	for (int i = 0; i< m_size; ++i)
		if(m_array[i]) m_array[i] = false;
		else
		m_array[i] = true;

	return *this;
}

bool& Boolean::operator[](int i)
{
	return m_array[i];
}

const bool& Boolean::operator[](int i) const
{
	return m_array[i];
}

ostream& operator<<(ostream& out, const Boolean& B)
{
	for (int i = 0; i< B.m_size; ++i)
		out << B.m_array[i] << ' ';
	return out;
}

istream& operator>>(istream& in, Boolean& B)
{
	for (int i = 0; i< B.m_size; ++i)
		in >> B.m_array[i];
	return in;
}

int main()
{
	bool A[5] = { false, true, true,true,false };
	Boolean B(5,A);
	cout<<B<<endl;
	B>>=3;
	cout<<B;

	return 0;
}
