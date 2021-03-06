// Probabilistic Question-Answering system
// @2017 Sarge Rogatch
// This software is distributed under GNU AGPLv3 license. See file LICENSE in repository root for details.

#pragma once

#include "../SRPlatform/Interface/SRPlatform.h"

namespace SRPlat {

class SRPLATFORM_API SRCriticalSection {
  friend class SRConditionVariable;
  CRITICAL_SECTION _block;
public:
  explicit SRCriticalSection();
  explicit SRCriticalSection(const uint32_t spinCount);

  SRCriticalSection(const SRCriticalSection&) = delete;
  SRCriticalSection& operator=(const SRCriticalSection&) = delete;
  SRCriticalSection(SRCriticalSection&&) = delete;
  SRCriticalSection& operator=(SRCriticalSection&&) = delete;

  ~SRCriticalSection();
  void Acquire(); // Enter
  void Release(); // Leave
};

} // namespace SRPlat
