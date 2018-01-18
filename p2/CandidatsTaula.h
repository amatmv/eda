#ifndef P2_CANDIDATSTAULA_H
#define P2_CANDIDATSTAULA_H


class CandidatsTaula
{
public:
    /**
     @pre cert
     @post Constructor per defecte de CandidatsTaula
     */
    CandidatsTaula();

    /**
     @pre cert
     @post Constructor amb paràmetres de CandidatsTaula
     */
    explicit CandidatsTaula(const int &v);

    /**
     @pre cert
     @post retorna el convidat actual
     */
    int actual() const;

    /**
     @pre cert
     @post retorna cert si no queden més convidat per mirar
     */
    bool es_fi() const;

    /**
     @pre cert
     @post incrementa iCan
     */
    void seguent();

private:

    int _iCan;
    int _convidats;
};


#endif //P2_CANDIDATSTAULA_H
