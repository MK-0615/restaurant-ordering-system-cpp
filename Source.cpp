
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <thread> //For decoration purpose
#include <chrono> //For decoration purpose
#include <windows.h> //For decoration purpose


using namespace std;

struct Customer {
	string user;
	string password;
};

struct Salads {
	string s_name;
	double s_price = 0;
};

struct MainCourse {
	string mc_name;
	double mc_price = 0;
};

struct Beverage {
	string b_name;
	double b_price[5][5] = { 0 };
};

struct LongDrink {
	string ld_name;
	double ld_price[5] = { 0 };
};

struct Selection {
	string bev[10][10] = { {"Juice","Smoothie"},{"Venti (M)","Grande (L)"},{"None","Less","Normal"} };
	string LD[10][10] = { {"Venti(M)","Grande(L)"},{"None","Less","Normal"} };
	string MC[20] = { "Baked potato","French fries","Onion rings","Grilled polenta" };
}sel;

void printLoadingbar(); //design
void admin();
void adminLogout();
void customer();
void customerDisplaySalad();
void customerDisplayMain();
void customerDisplayBeverages();
void customerDisplayLongDrink();

bool isEmpty();
void editMain();
void editSalad();
void editBeverage();
void editLongDrink();

void addSaladMenu();
void addMainMenu();
void addBeverageMenu();
void addLongMenu();

void deleteSalad();
void deleteMain();
void deleteBeverage();
void deleteLongDrink();

void orderAdd(string orderList[], double orderPrice[], int orderqty[]);
void orderAddSalad(string orderList[], double orderPrice[], int orderqty[]);
void orderAddMC(string orderList[], double orderPrice[], int orderqty[]);
void orderAddBeverage(string orderList[], double orderPrice[], int orderqty[]);
void orderAddLongDrink(string orderList[], double orderPrice[], int orderqty[]);
void orderAddLDLegal(string orderList[], double orderPrice[], int orderqty[]);
void orderProcess();
void printOrderList(string orderList[], int orderqty[]);
void orderDelete(string orderList[], int orderqty[], double orderPrice[]);
void orderUpdate(string orderList[], int orderqty[]);
void orderStatus(string orderList[], int orderqty[], double orderPrice[], int&);
void loadMenu();
void countTotalPrice(int orderqty[], double orderPrice[], double&, int);
bool inputValid(int, int);
void Payment(int&);
void printEDIT();
void printADD();
void printDELETE();
void printUPDATE();
void printURORDERS();
void printLoadingbar();
void printOrderSelection();
void printError();

void membership(int&);
void registerAcc(int&);
void forgetPassword(int&);
void updateDetail(Customer cus[], int&,int&);

void ending();
void animateText(const string&); //design

bool aLogout = false;
bool cusExit = false;

//global variable
int mc_num = 0, s_num = 0, b_num = 0, ld_num = 0;
MainCourse mc_item[100];
Salads s_item[100];
Beverage b_item[100];
LongDrink ld_item[100];

//Front page
int main()
{
	system("Color 0B"); //For decoration purpose
	int logInSelection;
	cout << "\t  __         ______        ______     __     ______     ______   ______     ______" << endl;
	cout << "\t /\\ \\       /\\  ___\\      /\\  == \\   /\\ \\   /\\  ___\\   /\\__  _\\ /\\  == \\   /\\  __ \\ " << endl;
	cout << "\t \\ \\ \\____  \\ \\  __\\      \\ \\  __<   \\ \\ \\  \\ \\___  \\  \\/_/\\ \\/ \\ \\  __<   \\ \\ \\/\\ \\ " << endl;
	cout << "\t  \\ \\_____\\  \\ \\_____\\     \\ \\_____\\  \\ \\_\\  \\/\\_____\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\ " << endl;
	cout << "\t   \\/_____/   \\/_____/      \\/_____/   \\/_/   \\/_____/     \\/_/   \\/_/ /_/   \\/_____/" << endl;
	cout << endl;

	animateText("\t\t\t\t~~~ Welcome to Le Bistro Restaurant ~~~");
	cout << endl;
	animateText("\t\t\t\t\t     Log in Page");
	animateText("\t\t\t\t\tPlease choose who you are: ");
	animateText("\t\t\t\t\t     1. Admin");
	animateText("\t\t\t\t\t     2. Customer");
	animateText("\t\t\t\t\t     3. Exit");
	cout << endl<<"\t\t\t\t\t     Answer: ";
	cin >> logInSelection;

	system("CLS");

	switch (logInSelection)
	{
	case 1:
		cout << "\t\t\t ______     _____     __    __     __     __   __        " << endl;
		cout << "\t\t\t/\\  __ \\   /\\  __-.  /\\ '-./  \\   /\\ \\   /\\ '-.\\ \\ " << endl;
		cout << "\t\t\t\\ \\  __ \\  \\ \\ \\/\\ \\ \\ \\ \\-./\\ \\  \\ \\ \\  \\ \\ \\-.  \\ " << endl;
		cout << "\t\t\t \\ \\_\\ \\_\\  \\ \\____-  \\ \\_\\ \\ \\_\\  \\ \\_\\  \\ \\_\\\\'\\_\\ " << endl;
		cout << "\t\t\t  \\/_/\\/_/   \\/____/   \\/_/  \\/_/   \\/_/   \\/_/ \\/_/ " << endl;
		admin();
		break;

	case 2:
		cout << " __    __     ______     __   __     __  __       _____     __     ______     ______   __         ______     __  __    " << endl;
		cout << "/\\ '-./ \\    /\\  ___\\   /\\ '-.\\ \\   /\\ \\/\\ \\     /\\  __-.  /\\ \\   /\\  ___\\   /\\  == \\ /\\ \\       /\\  __ \\   /\\ \\_\\ \\   " << endl;
		cout << "\\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\    \\ \\ \\/\\ \\ \\ \\ \\  \\ \\___  \\  \\ \\  _-/ \\ \\ \\____  \\ \\  __ \\  \\ \\____ \\  " << endl;
		cout << " \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\\'\\_\\  \\ \\_____\\    \\ \\____ - \\ \\_\\  \\/\\_____\\  \\ \\_\\    \\ \\_____\\  \\ \\_\\ \\_\\  \\/\\_____\\ " << endl;
		cout << "  \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/     \\/____/   \\/_/   \\/_____/   \\/_/     \\/_____/   \\/_/\\/_/   \\/_____/ " << endl;
		cout << endl << endl;
		printLoadingbar();
		system("CLS");
		customer();
		break;

	case 3:
		return 0;

	default:
		system("CLS");
		cout << "\t\t\t\t\tPLease try again!" << endl;
		cout << endl;
		system("pause");
		system("CLS");
		main();
	}
}

//Function to Display Design
void printLoadingbar() {
	double width = 50, totalProgress = 100, percentage, num;
	for (double i = 0; i <= totalProgress; ++i) {
		percentage = i / totalProgress;
		num = percentage * width;
		cout << setprecision(0) << "\t\t\t\t[";
		for (int i = 0; i < width; i++) {
			if (i < num) {
				cout << ">";
			}
			else {
				cout << " ";
			}
		}
		cout << "] " << int(percentage * 100) << "%" << flush;
		this_thread::sleep_for(chrono::milliseconds(30)); // Shorter sleep duration
		cout << "\r"; // Move cursor to the beginning of the line
	}
	cout << endl;
}

