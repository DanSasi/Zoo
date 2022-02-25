# include "allClasses.h"

using namespace std;

/*****************************Animals******************************/

Animal::Animal()//set the default color to GRAY and other params to 0
: m_childCount(0), m_avgLifetime(0.f)
{
	this->m_color = strdup("GRAY");
}
Animal::Animal(const char* color, int childs, float avgLifetime)//init the Animal with a given attributes
: m_childCount(childs), m_avgLifetime(avgLifetime)
{
	this->m_color = strdup(color);
}
Animal::Animal(ifstream& in_file)//init the Animal from a binary file
{
	char c;//to read the '\n' that we wrote
	m_color = readTextFromFile(in_file);
	in_file.read((char*)&m_childCount, sizeof(m_childCount));
	in_file.read(&c, 1);
	in_file.read((char*)&m_avgLifetime, sizeof(m_avgLifetime));
	in_file.read(&c, 1);
}
Animal::Animal(const Animal& other)
{
	this->m_color = strdup(other.m_color);
	this->m_childCount = other.m_childCount;
	this->m_avgLifetime = other.m_avgLifetime;
}
Animal::~Animal()
{
	if (m_color)
		delete m_color;

	m_color = NULL;
}

void Animal::Load(ifstream& in_file)//load the data from a text file
{
	m_color = readTextFromFile(in_file);
	in_file >> m_childCount;
	in_file >> m_avgLifetime;
}
void Animal::Save(ofstream& out_file) const//saves the data to a text file
{
	SaveType(out_file);
	out_file << m_color << endl;
	out_file << m_childCount << endl;
	out_file << m_avgLifetime << endl;
}
void Animal::SaveType(ofstream& out_file) const//saves the type to a text file
{
	out_file << GetTypeName() << endl;
}
void Animal::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	SaveTypeBin(out_file);
	out_file.write(m_color, strlen(m_color));
	out_file.write("\n", 1);
	out_file.write((char*)&m_childCount, sizeof(m_childCount));
	out_file.write("\n", 1);
	out_file.write((char*)&m_avgLifetime, sizeof(m_avgLifetime));
	out_file.write("\n", 1);
}
void Animal::SaveTypeBin(ofstream& out_file) const//saves the type to a binary file
{
	char type[20] = { 0 };
	strcpy(type, GetTypeName());
	out_file.write((const char*)type, strlen(type));
	out_file.write("\n", 1);
}
char* Animal::GetTypeName() const
{
	return fixTypeName((char*)typeid(*this).name());
}

/*****************************Mammals******************************/

