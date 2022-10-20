#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

class ShipInfo
{
	string Name;
	string Class;
	short Length;
	int Shield;
	float Warp;
	unsigned int WeaponNumber;
public: 
	ShipInfo(string Name = "null", string Class = "null", short Length = 0, int Shield = 0, float Warp = 0.0, unsigned int WeaponNumber = 0)
	{
		this->Name = Name;
		this->Class = Class;
		this->Length = Length;
		this->Shield = Shield;
		this->Warp = Warp;
		this->WeaponNumber = WeaponNumber;
	}
	string GetName()
	{
		return Name;
	}
	string GetClass()
	{
		return Class;
	}
	short GetLength()
	{
		return Length;
	}
	int GetShield()
	{
		return Shield;
	}
	float GetWarp()
	{
		return Warp;
	}
	int GetWeaponNumber()
	{
		return WeaponNumber;
	}


};
class WeaponType
{
	string WeaponName;
	int PowerLevel;
	float Version;
public:
	WeaponType(string WeaponName = "null", int PowerLevel = 0, float Version = 0.0)
	{
		this->WeaponName = WeaponName;
		this->PowerLevel = PowerLevel;
		this->Version = Version;
	}
	string GetWeaponName()
	{
		return WeaponName;
	}
	int GetPowerLevel()
	{
		return PowerLevel;
	}
	float GetVersion()
	{
		return Version;
	}
};
void openfile(string path, vector<ShipInfo>& ships, vector<WeaponType>& weapons);
void choice1(vector<ShipInfo>& ships, vector<WeaponType> weapons);
void choice2(vector<ShipInfo>& ships, vector<WeaponType> weapons);
void choice3(vector<ShipInfo>& ships, vector<WeaponType> weapons);
void choice4(vector<ShipInfo>& ships, vector<WeaponType> weapons);
void choice5(vector<ShipInfo>& ships);

int main()
{
	vector<ShipInfo> ships;
	vector<WeaponType> weapons;
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	/* Load files here */
	if (option == 1)
	{
		openfile("friendlyships.shp", ships, weapons);
		
	}
	if (option == 2)
	{

		fstream binary("enemyships.shp", ios_base::in | ios_base::binary);

		if (!binary.is_open())
		{
			cout << "error while opening file";
		}
		else {
			//reading the number of ships that are in the file
			int count;
			binary.read((char*)& count, sizeof(count));
			//cout << count << " successfull test" << endl;

			//reading the "count" number of data elements from the file

			for (int i = 0; i < count; i++)
			{


				string Name;
				unsigned int temp;
				binary.read((char*)& temp, 4);

				char* memory = new char[temp];
				binary.read(memory, temp * sizeof(memory[0]));
				//cout << sizeof(memory) << endl;
				//binary.read((memory, temp * sizeof(memory[0]));
				Name = memory;

				delete[] memory;

				string Class;
				binary.read((char*)& temp, 4);
				memory = new char[temp];
				binary.read(memory, temp * sizeof(memory[0]));
				Class = memory;

				delete[] memory;

				short Length;
				binary.read((char*)& Length, 2);

				int Shield;
				binary.read((char*)& Shield, 4);
				float Warp;
				binary.read((char*)& Warp, 4);

				//Below is the number of weapons equipped on the ship
				unsigned int WeaponNumber;
				binary.read((char*)& WeaponNumber, sizeof(WeaponNumber));
				int counter;
				counter = WeaponNumber;
				string WeaponName;
				int PoweLevel;
				float Version;
				for (int i = 0; i < counter; i++)
				{

					binary.read((char*)& temp, 4);
					memory = new char[temp];
					binary.read(memory, temp * sizeof(memory[0]));
					WeaponName = memory;

					delete[] memory;


					binary.read((char*)& PoweLevel, 4);


					binary.read((char*)& Version, 4);
					WeaponType d(WeaponName, PoweLevel, Version);
					weapons.push_back(d);
				}
				ShipInfo c(Name, Class, Length, Shield, Warp, WeaponNumber);
				ships.push_back(c);

			}
		}
	}
	if (option == 3)
	{
		openfile("friendlyships.shp", ships, weapons);
		openfile("enemyships.shp", ships, weapons);
	}

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */
	if(option == 1)
		choice1(ships, weapons);
	if (option == 2)
		choice2(ships, weapons);
	if (option == 3)
		choice3(ships, weapons);
	if (option == 4)
		choice4(ships, weapons);
	if (option == 5)
		choice5(ships);

	return 0;
}

