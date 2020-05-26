#include "one_wire_driver.hpp"

OneWireDriver::OneWireDriver(PinData pinData, uint16_t interval, char name[], uint8_t name_len)
							: GenericDriver(pinData, interval, name, name_len) {
	this->stateHandler = static_cast<StateHandler>(&OneWireDriver::firstStateHandler);
	this->timer->registerCallback(std::bind(&OneWireDriver::executeState, this));
};

void OneWireDriver::driverStartReadout(void){
	this->stateHandler = static_cast<StateHandler>(&OneWireDriver::firstStateHandler);
	this->executeState();
}

void OneWireDriver::executeState(void){
	(this->*stateHandler)();
}

void OneWireDriver::changePinMode(oneWireMode mode){
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = this->pinData.GPIO_Pin;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	if(mode == ONE_WIRE_OUTPUT){
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	}
	else if(mode == ONE_WIRE_INPUT){
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	}
	HAL_GPIO_Init(this->pinData.GPIO_Port, &GPIO_InitStruct);
};

void OneWireDriver::writePin(bool state){
	HAL_GPIO_WritePin(this->pinData.GPIO_Port,
					  this->pinData.GPIO_Pin,
					  state == true ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

bool OneWireDriver::readPin(void){
	return (1&HAL_GPIO_ReadPin(this->pinData.GPIO_Port, this->pinData.GPIO_Pin));
}
