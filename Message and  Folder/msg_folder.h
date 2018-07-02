#ifndef MSG_FOLDER_H
#define MSG_FOLDER_H

#include <set>
#include <string>

using namespace std;

class Folder;
class Message
{
public:

	explicit Message(const string& s = "") :
		content(string(s)),
		folderSet(set<Folder*>())
	{
	}

	Message(const Message& rhs) :
		content(rhs.content),
		folderSet(rhs.folderSet)
	{
		add2(folderSet);
	}

	Message& operator =(const Message& rhs) 
	{
		remove2(folderSet);

		content = rhs.content;
		folderSet = rhs.folderSet;
		add2(folderSet);

		return *this;
	}

	void save(Folder& folder);
	void remove(Folder& folder);

	void add2(set<Folder*>& folderSet);

	void remove2(set<Folder*>& folderSet);

	~Message()
	{
		remove2(folderSet);
	}

	//private:
	string content;
	set<Folder*> folderSet;
};


class Folder
{
public:
	Folder() :
		msgSet(set<Message*>())
	{
	}

	void addMsg(Message& msg)
	{
		msgSet.insert(&msg);
	}

	void removeMsg(Message& msg)
	{
		msgSet.erase(&msg);
	}

private:
	set<Message*> msgSet;
};

inline void Message::save(Folder& folder)
{
	folderSet.insert(&folder);
	folder.addMsg(*this);
}

inline void Message::remove(Folder& folder)
{
	folderSet.erase(&folder);
	folder.removeMsg(*this);
}

inline void Message::add2(set<Folder*>& folderSet)
{
	set<Folder*>::iterator iter = folderSet.begin();
	while (iter != folderSet.end()) {
		(*iter)->addMsg(*this);
	}
}

inline void Message::remove2(set<Folder*>& folderSet)
{
	set<Folder*>::iterator iter = folderSet.begin();
	while (iter != folderSet.end()) {
		(*iter)->removeMsg(*this);
	}
}



#endif

