#ifndef _INSTANCE_CONTROL_H
#define _INSTANCE_CONTROL_H

class InstanceControl
{
	int i;
	private:
	InstanceControl();
	~InstanceControl();
	static InstanceControl *pInstance;
	static int NoOfInstances;
	public:
	void ShowContacts();
	void ShowMusic();
	static InstanceControl* GetInstance();
	static void DeleteInstance();
};

#endif
