#include <iostream>
#include <new>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> cNames = {"Volvo      ", "BMW        ", "Toyota     ", "Opel       ", "Audi       ", "Hyundai    "};
vector<string> mNames = {"Yamaha     ", "Kawasaki   ", "Suzuki     "};
vector<string> tNames = {"Mercedes   ", "Iveco      ", "Scania     ", "Bell Trucks"};
vector<string> AllNames = {"Volvo      ", "BMW        ", "Toyota     ", "Opel       ", "Audi       ", "Hyundai    ", "Yamaha     ", "Kawasaki   ", "Suzuki     ", "Mercedes   ", "Iveco      ", "Scania     ", "Bell Trucks"};

class Vechicle
{
	public:
		Vechicle(): mass(0), price(0), brand("unknown"), sits(0), YearOfProd(0) {}

		virtual double getMass() const = 0;
		virtual int getSits() const = 0;
		virtual string getName() const = 0;
		virtual double getPrice() const = 0;
		virtual int getYear() const = 0;
		virtual void getInfo() const = 0;
		virtual double getMaxV() const = 0;

		~Vechicle() {}
	protected:
		double mass;
		double price;
		std::string brand;
		int sits;
		int YearOfProd;
};

class Car : public Vechicle
{
	public:
		Car() {cos = new int[5];}
		Car(double m, int s, int y, std::string& name)
		{
			mass = m;
			sits = s;
			YearOfProd = y;
			brand = name;
			price = mass*mass*(1.0/static_cast<double>(2024-YearOfProd));
			cos = new int[5];
		}
		double getMass() const override
		{
			return mass;
		}
		double getPrice() const override
		{
			return price;
		}
		string getName() const override
		{
			return brand;
		}
		int getSits() const override
		{
			return sits;
		}
		int getYear() const override
		{
			return YearOfProd;
		}
		void getInfo() const override
		{
			cout << brand << "   |   " << YearOfProd << "   |   " << sits << "      |   " << mass << "   |   " << maxVC << "     |   " << price  << endl;
		}
		double getMaxV() const override
		{
			return maxVC;
		}
		static double maxVC;
		~Car() {delete cos;}
	private:
		int *cos;
};

class Motor : public Vechicle
{
	public:
		Motor() {cos = new int[5];}
		Motor(double m, int s, int y, std::string& name)
		{
			mass = m;
			sits = s;
			YearOfProd = y;
			brand = name;
			price = mass*mass*(1.0/static_cast<double>(2024-YearOfProd));
			cos = new int[5];
		}
		double getMass() const override
		{
			return mass;
		}
		double getPrice() const override
		{
			return price;
		}
		string getName() const override
		{
			return brand;
		}
		int getSits() const override
		{
			return sits;
		}
		int getYear() const override
		{
			return YearOfProd;
		}
		void getInfo() const override
		{
			cout << brand << "   |   " << YearOfProd << "   |   " << sits << "      |   " << mass << "   |   " << maxVM << "     |   " << price  << endl;
		}
		double getMaxV() const override
		{
			return maxVM;
		}

		static double maxVM;
		~Motor() {delete cos;}
	private:
		int *cos;
};

class Truck : public Vechicle
{
	public:
		Truck() {cos = new int[5];}
		Truck(double m, int s, int y, std::string& name)
		{
			mass = m;
			sits = s;
			YearOfProd = y;
			brand = name;
			price = mass*mass*(1.0/static_cast<double>(2024-YearOfProd));
			cos = new int[5];
		}
		double getMass() const override
		{
			return mass;
		}
		double getPrice() const override
		{
			return price;
		}
		string getName() const override
		{
			return brand;
		}
		int getSits() const override
		{
			return sits;
		}
		int getYear() const override
		{
			return YearOfProd;
		}
		void getInfo() const override
		{
			cout << brand << "   |   " << YearOfProd << "   |   " << sits << "      |   " << mass << "   |   " << maxVT << "     |   " << price  << endl;
		}
		double getMaxV() const override
		{
			return maxVT;
		}
		static double maxVT;
		~Truck() {delete cos;}
	private:
		int *cos;
};

