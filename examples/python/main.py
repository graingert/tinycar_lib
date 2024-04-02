import cv2, sys
import numpy as np
from tinycar import Tinycar, TinycarTelemetry

def telemetryCallback(telemetry):
    print(f"Battery voltage {telemetry.battery_voltage} mV")

car = Tinycar(sys.argv[1])
car.registerTelemetryCallback(telemetryCallback)

car.setHeadlightOn()

while True:
    img = car.getLastImage()
    if img is not None:
        cv2.imshow("Image", img)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

car.setHeadlightOff()

cv2.destroyAllWindows()
