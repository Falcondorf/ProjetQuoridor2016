#ifndef QUORIDOREXCEPTIONS_H
#define QUORIDOREXCEPTIONS_H
#include <exception>

/*!
 * \brief The QuoridorExceptions classe chargée des exceptions lié au jeu Quoridor
 */
class QuoridorExceptions :public std::exception{
public:
    /*!
     * \brief QuoridorExceptions constructeur du lanceur d'exception
     * \param numero le numero de l'exception
     * \param niveau le niveau de l'exception
     * \param phrase la phrase expliquant l'exception
     */
    QuoridorExceptions(int numero=0, int niveau=0 ,std::string const& phrase="") throw()
             :m_numero(numero),m_phrase(phrase),m_niveau(niveau){}
    /*!
     * \brief what
     * \return la phrase d'exception
     */
    virtual const char* what() const throw(){
        return m_phrase.c_str();
    }
    /*!
     * \brief getNiveau donne le niveau d'exception
     * \return le niveau d'exception
     */
    int getNiveau() const throw(){
         return m_niveau;
    }
    /*!
     * \brief ~QuoridorExceptions destructeur du quoridor exception
     */
    virtual ~QuoridorExceptions() throw(){}

private:
    /*!
     * \brief m_numero le numéro de l'exception
     */
    int m_numero;
    /*!
     * \brief m_phrase la phrase de l'exception
     */
    std::string m_phrase;
    /*!
     * \brief m_niveau le niveau d exception
     */
    int m_niveau;
};
#endif // QUORIDOREXCEPTIONS_H
