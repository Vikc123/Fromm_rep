#include <iostream>

using namespace std;
template<typename T>
class Image {
    public:
    class Pixel {
    private:
        int red;
        int green;
        int blue;
    public:
        Pixel(int r, int g, int b) {
            this->red = r;
            this->green = g;
            this->blue = b;
        }
        void GetInfo() {
            cout << "Red: "+ to_string(red) + " Green: " + to_string(green) + " Blue: " + to_string(blue) << endl;
        }
    };
    void GetImageInfo() {
        for (int i = 0; i < 4; i++) {
            pixels[i].GetInfo();
        }
    }

    private:
    Pixel pixels[4] {
        Pixel(0, 0, 0),
        Pixel(2, 2, 2),
        Pixel(4, 4, 4),
        Pixel(6, 6, 6),
    };
};

int main() {
    Image<int> image;
    Image<int>::Pixel pixel(3,4,5);
    pixel.GetInfo();
    return 0;
}