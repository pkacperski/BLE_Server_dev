#ifndef ONE_WIRE_SENSOR_HPP
#define ONE_WIRE_SENSOR_HPP

#include "sensor.hpp"
#include "generic_driver.hpp"
#include "one_wire_driver.hpp"
#include "pin_data.hpp"

//#include <functional>

class OneWireSensor /*: public Sensor*/ {
private:
	OneWireDriver oneWireDriver; //TODO: nie ma go tu byc! za generycznego drivera z klasy bazowej!
	float lastTemperatureValue;
	float lastHumidityValue;
//	std::function<void()> func;
public:
	OneWireSensor(PinData *pinData);
	void startNewReadout(void);
	float getLastTempVal(void);
	float getLastHumidVal(void);
};

#endif