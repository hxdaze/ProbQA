﻿using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace ProbQANetCore
{
  public class PqaEngine
  {
    [DllImport("PqaCore.dll", CallingConvention = CallingConvention.Cdecl)]
    private static extern void CiReleasePqaEngine(IntPtr pEngine);

    [DllImport("PqaCore.dll", CallingConvention = CallingConvention.Cdecl)]
    private static extern IntPtr PqaEngine_Train(IntPtr pEngine, Int64 nQuestions, IntPtr pAQs, Int64 iTarget,
      double amount = 1.0);

    [DllImport("PqaCore.dll", CallingConvention = CallingConvention.Cdecl)]
    private static extern byte PqaEngine_QuestionPermFromComp(IntPtr pEngine, Int64 count, IntPtr pIds);

    private IntPtr _nativeEngine;

    internal PqaEngine(IntPtr native)
    {
      _nativeEngine = native;
    }

    ~PqaEngine()
    {
      CiReleasePqaEngine(_nativeEngine);
    }

    public PqaError Train(long nQuestions, AnsweredQuestion[] AQs, long iTarget, double amount = 1.0)
    {
      GCHandle pAQs = GCHandle.Alloc(AQs, GCHandleType.Pinned);
      try
      {
        return new PqaError(PqaEngine_Train(_nativeEngine, nQuestions, pAQs.AddrOfPinnedObject(), iTarget, amount));
      }
      finally
      {
        pAQs.Free();
      }
    }

    public bool QuestionPermFromComp(Int64[] ids)
    {
      GCHandle pIds = GCHandle.Alloc(ids, GCHandleType.Pinned);
      try
      {
        return PqaEngine_QuestionPermFromComp(_nativeEngine, ids.LongLength, pIds.AddrOfPinnedObject()) != 0;
      }
      finally
      {
        pIds.Free();
      }
    }
  }
}
