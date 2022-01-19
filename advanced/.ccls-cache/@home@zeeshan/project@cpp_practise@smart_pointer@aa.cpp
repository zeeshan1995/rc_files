

class three_d_object
{
    public:
        virtual ~three_d_object() {}
        virtual double surface_area() const = 0;
        virtual double volume() const = 0;
};


class sphere : public three_d_object
{
    sphere() : _radius{1.0} {}
    sphere(double radius) : _radius{radius} {}

    //other special member functions are default

    virtual double surface_area() const { return 4 * 3.14 * _radius * _radius; }
    virtual double volume() const { return 4 / 3 * 3.14 * _radius * _radius * _radius;}

    private:
        double _radius;
};

class cylinder : public three_d_object
{
    cylinder() : _radius{1.0}, _height{1.0} {}
    cylinder(double radius, double height) : _radius{radius}, _height{height} {}

    //other special member functions are default

    virtual double surface_area() { return 2 * 3.14 * _radius * (_radius + _height); }
    virtual double volume() { return 3.14 * _radius * _radius * _height;}

    private:
        double _radius;
        double _height;
};

int main()
{
    int a = 0;
    ++a;
}
