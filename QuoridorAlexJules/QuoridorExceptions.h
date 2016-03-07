#ifndef QUORIDOREXCEPTIONS_H
#define QUORIDOREXCEPTIONS_H
#include <exception>

/*!
 * \brief Classe chargée des exceptions lié au jeu Quoridor
 */
class QuoridorExceptions :public std::exception{
public:
    /*!
     * \brief Constructeur du lanceur d'exception
     * \param numero le numero de l'exception
     * \param niveau le niveau de l'exception
     * \param phrase la phrase expliquant l'exception
     */
    QuoridorExceptions(int numero=0, std::string const& phrase="" ,int niveau=0) throw()
             :m_numero(numero),m_phrase(phrase),m_niveau(niveau){}
    /*!
     * \brief Méthode permettant de récupérer le message lancé ar l'exception
     * \return la phrase d'exception
     */
    virtual const char* what() const throw(){
        return m_phrase.c_str();
    }
    /*!
     * \brief éthode donnant le niveau d'exception
     * \return le niveau d'exception
     */
    int getNiveau() const throw(){
         return m_niveau;
    }
    /*!
     * \brief Destructeur du quoridorExceptions
     */
    virtual ~QuoridorExceptions() throw(){}

private:
    /*!
     * \brief Le numéro de l'exception
     */
    int m_numero;
    /*!
     * \brief La phrase de l'exception
     */
    std::string m_phrase;
    /*!
     * \brief Le niveau d exception
     */
    int m_niveau;
};
#endif // QUORIDOREXCEPTIONS_H
