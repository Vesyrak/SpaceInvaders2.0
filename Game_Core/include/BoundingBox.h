#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
namespace Game_Core {
class BoundingBox{
    private:
        double x;
        double y;
        double width;
        double height;
    public:
        BoundingBox(double x, double y, double width, double height);
        ~BoundingBox();
        double getWidth();
        double getHeight();
        double getX();
        double getY();
        void setX(double value);
        void setY(double value);
        void setWidth(double value);
        void setHeight(double value);
        bool collidesWith(BoundingBox* bounds);
};}
#endif