//Check in module for admin
void admin()
{
	string adminPassword1, adminPassword2;
	string adminUser;
	char opt, yesNo;
	string again;

	cout << endl;
	cout << "\t\t\t\t   Please enter your username: ";
	cin >> adminUser;

	if (adminUser == "ABCD" || adminUser == "abcd")
	{
		while (!aLogout) {
			cout << "\t\t\t\t   Please enter your password: ";
			cin >> adminPassword1;
			cout << "\t\t\t\t   Please reenter your password: ";
			cin >> adminPassword2;
			cout << endl;


			if (adminPassword1 == adminPassword2)
			{
				if (adminPassword1 == "1234")
				{
					aLogout = false;
					system("CLS");
					cout << "\t\t ______     ______     __   __       __     ______     __  __     ______    " << endl;
					cout << "\t\t/\\  == \\   /\\  __ \\   /\\ '-.\\ \\     /\\ \\   /\\  __ \\   /\\ \\/\\ \\   /\\  == \\ " << endl;
					cout << "\t\t\\ \\  __<   \\ \\ \\/\\ \\  \\ \\ \\-.  \\   _\\_\\ \\  \\ \\ \\/\\ \\  \\ \\ \\_\\ \\  \\ \\  __<  " << endl;
					cout << "\t\t \\ \\_____\\  \\ \\_____\\  \\ \\_\\\\'\\_\\ /\\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\ " << endl;
					cout << "\t\t  \\/_____/   \\/_____/   \\/_/ \\/_/ \\/_____/   \\/_____/   \\/_____/   \\/_/ /_/ " << endl;
					cout << endl;

					do {
						system("CLS");
						cout << right << setw(95) << "-------------------------------------------------------------------------------" << endl;
						cout << endl;
						cout << right << setw(82) << "Choose the category that you want to do something!" << endl;
						cout << endl;
						cout << right << setw(95) << "-------------------------------------------------------------------------------" << endl;
						cout << left << setw(15) << "\t\t\t\t\t\ta. Salads" << endl;
						cout << left << setw(15) << "\t\t\t\t\t\tb. MainCourses" << endl;
						cout << left << setw(15) << "\t\t\t\t\t\tc. Beverages" << endl;
						cout << left << setw(15) << "\t\t\t\t\t\td. LongDrinks" << endl;
						cout << endl;
						cout << right << setw(60) << "\tPlease enter your choice: ";
						cin >> opt;

						if (opt == 'a' || opt == 'A') {
							system("CLS");
							customerDisplaySalad();
							cout << endl;
							cout << "-----------------------------------------------------------------------------------------------------------" << endl;
							cout << "Do you want to ADD new item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								addSaladMenu();

							cout << endl;
							cout << "Do you want to DELETE item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								deleteSalad();

							cout << endl;
							cout << "Do you want to EDIT item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								editSalad();
						}

						// do something at mainCourse
						else if (opt == 'b' || opt == 'B') {
							system("CLS");
							customerDisplayMain();
							cout << endl;
							cout << "-----------------------------------------------------------------------------------------------------------" << endl;
							cout << "Do you want to ADD new item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								addMainMenu();

							cout << endl;
							cout << "Do you want to DELETE item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								deleteMain();

							cout << endl;
							cout << "Do you want to EDIT item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								editMain();
						}
						// do something at beverages
						else if (opt == 'c' || opt == 'C') {
							system("CLS");
							customerDisplayBeverages();
							cout << endl;
							cout << "-----------------------------------------------------------------------------------------------------------" << endl;
							cout << "Do you want to ADD new item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								addBeverageMenu();

							cout << endl;
							cout << "Do you want to DELETE item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								deleteBeverage();

							cout << endl;
							cout << "Do you want to EDIT item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								editBeverage();
						}
						// do something at longDrinks
						else if (opt == 'd' || opt == 'D') {
							system("CLS");
							customerDisplayLongDrink();
							cout << endl;
							cout << "-----------------------------------------------------------------------------------------------------------" << endl;
							cout << "Do you want to ADD new item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								addLongMenu();

							cout << endl;
							cout << "Do you want to DELETE item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								deleteLongDrink();

							cout << endl;
							cout << "Do you want to EDIT item in this category?  ( Y = Yes ) : ";
							cin >> yesNo;
							if (yesNo == 'y' || yesNo == 'Y')
								editLongDrink();
						}
						else {
							cout << endl;
							cout << "\n" << right << setw(60) << "\tError in entering your choice! " << endl;
							system("pause");
							system("CLS");
						}
							
						cout << "\nDo you want to look another category?  ( Y = Yes ) : ";
						cin >> again;
						system("CLS");
					} while (again == "Y" || again == "y");
					main();
					return;
				}
			}
			else
			{
				cout << "\t\t\t\t\t  Invalid Password\n";
				cout << endl;
			}
		}
	}
	else
	{
		cout << "\n\t\t\t\t\t  Please try again!" << endl;
		admin();
	}

}

//Check out module for admin
void adminLogout()
{
	aLogout = true;
	cout << "\t\t\t\t!-----------------------------------------------!" << endl;
	cout << "\t\t\t\t\tLogged Out Successfully! Au revoir!" << endl;
	cout << "\t\t\t\t!-----------------------------------------------!" << endl;
	system("pause");
	system("CLS");
	main();
}

void customer()
{
	char cont1;
	customerDisplaySalad();
	customerDisplayMain();
	customerDisplayBeverages();
	customerDisplayLongDrink();
	while (!cusExit) {
		cout << "\n Enter 'Y' to proceed to order, 'E' to exit: ";
		cin >> cont1;
		if (cont1 == 'Y' || cont1 == 'y')
		{
			cusExit = false;
			system("CLS");
			orderProcess();
		}
		else if (cont1 == 'E' || cont1 == 'e')
		{
			cusExit = true;
			system("CLS");
			main();
		}
		else
			cout << " Please try again!" << endl;
	}
}

//Display Salad Menu
void customerDisplaySalad() {

	int idxSalads = 0;
	int numSalads = 1;
	string saladsName[20];
	string saladsDescript[20];
	string saladsPrice[20];

	ifstream saladsFile;
	saladsFile.open("salads.txt");
	if (saladsFile.fail())
		cout << "Unable to open salads.txt!" << endl;
	else {
		cout << "\t\t\t !-----------------------------------------------!" << endl;
		cout << "\t\t\t\t\t       Salad" << endl;
		cout << "\t\t\t !-----------------------------------------------!" << endl;
		while (saladsFile.peek() == '\n')
			saladsFile.ignore();
		while (!saladsFile.eof()) {
			getline(saladsFile, saladsName[idxSalads]);
			getline(saladsFile, saladsDescript[idxSalads]);
			getline(saladsFile, saladsPrice[idxSalads]);

			cout << right << setw(4) << numSalads << ". " << left << setw(80) << saladsName[idxSalads] << " ~~~ RM " << fixed << setprecision(2) << saladsPrice[idxSalads] << " ~~~" << endl;
			cout << "      - " << saladsDescript[idxSalads] << "\n" << endl;
			numSalads++, idxSalads++;
		}
	}
	saladsFile.close();
}

//Display Main Course Menu
void customerDisplayMain()
{
	int idxMain = 0;
	int numMain = 1;
	string mainName[20];
	string mainDescript[20];
	string mainPrice[20];

	ifstream mainCourseFile;
	mainCourseFile.open("mainCourse.txt");
	if (mainCourseFile.fail())
		cout << "Unable to open mainCourse.txt! " << endl;
	else {
		cout << "\n\t\t\t !-----------------------------------------------!" << endl;
		cout << "\t\t\t\t\t    Main Course" << endl;
		cout << "\t\t\t !-----------------------------------------------!" << endl;
		while (mainCourseFile.peek() == '\n')
			mainCourseFile.ignore();
		while (!mainCourseFile.eof()) {
			getline(mainCourseFile, mainName[idxMain]);
			getline(mainCourseFile, mainDescript[idxMain]);
			getline(mainCourseFile, mainPrice[idxMain]);

			cout << right << setw(4) << numMain << ". " << left << setw(80) << mainName[idxMain] << " ~~~ RM " << fixed << setprecision(2) << mainPrice[idxMain] << " ~~~" << endl;
			cout << "      - " << mainDescript[idxMain] << "\n" << endl;

			numMain++, idxMain++;
		}
	}
	mainCourseFile.close();
}

//Display Beverages Menu
void customerDisplayBeverages()
{
	int idxBeverages = 0;
	int numBeverages = 1;
	string typeBeverages[2] = { "Juice","Smoothie" };
	string sizeBeverages[2] = { "Venti(M)","Grande(L)" };
	string fruitName[20];
	string priceBeverages[20][4];

	ifstream beveragesFile;
	beveragesFile.open("beverages.txt");
	if (beveragesFile.fail())
		cout << "Unable to open beverages.txt! " << endl;
	else {
		cout << "\t        ||" << endl;
		cout << "\t,-'''```||`-." << endl;
		cout << "\t(       ||   )" << endl;
		cout << "\t|`-...__,..-'|\t !-----------------------------------------------!" << endl;
		cout << "\t|     __||   |\t\t\t    Beverages  " << endl;
		cout << "\t|,-''_~ ||`-.|   ** FRUITSSS: A new way to take your Vitamins! **\t" << endl;
		cout << "\t|`-.._/_,..-'|\t !-----------------------------------------------!\t" << endl;
		cout << "\t| -' ~~ || -.|" << endl;
		cout << "\t(   ~ ~   ~~ )" << endl;
		cout << "\t `-..___,..-'" << endl<<endl;
		while (beveragesFile.peek() == '\n')
			beveragesFile.ignore();
		while (!beveragesFile.eof()) {
			getline(beveragesFile, fruitName[idxBeverages]);
			beveragesFile >> priceBeverages[idxBeverages][0] >> priceBeverages[idxBeverages][1] >> priceBeverages[idxBeverages][2] >> priceBeverages[idxBeverages][3];

			cout << right << setw(4) << numBeverages << ". " << left << setw(25) << fruitName[idxBeverages];
			cout << "\t\t   " << typeBeverages[0] << "\t\t\t\t " << typeBeverages[1] << endl;
			cout << right << setw(40) << sizeBeverages[0] << "\t  " << sizeBeverages[1] << "\t\t" << sizeBeverages[0] << "\t  " << sizeBeverages[1] << endl;
			cout << right << setw(35) << "~~ RM " << priceBeverages[idxBeverages][0] << " ~~" << setw(11) << "~~ RM " << priceBeverages[idxBeverages][1] << " ~~" << setw(15) << "~~ RM " << priceBeverages[idxBeverages][2] << " ~~" << setw(11) << "~~ RM " << priceBeverages[idxBeverages][3] << " ~~" << endl;
			cout << endl;

			numBeverages++, idxBeverages++;
			beveragesFile.ignore();
		}
	}
	beveragesFile.close();
}

