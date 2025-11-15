#ifndef ERRLOG_ERR_HPP
#define ERRLOG_ERR_HPP

#include <iostream>
#include <fstream>

class ErrLog {

    public:
        void genLogFile(const std::string& t_message);

    private:
        std::string genTimeStamp();

};

#endif // ERRLOG_ERR_HPP