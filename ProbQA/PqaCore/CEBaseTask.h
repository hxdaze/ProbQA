// Probabilistic Question-Answering system
// @2017 Sarge Rogatch
// This software is distributed under GNU AGPLv3 license. See file LICENSE in repository root for details.

#pragma once

#include "../PqaCore/CEBaseTask.decl.h"
#include "../PqaCore/BaseCpuEngine.h"

namespace ProbQA {

inline CEBaseTask::CEBaseTask(BaseCpuEngine &engine) : _pCe(&engine) { }

inline SRPlat::SRThreadPool& CEBaseTask::GetThreadPool() const {
  return _pCe->GetWorkers();
}

inline BaseCpuEngine& CEBaseTask::GetBaseEngine() const { return *_pCe; }

} // namespace ProbQA
