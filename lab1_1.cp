#include <iostream>
#include <vector>

using namespace std;

enum BookType
{
	DETECTIVE,
	NOVEL
};

class Book
{
	string author;
	string name;
	BookType type;
public:
	Book(string a, string n, BookType t)
	{
		author = a;
		name = n;
		type = t;
	}
	
	BookType GetType() { return type; }
	
	void Print()
	{
		cout << author << " " << name<< " ";
		if(type == DETECIVE)
			cout << "(Detective)";
		else if(type == NOVEL)
			cout << "(Novel)";
		cout << endl;
	}
};

void TaskB(vector<Book*> library) {
	cout << "using switch: " << endl;
	int detective_count = 0;
	int novel_count = 0;

	for(int i=0; i<library.size(); i++)
	{
		switch(library[i]->GetType())
		{
			case DETECTIVE:
				detective_count++;
			break;
			case NOVEL:
				novel_count++;
			break;
		}
	}
	cout << "detective books: " << detective_count << endl;
	cout << "novel books: " << novel_count << endl;
	
}

void TaskC(vector<Book*> library) {
	cout << "using if: " << endl;
	int detective_count = 0;
	int novel_count = 0;

	for(int i=0; i<library.size(); i++)
	{
		if(library[i]->GetType() == DETECTIVE)
			detective_count++;
		else if(library[i]->GetType() == NOVEL)
			novel_count++;
	}
	cout << "detective books: " << detective_count << endl;
	cout << "tech books: " << novel_count << endl;
}


int main()
{
	vector<Book*> library = 
	{
		new Book("Three Comrades", "Erich Maria Remarque", NOVEL),
		new Book("Triumphal Arch", "Erich Maria Remarque", NOVEL),
		new Book("Sherlock Holmes", "Sir Arthur Conan Doyle", DETECTIVE),
		new Book("Hercule Poirot", "Agata Christie", DETECTIVE),
	};
	
	for(int i=0; i<library.size(); i++)
	{
		library[i]->Print();
	}
	
	TaskB(library);
	TaskC(library);
	
	for(int i=0; i<library.size(); i++)
	{
		delete library[i];
	}
	
	return 0;
}