Mammals::Mammals()//set the default color to GRAY and other params to 0
: Animal(),
m_pregnancyTime(0.f), m_milkLiters(0.f)
{}
Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk)//init the Mammals with a given attributes
: Animal(color, childs, avgLifetime),
m_pregnancyTime(preg), m_milkLiters(milk)
{}
Mammals::Mammals(ifstream& in_file)//init the Mammals from a binary file
	: Animal(in_file)
{
	char c;//to read the '\n' that we wrote
	in_file.read((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
	in_file.read(&c, 1);
	in_file.read((char*)&m_milkLiters, sizeof(m_milkLiters));
	in_file.read(&c, 1);
}
Mammals::Mammals(const Mammals& other)
	: Animal(other)
{
	this->m_pregnancyTime = other.m_pregnancyTime;
	this->m_milkLiters = other.m_milkLiters;
}
Mammals::~Mammals()
{}

void Mammals::Load(ifstream& in_file)//load the data from a text file
{
	Animal::Load(in_file);
	load(in_file);
}
void Mammals::Save(ofstream& out_file) const//saves the data to a text file
{
	Animal::Save(out_file);
	save(out_file);
}
void Mammals::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	Animal::SaveBin(out_file);
	saveBin(out_file);
}
void Mammals::load(ifstream& in_file)
{
	in_file >> m_pregnancyTime;
	in_file >> m_milkLiters;
}
void Mammals::save(ofstream& out_file) const
{
	out_file << m_pregnancyTime << endl;
	out_file << m_milkLiters << endl;
}
void Mammals::saveBin(ofstream& out_file) const
{
	out_file.write((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
	out_file.write("\n", 1);
	out_file.write((char*)&m_milkLiters, sizeof(m_milkLiters));
	out_file.write("\n", 1);
}

/******************************Birds*****************************/

Birds::Birds()//set the default color to GRAY and other params to 0
	: Animal(),
	m_incubationTime(0.f)
{}
Birds::Birds(const char* color, int childs, float avgLifetime, float incubation)//init the Birds with a given attributes
	: Animal(color, childs, avgLifetime),
	m_incubationTime(incubation)
{}
Birds::Birds(ifstream& in_file)//init the Birds from a binary file
	: Animal(in_file)
{
	char c;//to read the '\n' that we wrote
	in_file.read((char*)&m_incubationTime, sizeof(m_incubationTime));
	in_file.read(&c, 1);
}
Birds::Birds(const Birds& other)
	: Animal(other)
{
	this->m_incubationTime = other.m_incubationTime;
}
Birds::~Birds()
{}

void Birds::Load(ifstream& in_file)//load the data from a text file
{
	Animal::Load(in_file);
	in_file >> m_incubationTime;
}
void Birds::Save(ofstream& out_file) const//saves the data to a text file
{
	Animal::Save(out_file);
	out_file << m_incubationTime << endl;
}
void Birds::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	Animal::SaveBin(out_file);
	out_file.write((char*)&m_incubationTime, sizeof(m_incubationTime));
	out_file.write("\n", 1);
}

/*****************************Fish******************************/

Fish::Fish()//set the default color to GRAY and other params to 0
: Animal(),
m_finCount(0), m_gillsCount(0)
{}
Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills)//init the Fish with a given attributes
: Animal(color, childs, avgLifetime),
m_finCount(fin), m_gillsCount(gills)
{}
Fish::Fish(ifstream& in_file)//init the Fish from a binary file
	: Animal(in_file)
{
	char c;//to read the '\n' that we wrote
	in_file.read((char*)&m_finCount, sizeof(m_finCount));
	in_file.read(&c, 1);
	in_file.read((char*)&m_gillsCount, sizeof(m_gillsCount));
	in_file.read(&c, 1);
}
Fish::Fish(const Fish& other)
	: Animal(other)
{
	this->m_finCount = other.m_finCount;
	this->m_gillsCount = other.m_gillsCount;
}
Fish::~Fish()
{}

void Fish::Load(ifstream& in_file)//load the data from a text file
{
	Animal::Load(in_file);
	load(in_file);
}
void Fish::Save(ofstream& out_file) const//saves the data to a text file
{
	Animal::Save(out_file);
	save(out_file);
}
void Fish::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	Animal::SaveBin(out_file);
	saveBin(out_file);
}
void Fish::load(ifstream& in_file)
{
	in_file >> m_finCount;
	in_file >> m_gillsCount;
}
void Fish::save(ofstream& out_file) const
{
	out_file << m_finCount << endl;
	out_file << m_gillsCount << endl;
}
void Fish::saveBin(ofstream& out_file) const
{
	out_file.write((char*)&m_finCount, sizeof(m_finCount));
	out_file.write("\n", 1);
	out_file.write((char*)&m_gillsCount, sizeof(m_gillsCount));
	out_file.write("\n", 1);
}

/**************************Horse********************************/

Horse::Horse()//set the default color to GRAY and other params to 0
: Animal(), Mammals(),
m_type(NULL)
{}
Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type)//init the Horse with a given attributes
: Animal(color, childs, avgLifetime), Mammals(color, childs, avgLifetime, preg, milk)
{
	this->m_type = strdup(type);
}
Horse::Horse(ifstream& in_file)//init the Horse from a binary file
: Animal(in_file), Mammals(in_file)
{
	this->m_type = readTextFromFile(in_file);
}
Horse::Horse(const Horse& other)
: Animal(other), Mammals(other)
{
	this->m_type = strdup(other.m_type);
}
Horse::~Horse()
{
	if (m_type)
		delete m_type;

	m_type = NULL;
}