class Fabric
{
	public:
		Fabric()
		{
			cout << "Hello in vechicle fabric, from now on we will be taking care o production" << endl;
		}
		std::unique_ptr<Vechicle> doCar(double m, int s, int y, std::string& name)
		{
			/*Vechicle* NewCar;
			NewCar = new Car(m, s, y, name);*/
			std::unique_ptr<Vechicle> NewCar = std::make_unique<Car>(m, s, y, name);
			return NewCar;
		}

		std::unique_ptr<Vechicle> doMotor(double m, int s, int y, std::string& name)
		{
			/*Vechicle* NewMotor = new Motor(m, s, y, name);*/
			std::unique_ptr<Vechicle> NewMotor = std::make_unique<Motor>(m, s, y, name);
			return NewMotor;
		}

		std::unique_ptr<Vechicle> doTruck(double m, int s, int y, std::string& name)
		{
			//Vechicle* NewTruck = new Truck(m, s, y, name);
			std::unique_ptr<Vechicle> NewTruck = std::make_unique<Truck>(m, s, y, name);
			return NewTruck;
		}

		std::unique_ptr<Vechicle> doRand()
		{
			double m;
			int s;
			int y;
			std::string name = AllNames[rand () % AllNames.size()];

			for(int i = 0; i < cNames.size(); i++)
			{
				if(name == cNames[i])
				{	
					m = 2000 + 100 * (rand() % 10);
					s = 3 + rand() % 3;
					y = 1990 + rand() % 25;
					return doCar(m, s, y, name);
				}
			}
			for(int i = 0; i < mNames.size(); i++)
			{
				if(name == mNames[i])
				{
					m = 1000 + 100 * (rand() % 7);
					s = 1 + rand() % 2;
					y = 1990 + rand() % 25;
					return doMotor(m, s, y, name);
				}
			}
			for(int i = 0; i < tNames.size(); i++)
			{
				if(name == tNames[i])
				{
					m = 5000 + 100 * (rand() % 12);
					s = 3;
					y = 1990 + rand() % 25;
					return doTruck(m, s, y, name);
				}
			}
		}

		~Fabric() {}
	private:
		
};

