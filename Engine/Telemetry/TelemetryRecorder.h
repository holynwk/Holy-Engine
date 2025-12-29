#pragma once
#include <fstream>
#include <string>

namespace ote::telemetry {
class TelemetryRecorder {
public:
    bool Open(const std::string& path) { file_.open(path); if (file_) file_ << "timestamp,vehicle,posx,posy,posz,speed_kmh,air_pressure,lod\n"; return file_.good(); }
    void Record(double time, const std::string& name, const float* pos, float speed, float air, float lod) {
        if (!file_) return;
        file_ << time << "," << name << "," << pos[0] << "," << pos[1] << "," << pos[2] << "," << speed << "," << air << "," << lod << "\n";
    }
private:
    std::ofstream file_;
};
}