//Display Long Drink Menu
void customerDisplayLongDrink()
{
	int idxLongDrinks = 0;
	int numlongDrinks = 1;
	string longDrinksName[20];
	string longDrinksPrice[20][2];
	string longDrinksSize[2] = { "Venti(M)","Grande(L)" };

	ifstream longDrinksFile;
	longDrinksFile.open("longDrinks.txt");
	if (longDrinksFile.fail())
		cout << "Unable to open longDrink.txt!" << endl;
	else {
		cout << "\t\t\t\t\t\t\t\t\t       ." << endl;
		cout << "\t\t\t\t\t\t\t\t\t      ." << endl;
		cout << "\t\t\t\t\t\t\t\t\t     . ." << endl;
		cout << "\t\t\t !-----------------------------------------------!    ..." << endl;
		cout << "\t\t\t\t\t    Long Drinks  \t\t    \\~~~~~/" << endl;
		cout << "\t\t\t\t        ** Cheer you Up! **\t\t     \\   /" << endl;
		cout << "\t\t\t !-----------------------------------------------!    \\ /" << endl;
		cout << "\t\t\t\t\t\t\t\t\t       V" << endl;
		cout << "\t\t\t\t\t\t\t\t\t       |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t      ---" << endl;

		while (longDrinksFile.peek() == '\n')
			longDrinksFile.ignore();
		while (!longDrinksFile.eof()) {
			getline(longDrinksFile, longDrinksName[idxLongDrinks]);
			longDrinksFile >> longDrinksPrice[idxLongDrinks][0] >> longDrinksPrice[idxLongDrinks][1];

			cout << right << setw(4) << numlongDrinks << ". " << left << setw(30) << longDrinksName[idxLongDrinks];
			cout << "   " << longDrinksSize[0] << "\t\t     " << longDrinksSize[1] << endl;
			cout << right << setw(42) << "~~~ RM " << longDrinksPrice[idxLongDrinks][0] << " ~~~" << "\t ~~~ RM " << longDrinksPrice[idxLongDrinks][1] << " ~~~" << endl;
			cout << endl;

			idxLongDrinks++, numlongDrinks++;
			longDrinksFile.ignore();
		}
	}
	longDrinksFile.close();
}

bool isEmpty() {
	ifstream myFile;
	myFile.open("salads.txt", ios::ate);
	myFile.open("mainCourse.txt", ios::ate);
	myFile.open("beverages.txt", ios::ate);
	myFile.open("longDrinks.txt", ios::ate);
	myFile.open("temp.txt", ios::ate);

	if (myFile.tellg() == 0)
		return true;
	else
		return false;
	myFile.close();
}

//Admin Part
//Edit Salad Menu
void editSalad() {
	int select;
	string newName, editDescript, editPrice, response;

	do {
		system("CLS");
		customerDisplaySalad();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printEDIT();
		cout << endl;
		cout << "Enter the index number of item you want to edit: ";
		cin >> select;

		int idx = 0;
		int num = 0;
		string name[20];
		string descript[20];
		string price[20];
		ifstream myFile;
		myFile.open("salads.txt");
		if (myFile.fail())
			cout << "Unable to open the text file! " << endl;
		else {
			while (myFile.peek() == '\n') {
				myFile.ignore();
				num = 0;
			}
			while (!myFile.eof()) {
				getline(myFile, name[idx]);
				getline(myFile, descript[idx]);
				getline(myFile, price[idx]);
				num++, idx++;
			}
		}
		myFile.close();

		string editName, editDescript, editPrice;
		editName = name[select - 1];
		editDescript = descript[select - 1];
		editPrice = price[select - 1];
		cout << endl;
		//Prompt the user for new information.
		cout << "Enter a new name: ";
		cin.ignore(); // Consume the newline character.
		getline(cin, name[select - 1]);

		cout << "Enter a new description: ";
		getline(cin, descript[select - 1]);

		cout << "Enter a new price in 2 decimal places: RM ";
		cin >> price[select - 1];

		ofstream newFile;
		newFile.open("salads.txt");
		if (!newFile.is_open()) {
			cout << "Unable to open the text file!." << endl;
			return;
		}

		for (int i = 0; i < num; i++) {
			newFile << name[i] << endl << descript[i] << endl << price[i];
			if (i < num - 1)
				newFile << '\n';
		}
		newFile.close();

		cout << "\nDo you want to EDIT more item? (Y - Yes) :";
		cin >> response;
		cout << endl;

	} while (response == "y" || response == "Y");
	return;
}

//Edit Main Course Menu
void editMain() {
	int select;
	string newName, editDescript, editPrice, response;

	do {
		system("CLS");
		customerDisplayMain();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printEDIT();
		cout << endl;
		cout << "Enter the index number of item you want to edit: ";
		cin >> select;

		int idx = 0;
		int num = 0;
		string name[20];
		string descript[20];
		string price[20];
		ifstream myFile;
		myFile.open("mainCourse.txt");
		if (myFile.fail())
			cout << "Unable to open the text file!" << endl;
		else {
			while (myFile.peek() == '\n') {
				myFile.ignore();
				num = 0;
			}
			while (!myFile.eof()) {
				getline(myFile, name[idx]);
				getline(myFile, descript[idx]);
				getline(myFile, price[idx]);
				num++, idx++;
			}
		}
		myFile.close();

		string editName, editDescript, editPrice;
		editName = name[select - 1];
		editDescript = descript[select - 1];
		editPrice = price[select - 1];
		cout << endl;
		//Prompt the user for new information.
		cout << "Enter a new name: ";
		cin.ignore(); // Consume the newline character.
		getline(cin, name[select - 1]);

		cout << "Enter a new description: ";
		getline(cin, descript[select - 1]);

		cout << "Enter a new price in 2 decimal places: RM ";
		cin >> price[select - 1];

		ofstream newFile;
		newFile.open("mainCourse.txt");
		if (!newFile.is_open()) {
			cout << "Unable to open the text file!" << endl;
			return;
		}

		for (int i = 0; i < num; i++) {
			newFile << name[i] << endl << descript[i] << endl << price[i];
			if (i < num - 1)
				newFile << '\n';
		}
		newFile.close();

		cout << "\nDo you want to EDIT more item ? (Y - Yes) :";
		cin >> response;
		cout << endl;

	} while (response == "y" || response == "Y");
	return;
}

//Edit Beverage Menu
void editBeverage() {
	int select;
	string newName, response;
	string editName, editPrice1, editPrice2, editPrice3, editPrice4;

	do {
		system("CLS");
		customerDisplayBeverages();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printEDIT();
		cout << endl;
		cout << "Enter the index number of item you want to edit: ";
		cin >> select;

		int idx = 0;
		int num = 0;
		string name[20];
		string price[20][4];
		ifstream myFile;
		myFile.open("beverages.txt");
		if (myFile.fail())
			cout << "Unable to open the text file!" << endl;
		else {
			while (myFile.peek() == '\n') {
				myFile.ignore();
				num = 0;
			}
			while (!myFile.eof()) {
				getline(myFile, name[idx]);
				myFile >> price[idx][0] >> price[idx][1] >> price[idx][2] >> price[idx][3];
				num++, idx++;
				myFile.ignore();
			}
		}
		myFile.close();
		editName = name[select - 1];
		editPrice1 = price[select - 1][0];
		editPrice2 = price[select - 1][1];
		editPrice3 = price[select - 1][2];
		editPrice4 = price[select - 1][3];
		cout << endl;
		//Prompt the user for new information.
		cout << "Enter a new name: ";
		cin.ignore(); // Consume the newline character.
		getline(cin, name[select - 1]);
		cout << "Enter a new price for juice Venti (2 decimal places) : RM ";
		cin >> price[select - 1][0];
		cout << "Enter a new price for juice Grande (2 decimal places) : RM ";
		cin >> price[select - 1][1];
		cout << "Enter a new price for Smoothie Venti (2 decimal places) : RM ";
		cin >> price[select - 1][2];
		cout << "Enter a new price for Smoothie Grande (2 decimal places) : RM ";
		cin >> price[select - 1][3];

		ofstream newFile;
		newFile.open("beverages.txt");
		if (!newFile.is_open()) {
			cout << "Unable to open the text file!" << endl;
			return;
		}

		for (int i = 0; i < num; i++) {
			newFile << name[i] << endl << price[i][0] << " " << price[i][1] << " " << price[i][2] << " " << price[i][3];
			if (i < num - 1)
				newFile << '\n';
		}
		newFile.close();

		cout << "\nDo you want to EDIT more item ? (Y - Yes) :";
		cin >> response;
		cout << endl;

	} while (response == "y" || response == "Y");
	return;
}

//Edit Long Drink Menu
void editLongDrink() {
	int select;
	string newName, response;
	string editName, editPrice1, editPrice2;

	do {
		system("CLS");
		customerDisplayLongDrink();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printEDIT();
		cout << endl;
		cout << "Enter the index number of item you want to edit: ";
		cin >> select;

		int idx = 0;
		int num = 0;
		string name[20];
		string price[20][2];
		ifstream myFile;
		myFile.open("longDrinks.txt");
		if (myFile.fail())
			cout << "Unable to open the text file!" << endl;
		else {
			while (myFile.peek() == '\n') {
				myFile.ignore();
				num = 0;
			}
			while (!myFile.eof()) {
				getline(myFile, name[idx]);
				myFile >> price[idx][0] >> price[idx][1];
				num++, idx++;
				myFile.ignore();
			}
		}
		myFile.close();
		editName = name[select - 1];
		editPrice1 = price[select - 1][0];
		editPrice2 = price[select - 1][1];
		cout << endl;
		cout << "Enter a new name: ";
		cin.ignore();
		getline(cin, name[select - 1]);
		cout << "Enter a new price for Venti (2 decimal places) : RM ";
		cin >> price[select - 1][0];
		cout << "Enter a new price for Grande (2 decimal places) : RM ";
		cin >> price[select - 1][1];

		ofstream newFile;
		newFile.open("longDrinks.txt");
		if (!newFile.is_open()) {
			cout << "Unable to open the text file!" << endl;
			return;
		}

		for (int i = 0; i < num; i++) {
			newFile << name[i] << endl << price[i][0] << " " << price[i][1];
			if (i < num - 1)
				newFile << '\n';
		}
		newFile.close();

		cout << "\nDo you want to EDIT more item ? (Y - Yes) :";
		cin >> response;
		cout << endl;

	} while (response == "y" || response == "Y");
	return;
}

