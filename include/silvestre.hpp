#pragma once

class Silvestre{

protected:
    int marcacaoPermanente;
    bool emExtincao;
public:
    Silvestre(int marcacaoPermanente, bool emExtincao);
    int getMarcacaoPermanente() const;
    void setMarcacaoPermanente(int marcacao);
    bool getEmExtincao() const;
    void setEmExtincao(bool emExtincao);
    virtual ~Silvestre();
};


