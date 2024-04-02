#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include "tinycar.hpp"

#include "ndarray_converter.h"

namespace py = pybind11;

PYBIND11_MODULE(tinycar, m) {
    NDArrayConverter::init_numpy();
    
    py::class_<Tinycar>(m, "Tinycar")
        .def(py::init<const std::string&>())
        .def("getImage", &Tinycar::getImage)
        .def("getLastImage", &Tinycar::getLastImage)
        .def("getFPS", &Tinycar::getFPS)
        .def("setMotorDutyCycle", &Tinycar::setMotorDutyCycle)
        .def("setServoAngle", &Tinycar::setServoAngle)
        .def("setBlinkerLeft", &Tinycar::setBlinkerLeft)
        .def("setBlinkerRight", &Tinycar::setBlinkerRight)
        .def("setBlinkerHazard", &Tinycar::setBlinkerHazard)
        .def("setBlinkerOff", &Tinycar::setBlinkerOff)
        .def("setHeadlightOff", &Tinycar::setHeadlightOff)
        .def("setHeadlightOn", &Tinycar::setHeadlightOn)
        .def("setHeadlightFullBeam", &Tinycar::setHeadlightFullBeam)
        .def("setTaillightOff", &Tinycar::setTaillightOff)
        .def("setTaillightOn", &Tinycar::setTaillightOn)
        .def("setTaillightBrake", &Tinycar::setTaillightBrake)
        .def("registerTelemetryCallback", &Tinycar::registerTelemetryCallback)
        .def("isAlive", &Tinycar::isAlive);

    py::class_<TinycarTelemetry>(m, "TinycarTelemetry")
        .def_readwrite("battery_voltage", &TinycarTelemetry::battery_voltage)
        .def_readwrite("current_fps", &TinycarTelemetry::current_fps)
        .def_readwrite("interarrival_jitter", &TinycarTelemetry::interarrival_jitter)
        .def_readwrite("wifi_rssi", &TinycarTelemetry::wifi_rssi)
        .def_readwrite("packet_loss_percentage", &TinycarTelemetry::packet_loss_percentage)
        .def_readwrite("packets_per_frame", &TinycarTelemetry::packets_per_frame)
        .def_readwrite("frame_latency", &TinycarTelemetry::frame_latency);
}