void Horse::Load(ifstream& in_file)//load the data from a text file
{
	Mammals::Load(in_file);
	m_type = readTextFromFile(in_file);
}
void Horse::Save(ofstream& out_file) const//saves the data to a text file
{
	Mammals::Save(out_file);
	out_file << m_type << endl;
}
void Horse::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	Mammals::SaveBin(out_file);
	out_file.write(m_type, strlen(m_type));
	out_file.write("\n", 1);
}

/************************Flamingo*******************************/

Flamingo::Flamingo()//set the default color to GRAY and other params to 0
: Animal(), Birds(),
	m_avgHeight(0.f)
{}
Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight)//init the Flamingo with a given attributes
: Animal(color, childs, avgLifetime), Birds(color, childs, avgLifetime, incubation),
	m_avgHeight(avgHeight)
{}
Flamingo::Flamingo(ifstream& in_file)//init the Flamingo from a binary file
: Animal(in_file), Birds(in_file)
{
	char c;//to read the '\n' that we wrote
	in_file.read((char*)&m_avgHeight, sizeof(m_avgHeight));
	in_file.read(&c, 1);
}
Flamingo::Flamingo(const Flamingo& other)
: Animal(other), Birds(other)
{
	this->m_avgHeight = other.m_avgHeight;
}
Flamingo::~Flamingo()
{}

void Flamingo::Load(ifstream& in_file)//load the data from a text file
{
	Birds::Load(in_file);
	in_file >> m_avgHeight;
}
void Flamingo::Save(ofstream& out_file) const//saves the data to a text file
{
	Birds::Save(out_file);
	out_file << m_avgHeight << endl;
}
void Flamingo::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	Birds::SaveBin(out_file);
	out_file.write((char*)&m_avgHeight, sizeof(m_avgHeight));
	out_file.write("\n", 1);
}

/*************************MammalFish****************************/

MammalsFish::MammalsFish()//set the default color to GRAY and other params to 0
: Animal(), Mammals(), Fish()
{}
MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)//init the MammalsFish with a given attributes
: Animal(color, childs, avgLifetime), Mammals(color, childs, avgLifetime, preg, milk), Fish(color, childs, avgLifetime, fin, gills)
{}
MammalsFish::MammalsFish(ifstream& in_file)//init the MammalsFish from a binary file
: Animal(in_file), Mammals(in_file), Fish(in_file)
{}
MammalsFish::MammalsFish(const MammalsFish& other)
: Animal(other), Mammals(other), Fish(other)
{}
MammalsFish::~MammalsFish()
{}

void MammalsFish::Load(ifstream& in_file)//load the data from a text file
{
	Animal::Load(in_file);
	load(in_file);
}
void MammalsFish::Save(ofstream& out_file) const//saves the data to a text file
{
	Animal::Save(out_file);
	save(out_file);
}
void MammalsFish::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	Animal::SaveBin(out_file);
	saveBin(out_file);
}
void MammalsFish::load(ifstream& in_file)
{
	Mammals::load(in_file);
	Fish::load(in_file);
}
void MammalsFish::save(ofstream& out_file) const
{
	Mammals::save(out_file);
	Fish::save(out_file);
}
void MammalsFish::saveBin(ofstream& out_file) const
{
	Mammals::saveBin(out_file);
	Fish::saveBin(out_file);
}

/***********************GoldFish*********************************/

