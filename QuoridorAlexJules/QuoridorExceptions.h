#ifndef QUORIDOREXCEPTIONS_H
#define QUORIDOREXCEPTIONS_H
#include <exception>


class QuoridorExceptions :public std::exception{
public:
    QuoridorExceptions(int numero=0, std::string const& phrase="", int niveau=0) throw()
             :m_numero(numero),m_phrase(phrase),m_niveau(niveau){};
    virtual const char* what() const throw(){
        return m_phrase.c_str();
    };

    int getNiveau() const throw(){
         return m_niveau;
    };

    virtual ~QuoridorExceptions() throw(){};

private:
    int m_numero;
    std::string m_phrase;
    int m_niveau;
};
#endif // QUORIDOREXCEPTIONS_H