void choice1(vector<ShipInfo>& ships, vector<WeaponType> weapons)
{
	unsigned int escalatingVectorLocation;
	escalatingVectorLocation = 0;
	unsigned int j;
	j = 0;
	unsigned int TWeaponNumber;
	for (unsigned int i = 0; i < ships.size(); i++)

	{
		cout << "Name: " << ships[i].GetName() << endl;
		cout << "Class: " << ships[i].GetClass() << endl;
		cout << "Length: " << ships[i].GetLength() << endl;
		cout << "Shield capacity: " << ships[i].GetShield() << endl;
		cout << "Maximum Warp: " << ships[i].GetWarp() << endl;
		cout << "Armaments: " << endl;
		int totalFirePower;
		totalFirePower = 0;
		TWeaponNumber = ships[i].GetWeaponNumber();
		escalatingVectorLocation = escalatingVectorLocation + TWeaponNumber;
		for (; j < escalatingVectorLocation; j++)
		{
			totalFirePower = totalFirePower + weapons[j].GetPowerLevel();
			cout << weapons[j].GetWeaponName() << ", " << weapons[j].GetPowerLevel() << ", " << weapons[j].GetVersion() << endl;

		}
		if (TWeaponNumber == 0)
		{
			cout << "Unarmed" << endl << endl;
		}
		else 
		{
			cout << "Total firepower: " << totalFirePower << endl << endl;
		}
	} 
}

void choice2(vector<ShipInfo>& ships, vector<WeaponType> weapons)
{
	unsigned int escalatingVectorLocation;
	escalatingVectorLocation = 0;
	unsigned int j;
	j = 0;
	unsigned int TWeaponNumber;
	
	string ShipName;
	string ClassName;
	short LengthName;
	int ShieldName;
	float WarpName;
	unsigned int WeaponNumberName;
	string WeaponNameName;

	int MaxPower;
	MaxPower = 0;
	int jCheck=0;
	int escalatingVectorCheck=0;
	int totalFirePower;
	totalFirePower = 0;

	for (unsigned int i = 0; i < ships.size(); i++)
	{
		TWeaponNumber = ships[i].GetWeaponNumber();
		escalatingVectorLocation = escalatingVectorLocation + TWeaponNumber;
		for (; j < escalatingVectorLocation; j++)
		{
			if (weapons[j].GetPowerLevel() > MaxPower)
			{
				MaxPower = weapons[j].GetPowerLevel();
				ShipName = ships[i].GetName();
				
				ClassName= ships[i].GetClass();
				LengthName= ships[i].GetLength();
				ShieldName= ships[i].GetShield();
				WarpName= ships[i].GetWarp();
				WeaponNumberName= ships[i].GetWeaponNumber();
				WeaponNameName= weapons[j].GetWeaponName();

				jCheck = j - WeaponNumberName;
				escalatingVectorCheck = escalatingVectorLocation;

			}
		}
	}
	cout << "Name: " << ShipName << endl;
	cout << "Class: " << ClassName << endl;
	cout << "Length: " << LengthName << endl;
	cout << "Shield capacity: " << ShieldName << endl;
	cout << "Maximum Warp: " << WarpName << endl;
	cout << "Armaments: " << endl;
	if (jCheck < 0)
	{
		jCheck = 0;
	}
	for (; jCheck < escalatingVectorCheck; jCheck++)
	{
		totalFirePower = totalFirePower + weapons[jCheck].GetPowerLevel();
		cout << weapons[jCheck].GetWeaponName() << ", " << weapons[jCheck].GetPowerLevel() << ", " << weapons[jCheck].GetVersion() << endl;

	}
	cout << "Total firepower: " << totalFirePower << endl << endl;
}

