# tinycar_lib

Library to interact with a [tinycar](https://github.com/danielriege/tinycar) over WiFi. It is designed to be a simple and user friendly interface to control the car or receive camera images and telemetry data. It is written in C++ but can be used in Python as well. Please refer to the [examples](./examples/) for more information.

### Prerequisites:
The C++ library only requires you to have OpenCV installed (not the Python version). In order to use the Python Wrapper however, besides OpenCV you also need:
- numpy (not the Python version)
- cmake

### Installation:
When using C++ we recommend to clone this repo as a submodule and include the source files in your project. For a CMakeLists example, refer to the [examples](./examples/). 

If you want to use the Python Wrapper, you can install it via pip. This will compile the C++ code and wrap it around a Python module (therefore we need the prerequisites):
```bash
pip install git+https://github.com/danielriege/tinycar_lib.git
```
  
### Example:
C++
```cpp
#include "tinycar.hpp"

Tinycar car{std::string("HOSTNAME")};
car.setHeadlightOn();
```
Python
```python
from tinycar import Tinycar

car = Tinycar("HOSTNAME")
car.setHeadlightOn()
```
**Note:** In order to receive information from the car (e.g. camera images or telemetry data) you need to call an arbitrary control method (like `setHeadlightOn()`), so the car knows your IP address and can send you the data. The car uses UDP and a fire-and-forget mechanism, there is no handshake or acknowledgment. But you can call `isAlive()` which returns `true` if the car is periodically sending you any data. After sending any control message and `isAlive()` returns `false`, you can assume that the car is not reachable.
