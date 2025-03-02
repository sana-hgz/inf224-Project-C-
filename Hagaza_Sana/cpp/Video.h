#ifndef VIDEO_H
#define VIDEO_H

#include "BaseMultimedia.h"

class Video : public BaseMultimedia {
private:
    int duration;

public:
    Video() : BaseMultimedia("", ""), duration(0) {}
    Video(const std::string& name, const std::string& path, int dur = 0)
        : BaseMultimedia(name, path), duration(dur) {}
           std::string getClassName() const override { return "Video"; }
  //serialisation
    void serialize(std::ostream& os) const override {
        BaseMultimedia::serialize(os);
        os << duration << "\n";
    }
  //deserialisation
    void deserialize(std::istream& is) override {
        BaseMultimedia::deserialize(is);
        is >> duration;
        is.ignore();
    }

    int getDuration() const { return duration; }
    void setDuration(int dur) { duration = dur; }

    void display(std::ostream& os) const override {
        BaseMultimedia::display(os);
        os << "Duration: " << duration << " seconds" << std::endl;
    }

    void play() const override {
        std::string command = "mpv " + getFilePath() + " &";
        system(command.data());
    }
};

#endif // VIDEO_H       