//Add Salad Menu
void addSaladMenu() {
	string newSaladName, newSaladDescrip, newSaladPrice, response;
	ofstream inputNewSalad;
	inputNewSalad.open("salads.txt", ios::app);

	if (!inputNewSalad.is_open()) {
		cout << "Unable to open the text file!" << endl;
		return;
	}

	do {
		system("CLS");
		customerDisplaySalad();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printADD();
		cout << endl;
		cout << "Please enter the name of new item: ";
		cin.ignore();  //Clear any residual characters in the input buffer
		getline(cin, newSaladName);
		if (isEmpty())
			inputNewSalad << newSaladName << endl;
		else
			inputNewSalad << endl << newSaladName;

		cout << "Please enter the description of the new item: ";
		getline(cin, newSaladDescrip);
		inputNewSalad << endl << newSaladDescrip;

		cout << "Please enter the price of the new item (2 decimal places): RM ";
		cin >> newSaladPrice;
		cin.ignore();
		inputNewSalad << endl << newSaladPrice;
		cout << endl;

		cout << "Do you want to ADD more item? (Y - Yes) : ";
		cin >> response;
		//cout << endl;

	} while (response == "Y" || response == "y");

	inputNewSalad.close();
	return;
}

//Add Main Course Menu
void addMainMenu() {
	string newMainName, newMainDescrip, newMainPrice, response;

	ofstream inputNewMain;
	inputNewMain.open("mainCourse.txt", ios::app);

	if (!inputNewMain.is_open()) {
		cout << "Unable to open the text file!" << endl;
		return;
	}

	do {
		system("CLS");
		customerDisplayMain();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printADD();
		cout << endl;
		cout << "Please enter the name of new item: ";
		cin.ignore();
		getline(cin, newMainName);
		if (isEmpty())
			inputNewMain << newMainName << endl;
		else
			inputNewMain << endl << newMainName;

		cout << "Please enter the description of the new item : ";
		getline(cin, newMainDescrip);
		inputNewMain << endl << newMainDescrip;

		cout << "Please enter the price of the new item (2 decimal places): RM ";
		cin >> newMainPrice;
		cin.ignore();
		cout << endl;
		inputNewMain << endl << newMainPrice;

		cout << "Do you want to ADD more item? (Y - Yes) : ";
		cin >> response;

	} while (response == "Y" || response == "y");

	inputNewMain.close();
	return;
}

//Add Beverage Menu
void addBeverageMenu() {
	string newBeverageName, newJuiceVentiPrice, newJuiceGrandePrice, newSmooVentiPrice, newSmooGrandePrice, response;

	ofstream inputNewBeverage;
	inputNewBeverage.open("beverages.txt", ios::app);

	if (!inputNewBeverage.is_open()) {
		cout << "Unable to open the text file!" << endl;
		return;
	}
	do {
		system("CLS");
		customerDisplayBeverages();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printADD();
		cout << endl;
		cout << "Please enter the name of new item: ";
		cin.ignore();
		getline(cin, newBeverageName);
		if (isEmpty())
			inputNewBeverage << newBeverageName << endl;
		else
			inputNewBeverage << endl << newBeverageName;

		cout << "Please enter the information below with 2 decimal places <3" << endl;
		cout << "Please enter the price of JUICE (Venti) : RM ";
		cin >> newJuiceVentiPrice;
		cin.ignore();

		cout << "Please enter the price of JUICE (Grande) : RM ";
		cin >> newJuiceGrandePrice;
		cin.ignore();

		cout << "Please enter the price of SMOOTHIE (Venti) : RM ";
		cin >> newSmooVentiPrice;
		cin.ignore();

		cout << "Please enter the price of SMOOTHIE (Grande) : RM ";
		cin >> newSmooGrandePrice;
		cout << endl;
		cin.ignore();

		inputNewBeverage << endl << newJuiceVentiPrice << " " << newJuiceGrandePrice << " " << newSmooVentiPrice << " " << newSmooGrandePrice;

		cout << "Do you want to ADD another new item in Beverages ? ( Y - Yes ) : ";
		cin >> response;

	} while (response == "Y" || response == "y");

	inputNewBeverage.close();
	return;
}

//Add Long Drink Menu
void addLongMenu() {
	string newLongName, newVentiPrice, newGrandePrice, response;

	ofstream inputNewLongDrink;
	inputNewLongDrink.open("longDrinks.txt", ios::app);

	if (!inputNewLongDrink.is_open()) {
		cout << "Unable to open the text file!" << endl;
		return;
	}
	do {
		system("CLS");
		customerDisplayLongDrink();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printADD();
		cout << endl;
		cout << "Please enter the the name of new item: ";
		cin.ignore();
		getline(cin, newLongName);
		if (isEmpty())
			inputNewLongDrink << newLongName << endl;
		else
			inputNewLongDrink << endl << newLongName;

		cout << "Please enter the information below with 2 decimal places <3" << endl;
		cout << "Please enter the price of new item (Venti) : RM ";
		cin >> newVentiPrice;
		cin.ignore();

		cout << "Please enter the price of new item (Grande) : RM ";
		cin >> newGrandePrice;
		cout << endl;
		cin.ignore();

		inputNewLongDrink << endl << newVentiPrice << " " << newGrandePrice;

		cout << "Do you want to ADD more item? ( Y = Yes ) : ";
		cin >> response;

	} while (response == "Y" || response == "y");

	inputNewLongDrink.close();
	return;
}

//Delete Salad Menu
void deleteSalad() {
	int select;
	string deleteName, deleteDescript, deletePrice, response;

	do {
		system("CLS");
		customerDisplaySalad();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printDELETE();
		cout << endl;
		cout << "Enter the index number of item you want to delete: ";
		cin >> select;

		int idxSalads = 0;
		int numSalads = 1;
		string saladsName[20];
		string saladsDescript[20];
		string saladsPrice[20];

		ifstream saladsFile;
		saladsFile.open("salads.txt");
		if (saladsFile.fail()){
			cout << "Unable to open the text file!" << endl;
			return;
			}
		else {
			while (saladsFile.peek() == '\n') {
				saladsFile.ignore();
				numSalads = 0;
			}
			while (!saladsFile.eof()) {
				getline(saladsFile, saladsName[idxSalads]);
				getline(saladsFile, saladsDescript[idxSalads]);
				getline(saladsFile, saladsPrice[idxSalads]);
				numSalads++, idxSalads++;
			}
		}
		saladsFile.close();

		deleteName = saladsName[select - 1];
		deleteDescript = saladsDescript[select - 1];
		deletePrice = saladsPrice[select - 1];

		cout << "\nThe item you want to delete is: " << endl;
		cout << "Name: "<<deleteName << endl;
		cout << "Description: "<<deleteDescript << endl;
		cout << "Price: RM "<<deletePrice << endl;

		ofstream newFile;
		newFile.open("salads.txt");
		if (!newFile.is_open()) {
			cout << "Unable to open the text file!" << endl;
			return;
		}
		numSalads--;
		for (int i = 0; i < numSalads; i++) {
			if (saladsName[i] == deleteName)
				continue;
			newFile << saladsName[i] << endl << saladsDescript[i] << endl << saladsPrice[i];
			if (i < numSalads - 2)
				newFile << '\n';
		}
		newFile.close();


		newFile.close();
		cout << endl;
		cout << "Do you want to DELETE more item ? (Y = Yes) :";
		cin >> response;

	} while (response == "y" || response == "Y");
	return;
}

//Delete Main Course Menu 
void deleteMain() {
	int select;
	string deleteName, deleteDescript, deletePrice, response;
	do {
		system("CLS");
		customerDisplayMain();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printDELETE();
		cout << endl;
		cout << "Enter the index number of item you want to delete: ";
		cin >> select;

		int idx = 0;
		int num = 1;
		string name[20];
		string descript[20];
		string price[20];

		ifstream myFile;
		myFile.open("mainCourse.txt");
		if (myFile.fail())
			cout << "Unable to open the text file!" << endl;
		else {
			while (myFile.peek() == '\n') {
				myFile.ignore();
				num = 0;
			}
			while (!myFile.eof()) {
				getline(myFile, name[idx]);
				getline(myFile, descript[idx]);
				getline(myFile, price[idx]);
				num++, idx++;
			}
		}
		myFile.close();

		deleteName = name[select - 1];
		deleteDescript = descript[select - 1];
		deletePrice = price[select - 1];
		cout << "\nThe item you want to delete is: " << endl;
		cout << "Name: " << deleteName << endl;
		cout << "Description: " << deleteDescript << endl;
		cout << "Price: RM " << deletePrice << endl;

		ofstream newFile;
		newFile.open("mainCourse.txt");
		if (!newFile.is_open()) {
			cout << "Unable to open the text file!" << endl;
			return;
		}
		num--;
		for (int i = 0; i < num; i++) {
			if (name[i] == deleteName)
				continue;
			newFile << name[i] << endl << descript[i] << endl << price[i];
			if (i < num - 2)
				newFile << '\n';
		}
		newFile.close();

		cout << endl;
		cout << "Do you want to DELETE more item ? (Y = Yes) :";
		cin >> response;

	} while (response == "y" || response == "Y");
	return;
}