GoldFish::GoldFish()//set the default color to GRAY and other params to 0
: Animal(), MammalsFish(),
m_avgWeight(0), m_avgLength(0)
{}
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL)//init the GoldFish with a given attributes
: Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills),
m_avgWeight(avgW), m_avgLength(avgL)
{}
GoldFish::GoldFish(ifstream& in_file)//init the GoldFish from a binary file
: Animal(in_file), MammalsFish(in_file)
{
	char c;//to read the '\n' that we wrote
	in_file.read((char*)&m_avgWeight, sizeof(m_avgWeight));
	in_file.read(&c, 1);
	in_file.read((char*)&m_avgLength, sizeof(m_avgLength));
	in_file.read(&c, 1);
}
GoldFish::GoldFish(const GoldFish& other)
: Animal(other), MammalsFish(other)
{
	this->m_avgWeight = other.m_avgWeight;
	this->m_avgLength = other.m_avgLength;
}
GoldFish::~GoldFish()
{}

void GoldFish::Load(ifstream& in_file)//load the data from a text file
{
	MammalsFish::Load(in_file);
	in_file >> m_avgWeight;
	in_file >> m_avgLength;
}
void GoldFish::Save(ofstream& out_file) const//saves the data to a text file
{
	MammalsFish::Save(out_file);
	out_file << m_avgWeight << endl;
	out_file << m_avgLength << endl;
}
void GoldFish::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	MammalsFish::SaveBin(out_file);
	out_file.write((char*)&m_avgWeight, sizeof(m_avgWeight));
	out_file.write("\n", 1);
	out_file.write((char*)&m_avgLength, sizeof(m_avgLength));
	out_file.write("\n", 1);
}

/**************************Mermaid*******************************/

Mermaid::Mermaid()//set the default color to GRAY and other params to 0
: Animal(), MammalsFish(),
m_firstName(NULL), m_lastName(NULL)
{}
Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName)//init the Mermaid with a given attributes
: Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
{
	this->m_firstName = strdup(firstName);
	this->m_lastName = strdup(lastName);
}
Mermaid::Mermaid(ifstream& in_file)//init the Mermaid from a binary file
: Animal(in_file), MammalsFish(in_file)
{
	this->m_firstName = readTextFromFile(in_file);
	this->m_lastName = readTextFromFile(in_file);
}
Mermaid::Mermaid(const Mermaid& other)
: Animal(other), MammalsFish(other)
{
	this->m_firstName = strdup(other.m_firstName);
	this->m_lastName = strdup(other.m_lastName);
}
Mermaid::~Mermaid()
{
	if (m_firstName)
		delete m_firstName;

	m_firstName = NULL;

	if (m_lastName)
		delete m_lastName;

	m_lastName = NULL;
}

void Mermaid::Load(ifstream& in_file)//load the data from a text file
{
	MammalsFish::Load(in_file);

	m_firstName = readTextFromFile(in_file);
	m_lastName = readTextFromFile(in_file);
}
void Mermaid::Save(ofstream& out_file) const//saves the data to a text file
{
	MammalsFish::Save(out_file);
	out_file << m_firstName << endl;
	out_file << m_lastName << endl;
}
void Mermaid::SaveBin(ofstream& out_file) const//saves the data to a binary file
{
	MammalsFish::SaveBin(out_file);
	out_file.write(m_firstName, strlen(m_firstName));
	out_file.write("\n", 1);
	out_file.write(m_lastName, strlen(m_lastName));
	out_file.write("\n", 1);
}

/****************************Zoo*********************************/

