#ifndef TCLOCK_H
#define TCLOCK_H

class Tclock {
    public:
    void step();
    unsigned getSec();
    unsigned getMin();
    void reset();

    protected:
    unsigned sec;
    unsigned min;
};

#endif // TCLOCK_H