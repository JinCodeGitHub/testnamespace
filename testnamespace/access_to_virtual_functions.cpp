class VFuncBase {
public:
	virtual int GetState() { return _state; }
protected:
	int _state;
};

class VFuncDerived : public VFuncBase {
private:
	int GetState() { return _state; }
};
/*
int main() {
	VFuncDerived vfd;
	VFuncBase *pvfb = &vfd;
	VFuncDerived *pvfd = &vfd;
	int State;

	State = pvfb->GetState();
	
	//State = pvfd->GetState();



}
*/