void choice3(vector<ShipInfo>& ships, vector<WeaponType> weapons)
{

	unsigned int escalatingVectorLocation;
	escalatingVectorLocation = 0;
	unsigned int j;
	j = 0;
	unsigned int TWeaponNumber;

	string ShipName;
	string ClassName;
	short LengthName;
	int ShieldName;
	float WarpName;
	unsigned int WeaponNumberName;
	string WeaponNameName;

	int MaxPower;
	MaxPower = 0;
	int jCheck = 0;
	int escalatingVectorCheck = 0;
	int totalFirePower;
	totalFirePower = 0;

	for (unsigned int i = 0; i < ships.size(); i++)
	{
		TWeaponNumber = ships[i].GetWeaponNumber();
		escalatingVectorLocation = escalatingVectorLocation + TWeaponNumber;
		MaxPower = 0;
		for (; j < escalatingVectorLocation; j++)
		{
			MaxPower = MaxPower + weapons[j].GetPowerLevel();
			if (totalFirePower < MaxPower)
			{
				
				ShipName = ships[i].GetName();

				ClassName = ships[i].GetClass();
				LengthName = ships[i].GetLength();
				ShieldName = ships[i].GetShield();
				WarpName = ships[i].GetWarp();
				WeaponNumberName = ships[i].GetWeaponNumber();
				WeaponNameName = weapons[j].GetWeaponName();
				totalFirePower = MaxPower;
				jCheck = j - WeaponNumberName;
				escalatingVectorCheck = escalatingVectorLocation;

			}
		}
	}
	cout << "Name: " << ShipName << endl;
	cout << "Class: " << ClassName << endl;
	cout << "Length: " << LengthName << endl;
	cout << "Shield capacity: " << ShieldName << endl;
	cout << "Maximum Warp: " << WarpName << endl;
	cout << "Armaments: " << endl;
	if (jCheck < 0)
	{
		jCheck = 0;
	}
	for (; jCheck < escalatingVectorCheck-1; jCheck++)
	{
		//totalFirePower = totalFirePower + weapons[jCheck].GetPowerLevel();
		cout << weapons[jCheck+1].GetWeaponName() << ", " << weapons[jCheck + 1].GetPowerLevel() << ", " << weapons[jCheck + 1].GetVersion() << endl;

	}
	cout << "Total firepower: " << totalFirePower << endl << endl;
}

void choice4(vector<ShipInfo>& ships, vector<WeaponType> weapons)
{
	unsigned int escalatingVectorLocation;
	escalatingVectorLocation = 0;
	unsigned int j;
	j = 0;
	unsigned int k;
	k = 0;
	unsigned int TWeaponNumber;

	string ShipName;
	string ClassName;
	short LengthName;
	int ShieldName;
	float WarpName;
	
	string WeaponNameName;

	int MaxPower;
	MaxPower = 0;
	int jCheck = 0;
	int escalatingVectorCheck = 0;
	int totalFirePower;
	totalFirePower = 0;
	for (unsigned int i = 0; i < ships.size(); i++)
	{
		TWeaponNumber = ships[i].GetWeaponNumber();
		escalatingVectorLocation = escalatingVectorLocation + TWeaponNumber;
		MaxPower = 0;
		if (i == 0)
		{
			//unsigned int WeaponNumberName;

			for (; j < escalatingVectorLocation; j++)
			{
				MaxPower = MaxPower + weapons[j].GetPowerLevel();
				WeaponNameName = weapons[j].GetWeaponName();
				totalFirePower = MaxPower;
				jCheck = j- ships[i].GetWeaponNumber();
				escalatingVectorCheck = escalatingVectorLocation;
				ShipName = ships[i].GetName();
				ClassName = ships[i].GetClass();
				LengthName = ships[i].GetLength();
				ShieldName = ships[i].GetShield();
				WarpName = ships[i].GetWarp();
				//WeaponNumberName = ships[i].GetWeaponNumber();
				k++;
			}

			
		}
		else if (i != 0)
		{
			for (; j < escalatingVectorLocation; j++)
			{
				for (; k < escalatingVectorLocation; k++)
				{
				MaxPower = MaxPower + weapons[k].GetPowerLevel();
				}
				if (totalFirePower > MaxPower)
				{

					ShipName = ships[i].GetName();

					ClassName = ships[i].GetClass();
					LengthName = ships[i].GetLength();
					ShieldName = ships[i].GetShield();
					WarpName = ships[i].GetWarp();
					//WeaponNumberName = ships[i].GetWeaponNumber();
					WeaponNameName = weapons[j].GetWeaponName();
					totalFirePower = MaxPower;
					jCheck = escalatingVectorLocation- ships[i].GetWeaponNumber();
					escalatingVectorCheck = escalatingVectorLocation;
					//k++;
				}
			}
		}
	}
	cout << "Name: " << ShipName << endl;
	cout << "Class: " << ClassName << endl;
	cout << "Length: " << LengthName << endl;
	cout << "Shield capacity: " << ShieldName << endl;
	cout << "Maximum Warp: " << WarpName << endl;
	cout << "Armaments: " << endl;
	if (jCheck < 0)
	{
		jCheck = 0;
	}
	totalFirePower = 0;
	for (; jCheck< escalatingVectorCheck; jCheck++)
	{
		totalFirePower = totalFirePower + weapons[jCheck].GetPowerLevel();
		cout << weapons[jCheck].GetWeaponName() << ", " << weapons[jCheck].GetPowerLevel() << ", " << weapons[jCheck].GetVersion() << endl;

	}
	cout << "Total firepower: " << totalFirePower << endl << endl;
}

