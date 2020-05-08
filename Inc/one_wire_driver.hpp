/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ONE_WIRE_DRIVER_HPP
#define ONE_WIRE_DRIVER_HPP

#include "pin_data.hpp"
#include "timer.hpp"
#include "device_manager.hpp" //musimy miec obiekt DMa zeby dostac pin i timer

typedef enum {
	ONE_WIRE_OUTPUT = 0,
	ONE_WIRE_INPUT  = 1,
} oneWireMode;

extern DeviceManager deviceManager;

class OneWireDriver;
typedef void (OneWireDriver::*StateHandler)(void);

class OneWireDriver{
private:
	PinData *pinData;
	Timer *timer;
	StateHandler stateHandler;
	void firstStateHandler(void);
	void secondStateHandler(void);
	void thirdStateHandler(void);
	//.. moga byc kolejne stany wewnatrz odczytu
public:
	OneWireDriver(PinData *pinData);
	void driverStartReadout(void);
	void executeState(void);
	void changePinMode(oneWireMode mode);
	void writePin(bool state);
	bool readPin(void);
};

#endif
