#ifndef LOCALPARAMETERS_H
#define LOCALPARAMETERS_H

#include <Parameters.h>

struct FoldSeekDbValidator : public DbValidator {
    static std::vector<int> tmscore;
    static std::vector<int> cadb;
    static std::vector<int> flatfileStdinAndFolder;
    static std::vector<int> flatfileAndFolder;

};

class LocalParameters : public Parameters {
public:
    static void initInstance() {
        new LocalParameters;
    }
    LocalParameters();
    static LocalParameters& getLocalInstance() {
        if (instance == NULL) {
            initInstance();
        }
        return static_cast<LocalParameters&>(LocalParameters::getInstance());
    }

    static const int DBTYPE_CA_ALPHA;
    static const int DBTYPE_TMSCORE;

    static const int ALIGNMENT_TYPE_3DI = 0;
    static const int ALIGNMENT_TYPE_TMALIGN = 1;
    static const int ALIGNMENT_TYPE_3DI_AA = 2;

    static const unsigned int INDEX_DB_CA_KEY = 500;

    std::vector<MMseqsParameter *> strucclust;
    std::vector<MMseqsParameter *> tmalign;
    std::vector<MMseqsParameter *> structuresearchworkflow;
    std::vector<MMseqsParameter *> structureclusterworkflow;
    std::vector<MMseqsParameter *> databases;
    std::vector<MMseqsParameter *> easystructuresearchworkflow;
    std::vector<MMseqsParameter *> structurecreatedb;
    PARAMETER(PARAM_TMSCORE_THRESHOLD)
    PARAMETER(PARAM_ALIGNMENT_TYPE)

    PARAMETER(PARAM_GAPNW)
    PARAMETER(PARAM_NNWEIGHT)
    PARAMETER(PARAM_NNN)
    PARAMETER(PARAM_SLOPE)
    float tmScoreThr;
    int alignmentType;
    int gapNW;
    int nnWeight;
    int numberNN;
    int slope;
private:

    LocalParameters(LocalParameters const&);
    ~LocalParameters() {};
    void operator=(LocalParameters const&);
};


#endif
