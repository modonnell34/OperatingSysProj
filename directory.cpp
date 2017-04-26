#include <vector>
#include <iostream>
#include <assert.h>
#include "directory.h"
using namespace std;

// Constructors
Directory::Directory() {
	int size = 0;
}

Directory::Directory(string name){
	this->dname = name;
	this->dsize = 0;
}


string Directory::getName() const {
	return dname;
}


int Directory::getSize() const {
	return dsize;
}


int Directory::getnumBlocks(){
	return numBlocks;
}


void Directory::setnumBlocks(int n){
	this->numBlocks = n;
}


void Directory::setName(string name) {
	this->dname = name; 
}


// File and directory Management Methods
vector<string>Directory::getFiles(File * head) const { 

	vector<string> f;

    File * p;

    p = head;
	while (p!=NULL)
    {
	f.push_back(p->name);
        p = p->next;  //update p to point to next node in the linked list ...
    }

	return f; 
}

File *Directory::createFile(int s, string n){
    struct File *temp;
    temp = new(struct File); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->size = s;
	temp->name = n;
        temp->next = NULL;     
        return temp;
    }

}

void Directory::DisplayLinkedList (File * head)
{
   File * p;

    p = head;   //initialize pointer p to point to the first node in the linked list

    while (p!=NULL)
    {
        cout <<" Node at " << p << endl;
        cout <<"        name:  " << p->name <<" "<<p->size<<endl;
        cout <<"        next:   " <<p->next <<endl;
        p = p->next;  //update p to point to next node in the linked list ...
    }


}



void Directory::AppendInTheEnd (File * & head, string num, int size)
{
        File * tail=NULL;

        File * newNode = new File;

        newNode->mode = "closed";
        newNode->size = size;
	newNode->name = num;

        if (head==NULL){
                head = newNode;
        }
        else {
                //make tail points to the last node
                tail = head;
                while (tail->next!=NULL)
                        tail = tail->next;

                tail->next = newNode;
        }
}



File *Directory:: Search (File * firstNodePtr, string name)
{
        File * p;

        p = firstNodePtr;
        while (p!=NULL)
        {
                if (p->name==name)
                        return p;
                p = p->next; //update p with the current node's next field
        }
        return p;
}


File *Directory:: Search (File * firstNodePtr, string name,
                File * & prevNode)
{

        File * p;

        p = firstNodePtr;
        prevNode = NULL;

        while (p!=NULL)
        {
                if (p->name==name)
                        return p;

                prevNode = p;
                p = p->next; //update p with the current node's next field
        }

        prevNode=NULL;
        return p;
}




bool Directory::Delete (File * & firstPtr, string name)
{
    File * prev, * cur;

    cur = Search (firstPtr, name, prev);
    if (cur==NULL)
        return false;
    else {
        // remove cur node from the linked list
        if (prev!=NULL)
        {       //not the first one
                prev->next = cur->next;   //bypass the cur node
        }
        else //cur is the first node
                firstPtr = cur->next; //update the head pointer

        delete cur; //deallocate the node itself        return true;
    }
}



//int main(){
//	Directory d;
//	d.File.name = "A";
//}


