#ifndef ALL_CLASSES
#define ALL_CLASSES

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal
{
protected://so that it will not be possible to create Animal type
	Animal();//set the default color to GRAY and other params to 0
	Animal(const char* color, int childs, float avgLifetime);//init the Animal with a given attributes
	Animal(ifstream& in_file);//init the Animal from a binary file
	Animal(const Animal& other);

public:
	virtual ~Animal();

public:
	const char* GetColor() const { return m_color; }//return the color of the animal
	int			GetChildCount() const { return m_childCount; }//return the child count of the animal
	float		GetLifetime() const { return m_avgLifetime; }//return the life time of the animal

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file
	void SaveType(ofstream& out_file) const;//saves the type to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file
	void SaveTypeBin(ofstream& out_file) const;//saves the type to a binary file

public:
	char* GetTypeName() const;

protected:
	char* m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

class Mammals :virtual public Animal
{
public:
	Mammals();//set the default color to GRAY and other params to 0
	Mammals(const char* color, int childs, float avgLifetime, float preg, float milk);//init the Mammals with a given attributes
	Mammals(ifstream& in_file);//init the Mammals from a binary file
	Mammals(const Mammals& other);
	virtual ~Mammals();

public:
	float		GetPregnanceTime() const { return m_pregnancyTime; }//return the pregnance time of the animal
	float		GetMilk() const { return m_milkLiters; }//return the milk liters of the animal

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file

protected:
	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;
	virtual void saveBin(ofstream& out_file) const;

protected:
	float m_pregnancyTime;
	float m_milkLiters;
};

class Birds : virtual public Animal
{
public:
	Birds();//set the default color to GRAY and other params to 0
	Birds(const char* color, int childs, float avgLifetime, float incubation);//init the Birds with a given attributes
	Birds(ifstream& in_file);//init the Birds from a binary file
	Birds(const Birds& other);
	virtual ~Birds();

public:
	float		GetIncubationTime() const { return m_incubationTime; }//return the incubation time of the animal

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file

protected:
	float m_incubationTime;
};

class Fish :virtual public Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish(const char* color, int childs, float avgLifetime, int fin, int gills);//init the Fish with a given attributes
	Fish(ifstream& in_file);//init the Fish from a binary file
	Fish(const Fish& other);
	virtual ~Fish();

public:
	int		GetFinCount() const { return m_finCount; }//return the fin count of the animal
	int		GetGillsCount() const { return m_gillsCount; }//return the gills count of the animal

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file

protected:
	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;
	virtual void saveBin(ofstream& out_file) const;

protected:
	int m_finCount;
	int m_gillsCount;
};

class Horse : public Mammals
{
public:
	Horse();//set the default color to GRAY and other params to 0
	Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type);//init the Horse with a given attributes
	Horse(ifstream& in_file);//init the Horse from a binary file
	Horse(const Horse& other);
	virtual ~Horse();

public:
	const char* GetType() const { return m_type; }//return the type of the horse

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file

protected:
	char* m_type;
};

class Flamingo : public Birds
{
public:
	Flamingo();//set the default color to GRAY and other params to 0
	Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight);//init the Flamingo with a given attributes
	Flamingo(ifstream& in_file);//init the Flamingo from a binary file
	Flamingo(const Flamingo& other);
	virtual ~Flamingo();

public:
	float		GetHeight() const { return m_avgHeight; }//return the avg height of the flamingo

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file

protected:
	float m_avgHeight;
};

class MammalsFish : public Mammals, public Fish
{
public:
	MammalsFish();//set the default color to GRAY and other params to 0
	MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills);//init the MammalsFish with a given attributes
	MammalsFish(ifstream& in_file);//init the MammalsFish from a binary file
	MammalsFish(const MammalsFish& other);
	virtual ~MammalsFish();

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file

protected:
	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;
	virtual void saveBin(ofstream& out_file) const;
};

class GoldFish : public MammalsFish
{
public:
	GoldFish();//set the default color to GRAY and other params to 0
	GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL);//init the GoldFish with a given attributes
	GoldFish(ifstream& in_file);//init the GoldFish from a binary file
	GoldFish(const GoldFish& other);
	virtual ~GoldFish();

public:
	float		GetWeight() const { return m_avgWeight; }//return the avg weight of the gold fish
	float		GetLength() const { return m_avgLength; }//return the avg length of the gold fish

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file

protected:
	float m_avgWeight;
	float m_avgLength;
};

class Mermaid : public MammalsFish
{
public:
	Mermaid();//set the default color to GRAY and other params to 0
	Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName);//init the Mermaid with a given attributes
	Mermaid(ifstream& in_file);//init the Mermaid from a binary file
	Mermaid(const Mermaid& other);
	virtual ~Mermaid();

public:
	const char* GetFirstName() const { return m_firstName; }//return the first name of the mermaid
	const char* GetLastName() const { return m_lastName; }//return the last name of the mermaid

public:
	virtual void Load(ifstream& in_file);//load the data from a text file
	virtual void Save(ofstream& out_file) const;//saves the data to a text file

public:
	virtual void SaveBin(ofstream& out_file) const;//saves the data to a binary file

protected:
	char* m_firstName;
	char* m_lastName;
};

class Zoo
{
public:
	Zoo();//default c'tor  - all to 0 or null
	Zoo(const char* name, const char* address, float ticket, const char* open, const char* close);//c'tor with data - init class
	Zoo(ifstream& in_file);//c'tor that gets a binary file and loads the data of the zoo from the file
	Zoo(const Zoo& other);//copy c'tor that loads the data from the other (deep way)
	virtual ~Zoo();//d'tor

public:
	const char* GetName() const { return m_name; }//return the name of the zoo
	const char* GetAddress() const { return m_address; }//return the address of the zoo
	float			GetTicketPrice() const { return m_ticketPrice; }//return the ticket price of the zoo
	const char* GetOpenHour() const { return m_openHours; }//return the open hour of the zoo
	const char* GetCloseHour() const { return m_closeHours; }//return the close hour of the zoo
	int				GetNumOfAnimals() const { return m_numOfAnimals; }//return the num of animals in the zoo
	Animal** GetAnimals() const { return m_animals; }//return the animals array of the zoo

public:
	void AddAnimal(Animal* an);//creates a copy of "an" (deep copy) and adds an animal to the array

public:
	Zoo& operator+(Animal* an);//adds an animal (only pointer, no copy needed) to the class and returns this with the change
	Zoo operator+(const Zoo& other) const; //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
	Zoo& operator=(const Zoo& other);//operator = that copies the data from other to this and returns this
	Zoo& operator+=(Animal* an);//adds an animal (only pointer, no copy needed) to the class and returns this with the change

public:
	friend ofstream& operator<<(ofstream& out, const Zoo& z);//operator to write the zoo to a text file
	friend ifstream& operator>>(ifstream& in, Zoo& z);//operator to read the zoo from a text file

public:
	void Save(ofstream& ofs) const;//method to save the info to a text file
	void Load(ifstream& ifs);//method to load the info from a text file
	void SaveBin(ofstream& ofs) const;//method to save the info to a binary file

private:
	Animal* createAnimalBin(ifstream& in_file);
	Animal* createAnimalTxt(ifstream& in_file);

private:
	char* m_name;
	char* m_address;
	float		m_ticketPrice;
	char* m_openHours;
	char* m_closeHours;
	int			m_numOfAnimals;
	Animal** m_animals;
};

ofstream& operator<<( ofstream& out, const Zoo& z );
ifstream& operator>>( ifstream& in, Zoo& z );
char* readTextFromFile(ifstream& in_file);
char* fixTypeName(char* name);

#endif // ifndef