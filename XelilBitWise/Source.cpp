#include<iostream>
using namespace std;


//struct Human {
//	int score : 8;
//	int age : 10;
//	int isBest :1;
//};
//4  32 => 8 + 10 =>18 + 1 =>19 bit
//4  32


//BIT FIELDS

//struct HumanValidation {
//	bool isEmailValidate : 1;
//	bool isAgeValidate : 1;
//	bool isPhoneValidate : 1;
//	bool isCardValidate : 1;
//	bool isEmailValidate2 : 1;
//	bool isAgeValidate2 : 1;
//	bool isPhoneValidate2 : 1;
//	bool isCardValidate2 : 1;
//};
//
//
//
//void main() {
//	cout << sizeof(HumanValidation) << endl;
//}


//
//struct User {
//	short age:9;
//	short score:7;
//};
//
//void main() {
//	User user{ 150,44 };
//	cout << user.age << endl;
//	cout << user.score << endl;
//	cout << sizeof(User) << endl;
//}




//Standart Struct
//Nested Structure

//struct Time {
//	short minute : 8;
//	short hour : 8;
//};
//
//struct Date {
//	short day : 6;
//	short month : 5;
//	short year : 21;
//};
//
//
//struct Event {
//	char* name;
//	Time time;
//	Date date;
//};
//
//
//void main() {
//	Time t{ 30,21 };
//	Date d{ 31,12,2022 };
//	Event e{ new char[] {"Merry Christmas"},t,d };
//
//}



struct HDD {
	double maxSize = 1024;//byte
	double size = 0;
	struct File {
		char* name;
		char* content;
	};
	File** files;
	int filesCount = 0;

};
HDD::File* GetFile(HDD& disc, const char* filename) {
	for (size_t i = 0; i < disc.filesCount; i++)
	{
		if (strcmp(disc.files[i]->name, filename) == 0) {
			return disc.files[i];
		}
	}
	return nullptr;
}

void AddFileToDisc(HDD& disc, HDD::File* file) {
	auto newfiles = new HDD::File * [disc.filesCount + 1]{};
	for (size_t i = 0; i < disc.filesCount; i++)
	{
		newfiles[i] = disc.files[i];
	}
	newfiles[disc.filesCount] = file;
	disc.files = newfiles;
	newfiles = nullptr;
	disc.filesCount++;
	disc.size += strlen(file->content);
}


//nezere alin  file yaranmamishdan once hemen adda fayl varsa yaranmasin
//eger fayl disce yerleshmirse yaranmasin
//hech bir problem yoxdursa Files massivine hemen fayl elave olunsun
//ve discin tutumu deyishsin
void createFile(HDD& disc, char* filename,  char* content) {
	auto file = GetFile(disc, filename);
	if (file == nullptr) {
		int contentSize = strlen(content);
		if ((disc.size + contentSize) <= disc.maxSize) {
			auto file = new HDD::File{ filename,content };
			AddFileToDisc(disc, file);
			cout << "File added successfully" << endl;
		}
		else {
			cout << "You can not add this file , problem higher size" << endl;
		}
	}
	else {
		cout << filename << " is already exists" << endl;
	}
	//HDD::File myfile{ filename,content };
	//AddFileToDisc(disc, myfile);
}

void ShowAllFiles(const HDD& disc) {
	for (size_t i = 0; i < disc.filesCount; i++)
	{
	     //cout<<"Filename : "<<
	}
}


//nezere alin  file update once hemen adda fayl yoxdusa
//eger fayl disce yerleshmirse yaranmasin
//hech bir problem yoxdursa Files massivine hemen fayl elave olunsun
//ve discin tutumu deyishsin
void updateFile(HDD& disc, const char* filename, const char* newcontent) {

}

void main() {
	//   ::   scope resolution
	/*HDD::File hdd;*/

	HDD mydisc;
	createFile(mydisc, new char[10] {"a.txt"}, new char[20] {"Salam Millet"});
	createFile(mydisc, new char[10] {"a.txt"}, new char[20] {"Salam Millet"});

}
