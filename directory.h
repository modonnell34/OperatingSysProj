#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>
#include <iostream>
//#include "file.h"

using namespace std;

struct File {
   string name;
   string mode;
   int size;
   struct File * next;
};

class Directory {


	public:
//		struct File;
		// Constructors
		Directory();
		Directory(string name);
		~Directory();

		// Getters and Setters
		string getName() const;
		int getSize() const;
		int getnumBlocks();
		
		void setSize(int s);
		void setName(string name);
		void setnumBlocks(int n);

		// File and directory Management Methods
		vector<string> getFiles(File * head)const;
 		File * createFile(int,string);	
		void DisplayLinkedList (File * head);
		void AppendInTheEnd (File * & head, string num, int size);
		File * Search (File * firstNodePtr, string name);
		File * Search (File * firstNodePtr, string name,
                File * & prevNode);
		void InsertBeforeValue (File * & head, string name, string beforeValue);
		bool Delete (File * & firstPtr, string name);
	
	private:
//		struct File;
		int dsize;
		int numBlocks;
		string  dname;
	//	Diskprocess disk;


};

#endif
