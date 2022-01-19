
class Bar
{

    public:
        // Default constructor
        Bar();

        // Copy constructor
        Bar(Bar const & rhs);

        // Copy assignment operator
        Bar & operator = (Bar const & rhs);

        // Destructor
        ~Bar();

#if 0
        // Move constructor
        Bar(Bar && lhs) = delete;

        // Move assignment operator
        Bar & operator = (Bar && rhs) = delete;
#endif
};
