#ifndef DROIDMEMORY_HH
#define DROIDMEMORY_HH

#include <iostream>

class	DroidMemory
{
public:
  DroidMemory();
  DroidMemory&	operator<<(DroidMemory const& other);
  DroidMemory const&	operator>>(DroidMemory& other);
  DroidMemory& operator+=(DroidMemory const& other);
  DroidMemory& operator+=(size_t const other);
  DroidMemory 	operator+(DroidMemory const& other) const;
  DroidMemory	operator+(size_t const other) const;
  ~DroidMemory();
  
  size_t	getFingerPrint() const;
  void		setFingerPrint(size_t fingerPrints);

  size_t	getExp() const;
  void		setExp(size_t exp);
  
private:

  size_t	_fingerPrints;
  size_t	_exp;
  
};

std::ostream& operator<<(std::ostream& os, DroidMemory const& droid);

#endif
