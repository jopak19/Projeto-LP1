#pragma once

class Silvestre{

protected:
    int marcacaoPermanente;
    bool perigoso;
    bool emExtincao;
public:
    Silvestre(int marcacaoPermanente, bool perigoso, bool emExtincao);
    int getMarcacaoPermanente() const;
    void setMarcacaoPermanente(int marcacao);
    bool getPerigoso() const;
    void setPerigoso(bool perigoso);
    bool getEmExtincao() const;
    void setEmExtincao(bool emExtincao);
};


