#ifndef ONE_WIRE_SENSOR_HPP
#define ONE_WIRE_SENSOR_HPP

#include <memory>
#include "sensor.hpp"
#include "generic_driver.hpp"
#include "one_wire_driver.hpp"
#include "pin_data.hpp"

class OneWireSensor : public Sensor {
private:
	float lastTemperatureValue;
	float lastHumidityValue;
public:
	//OneWireSensor(PinData *pinData);

	OneWireSensor(PinData pinData);

//	OneWireSensor(const OneWireSensor &sensor);
//	OneWireSensor(PinData *pinData, std::string name, uint16_t interval);
	float getLastTempVal(void);
	float getLastHumidVal(void);
};

#endif
