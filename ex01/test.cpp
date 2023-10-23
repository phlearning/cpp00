#include <iostream>

class Sample {

public:
    int publicFoo;

    Sample(float const f);
    ~Sample(void);

    void publicBar(void) const;

private:
    int _privateFoo;

    void _privateBar(void) const;
};

Sample::Sample(void) {

    std::cout << "Constructor called " << __func__ << std::endl;

    this->publicFoo = 0;
    std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
    this->_privateFoo = 0;
    std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

    this->publicBar();
    this->_privateBar();
    return;
}

Sample::~Sample(void) {
    std::cout << "Constructor called " << __func__ << std::endl;
    return;
}

void Sample::publicBar(void) const {

    std::cout << "Member function publicBar called" << std::endl;
    return;
}

int main(void) {
    Sample instance;


    return (0);
}