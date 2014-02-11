#ifndef HMC6352_H
#define HMC6352_H

class HMC6352
{
	public:
		// void constructor
		HMC6352();	

		// user-specified address
		HMC6352(int address);

		float getHeading();

	private:
		static const int c_getDataStandby_ = 0x41;
		
		int address_;
};

#endif