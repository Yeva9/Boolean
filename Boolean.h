#pragma <once> 
#include <iostream>
using namespace std;

class  Boolean
{
	friend ostream& operator<<(ostream&, const Boolean&);
	friend istream& operator>>(istream&, Boolean&);

public:
	Boolean(int);
	Boolean(int, const bool*);
	Boolean(const Boolean&);
	~Boolean();

	int get_size() const { return m_size; }
	bool is_empty() const { return m_size == 0; }
	//void Print() const;

	Boolean& operator=(const Boolean&);
	bool operator==(const Boolean&) const;
	bool& operator[](int);
	const bool& operator[](int) const;
	Boolean& operator<<=(int);
	Boolean& operator>>=(int);
	Boolean& operator^=(const Boolean&);
	Boolean& operator|=(const Boolean&);
	Boolean& operator&=(const Boolean&);
	Boolean& operator~();

private:
	int m_size;
	bool * m_array;
};

bool operator!=(const Boolean&, const Boolean&);
Boolean operator<<(Boolean, int );
Boolean operator>>(Boolean, int );
Boolean operator^(Boolean, const Boolean&);
Boolean operator|(Boolean, const Boolean&);
Boolean operator&(Boolean, const Boolean&);
