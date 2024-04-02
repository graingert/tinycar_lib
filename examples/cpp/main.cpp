#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <chrono>

#include "tinycar.hpp"

void telemetryCallback(TinycarTelemetry telemetry) {
    std::cout << "\rBattery voltage: " << telemetry.battery_voltage << " mV" << "                         " << std::endl;
    std::cout << "\rCurrent FPS: " << (int)telemetry.current_fps << " FPS" << "                         " << std::endl;
    std::cout << "\rInterarrival jitter: " << telemetry.interarrival_jitter  << " ms" << "                         " << std::endl;
    std::cout << "\rWifi RSSI: " << (int)telemetry.wifi_rssi << " dB" << "                         " << std::endl;
    std::cout << "\rPacket loss percentage: " << (int)telemetry.packet_loss_percentage << " %" << "                         " << std::endl;
    std::cout << "\rPackets per frame: " << (int)telemetry.packets_per_frame << "                         " << std::endl;
    std::cout << "\rFrame latency: " << telemetry.frame_latency << " ms" << "                         " << std::endl;
    std::cout << std::flush;
    std::cout << "\033[7A";
}

int main(int argc, char** argv) {
    Tinycar car{std::string(argv[1])};
    // register telemetry callback
    car.registerTelemetryCallback(telemetryCallback);

    // we need to do any arbitrary action to receive images and telemetry
    car.setHeadlightOn();

    while(true) {
        cv::Mat img;
        if (car.getImage(img)) {
            cv::imshow("Tinycar", img);
            cv::waitKey(1);
        }
    }
    cv::destroyAllWindows();
    return 0;
}