class Garage
{
	public:
		Garage() 
		{	
			Manufacture = std::make_unique<Fabric>();
			cout << "Here we will store vechicles and iformations about them" << endl;
			InsertTo(Manufacture->doMotor(1500,2,2005,mNames[rand()%mNames.size()]));
			InsertTo(Manufacture->doCar(2500,5,2014,cNames[rand()%cNames.size()]));
			InsertTo(Manufacture->doTruck(5500,3,2002,tNames[rand()%tNames.size()]));
			cout << "\n\n\n" << endl;
		}
		void PrintRecordsSorted(Garage &This)
		{
			std::string SortType;
			std::string Wrong = "Wrong char was given";
			cout << "How would you like to have records sorted?" << endl;
			cout << "Brand - b\n" << "Year - y\n" << "Sits - s\n" << "Mass - m\n" << "Max speed - v\n" << "Price - p\n" << "Not sorted - n\n" << endl;
			cout << "Choose the corresponding char" << endl;
			cin >> SortType;
			if((SortType != "b") && (SortType != "y") && (SortType != "s") && (SortType != "m") && (SortType != "v") && (SortType != "p") && (SortType != "n"))
			{
				cout << Wrong << endl;
			}
			else
			{
				SortRecords(SortType);
				PrintRecords(This);
			}
		}
		void PrintRecords(Garage &This)
		{
			cout << "No." << "   |  " << "Brand      " << "   |   " << "Year" << "   |   " << "Sits" << "   |   " << "Mass" << "   |   " << "Max V" << "   |   " << "Price" << endl;
			cout << "---" << "-------" << "-----------" << "-------" << "----" << "-------" << "----" << "-------" << "----" << "-------" << "-----" << "-------" << "----------------" << endl;
			for(int i = 0; i < record.size(); i++)
			{
				This[i];
			}
		}
		/*void PrintSpecial(Garage &This)
		{
			cout << "No." << "   |  " << "Brand      " << "   |   " << "Year" << "   |   " << "Sits" << "   |   " << "Mass" << "   |   " << "Max V" << "   |   " << "Price" << endl;
			cout << "---" << "-------" << "-----------" << "-------" << "----" << "-------" << "----" << "-------" << "----" << "-------" << "-----" << "-------" << "----------------" << endl;
			for(int i = 0; i < recordSel.size(); i++)
			{
				This[i];
			}
			recordSel.clear();
		}*/
		void InsertRand()
		{
			InsertTo(Manufacture->doRand());
		}
		void InsertTo(std::unique_ptr<Vechicle> Vech)
		{
			record.push_back(std::move(Vech));
		}
		void SortRecords(std::string &c)
		{
			if(c == "b")
			{
				std::sort(record.begin(), record.end(), [](const std::unique_ptr<Vechicle> &Vech1,const std::unique_ptr<Vechicle> &Vech2) {return Vech1->getName() > Vech2->getName();});
			}
			else if(c == "y")
			{
				std::sort(record.begin(), record.end(), [](const std::unique_ptr<Vechicle> &Vech1,const std::unique_ptr<Vechicle> &Vech2) {return Vech1->getYear() > Vech2->getYear();});
			}
			else if(c == "s")
			{
				std::sort(record.begin(), record.end(), [](const std::unique_ptr<Vechicle> &Vech1,const std::unique_ptr<Vechicle> &Vech2) {return Vech1->getSits() > Vech2->getSits();});
			}
			else if(c == "m")
			{
				std::sort(record.begin(), record.end(), [](const std::unique_ptr<Vechicle> &Vech1,const std::unique_ptr<Vechicle> &Vech2) {return Vech1->getMass() > Vech2->getMass();});
			}
			else if(c == "v")
			{
				std::sort(record.begin(), record.end(), [](const std::unique_ptr<Vechicle> &Vech1,const std::unique_ptr<Vechicle> &Vech2) {return Vech1->getMaxV() > Vech2->getMaxV();});
			}
			else if(c == "p")
			{
				std::sort(record.begin(), record.end(), [](const std::unique_ptr<Vechicle> &Vech1,const std::unique_ptr<Vechicle> &Vech2) {return Vech1->getPrice() > Vech2->getPrice();});
			}
		}
		void operator[](int i)
		{	
			cout << i+1 << ".    |  ";
			record[i]->getInfo();
		}
		~Garage() {}
	private:
		std::unique_ptr<Fabric> Manufacture;
		vector<std::unique_ptr<Vechicle>> record;
		vector<std::unique_ptr<Vechicle>> recordSel;
};

//template<typename condit>
//class choose
//{
//	public:
//		void operator()(vector<std::unique_ptr<Vechicle>> Vech1, std::string &c, condit &cond, vector<std::unique_ptr<Vechicle>> yes)
//		{
//			if(c == "b")
//			{
//				[&](const std::unique_ptr<Vechicle> &Vech1) {if(Vech1->getName() == cond){yes.push_back(Vech1);}};
//			}
//			else if(c == "y")
//			{
//				[&](const std::unique_ptr<Vechicle> &Vech1) {if(Vech1->getYear() == cond){yes.push_back(Vech1);}};
//			}
//			else if(c == "s")
//			{
//				[&](const std::unique_ptr<Vechicle> &Vech1) {if(Vech1->getSits() == cond){yes.push_back(Vech1);}};
//			}
//			else if(c == "m")
//			{
//				[&](const std::unique_ptr<Vechicle> &Vech1) {if(Vech1->getMass() == cond){yes.push_back(Vech1);}};
//			}
//			else if(c == "v")
//			{
//				[&](const std::unique_ptr<Vechicle> &Vech1) {if(Vech1->getMaxV() == cond){yes.push_back(Vech1);}};
//			}
//			else if(c == "p")
//			{
//				[&](const std::unique_ptr<Vechicle> &Vech1>) {if(Vech1->getPrice() == cond){yes.push_back(Vech1);}};
//			}
//		}
//};
double Car::maxVC = 160;
double Motor::maxVM = 230;
double Truck::maxVT = 110;

int main()
{	
	srand(time(NULL));
	Garage Station1;

	vector<std::unique_ptr<Vechicle>> record;
	vector<std::unique_ptr<Vechicle>> recordSel;

	for(int i = 0; i < 997; i++)
	{
		Station1.InsertRand();
	}

	Station1.PrintRecords(Station1);


	while(1)
	{
		Station1.PrintRecordsSorted(Station1);
	}

}