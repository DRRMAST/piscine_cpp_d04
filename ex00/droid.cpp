#include "droid.hh"

Droid::Droid(std::string serial) : Id(serial), Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
  std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const& droid) : Id(droid.Id), Energy(droid.Energy), Attack(droid.Attack), Toughness(droid.Toughness), Status(new std::string(*(droid.Status)))
{
  std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}


Droid& Droid::operator=(Droid const& droid)
{
	if (this != &droid)
	{
		if (this->Status)
			delete this->Status;
		this->Status = new std::string(*(droid.Status));
		this->Energy = droid.Energy;
		this->Id = droid.Id;
	}
	return *this;
}

bool Droid::operator==(Droid const& other) const
{
	return ((Id == other.Id)
			&& (Energy == other.Energy)
			&& (Attack == other.Attack)
			&& (Toughness == other.Toughness)
			&& (*Status == *(other.Status))
			);
}

bool Droid::operator!=(Droid const& other) const
{
	return ((Id != other.getId())
			|| (Energy != other.getEnergy())
			|| (Attack != other.getAttack())
			|| (Toughness != other.Toughness)
			|| (*Status != *(other.getStatus()))
			);
}

Droid& Droid::operator<<(size_t& other)
{
	size_t required = 100 - Energy;
	if (other >= required)
    {
		Energy = 100;
		other -= required;
    }
	else
    {
		Energy += other;
		other = 0;
    }
	return *this;
}

std::ostream& operator<<(std::ostream& os, Droid const& droid)
{
	std::cout << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
	return (os);
}

Droid::~Droid()
{
	if (Status)
		delete Status;
	std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

std::string	Droid::getId() const
{
	return this->Id;
}

void Droid::setId(std::string serial)
{
	this->Id = serial;
}

size_t Droid::getEnergy() const
{
	return this->Energy;
}

void Droid::setEnergy(size_t energy)
{
	if (energy > 100)
		energy = 100;
	this->Energy = energy;
}

size_t Droid::getAttack() const
{
	return this->Attack;
}

size_t Droid::getToughness() const
{
	return this->Toughness;
}

std::string* Droid::getStatus() const
{
  return this->Status;
}

void Droid::setStatus(std::string* status)
{
	if (this->Status)
		delete this->Status;
	this->Status = status;
}
