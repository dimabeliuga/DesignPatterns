#ifndef SMART_LOCK_H
#define SMART_LOCK_H

#include <iostream>

class SmartLock {
    private:
        bool isLocked = true;
    public:
        void lock() {
            isLocked = true;
            std::cout << "Smart lock is locked" << std::endl;
        }
        void unlock() {
            isLocked = false;
            std::cout << "Smart lock is unlocked" << std::endl;
        }
        void getStatus() const {
            std::cout << "Smart lock is " << (isLocked ? "locked" : "unlocked") << std::endl;
        }
};

#endif // SMART_LOCK_H