// classe Mère
//case.h
class Case
{
protected:
    Case()=default;
};

// classe Pion
//pion.h
class Pion : public Case
{
public:
    Pion();
};
//pion.cpp
Pion::Pion() : Case()
{
}

// classe Mur
// mur.h
class Mur : public Case
{
public:
    Mur();
};
//mur.cpp
Mur::Mur() : Case()
{
}

// classe Plateau
//plateau.h
class Plateau
{
private:
    unsigned len_;
    std::vector<std::vector<Case *>> plateau;
public:
    Plateau(unsigned len);
};
//plateau.cpp
Plateau::Plateau(unsigned len) : len_(len)
{
    unsigned hidden_len=len*2-1;
    plateau=vector<vector<Case *>>(hidden_len, vector<Case *>(hidden_len, nullptr);
    //TODO :
    //assigner les cases
}

//TODO :
//getter d'un Mur, getter d'un Pion

//Bon travail :).
