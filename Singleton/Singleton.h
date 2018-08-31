#ifndef _SINGLETON_H
#define _SINGLETON_H

class Singleton
{
	int i;
	private:
	Singleton();
	~Singleton();
	static Singleton *pInstance;
	public:
	void ShowContacts();
	void ShowMusic();
	static Singleton* GetInstance();
	static void DeleteInstance();
};

#endif
