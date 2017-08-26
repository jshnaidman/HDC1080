# HDC1080
Arduino Library for the HDC1080

The advantage of this library is that it configures the HDC1080 to attain the temperature and humidity in a single transaction.
This saves a bit of energy as it maximizes the amount of time the temperature sensor spends in sleep mode.

You can also configure the read operation separately from getTemp and getHumidity, allowing you to have better control over how often you want to take measurements.

This library was designed for my own purposes. It doesn't currently support some of the potentially useful features of the HDC1080 like its ability to activate HEAT and rid itself of any potential moisture left on the sensor. It shouldn't be necessary unless you're keeping it in a very humid environment. 


Also, I should caution anybody that is new to the HDC1080 to be aware that the soldering profile requires that peak temperatures never rise higher than 260 degrees Celcius. If you don't own a soldering iron with a temeprature display, this temperature will take 3-4 seconds to melt solder and will not easily melt. I would try to use as little heat as necessary. Otherwise, you risk breaking both the temperature and humidity sensor.
