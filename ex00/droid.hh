#ifndef DROID_HH
#define DROID_HH
#include <iostream>

class Droid
{
	public:
		Droid(std::string serial = "");
		Droid(Droid const& droid);
		Droid& operator = (Droid const& droid);
		bool operator == (Droid const& other) const;
		bool operator != (Droid const& other) const;
		Droid& operator<<(size_t& other);
		~Droid();
		
		std::string getId() const;
		size_t getEnergy() const;
		size_t getAttack() const;
		size_t getToughness() const;
		std::string *getStatus() const;
		
		void setId(std::string id);
		void setEnergy(size_t energy);
		void setStatus(std::string *status);
		
	private:
		std::string Id;
		size_t Energy;
		size_t const Attack;
		size_t const Toughness;
		std::string * Status;
};

std::ostream& operator<<(std::ostream& os, Droid const& droid);
#endif