//Delete Beverage Menu
void deleteBeverage() {
	int select;
	string deleteName, response;
	string deletePrice1, deletePrice2, deletePrice3, deletePrice4;
	do {
		system("CLS");
		customerDisplayBeverages();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printDELETE();
		cout << endl;
		cout << "Enter the index number of item you want to delete:";
		cin >> select;
		int count = 0;
		int idx = 0;
		int num = 0;
		string name[20];
		string price[20][4];

		ifstream myFile;
		myFile.open("beverages.txt");
		if (myFile.fail())
			cout << "Unable to open the text file!" << endl;
		else {
			while (myFile.peek() == '\n') {
				myFile.ignore();
				num = 0;
			}
			while (!myFile.eof()) {
				getline(myFile, name[idx]);
				myFile >> price[idx][0] >> price[idx][1] >> price[idx][2] >> price[idx][3];
				num++, idx++;
				myFile.ignore();
			}
		}
		myFile.close();
		deleteName = name[select - 1];
		deletePrice1 = price[select - 1][0];
		deletePrice2 = price[select - 1][1];
		deletePrice3 = price[select - 1][2];
		deletePrice4 = price[select - 1][3];
		cout << "\nThe item you want to delete is: " << endl;
		cout << "Number: " << select << endl;
		cout << "Name: " << deleteName << endl;
		cout << "Juice (Venti): RM " << deletePrice1 << endl<<"Juice (Grande): RM " << deletePrice2 << endl;
		cout << "Smoothie (Venti): RM " << deletePrice3 << endl<<"Smoothie (Grande): RM " << deletePrice4 << endl;

		ofstream newFile;
		newFile.open("beverages.txt");
		if (!newFile.is_open()) {
			cout << "Unable to open the text file!" << endl;
			return;
		}

		for (int i = 0; i < num; i++) {
			if (name[i] == deleteName) {
				continue;
				i++;
			}
			count++;
			newFile << name[i] << endl;

			for (int j = 0; j < 4; j++) {
				newFile << price[i][j];
				if (j < 3)
				{
					newFile << " ";
				}

			}
			if (count < num - 1) {
				newFile << endl;
			}
		}
		newFile.close();

		newFile.close();

		cout << endl;
		cout << "Do you want to DELETE more item ? (Y = Yes) :";
		cin >> response;

	} while (response == "y" || response == "Y");
	return;
}

//Delete Long Drink Menu
void deleteLongDrink() {
	int select;
	string deleteName, response;
	string deletePrice1, deletePrice2;
	do {
		system("CLS");
		customerDisplayLongDrink();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		printDELETE();
		cout << endl;
		cout << "Enter the index number of item you want to delete: ";
		cin >> select;
		int count = 0;
		int idx = 0;
		int num = 0;
		string name[20];
		string price[20][2];

		ifstream myFile;
		myFile.open("longDrinks.txt");
		if (myFile.fail())
			cout << "Unable to open the text file!" << endl;
		else {
			while (myFile.peek() == '\n') {
				myFile.ignore();
				num = 0;
			}
			while (!myFile.eof()) {
				getline(myFile, name[idx]);
				myFile >> price[idx][0] >> price[idx][1];
				num++, idx++;
				myFile.ignore();
			}
		}
		myFile.close();
		deleteName = name[select - 1];
		deletePrice1 = price[select - 1][0];
		deletePrice2 = price[select - 1][1];
		cout << "\nThe item you want to delete is: " << endl;
		cout << "Name: "<<deleteName << endl;
		cout << "Price for Venti(M): RM " << deletePrice1 << endl;
		cout<<"Price for Grande(L): RM " << deletePrice2 << endl;

		ofstream newFile;
		newFile.open("longDrinks.txt");
		if (!newFile.is_open()) {
			cout << "Unable to open the text file!" << endl;
			return;
		}

		for (int i = 0; i < num; i++) {
			if (name[i] == deleteName) {
				continue;
				i++;
			}
			count++;
			newFile << name[i] << endl;

			for (int j = 0; j < 2; j++) {
				newFile << price[i][j];
				if (j < 1)
				{
					newFile << " ";
				}

			}
			if (count < num - 1) {
				newFile << endl;
			}
		}

		cout << endl;
		cout << "Do you want to DELETE more item ? (Y = Yes) :";
		cin >> response;

	} while (response == "y" || response == "Y");
	return;
}

//Customer Part
//Order Process
void orderProcess() {
	int selection;
	string orderList[100] = { "" };
	double orderPrice[100] = { 0 };
	int orderqty[100] = { 0 };
	loadMenu();
	do {
		printURORDERS();
		printOrderSelection();
		cin >> selection;
		switch (selection)
		{
		case 1:
			system("CLS");
			orderAdd(orderList, orderPrice, orderqty);
			break;
		case 2:
			system("CLS");
			orderDelete(orderList, orderqty, orderPrice);
			break;
		case 3:
			system("CLS");
			orderUpdate(orderList, orderqty);
			break;
		case 4:
			system("CLS");
			orderStatus(orderList, orderqty, orderPrice, selection);
			break;
		case 5:
			system("CLS");
			main();
			break;
		default:
			printError();
			system("CLS");
		}

	} while (selection != 5);
}

//Load Menu
void loadMenu() {
	string desc;
	ifstream inFile;
	inFile.open("mainCourse.txt");
	if (inFile.fail())
		cout << "\t\t\t\t\tUnable to open mainCourse.txt file!" << endl;
	else {
		while (!inFile.eof()) {
			mc_num++;
			getline(inFile, mc_item[mc_num - 1].mc_name);
			getline(inFile, desc);
			inFile >> mc_item[mc_num - 1].mc_price;
			inFile.ignore();
		}
	}
	inFile.close();

	inFile.open("salads.txt");
	if (inFile.fail())
		cout << "\t\t\t\t\tUnable to open salads.txt file!" << endl;
	else {
		while (!inFile.eof()) {
			s_num++;
			getline(inFile, s_item[s_num - 1].s_name);
			getline(inFile, desc);
			inFile >> s_item[s_num - 1].s_price;
			inFile.ignore();
		}
	}
	inFile.close();

	inFile.open("beverages.txt");
	if (inFile.fail())
		cout << "\t\t\t\t\tUnable to open beverages.txt file!" << endl;
	else {
		while (!inFile.eof()) {
			b_num++;
			getline(inFile, b_item[b_num - 1].b_name);
			inFile >> b_item[b_num - 1].b_price[0][0] >> b_item[b_num - 1].b_price[0][1] >> b_item[b_num - 1].b_price[1][0] >> b_item[b_num - 1].b_price[1][1];
			inFile.ignore();
		}
	}
	inFile.close();

	inFile.open("longDrinks.txt");
	if (inFile.fail())
		cout << "\t\t\t\t\tUnable to open longDrinks.txt file!" << endl;
	else {
		while (!inFile.eof()) {
			ld_num++;
			getline(inFile, ld_item[ld_num - 1].ld_name);
			inFile >> ld_item[ld_num - 1].ld_price[0] >> ld_item[ld_num - 1].ld_price[1];
			inFile.ignore();
		}
	}
	inFile.close();
}

//Add Order
void orderAdd(string orderList[], double orderPrice[], int orderqty[]) {
	int slt1;
	do {
		printADD();
		cout << endl;
		printOrderList(orderList, orderqty);
		
		cout << "\t\t\t __| |____________________________________________| |__" << endl;
		cout << "\t\t\t(__   ____________________________________________   __)" << endl;
		cout << "\t\t\t   | |            Please Select One               | |" << endl;
		cout << "\t\t\t   | |              1. Salad                      | |" << endl;
		cout << "\t\t\t   | |              2. Main Course                | |" << endl;
		cout << "\t\t\t   | |              3. Beverage                   | |" << endl;
		cout << "\t\t\t   | |              4. Long Drink                 | |" << endl;
		cout << "\t\t\t   | |            Enter 0 to proceed              | |" << endl;
		cout << "\t\t\t __| |____________________________________________| |__" << endl;
		cout << "\t\t\t(__   ____________________________________________   __)" << endl;
		cout << "\t\t\t   | |                                            | |" << endl;

		cout << endl;
		cout << "\t\t\t\t\tAnswer: ";
		cin >> slt1;
		cout << endl;
		cout << "  ----------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;

		switch (slt1)
		{
		case 0:
			break;
		case 1:
			orderAddSalad(orderList, orderPrice, orderqty);
			break;

		case 2:
			orderAddMC(orderList, orderPrice, orderqty);
			break;

		case 3:
			orderAddBeverage(orderList, orderPrice, orderqty);
			break;

		case 4:
			orderAddLDLegal(orderList, orderPrice, orderqty);
			break;
		default:
			printError();
			system("CLS");
			orderProcess();
		}
		system("CLS");

	} while (slt1 != 0);
}

