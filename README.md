| <center><img src="./assets/rakstar.jpg" alt="RAKstar" width=25%></center>  | ![RAKWireless](./assets/RAK-Whirls.png) | [![Build Status](https://github.com/RAKWireless/RAK14001-NCP5623-Library/workflows/Arduino%20Library%20CI/badge.svg)](https://github.com/RAKWireless/RAK14001-NCP5623-Library/actions) |
| -- | -- | -- |

# NCP5623

The NCP5623 is an I2C RGB LED driver chip from ON Semiconductor. This library provides basic support for setting the colors of the individual channels. It does not support the built-in hardware dimming.

[*RAKwireless RAK14001 RGB LED*](https://docs.rakwireless.com/Product-Categories/WisBlock/#wisblock-io)

# Documentation

* **[Product Repository](https://github.com/RAKWireless/RAK14001-NCP5623-Library)** - Product repository for the RAKWireless RAK14001 RGB LED module.
* **[Documentation](https://docs.rakwireless.com/Product-Categories/WisBlock/#wisblock-io)** - Documentation and Quick Start Guide for the RAK14001 RGB LED module.

# Installation

In Arduino IDE open Sketch->Include Library->Manage Libraries then search for RAK14001.    

In PlatformIO open PlatformIO Home, switch to libraries and search for RAK14001. 
Or install the library project depend by adding 
```log
lib_deps =
  rakwireless/RAKwireless NCP5623 RGB LED library
```
into **`platformio.ini`**

For manual installation download the archive, unzip it and place the RAK14001-NCP5623-Library folder into the library directory.    
In Arduino IDE this is usually <arduinosketchfolder>/libraries/     
In PlatformIO this is usually <user/.platformio/lib>     

# Usage

The library provides a NCP5623 class, which allows communication to the NCP5623 RGB LED controller IC. Check out the examples how to use the library.

## This class provides the following methods:

**NCP5623();**    
Constructor NCP5623 class

**bool begin(TwoWire &wirePort = Wire);**     
Initializes state of NCP5623    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | wirePort | I2C port |
| return    |  | void |

**void setColor(uint8_t red, uint8_t green, uint8_t blue);**    
Sets all color channels. Values 0-255    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | red | Red channel | 
| in        | green | Green channel | 
| in        | blue | Blue channel | 
| return    |  | void |

**void setCurrent(uint8_t iled = 31);**    
Sets ILED (max current per channel). Rounds to nearest step    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | iled | Max current in milliamps (mA) | 
| return    |  | void |

**void setChannel(uint8_t channel, uint8_t value);**    
Sets the value of a specific PWM channel    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | channel | PWM channel 0, 1, or 2 | 
| in        | value | PWM value 0-31 | 
| return    |  | void |

**void setRed(uint8_t value);**    
Sets the intensity of the red channel
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | value | Intensity 0-255 | 
| return    |  | void |

**void setGreen(uint8_t value);**    
Sets the intensity of the green channel    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | value | Intensity 0-255 | 
| return    |  | void |

**void setBlue(uint8_t value);**    
Sets the intensity of the blue channel    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | value | Intensity 0-255 | 
| return    |  | void |

**void writeReg(uint8_t reg, uint8_t value);**    
Writes to a register    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | reg | Register 0-7
| in        | value | Value 0-31 | 
| return    |  | void |

**void mapColors(uint8_t red, uint8_t green, uint8_t blue);**    
Maps colors to channels    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | red | Channel 0-2 | 
| in        | green | Channel 0-2 | 
| in        | blue | Channel 0-2 | 
| return    |  | void |

**void setGradualDimming(uint32_t stepMs);**	 
Maps colors to channels    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | stepMs | 1-248ms | 
| return    |  | void |
		
**void setGradualDimmingUpEnd(uint8_t value);**    
Gradual Dimming Up End value    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | value | 0-31 | 
| return    |  | void |

void setGradualDimmingDownEnd(uint8_t value);    		
Maps Gradual Dimming Down End value    
Parameters:    
| Direction | Name | Function | 
| --------- | ---- | -------- |
| in        | value | 0-31 | 
| return    |  | void |

 # Channels

 | Channel | Pin | Default color mapping |
 | --- | --- | --- |
 | 0 | 5 | Red |
 | 1 | 4 | Green |
 | 2 | 3 | Blue |

 Use `mapColors` to map the channels to different colors. 
 Most functions accept 8 bit color values. These values are reduced to 5 bits by shifting right.