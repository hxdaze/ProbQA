#include "stdafx.h"
#include "PqaEngineBaseFactory.h"
#include "../PqaCore/Interface/PqaErrorParams.h"
#include "../PqaCore/CpuEngine.h"
#include "../PqaCore/DoubleNumber.h"

using namespace SRPlat;

namespace ProbQA {

IPqaEngine* PqaEngineBaseFactory::CreateCpuEngine(PqaError& err, const EngineDefinition& engDef) {
  //TODO: implement
  switch (engDef._prec._type) {
  case TPqaPrecisionType::Double:
    return new CpuEngine<DoubleNumber>(engDef);
  default:
    err = PqaError(PqaErrorCode::NotImplemented, new NotImplementedErrorParams(SRString::MakeUnowned(
      "ProbQA Engine on CPU for precision except double.")));
    return nullptr;
  }
}

IPqaEngine* PqaEngineBaseFactory::CreateCudaEngine(PqaError& err, const EngineDefinition& engDef) {
  //TODO: implement
  err = PqaError(PqaErrorCode::NotImplemented, new NotImplementedErrorParams(SRString::MakeUnowned(
    "ProbQA Engine on CUDA.")));
  return nullptr;
}

IPqaEngine* PqaEngineBaseFactory::CreateGridEngine(PqaError& err, const EngineDefinition& engDef) {
  //TODO: implement
  err = PqaError(PqaErrorCode::NotImplemented, new NotImplementedErrorParams(SRString::MakeUnowned(
    "ProbQA Engine over a grid.")));
  return nullptr;
}

} // namespace ProbQA
