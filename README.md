# LPRS2

Subject of this project was to connect two Arduino Uno boards which can share information about conditions on three sensors: rain sensor, dht11 temperature and humidity sensor and soil humidity sensor. For communication is used i2c protocol, in which one board works as master and second as slave. Master sends information about values on sensors on every seven seconds, slave receives that and print on serial monitor. 

The rain sensor is a plate on which nickel is applied in the form of lines. It works on the principle of resistance. The resistance between each contact is extremely high when the sensor is dry (open circuit). When there is water on the board's surface, it forms a resistive connection across the two-copper strip. This difference in resistance enables the circuit to distinguish between dry and wet states allowing the sensor to detect rain.

The DHT11 is a basic, digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air, and spits out a digital signal on the data pin.

The soil moisture sensor uses capacitance to measure dielectric permittivity of the surrounding medium. In soil, dielectric permittivity is a function of the water content. The sensor creates a voltage proportional to the dielectric permittivity, and therefore the water content of the soil.

Arduino Youtube video presentation:
https://www.youtube.com/watch?v=2cNNIRl0MP0&ab_channel=MarijaDabic