//Add Salad Order
void orderAddSalad(string orderList[], double orderPrice[], int orderqty[]) {
	int select1, quantity;
	for (int i = 0; i < s_num; i++)
		cout << "\t\t\t\t\t " << i + 1 << ". " << s_item[i].s_name << endl;

	cout << "\t\t\t\t\tPlease choose one: ";
	cin >> select1;
	if (inputValid(select1, s_num)) {
		cout << "\t\t\t\t\tQuantity: ";
		cin >> quantity;
		if (quantity < 1) {
			cout << "\t\t\t\t\tPlease enter value more than 0" << endl;
			cout << "\t\t\t\t\t";
			system("PAUSE");
		}
		else {
			for (int i = 0; i < 100; i++) {
				if (orderList[i] == "") {
					orderList[i] = s_item[select1 - 1].s_name;
					orderqty[i] = quantity;
					orderPrice[i] = s_item[select1 - 1].s_price;
					break;
				}
			}
		}
	}
	else
		printError();
}

//Add Main Course Order
void orderAddMC(string orderList[], double orderPrice[], int orderqty[]) {
	int select1, select2, quantity;
	string orderName;
	bool cont = false;
	for (int i = 0; i < mc_num; i++)
		cout << "\t\t\t\t\t" << i + 1 << ". " << mc_item[i].mc_name << endl;

	cout << "\t\t\t\t\tPlease choose one: ";
	cin >> select1;
	cout << endl;
	if (inputValid(select1, mc_num)) {
		orderName = mc_item[select1 - 1].mc_name;
		cout << "\t\t\t\t\tSelection 1:" << endl;
		for (int j = 0; j < 20; j++) {
			if (sel.MC[j] == "")
				break;
			else
				cout << "\t\t\t\t\t" << (j + 1) << ". " << sel.MC[j] << endl;
		}
		cout << "\t\t\t\t\tPlease select one: ";
		cin >> select2;
		if (sel.MC[select2 - 1] == "" || select2 < 1) {
			printError();
		}
		else {
			orderName += " (" + sel.MC[select2 - 1] + ")";
			cout << "\t\t\t\t\tQuantity: ";
			cin >> quantity;
			if (quantity < 1) {
				cout << "\t\t\t\t\tPlease enter value more than 0" << endl;
				cout << "\t\t\t\t\t";
				system("PAUSE");
			}
			else {
				for (int i = 0; i < 50; i++) {
					if (orderList[i] == "") {
						orderList[i] = orderName;
						orderqty[i] = quantity;
						orderPrice[i] = mc_item[select1 - 1].mc_price;
						break;
					}
				}
			}
		}
	}
	else
		printError();
	
}

//Add Beverage Order
void orderAddBeverage(string orderList[], double orderPrice[], int orderqty[]) {
	int select1, select2, select3, select4, quantity;
	string orderName;

	for (int i = 0; i < b_num; i++)
		cout << "\t\t\t\t\t" << i + 1 << ". " << b_item[i].b_name << endl;

	cout << "\t\t\t\t\tPlease choose one: ";
	cin >> select1;
	if (inputValid(select1, b_num)) {
		orderName = b_item[select1 - 1].b_name;

		cout << endl << "\t\t\t\t\tSelection 1: Type" << endl;
		for (int i = 0; i < 10; i++) {
			if (sel.bev[0][i] == "")
				break;
			else
				cout << "\t\t\t\t\t" << (i + 1) << ". " << sel.bev[0][i] << endl;
		}
		cout << "\t\t\t\t\tPlease choose one: ";
		cin >> select2;
		if (sel.bev[0][select2 - 1] == "" || select2 < 1)
			printError();
		else {
			cout << endl << "\t\t\t\t\tSelection 2: Size" << endl;
			for (int i = 0; i < 10; i++) {
				if (sel.bev[1][i] == "")
					break;
				else
					cout << "\t\t\t\t\t" << (i + 1) << ". " << sel.bev[1][i] << endl;
			}
			cout << "\t\t\t\t\tPlease choose one: ";
			cin >> select3;
			if (sel.bev[1][select3 - 1] == "")
				printError();
			else {
				cout << endl << "\t\t\t\t\tSelection 3: Ice Level" << endl;
				for (int i = 0; i < 10; i++) {
					if (sel.bev[2][i] == "")
						break;
					else
						cout << "\t\t\t\t\t" << (i + 1) << ". " << sel.bev[2][i] << endl;
				}
				cout << "\t\t\t\t\tPlease choose one: ";
				cin >> select4;
				if (sel.bev[2][select4 - 1] == "")
					printError();
				else {
					orderName = b_item[select1 - 1].b_name + " (" + sel.bev[0][select2 - 1] + ")" + " (" + sel.bev[1][select3 - 1] + ")" + " (" + sel.bev[2][select4 - 1] + ")";

					cout << "\t\t\t\t\tQuantity: ";
					cin >> quantity;
					if (quantity < 1) {
						cout << "\t\t\t\t\tPlease enter value more than 0" << endl;
						cout << "\t\t\t\t\t";
						system("PAUSE");
					}
					else {
						for (int i = 0; i < 50; i++) {
							if (orderList[i] == "") {
								orderList[i] = orderName;
								orderPrice[i] = b_item[select1 - 1].b_price[select2 - 1][select3 - 1];
								orderqty[i] = quantity;
								break;
							}
						}
					}
				}
			}
		}
	}
	else {
		printError();
	}
}

//Ask Customer's Age
void orderAddLDLegal(string orderList[], double orderPrice[], int orderqty[]) {
	int age;
	cout << "\t\t\t\t\tYour age: ";
	cin >> age;
	cout << endl;
	if (age < 18) {
		cout << "\t\t\t\t\tSorry, you are not legal to buy/drink wine." << endl;
		cout << "\t\t\t\t\t";
		system("PAUSE");
	}
	else {
		orderAddLongDrink(orderList, orderPrice, orderqty);
	}
}

//Add Long Drink Order
void orderAddLongDrink(string orderList[], double orderPrice[], int orderqty[]) {
	int select1, select2, select3, quantity;
	string orderName;

	for (int i = 0; i < ld_num; i++)
		cout << "\t\t\t\t\t" << i + 1 << ". " << ld_item[i].ld_name << endl;

	cout << "\t\t\t\t\tPlease choose one: ";
	cin >> select1;
	if (inputValid(select1, ld_num)) {
		orderName = ld_item[select1 - 1].ld_name;

		cout << endl << "\t\t\t\t\tSelection 1: Size" << endl;
		for (int i = 0; i < 3; i++) {
			if (sel.LD[0][i] == "")
				break;
			else
				cout << "\t\t\t\t\t" << (i + 1) << ". " << sel.LD[0][i] << endl;
		}
		cout << "\t\t\t\t\tPlease choose one: ";
		cin >> select2;
		if (sel.LD[0][select2 - 1] == "" || select2 < 1)
			printError();
		else {
			cout << endl << "\t\t\t\t\tSelection 2: Ice Level" << endl;
			for (int i = 0; i < 3; i++) {
				if (sel.LD[1][i] == "")
					break;
				else
					cout << "\t\t\t\t\t" << (i + 1) << ". " << sel.LD[1][i] << endl;
			}
			cout << "\t\t\t\t\tPlease choose one: ";
			cin >> select3;
			if (sel.LD[1][select3 - 1] == "" || select3 < 1)
				printError();
			else {
				orderName = ld_item[select1 - 1].ld_name + " (" + sel.LD[0][select2 - 1] + ")" + " (" + sel.LD[1][select3 - 1] + ")";
				cout << "\t\t\t\t\tQuantity: ";
				cin >> quantity;
				if (quantity < 1) {
					cout << "\t\t\t\t\tPlease enter value more than 0" << endl;
					cout << "\t\t\t\t\t";
					system("PAUSE");
				}
				else {
					for (int i = 0; i < 50; i++) {
						if (orderList[i] == "") {
							orderList[i] = orderName;
							orderPrice[i] = ld_item[select1 - 1].ld_price[select2 - 1];
							orderqty[i] = quantity;
							break;
						}
					}
				}
			}
		}
	}
	else {
		printError();
	}
}

//Delete Order
void orderDelete(string orderList[], int orderqty[], double orderPrice[]) {
	int del;
	printDELETE();
	printOrderList(orderList, orderqty);
	cout << "\t\t\t\t\tWhich one do you want to delete?: ";
	cin >> del;
	if (orderList[del - 1] == "" || del < 1 || del > 100)
		printError();
	else {
		orderList[del - 1] = "";
		orderPrice[del - 1] = 0;
		orderqty[del - 1] = 0;

		for (int i = del - 1; i < 99; i++) {
			orderList[i] = orderList[i + 1];
			orderPrice[i] = orderPrice[i + 1];
			orderqty[i] = orderqty[i + 1];
		}
	}
	system("CLS");
}