Zoo::Zoo()//default c'tor  - all to 0 or null
{
	this->m_name = NULL;
	this->m_address = NULL;
	this->m_ticketPrice = 0;
	this->m_openHours = NULL;
	this->m_closeHours = NULL;
	this->m_numOfAnimals = 0;
	this->m_animals = NULL;
}
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)//c'tor with data - init class
: m_ticketPrice(ticket), m_numOfAnimals(0), m_animals(NULL)
{
	this->m_name = strdup(name);
	this->m_address = strdup(address);
	this->m_openHours = strdup(open);
	this->m_closeHours = strdup(close);
}
Zoo::Zoo(ifstream& in_file)//c'tor that gets a binary file and loads the data of the zoo from the file
{
	m_name = readTextFromFile(in_file);
	m_address = readTextFromFile(in_file);

	in_file.read((char*)&m_ticketPrice, sizeof(m_ticketPrice));

	m_openHours = readTextFromFile(in_file);
	m_closeHours = readTextFromFile(in_file);

	in_file.read((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));

	m_animals = new Animal * [m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals; ++i)
	{
		Animal* a = createAnimalBin(in_file);
		m_animals[i] = a;
	}
}
Zoo::Zoo(const Zoo& other)//copy c'tor that loads the data from the other (deep way)
{
	*this = other;
}
Zoo::~Zoo()
{
	if (m_name)
		delete m_name;

	m_name = NULL;

	if (m_address)
		delete m_address;

	m_address = NULL;

	if (m_openHours)
		delete m_openHours;

	m_openHours = NULL;

	if (m_closeHours)
		delete m_closeHours;

	m_closeHours = NULL;

	if (m_numOfAnimals)
	{
		for (int i = 0; i < m_numOfAnimals; ++i)
			delete m_animals[i];

		delete[] m_animals;

		m_animals = NULL;
	}
}
void Zoo::AddAnimal(Animal* an)//adds an animal to the array
{
	//first expand the array of animals and keep the old data
	++m_numOfAnimals;
	Animal** newArr = new Animal * [m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals - 1; ++i)
		newArr[i] = m_animals[i];

	//delete the old array
	delete[] m_animals;

	//set the array to the new one
	m_animals = newArr;

	//now determine the type of the added animal and add it to the last place in the array	
	char* type = an->GetTypeName();
	if (0 == strcmp(type, fixTypeName((char*)typeid(Horse).name())))
		m_animals[m_numOfAnimals - 1] = new Horse(*(dynamic_cast<Horse*>(an)));
	else if (0 == strcmp(type, fixTypeName((char*)typeid(Flamingo).name())))
		m_animals[m_numOfAnimals - 1] = new Flamingo(*(dynamic_cast<Flamingo*>(an)));
	else if (0 == strcmp(type, fixTypeName((char*)typeid(GoldFish).name())))
		m_animals[m_numOfAnimals - 1] = new GoldFish(*(dynamic_cast<GoldFish*>(an)));
	else if (0 == strcmp(type, fixTypeName((char*)typeid(Mermaid).name())))
		m_animals[m_numOfAnimals - 1] = new Mermaid(*(dynamic_cast<Mermaid*>(an)));
	else
		m_animals[m_numOfAnimals - 1] = NULL;
}
Zoo& Zoo::operator+(Animal* an)//adds an animal to the class and returns this with the change
{
	//first expand the array of animals and keep the old data
	++m_numOfAnimals;
	Animal** newArr = new Animal * [m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals - 1; ++i)
		newArr[i] = m_animals[i];

	//delete the old array
	delete[] m_animals;

	//set the array to the new one
	m_animals = newArr;

	//now add the new Animal to the array
	m_animals[m_numOfAnimals - 1] = an;

	return *this;
}
Zoo Zoo::operator+(const Zoo& other) const //returns a new Zoo with the properties of this and animals of this and other
{
	Zoo z(*this);
	for (int i = 0; i < other.m_numOfAnimals; ++i)
		z.AddAnimal(other.m_animals[i]);

	return z;
}
Zoo& Zoo::operator+=(Animal* an)
{
	*this + an;
	return *this;
}
Zoo& Zoo::operator=(const Zoo& other)//operator = that copies the data from other to this and returns this
{
	m_name = strdup(other.m_name);
	m_address = strdup(other.m_address);
	m_ticketPrice = other.m_ticketPrice;
	m_openHours = strdup(other.m_openHours);
	m_closeHours = strdup(other.m_closeHours);

	m_numOfAnimals = 0;
	for (int i = 0; i < other.m_numOfAnimals; ++i)
		AddAnimal(other.m_animals[i]);

	return *this;
}
void Zoo::Save(ofstream& ofs) const//method to save the info to a text file
{
	ofs << m_name << endl;
	ofs << m_address << endl;
	ofs << m_ticketPrice << endl;
	ofs << m_openHours << endl;
	ofs << m_closeHours << endl;
	ofs << m_numOfAnimals << endl;

	for (int i = 0; i < m_numOfAnimals; ++i)
		m_animals[i]->Save(ofs);
}
void Zoo::Load(ifstream& ifs)//method to load the info from a text file
{
	m_name = readTextFromFile(ifs);
	m_address = readTextFromFile(ifs);
	ifs >> m_ticketPrice;
	m_openHours = readTextFromFile(ifs);
	m_closeHours = readTextFromFile(ifs);
	ifs >> m_numOfAnimals;

	m_animals = new Animal * [m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals; ++i)
	{
		Animal* a = createAnimalTxt(ifs);
		a->Load(ifs);
		m_animals[i] = a;
	}
}
void Zoo::SaveBin(ofstream& ofs) const//method to save the info to a binary file
{
	ofs.write(m_name, strlen(m_name));
	ofs.write("\n", 1);
	ofs.write(m_address, strlen(m_address));
	ofs.write("\n", 1);
	ofs.write((char*)&m_ticketPrice, sizeof(m_ticketPrice));
	ofs.write("\n", 1);
	ofs.write(m_openHours, strlen(m_openHours));
	ofs.write("\n", 1);
	ofs.write(m_closeHours, strlen(m_closeHours));
	ofs.write("\n", 1);
	ofs.write((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));
	ofs.write("\n", 1);

	for (int i = 0; i < m_numOfAnimals; ++i)
		m_animals[i]->SaveBin(ofs);
}
Animal* Zoo::createAnimalBin(ifstream& in_file)
{
	Animal* retVal = NULL;
	char* type = readTextFromFile(in_file);

	if (0 == strcmp(type, fixTypeName((char*)typeid(Horse).name())))
		retVal = new Horse(in_file);

	if (0 == strcmp(type, fixTypeName((char*)typeid(Flamingo).name())))
		retVal = new Flamingo(in_file);

	if (0 == strcmp(type, fixTypeName((char*)typeid(GoldFish).name())))
		retVal = new GoldFish(in_file);

	if (0 == strcmp(type, fixTypeName((char*)typeid(Mermaid).name())))
		retVal = new Mermaid(in_file);

	delete type;

	return retVal;
}
Animal* Zoo::createAnimalTxt(ifstream& in_file)
{
	Animal* retVal = NULL;
	char* type = readTextFromFile(in_file);

	if (0 == strcmp(type, fixTypeName((char*)typeid(Horse).name())))
		retVal = new Horse();

	if (0 == strcmp(type, fixTypeName((char*)typeid(Flamingo).name())))
		retVal = new Flamingo();

	if (0 == strcmp(type, fixTypeName((char*)typeid(GoldFish).name())))
		retVal = new GoldFish();

	if (0 == strcmp(type, fixTypeName((char*)typeid(Mermaid).name())))
		retVal = new Mermaid();

	delete type;

	return retVal;
}
ofstream& operator<<(ofstream& out, const Zoo& z)
{
	z.Save(out);
	return out;
}
ifstream& operator>>(ifstream& in, Zoo& z)
{
	z.Load(in);
	return in;
}

/*****************************************************************/

char* readTextFromFile(ifstream& in_file)
{
	char str[256] = { 0 };
	while (0 == strlen(str))
		in_file.getline(str, 256, '\n');

	return strdup(str);
}
char* fixTypeName(char* name)
{
	if ('0' <= name[0] && name[0] <= '9')
		return (char*)(name + 1);

	return (char*)(name + 6);
}