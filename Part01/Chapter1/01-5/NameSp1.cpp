#include <iostream>

namespace BestComImpl {
    void SimpleFunc(void) {
        std::cout << "The Function BestCom Defined" << std::endl;
    }
}

namespace ProgComImpl {
    void SimpleFunc(void) {
        std::cout << "The Function ProgCom Defined" << std::endl;
    }
}

int main(void) {
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();

    return 0;
}