//Update Order
void orderUpdate(string orderList[], int orderqty[]) {
	int update, quantity;
	printUPDATE();
	printOrderList(orderList, orderqty);
	cout << "\t\t\t\t\tWhich one do you want to update?: ";
	cin >> update;
	if (orderList[update - 1] == "" || update < 1 || update > 100)
		printError();
	else {
		cout << "\t\t\t\t\tQuantity: ";
		cin >> quantity;
		if (quantity < 1) {
			cout << "\t\t\t\t\tPlease enter value more than 0" << endl;
			cout << "\t\t\t\t\t";
			system("PAUSE");
		}
		else
			orderqty[update - 1] = quantity;
	}
	system("CLS");
}

//Design
void printEDIT() {
	cout << "\t\t\t\t ______     _____     __     ______  " << endl;
	cout << "\t\t\t\t/\\  ___\\   /\\  __-.  /\\ \\   /\\__  _\\ " << endl;
	cout << "\t\t\t\t\\ \\  __\\   \\ \\ \\/\\ \\ \\ \\ \\  \\/_/\\ \\/ " << endl;
	cout << "\t\t\t\t \\ \\_____\\  \\ \\____-  \\ \\_\\    \\ \\_\\ " << endl;
	cout << "\t\t\t\t  \\/_____/   \\/____/   \\/_/     \\/_/ " << endl;
}

void printADD() {
	cout << " \t\t\t\t    ______     _____      _____ " << endl;
	cout << " \t\t\t\t   /\\  __ \\   /\\  __-.   /\\  __-. " << endl;
	cout << " \t\t\t\t   \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\ \\/\\ \\  " << endl;
	cout << " \t\t\t\t    \\ \\_\\ \\_\\  \\ \\____ -  \\ \\____ - " << endl;
	cout << " \t\t\t\t     \\/_/\\/_/   \\/____/    \\/____/    " << endl;
}

void printDELETE() {
	cout << " \t\t     _____      ______     __         ______     ______     ______ " << endl;
	cout << " \t\t    /\\  __-.   /\\  ___\\   /\\ \\       /\\  ___\\   /\\__  _\\   /\\  ___\\ " << endl;
	cout << " \t\t    \\ \\ \\/\\ \\  \\ \\  __\\   \\ \\ \\____  \\ \\  __\\   \\/_/\\ \\/   \\ \\  __\\  " << endl;
	cout << " \t\t     \\ \\____ -  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\    \\ \\_\\    \\ \\_____\\ " << endl;
	cout << " \t\t      \\/____/    \\/_____/   \\/_____/   \\/_____/     \\/_/     \\/_____/ " << endl;
}

void printUPDATE() {
	cout << " \t\t    __  __     ______     _____      ______     ______     ______    " << endl;
	cout << " \t\t   /\\ \\/\\ \\   /\\  == \\   /\\  __-.   /\\  __ \\   /\\__  _\\   /\\  ___\\      " << endl;
	cout << " \t\t   \\ \\ \\_\\ \\  \\ \\  _-/   \\ \\ \\/\\ \\  \\ \\  __ \\  \\/_/\\ \\/   \\ \\  __\\          " << endl;
	cout << " \t\t    \\ \\_____\\  \\ \\_\\      \\ \\____ -  \\ \\_\\ \\_\\    \\ \\_\\    \\ \\_____\\     " << endl;
	cout << " \t\t     \\/_____/   \\/_/       \\/____/    \\/_/\\/_/     \\/_/     \\/_____/  " << endl;
}

void printURORDERS() {
	cout << "\t\t\t ______     ______     _____     ______     ______    " << endl;
	cout << "\t\t\t/\\  __ \\   /\\  == \\   /\\  __-.  /\\  ___\\   /\\  == \\   " << endl;
	cout << "\t\t\t\\ \\ \\/\\ \\  \\ \\  __<   \\ \\ \\/\\ \\ \\ \\  __\\   \\ \\  __<   " << endl;
	cout << "\t\t\t \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\____-  \\ \\_____\\  \\ \\_\\ \\_\\ " << endl;
	cout << "\t\t\t  \\/_____/   \\/_/ /_/   \\/____/   \\/_____/   \\/_/ /_/ " << endl;
	cout << endl;

}

//Print Order List
void printOrderList(string orderList[], int orderqty[]) {

	cout << endl;
	cout << "  ----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "    No.                                     Food                                                  Quantity" << endl;
	cout << "  ----------------------------------------------------------------------------------------------------------------" << endl;

	for (int j = 0; j < 100; j++) {
		if (orderList[j] == "")
			break;
		else {
			cout << "   " << right << setw(2) << (j + 1) << ".  " << left << setw(92) << orderList[j] << setw(4) << orderqty[j] << endl;
		}
	}
	if (orderList[0] == "") {
		cout << endl;
		cout << "\t\t\t\t\t No order yet" << endl;
		cout << endl;
	}

	cout << "  ----------------------------------------------------------------------------------------------------------------" << endl << endl;
}

//Order Status
void orderStatus(string orderList[], int orderqty[], double orderPrice[], int& selection) {
	system("CLS");
	int exist = 0;
	double totalPrice = 0;
	membership(exist);
	printURORDERS();
	printOrderList(orderList, orderqty);
	countTotalPrice(orderqty, orderPrice, totalPrice, exist);
	cout << fixed << setprecision(2) << "\t\t\t\tTotal Price: RM " << totalPrice << endl;
	cout << "\t\t\t\tYour order will be ready in 30 minutes" << endl << endl;
	cout << "\t\t\t\tTo proceed to payment -> ";
	system("PAUSE");
	Payment(selection);
}

//Total Price
void countTotalPrice(int orderqty[], double orderPrice[], double& totalPrice, int exist) {
	for (int i = 0; i < 100; i++) {
		if (orderqty[i] == 0)
			break;
		else {
			totalPrice += (orderqty[i] * orderPrice[i]);
		}
	}
	if (exist == 1)
		totalPrice *= 0.9;
	if (totalPrice > 200)
		totalPrice *= 0.9;
	else if (totalPrice > 100)
		totalPrice *= 0.95;
}

//check in module for customer
//membership - discount modules
void membership(int& exist)
{
	char ans1, ans2;
	string cusUser, cusPassword, u, p;
	cout << "\t\t ______     __  __     ______     ______    ______     __    __    ______     ______" << endl;
	cout << "\t\t/\\  ___\\   /\\ \\/\\ \\   /\\  ___\\   /\\__  _\\  /\\  __ \\   /\\ '-./  \\  /\\ ___ \\   /\\  == \\ " << endl;
	cout << "\t\t\\ \\ \\____  \\ \\ \\_\\ \\  \\ \\___  \\  \\/_/\\ \\/  \\ \\ \\/\\ \\  \\ \\ \\-./\\ \\ \\ \\  __\\   \\ \\  __<" << endl;
	cout << "\t\t \\ \\_____\\  \\ \\_____\\  \\/\\_____\\    \\ \\_\\   \\ \\_____\\  \\ \\_\\ \\ \\_\\ \\ \\_____\\  \\ \\_\\ \\_\\ " << endl;
	cout << "\t\t  \\/_____/   \\/_____/   \\/_____/     \\/_/    \\/_____/   \\/_/  \\/_/  \\/_____/   \\/_/ /_/ " << endl;
	cout << endl;
	cout << "\t\t\t\t\tAre you a member? (y - yes, n - no): ";
	cin >> ans1;
	cout << endl;
	if (ans1 == 'y' || ans1 == 'Y')
	{
		cout << "\t\t\t\t\tPlease enter the following details: " << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << "\t\t\t\t\t\t Username :";
			cin >> cusUser;
			cout << "\t\t\t\t\t\t Password :";
			cin >> cusPassword;
			cout << endl;

			ifstream infile("customer.txt");
			if (infile.fail())
				cout << "\t\t\t\t\tUnable to read file!" << endl;
			else
			{
				while (!infile.eof())
				{
					infile >> u >> p;
					if (cusUser == u && cusPassword == p)
						exist = 1;

				}
			}
			infile.close();

			if (exist == 1)
			{
				cout << "\t\t\t\t\t    Login Success! Bonjour!" << endl;
				cout << endl << "\t\t\t\t\t";
				system("pause");
				system("CLS");
				return;
			}
			else
			{
				cout << "\t\t\t\t\tIncorrect Username or Password." << endl;
				cout << endl;
			}
		}
		system("CLS");
		forgetPassword(exist);

	}
	else
	{
		cout << endl;
		cout << "\t\t\t\tWould you like to create a new account? (y - yes, n - no): ";
		cin >> ans2;
		if (ans2 == 'y' || ans2 == 'Y')
			registerAcc(exist);
		else
		{
			system("CLS");
			
		}
	}
}