void choice5(vector<ShipInfo>& ships)
{
	unsigned int TWeaponNumber;
	for (unsigned int i = 0; i < ships.size(); i++)
	{
		TWeaponNumber = ships[i].GetWeaponNumber();
		if (ships[i].GetWeaponNumber() == 0)
		{
			cout << "Name: " << ships[i].GetName() << endl;
			cout << "Class: " << ships[i].GetClass() << endl;
			cout << "Length: " << ships[i].GetLength() << endl;
			cout << "Shield capacity: " << ships[i].GetShield() << endl;
			cout << "Maximum Warp: " << ships[i].GetWarp() << endl;
			cout << "Armaments: " << endl;
			if (TWeaponNumber == 0)
			{
				cout << "Unarmed" << endl << endl;
			}
			else
			{
				cout << "This ship is not unarmed: " << endl << endl;
			}
		}
	}

}

void openfile(string path, vector<ShipInfo>& ships, vector<WeaponType>& weapons)
{
	fstream binary(path, ios_base::in | ios_base::binary);

	if (!binary.is_open())
	{
		cout << "error while opening file";
	}
	else {
		//reading the number of ships that are in the file
		int count;
		binary.read((char*)& count, sizeof(count));
		//cout << count << " successfull test" << endl;

		//reading the "count" number of data elements from the file

		for (int i = 0; i < count; i++)
		{


			string Name;
			unsigned int temp;
			binary.read((char*)& temp, 4);

			char* memory = new char[temp];
			binary.read(memory, temp * sizeof(memory[0]));
			//cout << sizeof(memory) << endl;
			//binary.read((memory, temp * sizeof(memory[0]));
			Name = memory;

			delete[] memory;

			string Class;
			binary.read((char*)& temp, 4);
			memory = new char[temp];
			binary.read(memory, temp * sizeof(memory[0]));
			Class = memory;

			delete[] memory;

			short Length;
			binary.read((char*)& Length, 2);

			int Shield;
			binary.read((char*)& Shield, 4);
			float Warp;
			binary.read((char*)& Warp, 4);

			//Below is the number of weapons equipped on the ship
			unsigned int WeaponNumber;
			binary.read((char*)& WeaponNumber, sizeof(WeaponNumber));
			int counter;
			counter = WeaponNumber;
			string WeaponName;
			int PoweLevel;
			float Version;
			for (int i = 0; i < counter; i++)
			{

				binary.read((char*)& temp, 4);
				memory = new char[temp];
				binary.read(memory, temp * sizeof(memory[0]));
				WeaponName = memory;

				delete[] memory;


				binary.read((char*)& PoweLevel, 4);


				binary.read((char*)& Version, 4);
				WeaponType d(WeaponName, PoweLevel, Version);
				weapons.push_back(d);
			}
			ShipInfo c(Name, Class, Length, Shield, Warp, WeaponNumber);
			ships.push_back(c);

		}
	}
}