//For customer to register a new account / membership
void registerAcc(int& exist)
{
	int exist2 = 0;
	string newUser, newPassword1, newPassword2, u1, p1;
	system("CLS");
	cout << "\t\t\t ______     ______     ______     __     ______     ______   ______     ______    " << endl;
	cout << "\t\t\t/\\  == \\   /\\  ___\\   /\\  ___\\   /\\ \\   /\\  ___\\   /\\__  _\\ /\\  ___\\   /\\  == \\   " << endl;
	cout << "\t\t\t\\ \\  __<   \\ \\  __\\   \\ \\ \\__ \\  \\ \\ \\  \\ \\___  \\  \\/_/\\ \\/ \\ \\  __\\   \\ \\  __<   " << endl;
	cout << "\t\t\t \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\  \\/\\_____\\    \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\ " << endl;
	cout << "\t\t\t  \\/_/ /_/   \\/_____/   \\/_____/   \\/_/   \\/_____/     \\/_/   \\/_____/   \\/_/ /_/ " << endl;
	cout << endl;
	cout << "\t\t\t\t  * No spacing is allowed in creating a username and password! *" << endl << endl;
	cout << "\t\t\t\t\t  Please enter your username: ";
	cin >> newUser;

	do
	{
		cout << endl;
		cout << "\t\t\t\t\t  Please enter your password: ";
		cin >> newPassword1;

		cout << "\t\t\t\t\t  Please reenter your password: ";
		cin >> newPassword2;

	} while (newPassword1 != newPassword2);

	ifstream infile("customer.txt");
	if (infile.fail())
		cout << "Unable to read file!" << endl;
	else
	{
		while (!infile.eof())
		{
			infile >> u1 >> p1;
			if (newUser == u1 && newPassword1 == p1)
				exist2 = 1;
		}
		infile.close();

		if (exist2 == 1)
		{
			cout << "\n\t\t\t\t\t  Account has existed! Please try to Log In" << endl;
			system("Pause");
			system("CLS");
			membership(exist);

		}
		else
		{
			ofstream outfile("customer.txt", ios::app);
			if (outfile.fail())
				cout << "Unable to open file!" << endl;
			else
			{
				if (isEmpty())
					outfile << newUser << " " << newPassword1;
				else 
					outfile << endl<< newUser << " " << newPassword1 << endl;
				cout << endl;
				cout << "\t\t\t\t\t  Resgistration Successfully!" << endl;
				system("pause");
				system("CLS");
				membership(exist);
			}
			outfile.close();
		}
	}
}

//Customer Forget Password
void forgetPassword(int& exist)
{
	cout << "\t\t\t ______   ______     ______     ______     ______     ______      ____ " << endl;
	cout << "\t\t\t/\\  ___\\ /\\  __ \\   /\\  == \\   /\\  ___\\   /\\  ___\\   /\\__  _\\    |___ \\" << endl;
	cout << "\t\t\t\\ \\  __\\ \\ \\ \\/\\ \\  \\ \\  __<   \\ \\ \\__ \\  \\ \\  __\\   \\/_/\\ \\/       / /" << endl;
	cout << "\t\t\t \\ \\_\\    \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\    \\ \\_\\      |_| " << endl;
	cout << "\t\t\t  \\/_/     \\/_____/   \\/_/ /_/   \\/_____/   \\/_____/     \\/_/      (_) " << endl;
	cout << endl;
	int no = 0; //Keep track of the number of customers
	Customer cus[100];
	int ans3;
	ifstream infile("customer.txt");

	if (infile.fail()) {
		cout << "\t\t\t\t\tUnable to read file!" << endl;
		system("pause");
	}
	else
	{
		while (infile >> cus[no].user >> cus[no].password) {
			no++;
		}

		infile.close();
	}
	cout << "\t\t\t\t\t    Forget your password?" << endl;
	cout << "\n\t\t\t\t    We here to help! Please choose one <3 " << endl;
	cout << "\t\t\t\t\t 1. Change a new password" << endl;
	cout << "\t\t\t\t\t 2. Create a new account" << endl;
	cout << "\t\t\t\t\t 3. Proceed to payment without a membership" << endl;
	cout << "\t\t\t\t\t\t  Answer: ";
	cin >> ans3;

	switch (ans3) {
	case 1:
		updateDetail(cus, no, exist);
		break;

	case 2:
		registerAcc(exist);
		break;

	case 3:
		system("pause");
		system("CLS");
		break;

	default:
		cout << "Please try again!" << endl;
		system("CLS");
		forgetPassword(exist);
	}

}

//Update Log In Details
void updateDetail(Customer cus[], int& no, int& exist) {

	string user;
	int notFound = 0, cusSelection;
	cout << "\n\t\t\t\t\t    * Update Details *" << endl;
	cout << "\t\t\t\t\tPlease key in your username: ";
	cin >> user;
	cout << endl << endl;
	for (int i = 0; i < no; i++) {
		if (cus[i].user == user) {
			cout << "\t\t\t\t\tWhat do you want to update?" << endl;
			cout << "\t\t\t\t\t1 - Username, 2 - Password: ";
			cin >> cusSelection;
			if (cusSelection == 1) {
				cout << "\t\t\t\t\tNew Username: ";
				cin >> cus[i].user;
			}
			else {
				cout << "\t\t\t\t\tNew Password: ";
				cin >> cus[i].password;
			}
			cout << endl;
			cout << "\t\t\t\t\t    Update successfully!" << endl;
			cout << "\t\t\t\t\t";
			system("pause");
			system("CLS");
			return;
		}
		else
			notFound++;
	}

	if (notFound == no) {
		cout << "\t\t\t\t\tUsername is not found! :(" << endl;
		system("pause");
		registerAcc(exist);
	}

	ofstream outfile("customer.txt");
	if (outfile.fail()) {
		cout << "\t\t\t\t\tUnable to open file!" << endl;
	}
	else
	{
		for (int i = 0; i < no; i++) {
			outfile << cus[i].user << " " << cus[i].password << endl;
		}
	}
	outfile.close();
	system("CLS");
	membership(exist);
}

bool inputValid(int x, int y) {
	if (x > 0 && x <= y)
		return true;
	else
		return false;
}

//Payment
void Payment(int& selection) {
	system("CLS");
	string num, expDate, cvv, name;
	bool cont;
	do {
		cout << " \t\t   ______     ______     __  __     __    __     ______     __   __     ______ " << endl;
		cout << " \t\t  /\\  == \\   /\\  __ \\   /\\ \\_\\ \\   /\\ '-. / \\   /\\  ___\\   /\\ '-.\\ \\   /\\__  _\\ " << endl;
		cout << " \t\t  \\ \\  _-/   \\ \\  __ \\  \\ \\____ \\  \\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\/_/\\ \\/ " << endl;
		cout << " \t\t   \\ \\_\\      \\ \\_\\ \\_\\  \\/\\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\\'\\_\\    \\ \\_\\ " << endl;
		cout << " \t\t    \\/_/       \\/_/\\/_/   \\/_____/   \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/     \\/_/  " << endl;
		cout << endl;
		animateText("\t\t\t\t    Please enter your Bank Card Details:");
		cout << "\t\t\t\t\tCard Number: ";
		cin >> num;
		cout << "\t\t\t\t\tExpiry Date (MM/YY): ";
		cin >> expDate;
		cout << "\t\t\t\t\tCVV: ";
		cin >> cvv;
		cin.ignore();
		cout << "\t\t\t\t\tName on Card: ";
		getline(cin, name);

		if (num.length() != 16) {
			cout << "\t\t\t\t\tInvalid input of Card Number" << endl;
			cont = false;
			cout << "\t\t\t\t\t";
			system("PAUSE");
			system("CLS");
		}
		else if (expDate.length() != 5 || expDate[2] != '/') {
			cout << "\t\t\t\t\tInvalid input of Expiry Date" << endl;
			cout << "\t\t\t\t\t";
			system("PAUSE");
			system("CLS");
			cont = false;
		}
		else if (cvv.length() != 3) {
			cout << "\t\t\t\t\tInvalid input of CVV" << endl;
			cout << "\t\t\t\t\t";
			system("PAUSE");
			system("CLS");
			cont = false;
		}
		else
			cont = true;
	} while (cont == false);

	cout << endl;
	printLoadingbar();
	cout << "\n\t\t\t\t\tPayment Successful!" << endl;
	cout << "\t\t\t\t\t";
	system("PAUSE");
	selection = 5;
	system("CLS");
	ending();
	main();
}

//Display
void printOrderSelection() {
	cout << "\t\t\t\t   ______________________________" << endl;
	cout << "\t\t\t\t / \\                             \\." << endl;
	cout << "\t\t\t\t|   |     Please Select One:     |." << endl;
	cout << "\t\t\t\t \\_ |                            |." << endl;
	cout << "\t\t\t\t    |  1. Add Order              |." << endl;
	cout << "\t\t\t\t    |  2. Delete Order           |." << endl;
	cout << "\t\t\t\t    |  3  Update Order Quantity  |." << endl;
	cout << "\t\t\t\t    |  4. Done Ordering          |." << endl;
	cout << "\t\t\t\t    |  5. Exit                   |." << endl;
	cout << "\t\t\t\t    |   _________________________|___" << endl;
	cout << "\t\t\t\t    |  /                            /." << endl;
	cout << "\t\t\t\t    \\_/____________________________/." << endl << endl;
	cout << "\t\t\t\t\t\tAnswer: ";
}

void printError() {
	cout << "\t\t\t\t\tInvalid input" << endl;
	cout << "\t\t\t\t\t";
	system("PAUSE");
}

void ending() {
	animateText("\t\t\t\tThank you for your purchasing and order <3");
	animateText("\t\t\t\t\t   See you next time!");
	cout << "\t\t\t\t";
	system("pause");
	system("CLS");
}

void animateText(const string& text) {
	for (char c : text) {
		cout << c;
		this_thread::sleep_for(chrono::milliseconds(30));
	}
	cout << endl;
}



